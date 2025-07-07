/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DDG_MAGIC_1_Pin GPIO_PIN_3
#define DDG_MAGIC_1_GPIO_Port GPIOC
#define DDG_MAGIC_2_Pin GPIO_PIN_0
#define DDG_MAGIC_2_GPIO_Port GPIOA
#define DDG_MAGIC_3_Pin GPIO_PIN_1
#define DDG_MAGIC_3_GPIO_Port GPIOA
#define DDG_MAGIC_4_Pin GPIO_PIN_2
#define DDG_MAGIC_4_GPIO_Port GPIOA
#define DDG_MAGIC_5_Pin GPIO_PIN_3
#define DDG_MAGIC_5_GPIO_Port GPIOA
#define STATUS_LED_Pin GPIO_PIN_7
#define STATUS_LED_GPIO_Port GPIOA
#define BAT_MEASURE_Pin GPIO_PIN_4
#define BAT_MEASURE_GPIO_Port GPIOC
#define NRF_CS_Pin GPIO_PIN_12
#define NRF_CS_GPIO_Port GPIOE
#define NRF_CE_Pin GPIO_PIN_13
#define NRF_CE_GPIO_Port GPIOE
#define SD_CS_Pin GPIO_PIN_12
#define SD_CS_GPIO_Port GPIOB
#define DCMI_PWDN_Pin GPIO_PIN_6
#define DCMI_PWDN_GPIO_Port GPIOD
#define DCMI_RST_Pin GPIO_PIN_7
#define DCMI_RST_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
