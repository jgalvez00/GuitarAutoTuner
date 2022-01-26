
//============================================================================
// ECE 362 lab experiment 8 -- SPI and DMA
//============================================================================

#include "stm32f0xx.h"
#include "lcd.h"
#include <stdio.h> // for sprintf()

const char* menu[3] = {"Tune", "Manual", "Config"};

// Be sure to change this to your login...
const char login[] = "gamble13";

int currentSelectIndex = 0;


// Prototypes for misc things in lcd.c
void nano_wait(unsigned int);

// Write your subroutines below.

void setup_buttons() {
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	GPIO_InitTypeDef buttons;
	buttons.GPIO_Mode = GPIO_Mode_IN;
	buttons.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOB, &buttons);
	buttons.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOB, &buttons);
	buttons.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOB, &buttons);
}

void setup_LEDS() {
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	GPIO_InitTypeDef leds;
	leds.GPIO_Mode = GPIO_Mode_OUT;
	leds.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOC, &leds);
	leds.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOC, &leds);
	leds.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init(GPIOC, &leds);
}



void setup_bb() {
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    GPIOB->MODER &= ~GPIO_MODER_MODER12 & ~GPIO_MODER_MODER13 & ~GPIO_MODER_MODER15;
    GPIOB->MODER |= GPIO_MODER_MODER12_0 | GPIO_MODER_MODER13_0 | GPIO_MODER_MODER15_0;
    GPIOB->ODR |= GPIO_ODR_12;
    GPIOB->ODR &= ~GPIO_ODR_13;
}

void small_delay() {
    nano_wait(1000000);
}

void bb_write_bit(int MOSIpin) {
    GPIOB->ODR &= ~GPIO_ODR_15;
    GPIOB->ODR |= (MOSIpin << 15);
    small_delay();
    GPIOB->ODR |= GPIO_ODR_13; //SCK
    small_delay();
    GPIOB->ODR &= ~GPIO_ODR_13;
}

void bb_write_byte(unsigned int byte) {
    for(int i = 7; i >= 0; i--){
        bb_write_bit((byte>>i) & 1);
    }
}

void bb_cmd(int byte) {
    GPIOB->ODR &= ~GPIO_ODR_12; //NSS
    small_delay();
    bb_write_bit(0); //RS
    bb_write_bit(0); //R/W
    bb_write_byte(byte);
    small_delay();
    GPIOB->ODR |= GPIO_ODR_12; //NSS
    small_delay();
}

void bb_data(int byte) {
    GPIOB->ODR &= ~GPIO_ODR_12; //NSS
    small_delay();
    bb_write_bit(1); //RS
    bb_write_bit(0); //R/W
    bb_write_byte(byte);
    small_delay();
    GPIOB->ODR |= GPIO_ODR_12; //NSS
    small_delay();
}

void bb_init_oled() {
    nano_wait(1000000);
    bb_cmd(0x38);
    bb_cmd(0x08);
    bb_cmd(0x01);
    nano_wait(2000000);
    bb_cmd(0x06);
    bb_cmd(0x02);
    bb_cmd(0x0c);
}

bb_display1(const char* str) {
    bb_cmd(0x02);
    int pos = 0;
    while(str[pos] != '\0') {
        bb_data(str[pos]);
        pos++;
    }
}

bb_display2(const char* str) {
    bb_cmd(0xc0);
    int pos = 0;
    while(str[pos] != '\0') {
        bb_data(str[pos]);
        pos++;
    }
}

void setup_spi2() {
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
    GPIOB->MODER &= ~GPIO_MODER_MODER12 & ~GPIO_MODER_MODER13 & ~GPIO_MODER_MODER15;
    GPIOB->MODER |= GPIO_MODER_MODER12_1 | GPIO_MODER_MODER13_1 | GPIO_MODER_MODER15_1;
    SPI2->CR1 |= SPI_CR1_BR | SPI_CR1_MSTR | SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE;
    SPI2->CR2 = SPI_CR2_DS_3 | SPI_CR2_DS_0;
    //SPI2->CR2 |= SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0;
    SPI2->CR2 |= SPI_CR2_NSSP | SPI_CR2_SSOE;
    SPI2->CR1 |= SPI_CR1_SPE;

}

void spi_cmd(unsigned int cmd) {
    while (!(SPI2->SR & SPI_SR_TXE));
    SPI2->DR = cmd;
}

void spi_data(unsigned int data) {
    while (!(SPI2->SR & SPI_SR_TXE));
        SPI2->DR = 0x200 | data;
}

void spi_init_oled() {
    nano_wait(1000000);
    spi_cmd(0x38);
    spi_cmd(0x08);
    spi_cmd(0x01);
    nano_wait(2000000);
    spi_cmd(0x06);
    spi_cmd(0x02);
    spi_cmd(0x0c);

}

void spi_display1(const char* str) {
    spi_cmd(0x02);
    int pos = 0;
    while(str[pos] != '\0') {
        spi_data(str[pos]);
        pos++;
    }
}

void spi_display2(const char* str) {
    spi_cmd(0xc0);
    int pos = 0;
    while(str[pos] != '\0') {
        spi_data(str[pos]);
        pos++;
    }
}

void spi_enable_dma(const short* data) {
    RCC->AHBENR |= RCC_AHBENR_DMA1EN;
    DMA1_Channel5->CCR &= ~DMA_CCR_EN;
    DMA1_Channel5->CPAR = &(SPI2->DR);
    DMA1_Channel5->CMAR = data;
    DMA1_Channel5->CNDTR = 34;
    DMA1_Channel5->CCR |= DMA_CCR_DIR | DMA_CCR_CIRC;
    DMA1_Channel5->CCR |= DMA_CCR_MINC;
    DMA1_Channel5->CCR &= ~DMA_CCR_PSIZE & ~DMA_CCR_MSIZE;
    DMA1_Channel5->CCR |= DMA_CCR_PSIZE_0 | DMA_CCR_MSIZE_0;
    DMA1_Channel5->CCR |= DMA_CCR_EN;
    SPI2->CR2 |= SPI_CR2_TXDMAEN;
}

void setup_spi1() {
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA -> MODER &= ~GPIO_MODER_MODER4 & ~GPIO_MODER_MODER5 & ~GPIO_MODER_MODER7;
    GPIOA -> MODER |= GPIO_MODER_MODER4_1 | GPIO_MODER_MODER5_1 | GPIO_MODER_MODER7_1;
    GPIOA -> MODER &= ~GPIO_MODER_MODER2 & ~GPIO_MODER_MODER3;
    GPIOA -> MODER |= GPIO_MODER_MODER2_0 | GPIO_MODER_MODER3_0;
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFRL4 & ~GPIO_AFRL_AFRL5 & ~GPIO_AFRL_AFRL7;

    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
    SPI1->CR1 |= SPI_CR1_MSTR | SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE;
    SPI1->CR1 &= ~SPI_CR1_BR;
    SPI1->CR2 = SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0;
    SPI1->CR2 |= SPI_CR2_NSSP | SPI_CR2_SSOE;
    SPI1->CR1 |= SPI_CR1_SPE;


}


// Write your subroutines above.

void show_counter(short buffer[])
{
    for(int i=0; i<10000; i++) {
        char line[17];
        sprintf(line,"% 16d", i);
        for(int b=0; b<16; b++)
            buffer[1+b] = line[b] | 0x200;
    }
}


extern const Picture *image;

void menu_select(int selectIndex) {
	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, menu[selectIndex], 16, 0);
	LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, menu[currentSelectIndex], 16, 0);

	currentSelectIndex = selectIndex;
}

int main(void)
{
    //internal_clock();
    //demo();
    //autotest();

    /*setup_bb();
    bb_init_oled();
    bb_display1("Hello,");
    bb_display2(login);

    setup_spi2();
    spi_init_oled();
    spi_display1("Hello again,");
    spi_display2(login);

    short buffer[34] = {
            0x02, // This word sets the cursor to the beginning of line 1.
            // Line 1 consists of spaces (0x20)
            0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220,
            0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220,
            0xc0, // This word sets the cursor to the beginning of line 2.
            // Line 2 consists of spaces (0x20)
            0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220,
            0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220, 0x220,
    };

    spi_enable_dma(buffer);
    show_counter(buffer);*/

    setup_spi1();
    LCD_Init();
    LCD_Clear(BLUE);
    setup_buttons();
    setup_LEDS();
    //LCD_DrawLine(10,20,100,200, WHITE);
    //LCD_DrawRectangle(10,20,100,200, GREEN);
    //LCD_DrawFillRectangle(120,20,220,200, RED);
    //LCD_Circle(50, 260, 50, 1, BLUE);
    //LCD_DrawFillTriangle(130,130, 130,200, 190,160, YELLOW);
    //GPIO_WriteBit(GPIOC,7,Bit_SET);
    //GPIO_SetBits(GPIOC,7);
    for (int i = 0; i < 3; i++) {
    	LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, menu[i], 16, 0);
    }

    while (1) {
    	menu_select(0);
    	 nano_wait(100000000);

    	 menu_select(1);
		 nano_wait(100000000);

		 menu_select(2);
		 nano_wait(100000000);

    	/*if (GPIO_ReadInputDataBit(GPIOB,2) == 1) {
    		GPIO_SetBits(GPIOC,7);
    	} else GPIO_ResetBits(GPIOC,7);*/

    }




    //LCD_DrawString(140,60,  WHITE, BLACK, "ECE 362", 16, 0);
    //LCD_DrawString(140,80,  WHITE, BLACK, "has the", 16, 1);
    //LCD_DrawString(130,100, BLACK, GREEN, "best toys", 16, 0);
    //LCD_DrawPicture(110,220,(const Picture *)&image);
}
