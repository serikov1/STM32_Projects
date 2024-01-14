/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define X_LEFT_Pin GPIO_PIN_0
#define X_LEFT_GPIO_Port GPIOA
#define Y_LEFT_Pin GPIO_PIN_1
#define Y_LEFT_GPIO_Port GPIOA
#define X_RIGHT_Pin GPIO_PIN_2
#define X_RIGHT_GPIO_Port GPIOA
#define Y_RIGHT_Pin GPIO_PIN_3
#define Y_RIGHT_GPIO_Port GPIOA
#define JOYBTN_RIGHT_Pin GPIO_PIN_4
#define JOYBTN_RIGHT_GPIO_Port GPIOA
#define JOYBTN_RIGHT_EXTI_IRQn EXTI4_IRQn
#define JOYBTN_LEFT_Pin GPIO_PIN_5
#define JOYBTN_LEFT_GPIO_Port GPIOA
#define JOYBTN_LEFT_EXTI_IRQn EXTI9_5_IRQn
#define BUZZER_Pin GPIO_PIN_12
#define BUZZER_GPIO_Port GPIOB
#define LED_LEFT_Pin GPIO_PIN_13
#define LED_LEFT_GPIO_Port GPIOB
#define LED_RIGHT_Pin GPIO_PIN_14
#define LED_RIGHT_GPIO_Port GPIOB
#define BTN_RIGHT_Pin GPIO_PIN_15
#define BTN_RIGHT_GPIO_Port GPIOB
#define BTN_RIGHT_EXTI_IRQn EXTI15_10_IRQn
#define BTN_LEFT_Pin GPIO_PIN_8
#define BTN_LEFT_GPIO_Port GPIOA
#define BTN_LEFT_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */
#define AMOUNT_BYTES_TO_TRANSMIT 24
#define ADC_CHANNELS_NUM 4

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
