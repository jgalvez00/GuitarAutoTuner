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
#include "lcd.h"
#include "menu.h"
#include "dsp_v2.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//#define ADC_BUF_LEN 2048
#define I2C_BUF_LEN 4
#define BATTERY_CAPACITY 5200.0
#define BATTERY_PRESCALE 1
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;
DMA_HandleTypeDef hdma_adc;

I2C_HandleTypeDef hi2c1;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim1;

/* USER CODE BEGIN PV */
//uint16_t adc_buf[BUF_LEN] = {0};
uint8_t batbuf[I2C_BUF_LEN];
//uint16_t temp[ADC_BUF_LEN*8];
int tmp;
uint8_t gotNote;
static const uint8_t I2C_BATTERY_MONITOR_ADDR = 0x64 << 1;

void battery_setPresacle(uint8_t scale);

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM1_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */
void Sample(ADC_HandleTypeDef*, uint32_t*, uint32_t);
void acquireTune();
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
  MX_DMA_Init();
  MX_ADC_Init();
  MX_SPI1_Init();
  MX_TIM1_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
  initialize();
  LCD_Init();
  LCD_Clear(BLUE);
  resetSel();
  menu_home();
  /*auto_tune();
  HAL_Delay(1000);
  dspmain();*/
  while(1)
  {
  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14
                              |RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
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
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
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
  hadc.Init.ContinuousConvMode = ENABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = ENABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel to be converted.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC_Init 2 */

  /* USER CODE END ADC_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x2000090E;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

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
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
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
  htim1.Init.Period = 7500*6;
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
  sConfigOC.Pulse = 7500/2*6;
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
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Ch1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Ch1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Ch1_IRQn);

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB11 PB12 PB13 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PC6 PC7 PC8 PC10 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA10 PA11 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB4 PB5 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

}

/* USER CODE BEGIN 4 */
//===========================================================================
// EXTERNAL INTERRUPT CALLBACK
// Used for navigation buttons and trigger
//===========================================================================
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	curr = HAL_GetTick();
	UNUSED(GPIO_Pin);
	if((GPIO_Pin == (1<<4)) && (curr - prev > 200)) //Left button
	{
		move_left();//move left
		prev = curr;
	}
	if(((GPIO_Pin == (1<<5)) | (GPIO_Pin == (1<<7))) && (curr - prev > 200)) //select button
		{
			display_select(currentSelectIndex); //select option
			prev = curr;
		}
	if((GPIO_Pin == (1<<6)) && (curr - prev > 200)) // right button
	{
		move_right();//move right
		prev = curr;
	}
}
// Called when first half of buffer is filled
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc) {
  __NOP();
}

// Called when buffer is completely filled
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
//	gotNote = 1;
//	HAL_ADC_Stop_DMA(hadc);
	//LCD_Drawnum(3, 0, 0, , num2)

	HAL_ADC_Stop_DMA(hadc);

//	for(int i = 0; i < ADC_BUF_LEN; i++){
//			adc_buf[i] = buffer.raw[i*8];
//	}

	LCD_DrawString(60 ,80,  YELLOW, BLUE,"Finished samples", 16, 0);
	//dspmain();
	dspmain2();
	//LCD_DrawString(60 ,160,  YELLOW, BLUE,"Finished DSP", 16, 0);

}
void battery() {

	battery_setPresacle(5);


	LCD_DrawString(60,100,YELLOW, BLUE, "I2C:", 16, 0);
	//HAL_I2C_Master_Transmit(&hi2c1, I2C_BATTERY_MONITOR_ADDR, pData, Size, Timeout);
	HAL_StatusTypeDef ret;
	batbuf[0] = 0;
	ret = HAL_I2C_Master_Transmit(&hi2c1, I2C_BATTERY_MONITOR_ADDR, batbuf, 1, HAL_MAX_DELAY);
	if ( ret != HAL_OK ) {
		LCD_DrawString(140,100,YELLOW, BLUE, "ERROR", 16, 0);
	} else {
		LCD_DrawString(140,100,YELLOW, BLUE, "ACK", 16, 0);
		LCD_DrawString(60,120,YELLOW, BLUE, "Status", 16, 0);

		ret = HAL_I2C_Master_Receive(&hi2c1, I2C_BATTERY_MONITOR_ADDR, batbuf, 1, HAL_MAX_DELAY);
		if ( ret != HAL_OK ) {
			LCD_DrawString(140,120,YELLOW, BLUE, "ERROR", 16, 0);
		} else {
			char text[20];
			sprintf(text, "0x%x", batbuf[0]);

			LCD_DrawString(140,120,YELLOW, BLUE, text, 16, 0);
		}
	}

	batbuf[0] = 2;
	LCD_DrawString(60,140,YELLOW, BLUE, "Chrg Reg:", 16, 0);
	ret = HAL_I2C_Master_Transmit(&hi2c1, I2C_BATTERY_MONITOR_ADDR, batbuf, 1, HAL_MAX_DELAY);
	if ( ret != HAL_OK ) {
		LCD_DrawString(140,140,YELLOW, BLUE, "ERROR", 16, 0);
	} else {
		LCD_DrawString(140,140,YELLOW, BLUE, "ACK", 16, 0);

		LCD_DrawString(60,160,YELLOW, BLUE, "Amount:", 16, 0);
		ret = HAL_I2C_Master_Receive(&hi2c1, I2C_BATTERY_MONITOR_ADDR, batbuf, 4, HAL_MAX_DELAY);
		if ( ret != HAL_OK ) {
			LCD_DrawString(140,160,YELLOW, BLUE, "ERROR", 16, 0);
		} else {
			char text[40];
			sprintf(text, "0x%02x%02x %02x%02x", batbuf[0],batbuf[1],batbuf[2],batbuf[3]);

			LCD_DrawString(140,160,YELLOW, BLUE, text, 16, 0);

			float chargeAmount = 0.085 * (batbuf[3] + batbuf[2] * 256);
			sprintf(text, "Capacity: %d mAh   %d %%", (uint32_t)chargeAmount, (uint32_t) (chargeAmount/5200.0*100));

			LCD_DrawString(25 ,50,  YELLOW, BLUE, text, 16, 0);


		}
	}


	//HAL_I2C_Master_Receive_IT(&hi2c1, 100, batbuf, I2C_BUF_LEN);
	//HAL_I2C_Master_Receive(&hi2c1, DevAddress, pData, Size, Timeout), DevAddress, pData, Size, Timeout)

	//nano_wait(100000);
}

void battery_display()
{
	HAL_StatusTypeDef ret;
	batbuf[0] = 2;
	ret = HAL_I2C_Master_Transmit(&hi2c1, I2C_BATTERY_MONITOR_ADDR, batbuf, 1, HAL_MAX_DELAY);
	if ( ret != HAL_OK ) {
//		LCD_DrawString(140,140,YELLOW, BLUE, "ERROR", 16, 0);
	} else {
		ret = HAL_I2C_Master_Receive(&hi2c1, I2C_BATTERY_MONITOR_ADDR, batbuf, 4, HAL_MAX_DELAY);
		if ( ret != HAL_OK ) {
//			LCD_DrawString(140,160,YELLOW, BLUE, "ERROR", 16, 0);
		} else {
			char text[40];
			float chargeAmount = 0.085 * BATTERY_PRESCALE * (batbuf[3] + batbuf[2] * 256);
			sprintf(text, "Capacity: %d mAh   %d %%", (uint32_t)chargeAmount, (uint32_t) (chargeAmount/BATTERY_CAPACITY*100));

			LCD_DrawString(25 ,5,  YELLOW, BLUE, text, 16, 0);


		}
	}


}


void battery_setPresacle(uint8_t scale)
{
	HAL_StatusTypeDef ret;
	batbuf[0] = 0x01;
	batbuf[1] = 0x30;
	ret = HAL_I2C_Master_Transmit(&hi2c1, I2C_BATTERY_MONITOR_ADDR, batbuf, 2, HAL_MAX_DELAY);
	if ( ret != HAL_OK ) {
		LCD_DrawString(140,40,YELLOW, BLUE, "ERROR", 16, 0);
	} else {
		//LCD_DrawString(140,100,YELLOW, BLUE, "ACK", 16, 0);
		//LCD_DrawString(60,120,YELLOW, BLUE, "Status", 16, 0);
		batbuf[0] = 0x30;

		//ret = HAL_I2C_Master_Transmit(&hi2c1, I2C_BATTERY_MONITOR_ADDR, batbuf, 1, HAL_MAX_DELAY);
		if ( ret != HAL_OK ) {
				LCD_DrawString(140,40,YELLOW, BLUE, "ERROR", 16, 0);
		} //else {LCD_DrawString(140,40,YELLOW, BLUE, "DONE", 16, 0);}
	}

	return;
}
/*void HAL_I2C_MasterRxCpltCallback (I2C_HandleTypeDef * hi2c)
{
	//for(int i = 0; i < 4; i++)
		//LCD_Draw4digit(i, 0, i, batbuf);
	char fma[15];
	gcvt(*batbuf, 6, fma);
	LCD_DrawString(60,120,YELLOW, BLUE, "BATTERY", 16, 0);
	LCD_DrawString(60,140,YELLOW, BLUE, fma, 16, 0);
}*/
void LCD_Draw4digit(int idx, int side, int row, uint16_t *buff)
{
	tmp =0;
	int renew = 0;
	int fact = 1;
	LCD_DrawString(60 ,80,  YELLOW, BLUE,"Finished samples", 16, 0);
	for(int i = 0; i < 4; i++)
	{
		fact = 1;
		for(int j = i ; j < 3; j++)
		  {
			  fact = fact * 10;
		  }
		tmp = (buff[idx]- renew)/fact ;

		LCD_DrawChar(60 +i*10 + side * 100,100 + row*20,YELLOW, BLUE,tmp+48, 16, 0);
		renew +=  tmp * fact;
	  }

}

void LCD_Drawpin(uint8_t pin)
{
	tmp =0;
	int renew = 0;
	int fact = 1;
	LCD_DrawString(60 ,80,  YELLOW, BLUE,"Finished samples", 16, 0);
	for(int i = 0; i < 4; i++)
	{
		fact = 1;
		for(int j = i ; j < 3; j++)
		  {
			  fact = fact * 10;
		  }
		tmp = (pin- renew)/fact ;

		LCD_DrawChar(60 +i*10 + 100,100 + 20,YELLOW, BLUE,tmp+48, 16, 0);
		renew +=  tmp * fact;
	  }

}
void auto_tune()
{
	LCD_Clear(BLUE);
	for (int i = 0; i < 2; i++) {
		LCD_DrawString(65*i + 25,SELECT_HEIGHT,  YELLOW, BLUE, (currDisplay->selection)[i], 16, 0);
	}
	LCD_DrawString(60 ,40,  YELLOW, BLUE,pegsel[currentPeg], 16, 0);
	LCD_DrawString(60 ,60,  YELLOW, BLUE,"Play open", 16, 0);
	LCD_DrawString(140 ,60,  YELLOW, BLUE, note[currentPeg], 16, 0);
	LCD_DrawString(65*2 + 25,SELECT_HEIGHT,  YELLOW, BLUE, (currDisplay->selection)[2], 16, 0);
	LCD_DrawString(80 ,80,  YELLOW, BLUE,"Take samples", 16, 0);
	acquireTune();



	//dspmain();
	//dspmain2();

	//dspmain();
}

void acquireTune()
{
	//gotNote = 0;
	//uint16_t temp[ADC_BUF_LEN*8]= {0};
	HAL_ADC_Start_DMA(&hadc, buffer.raw, SAMPLE_LEN);
//	while(gotNote == 0) nano_wait(100);
//
//	for(int i = 0; i < ADC_BUF_LEN; i++){
//		adc_buf[i] = temp[i*8];
//	}
//
//	LCD_DrawString(60 ,80,  YELLOW, BLUE,"Finished samples", 16, 0);


}

void startmotor()
{
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}
void stopmotor()
{
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
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

