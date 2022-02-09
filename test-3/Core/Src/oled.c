
#include "stm32f0xx.h"
#include <stdint.h>
#include <stdlib.h>
#include "lcd.h"

//edit
//#include <string.h>
char check_key()
{/*
    if ((GPIOB->IDR>>4) == 1)
        return '*';
    if ((GPIOB->IDR>>7) == 1)
        return 'D';
    return 0;
*/

    if((GPIOB -> IDR >> 4) & 0x1){
        return '*';
    }
    if((GPIOB -> IDR >> 5) & 0x1){
            return '8';
        }
    if((GPIOB -> IDR >> 6) & 0x1){
        return '#';
    }

    return 0;
    // If the '*' key is pressed, return '*'
    // If the 'D' key is pressed, return 'D'
    // Otherwise, return 0
}

void setup_spi1()
{
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
        GPIOA->MODER &=~ 0xcff0;
        GPIOA->MODER |= 0x8A50;

        RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
        SPI1->CR1 |= SPI_CR1_MSTR | SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE;
        SPI1->CR1 &=~ (SPI_CR1_BR_0 | SPI_CR1_BR_1 | SPI_CR1_BR_2);
        SPI1->CR2 = SPI_CR2_DS_0 | SPI_CR2_DS_1 | SPI_CR2_DS_2 | SPI_CR2_NSSP | SPI_CR2_SSOE;
        SPI1->CR1 |= SPI_CR1_SPE;

        return;
    // Use setup_spi1() from lab 8.
}
void setup_bb()
{
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    GPIOB->MODER &= ~ 0xcf000000;
    GPIOB->MODER |=  0x45000000;
    GPIOB->ODR |= 0x1000;

}
void small_delay()
{
    nano_wait(1000000);

}
void bb_write_bit(int input)
{
    GPIOB->ODR &=~ 0x8000;
    GPIOB->ODR |= input << 15;
    small_delay();
    GPIOB->ODR &=~ 0x2000;
    GPIOB->ODR |=  1<< 13;

    small_delay();
    GPIOB->ODR &=~ 0x2000;


}
void bb_write_byte(int input)
{
    bb_write_bit((input >> 7) & 0x1);
    bb_write_bit((input >> 6) & 0x1);
    bb_write_bit((input >> 5) & 0x1);
    bb_write_bit((input >> 4) & 0x1);
    bb_write_bit((input >> 3) & 0x1);
    bb_write_bit((input >> 2) & 0x1);
    bb_write_bit((input >> 1) & 0x1);
    bb_write_bit((input >> 0) & 0x1);

}
void bb_cmd(int input)
{
    GPIOB->ODR &=~ 0x1000;
    small_delay();
    bb_write_bit(0);
    bb_write_bit(0);
    bb_write_byte(input);
    small_delay();
    GPIOB->ODR &=~ 0x1000;
    GPIOB->ODR |= 1 << 12;
    small_delay();

}
void bb_data(int input)
{
    GPIOB->ODR &=~ 0x1000;
    small_delay();
    bb_write_bit(1);
    bb_write_bit(0);
    bb_write_byte(input);
    small_delay();
    GPIOB->ODR &=~ 0x1000;
    GPIOB->ODR |= 1 << 12;
    small_delay();

}
void bb_init_oled()
{
    nano_wait(1000000);
    bb_cmd(0x38);
    bb_cmd(0x08);
    bb_cmd(0x01);
    nano_wait(2000000);
    bb_cmd(0x06);
    bb_cmd(0x02);
    bb_cmd(0x0c);

}
void bb_display1(const char * input)
{
    bb_cmd(0x02);
    int i = 0;
    while(i < strlen(input))
        {
            if(input[i] != NULL)
                bb_data(input[i]);
            i++;
        }


}
void bb_display2(const char *input)
{
    bb_cmd(0xc0);
    int i = 0;
    while(i < strlen(input))
    {
      if(input[i] != NULL)
          bb_data(input[i]);

      i++;
     }


}
/*int main(void)
{
    //setup_portb();
    setup_spi1();
    
    setup_bb();
    bb_init_oled();
    bb_display1("Home Display");
    bb_display2("Info Tune Manual");

}*/
