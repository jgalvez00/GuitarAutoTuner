/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32f0xx.h"
#include "lcd.h"
#include "oled.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
void menu_move(int selectIndex);
void Tune_move(int scrollidx, int selectIndex, int enable);
void Tunemode();
int Tune_select(int selectIndex);
void stepperMotor(int direction, int freq, int step, int mode);
void peg_move(int selectIndex);
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;

I2C_HandleTypeDef hi2c2;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim1;

/* USER CODE BEGIN PV */

const char* menu[3] = {"Info", "Tune", "Manual"};
const char* Tune[7] = {"Back", "Peg1", "Peg2", "Peg3", "Peg4", "Peg5", "Peg6"};
const char* Manual[3] = {"Back", "Tight", "Loose"};
const char* Info[2] = {"Back", "Next"};
const char* peg[3] = {"Back", "Test1", "90"};
const char* pegsel[6] = {"Peg 1", "Peg 2", "Peg 3", "Peg 4", "Peg 5", "Peg 6"};
const char* note[6] = {"E", "A", "D", "G", "B", "E"};
int currentSelectIndex = 0;
int currentScrollIndex = 0;
int goleft = 0;
int goright  =0;
//int thefall = 0;
uint32_t prev = 0;
uint32_t curr = 0;
uint32_t stepprev = 0;
uint32_t stepcurr = 0;
uint8_t lastPressed = -1;
uint8_t lastButton = -1;
uint8_t pressHistory[3] = {0,0,0};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC_Init(void);
static void MX_I2C2_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */

void menu_select(int selectIndex);
uint8_t updateToggleHistory(uint8_t button);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC_Init();
  MX_I2C2_Init();
  MX_SPI1_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */

  LCD_Init();
  LCD_Clear(BLUE);
  for (int i = 0; i < 3; i++) {
	LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, menu[i], 16, 0);
  }
  LCD_DrawString(25,200,  YELLOW, BLACK, menu[0], 16, 0);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  //----------------------added----------------------------------//
  /*setup_bb();
  setup_spi1();
  bb_init_oled();
  bb_display1("Home Display");
  bb_display2("Info Tune Manual");*/
  //----------------------ENDadded----------------------------------//
  //stepperMotor(1, 100, 1000);
  /*HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  nano_wait(5000000000);*/
  /*HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
  nano_wait(5000000000);
  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
  change_pwm(15000);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  nano_wait(5000000000);
  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
  change_pwm(7500);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  nano_wait(5000000000);
  HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
  stepperMotor(1, 0, 1000);
  stepperMotor(0, 0, 1000);*/

  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
  /*	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
  for (int i = 0; i < 90; i++)
  	{
  		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
  		nano_wait(5000000);
  		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
  		nano_wait(5000000);
  	}
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
  //stepperMotor(1, 15000, 90, 0);*/
  while (1)
  {

	LCD_DrawString(80 ,40,  YELLOW, BLUE,"Home Menu", 16, 0);

	if (goleft == 1/*updateToggleHistory(2)*/) {
		if (currentSelectIndex == 0) {
			menu_move(2);

		} else {
			menu_move((currentSelectIndex - 1) % 3);
		}
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
		goleft = 0;

	} else if (updateToggleHistory(3)) {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
		menu_select(currentSelectIndex);

	} else if (goright == 1/*updateToggleHistory(4)*/) {

		if (currentSelectIndex == 2) {
					menu_move(0);
		} else {
			menu_move((currentSelectIndex + 1) % 3);
		}
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
		goright = 0;

	} else {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
	}

	HAL_Delay(40);


  }
}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

void change_pwm(int per)
{
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	  TIM_OC_InitTypeDef sConfigOC = {0};
	  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

	  htim1.Instance = TIM1;
	  htim1.Init.Prescaler = 0;
	  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim1.Init.Period = per;
	  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  htim1.Init.RepetitionCounter = 90;//0;
	  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = per/2;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
	  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
	  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
	  sBreakDeadTimeConfig.DeadTime = 0;
	  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
	  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
	  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
	  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  HAL_TIM_MspPostInit(&htim1);
}

extern const Picture *image;

void menu_move(int selectIndex) {

	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, menu[selectIndex], 16, 0);
	LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, menu[currentSelectIndex], 16, 0);

	currentSelectIndex = selectIndex;
}

void menu_select(int selectIndex) {
	/*if (selectIndex == lastPressed) {
			return;
	}*/
    LCD_DrawString(75*selectIndex + 25,200,  YELLOW, RED, menu[selectIndex], 16, 0);
    lastPressed = selectIndex;

    if(selectIndex == 1)
    {
    	Tunemode();
    }
    else if (selectIndex == 2)
    {
    	Manualmode();
    }
    else if (selectIndex == 0)
    {
    	Infomode();
    }
}
void Infomode()
{
	LCD_Clear(BLUE);
	for (int i = 0; i < 2; i++) {
		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Info[i], 16, 0);
	}
	LCD_DrawString(25 ,50,  YELLOW, BLUE,"Info will be displayed", 16, 0);
	Info_move(0);

	 while (1)
	  {
		if (goleft == 1) {
			if (currentSelectIndex == 0) {
				Info_move(1);

			} else {
				Info_move((currentSelectIndex - 1) % 3);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goleft = 0;
		} else if (updateToggleHistory(3)) {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			if(Info_select(currentSelectIndex) == 1)
			{
				return;
			}

		} else if (goright == 1) {

			if (currentSelectIndex == 1) {
						Info_move(0);
			} else {
				Info_move((currentSelectIndex + 1) % 3);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goright = 0;
		} else {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		}

		HAL_Delay(40);

	  }
}
void Info_move(int selectIndex)
{
	LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, Info[currentSelectIndex], 16, 0);
	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, Info[selectIndex], 16, 0);
	currentSelectIndex = selectIndex;
}
int Info_select(int selectIndex) {
	/*if (selectIndex == lastPressed) {
			return 0;
	}*/
    LCD_DrawString(75*selectIndex + 25,200,  YELLOW, RED, Info[selectIndex], 16, 0);
    lastPressed = selectIndex;
    if(currentSelectIndex == 0)
    {
    	LCD_Clear(BLUE);
    	for (int i = 0; i < 3; i++) {
    		/*bb_init_oled();
    		bb_display1("Home Display");
    		bb_display2("Info Tune Manual");*/
    		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, menu[i], 16, 0);
    	}
    	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, menu[selectIndex], 16, 0);
    	return 1;
    }

    return 0;
}
void Manualmode()
{
	LCD_Clear(BLUE);
	for (int i = 0; i < 3; i++) {
		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Manual[i], 16, 0);
	}
	LCD_DrawString(25 ,50,  YELLOW, BLUE,"Manually Control drill", 16, 0);
	LCD_DrawString(25 ,75,  YELLOW, BLUE,"Re-String Purpose", 16, 0);
	Manual_move(0, 0, 0);

	 while (1)
	  {
		if (goleft == 1) {
			if (currentSelectIndex == 0) {
				Manual_move(2);

			} else {
				Manual_move((currentSelectIndex - 1) % 3);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goleft = 0;
		} else if (updateToggleHistory(3)) {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			if(Manual_select(currentSelectIndex) == 1)
			{
				return;
			}

		} else if (goright == 1) {

			if (currentSelectIndex == 2) {
						Manual_move(0);
			} else {
				Manual_move((currentSelectIndex + 1) % 3);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goright = 0;
		} else {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		}

		HAL_Delay(40);

	  }
}
void Manual_move(int selectIndex)
{
	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, Manual[selectIndex], 16, 0);
	LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, Manual[currentSelectIndex], 16, 0);
	currentSelectIndex = selectIndex;
}
int Manual_select(int selectIndex) {
	/*if (selectIndex == lastPressed) {
			return 0;
	}*/
    LCD_DrawString(75*selectIndex + 25,200,  YELLOW, RED, Manual[selectIndex], 16, 0);
    lastPressed = selectIndex;
    if(currentSelectIndex == 0)
    {
    	LCD_Clear(BLUE);
    	for (int i = 0; i < 3; i++) {
    		/*bb_init_oled();
    		bb_display1("Home Display");
    		bb_display2("Info Tune Manual");*/
    		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, menu[i], 16, 0);
    	}
    	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, menu[selectIndex], 16, 0);
    	currentSelectIndex = 0;
    	return 1;
    }
    else if (currentSelectIndex == 1)
    {
    	stepperMotor(0, 15000, 1000, 1);
    }
    else if(currentSelectIndex == 2)
    {
    	stepperMotor(1, 15000, 1000, 1);
    }
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
    return 0;
}
void stepperMotor(int direction, int per, int step, int mode)
{
	//thefall = 0;
	if(direction == 0)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
	change_pwm(per);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
	if(mode == 1)
	{
	while(updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))
	{
		HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
		nano_wait(5000000);

	}
	/*for (int i = 0; i < 90; i++)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
		nano_wait(5000000);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
		nano_wait(5000000);
	}*/
	}
	else
		{
		uint32_t timemotor = per* step  / 10000 / 1.8 * 1.25;
		HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
		uint32_t startmotor = HAL_GetTick();
		//HAL_TIM_Base_Start(&htim2);
		uint32_t currmotor = HAL_GetTick();
		while((HAL_GetTick() - startmotor < timemotor) &( updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3))))
		{
		//nano_wait(per * step * 10 * 1.135);
		}
		}

	//nano_wait(5000000000);
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
}
void Tunemode() {
	/*bb_init_oled();
	bb_display1("Tune Mode");
	bb_display2("Select Peg");*/
	int scrollidx = 0;
	LCD_Clear(BLUE);
	for (int i = 0; i < 3; i++) {
		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[i], 16, 0);
	  }
	LCD_DrawString(95 ,25,  YELLOW, BLUE,"-----", 16, 0);
	LCD_DrawString(60 ,40,  YELLOW, BLUE,"3 - |    | - 4", 16, 0);
	LCD_DrawString(60 ,60,  YELLOW, BLUE,"2 - |    | - 5", 16, 0);
	LCD_DrawString(60 ,80,  YELLOW, BLUE,"1 - |    | - 6", 16, 0);
	LCD_DrawString(95 ,100,  YELLOW, BLUE,"-----", 16, 0);
	LCD_DrawString(100 ,115,  YELLOW, BLUE,"||||", 16, 0);
	LCD_DrawString(100 ,130,  YELLOW, BLUE,"||||", 16, 0);
	Tune_move(0, 0, 0);
	while (1)
	  {
		scrollidx = currentScrollIndex;

		if (goleft == 1) {
			if (currentSelectIndex == 0) {
				if(scrollidx == 0)
				{
					LCD_DrawString(75*0 + 25,200,  YELLOW, BLUE, Tune[6], 16, 0);
					for (int i = 1; i < 3; i++) {
							LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[i-1], 16, 0);
						  }
					Tune_move(6, 0, 0);
				}
				else if(scrollidx == 6)
				{
					for (int i = 0; i < 2; i++) {
						LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[5+i], 16, 0);
					}
					LCD_DrawString(75*2 + 25,200,  YELLOW, BLUE, Tune[0], 16, 0);
					Tune_move((currentScrollIndex - 1) % 7, 0, 0);
				}
				else
				{
					//LCD_DrawString(75*0 + 25,200,  YELLOW, BLUE, Tune[(currentScrollIndex - 1) % 7], 16, 0);
					for (int i = 0; i < 3; i++) {
					LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[(currentScrollIndex - 1) % 7+i], 16, 0);

				}
					Tune_move((currentScrollIndex - 1) % 7, 0, 0);
			}
			goleft = 0;

			} else {
				if(scrollidx == 0)
				{
					Tune_move(6, (currentSelectIndex - 1) % 3, 1);
				}
				else{
					Tune_move((currentScrollIndex - 1) % 7, (currentSelectIndex - 1) % 3, 1);
				}
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);

		} else if (updateToggleHistory(3)) {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			if(Tune_select(currentSelectIndex) == 1)
			{
				currentSelectIndex = 0;
				return;
			}


		} else if (goright == 1) {

			if (currentSelectIndex == 2) {
				if(currentScrollIndex == 6)
				{	int x = 0;
					for (int i = 5; i < 7; i++) {
						LCD_DrawString(75*x + 25,200,  YELLOW, BLUE, Tune[i], 16, 0);
						x++;
					}
					LCD_DrawString(75*2 + 25,200,  YELLOW, BLUE, Tune[0], 16, 0);
					Tune_move(0, 2, 0);
				}
				else
				{
					if(currentScrollIndex == 0)
						LCD_DrawString(75*0 + 25,200,  YELLOW, BLUE, Tune[6], 16, 0);
					else
						LCD_DrawString(75*0 + 25,200,  YELLOW, BLUE, Tune[currentScrollIndex - 1], 16, 0);
					for (int i = 1; i < 3; i++) {
						LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[(currentScrollIndex - 1) % 7+i], 16, 0);
					}
					Tune_move((currentScrollIndex + 1) % 7, 2, 0);
				}
			} else {
				if(scrollidx == 6)
				{
					Tune_move(0, (currentSelectIndex + 1) % 3, 1);
				}
				else
					Tune_move( (currentScrollIndex + 1) % 7,(currentSelectIndex + 1) % 3, 1);
			}
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goright = 0;
		} else {
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
		}

		HAL_Delay(40);


	  }
}
void Tune_move(int scrollidx, int selectIndex, int enable) {

	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, Tune[scrollidx], 16, 0);
	if(enable)
		LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, Tune[currentScrollIndex], 16, 0);

	currentSelectIndex = selectIndex;
	currentScrollIndex = scrollidx;
}

int Tune_select(int selectIndex) {
	/*if (selectIndex == lastPressed) {
			return 0;
	}*/
    LCD_DrawString(75*selectIndex + 25,200,  YELLOW, RED, Tune[currentScrollIndex], 16, 0);
    lastPressed = selectIndex;
    if(currentScrollIndex == 0)
    {
    	LCD_Clear(BLUE);
    	for (int i = 0; i < 3; i++) {
    		/*bb_init_oled();
    		bb_display1("Home Display");
    		bb_display2("Info Tune Manual");*/
    		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, menu[i], 16, 0);
    	}
    	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, menu[selectIndex], 16, 0);
    	currentSelectIndex = 0;
    	return 1;
    }
    else
    {
    	pegDisplay();
    	LCD_Clear(BLUE);
    	for (int i = 0; i < 3; i++) {
    	    LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, Tune[i], 16, 0);
    	 }

    	currentSelectIndex = 0;
    	currentScrollIndex = 0;
    	LCD_DrawString(95 ,25,  YELLOW, BLUE,"-----", 16, 0);
    	LCD_DrawString(60 ,40,  YELLOW, BLUE,"3 - |    | - 4", 16, 0);
    	LCD_DrawString(60 ,60,  YELLOW, BLUE,"2 - |    | - 5", 16, 0);
    	LCD_DrawString(60 ,80,  YELLOW, BLUE,"1 - |    | - 6", 16, 0);
    	LCD_DrawString(95 ,100,  YELLOW, BLUE,"-----", 16, 0);
    	LCD_DrawString(100 ,115,  YELLOW, BLUE,"||||", 16, 0);
    	LCD_DrawString(100 ,130,  YELLOW, BLUE,"||||", 16, 0);
    	Tune_move(0, 0, 0);
    	return 0;
    }
    return 0;
}
int pegDisplay()
{
	LCD_Clear(BLUE);
	for (int i = 0; i < 3; i++) {
		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, peg[i], 16, 0);
	}
	LCD_DrawString(60 ,40,  YELLOW, BLUE,pegsel[currentScrollIndex-1], 16, 0);
	LCD_DrawString(60 ,60,  YELLOW, BLUE,"Play Note", 16, 0);
	LCD_DrawString(140 ,60,  YELLOW, BLUE, note[currentScrollIndex-1], 16, 0);
	peg_move(0);
	//LCD_DrawString(25,200,  YELLOW, BLUE, "Back", 16, 0);
	//stepperMotor(1, 15000, 90, 0);
	while(1)
	{

		if (goleft == 1) {
				if (currentSelectIndex == 0) {
					peg_move(2);

				} else {
					peg_move((currentSelectIndex - 1) % 3);
				}
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goleft = 0;

			} else if (updateToggleHistory(3)) {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
				if(peg_select(currentSelectIndex) == 1)
				{
					return;
				}

			} else if (goright == 1) {

				if (currentSelectIndex == 2) {
							peg_move(0);
				} else {
					peg_move((currentSelectIndex + 1) % 3);
				}
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
			goright =0;

			} else {
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
			}
	}
}
void peg_move(int selectIndex)
{
	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, peg[selectIndex], 16, 0);
	LCD_DrawString(75*currentSelectIndex + 25,200,  YELLOW, BLUE, peg[currentSelectIndex], 16, 0);
	currentSelectIndex = selectIndex;
}
int peg_select(int selectIndex) {
	/*if (selectIndex == lastPressed) {
			return 0;
	}*/
    LCD_DrawString(75*selectIndex + 25,200,  YELLOW, RED, peg[selectIndex], 16, 0);
    lastPressed = selectIndex;
    if(currentSelectIndex == 0)
    {
    	LCD_Clear(BLUE);
    	for (int i = 0; i < 3; i++) {
    		/*bb_init_oled();
    		bb_display1("Home Display");
    		bb_display2("Info Tune Manual");*/
    		LCD_DrawString(75*i + 25,200,  YELLOW, BLUE, peg[i], 16, 0);
    	}
    	LCD_DrawString(75*selectIndex + 25,200,  YELLOW, BLACK, peg[selectIndex], 16, 0);
    	currentSelectIndex = 0;
    	return 1;
    }
    else if (currentSelectIndex == 1)
    {
    	stepperMotor(0, 15000,45 , 0);
    	HAL_Delay(500);

    		for(int j = 0; j < 10; j++)
    		{
    	if(updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))
    		{stepperMotor(0, 15000,10 , 0);
    		HAL_Delay(500);}
    		}
    		for(int j = 0; j < 10; j++)
    		 {
    		if(updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))
    			{stepperMotor(0, 15000,45 , 0);
    			HAL_Delay(500);}

    		 }
    		for(int j = 0; j < 10; j++)
    		  {
    		   if(updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))
    			   {stepperMotor(0, 15000,90 , 0);
    			   HAL_Delay(500);}
    		  }
    		for(int j = 0; j < 10; j++)
    		    		  {
    		    		   if (updateToggleHistory(3) || HAL_GPIO_ReadPin(GPIOB, 1 << (3)))
    		    			   {stepperMotor(0, 15000,180 , 0);
    		    			   HAL_Delay(500);}
    		    		  }
    }
    else if(currentSelectIndex == 2)
    {
    	stepperMotor(1, 15000, 90, 0);
    }
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
    HAL_Delay(100);
    return 0;
}
uint8_t updateToggleHistory(uint8_t button) {
	uint8_t prev = pressHistory[button - 2];
	uint8_t new = HAL_GPIO_ReadPin(GPIOB, 1 << (button));
	pressHistory[button - 2] = new;
	if (lastButton == button && (prev == 1 || new == 1)) return 0;
	else if (prev == 1 && new == 1) {
		lastButton = button;
	} else if (prev == 0 && new == 0){
		lastButton = -1;
	}

	return prev && new;


  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC_Init(void)
{

  /* USER CODE BEGIN ADC_Init 0 */

  /* USER CODE END ADC_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC_Init 1 */

  /* USER CODE END ADC_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = DISABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_8;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC_Init 2 */

  /* USER CODE END ADC_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0x2000090E;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_4BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_HARD_OUTPUT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

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

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */



  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3
                           PC4 PC5 PC8 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA3 PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB2 PB3 PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_2/*|GPIO_PIN_3*/|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB2 PB3 PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PC6 PC7 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);

  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	curr = HAL_GetTick();
	UNUSED(GPIO_Pin);
	if((GPIO_Pin == 4) && (curr - prev > 200))
		{goleft = 1;
		 prev = curr;
		}
	if((GPIO_Pin == 16) && (curr - prev > 200))
		{goright = 1;
		prev = curr;
		}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state*/
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

