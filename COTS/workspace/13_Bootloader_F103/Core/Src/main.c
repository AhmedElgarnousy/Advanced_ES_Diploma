/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

#include<string.h>

#include<bootloader.h>

/* USER CODE END Includes */



/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CRC_HandleTypeDef hcrc;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CRC_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

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
	char HelloBootloader [] = "Hello Bootloader in F103\r\n";

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
  MX_CRC_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  if( HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11) == GPIO_PIN_RESET)
  {
 	 Bootloader_UartReadData();
  }
  else
  {
 	 Bootloader_JumpToUserApp();
  }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
		HAL_UART_Transmit(&huart1, (uint8_t*)HelloBootloader, sizeof(HelloBootloader), HAL_MAX_DELAY);

		HAL_Delay(1000);

    /* USER CODE BEGIN 3 */
  }
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin : PA11 */
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void Bootloader_UartReadData(){
	/*This function used to read commands from host */

	uint8_t Local_u8CommandPacket[255] = {0};

	while(1)
	{
		/*clear the command packet every iteration */
		memset(Local_u8CommandPacket,0,255); /*INSTEAD of for loop to clear the array */

		/*1st step: read the 1st byte which includes the "Length to follow" field of the command */
		HAL_UART_Receive(&huart1, Local_u8CommandPacket, 1, HAL_MAX_DELAY);

		/*2nd step: read the rest of the command, it's size is the previously byte value */
		HAL_UART_Receive(&huart1, &Local_u8CommandPacket[1], Local_u8CommandPacket[0], HAL_MAX_DELAY);

		/*3rd step: check the command code, then handle the command */
		switch(Local_u8CommandPacket[1]) // second item the command code in all commands frame
		{
			case BL_GET_VER: 				BL_voidHandleGetVerCmd(Local_u8CommandPacket);				break;
			case BL_GET_HELP: 				BL_voidHandleGetHelpCmd(Local_u8CommandPacket);				break;
			case BL_GET_CID: 				BL_voidHandleGetCIDCmd(Local_u8CommandPacket);				break;
			case BL_GET_RDP_STATUS: 		BL_voidHandleGetRDPStatusCmd(Local_u8CommandPacket);		break;
			case BL_GO_TO_ADDR: 			BL_voidHandleGoToAddrCmd(Local_u8CommandPacket);			break;
			case BL_FLASH_ERASE: 			BL_voidHandleFlashEraseCmd(Local_u8CommandPacket);			break;
			case BL_MEM_WRITE: 				BL_voidHandleMemWriteCmd(Local_u8CommandPacket);			break;
			case BL_EN_RW_PROTECT: 			BL_voidHandleEnRWProtectCmd(Local_u8CommandPacket);			break;
			case BL_MEM_READ: 				BL_voidHandleMemReadCmd(Local_u8CommandPacket);				break;
			case BL_READ_SECTOR_STATUS: 	BL_voidHandleReadSectorStatusCmd(Local_u8CommandPacket);	break;
			case BL_OTP_READ: 				BL_voidHandleOTPReadCmd(Local_u8CommandPacket);				break;
			case BL_DIS_RW_PROTECT: 		BL_voidHandleDisRWProtectCmd(Local_u8CommandPacket);	 	break;
			default: 						/* INVALID CMD FROM HOST */ break;
		}
	}
}

void Bootloader_JumpToUserApp(){
	 /* To jump to user app, go to reset handler of user app */

	  /* Pointer to function to hold address of the reset handler of the user app */
	  void (*App_ResetHandler)(void);

	  uint32_t ResetHandlerAddress;
	  uint32_t Local_u32MSPVal;

	  /* the reset handler of user app is 2nd location at vectortable of user app at sector2 in flash (0x08008000) */

	  ResetHandlerAddress = *((volatile uint32_t*)(FLASH_SECTOR2_BASE_ADDRESS + 4));

	  App_ResetHandler = (void*)ResetHandlerAddress;

	  /* before calling we should initailize MSP for user app by software
	  , Configure MSP of user app by reading value from base address of sector2 , 1st location in VT of user app */
	  Local_u32MSPVal = *(volatile uint32_t*)(FLASH_SECTOR2_BASE_ADDRESS);

	  /*Write the user MSP value into MSP register */
	  asm volatile ("MSR MSP, %0"::"r"(Local_u32MSPVal));

	  /* now jump to the user app reset handler, now PC update with reset handler of user app and continue in execution */
	  App_ResetHandler();
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
