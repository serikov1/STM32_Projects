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
#define PWM0_BL_Pin GPIO_PIN_0
#define PWM0_BL_GPIO_Port GPIOA
#define PWM1_BL_Pin GPIO_PIN_1
#define PWM1_BL_GPIO_Port GPIOA
#define PWM1_BR_Pin GPIO_PIN_2
#define PWM1_BR_GPIO_Port GPIOA
#define PWM0_BR_Pin GPIO_PIN_3
#define PWM0_BR_GPIO_Port GPIOA
#define FAULT_F_Pin GPIO_PIN_4
#define FAULT_F_GPIO_Port GPIOA
#define FAULT_B_Pin GPIO_PIN_5
#define FAULT_B_GPIO_Port GPIOA
#define PWM0_FR_Pin GPIO_PIN_6
#define PWM0_FR_GPIO_Port GPIOA
#define PWM1_FR_Pin GPIO_PIN_7
#define PWM1_FR_GPIO_Port GPIOA
#define PWM1_FL_Pin GPIO_PIN_0
#define PWM1_FL_GPIO_Port GPIOB
#define PWM0_FL_Pin GPIO_PIN_1
#define PWM0_FL_GPIO_Port GPIOB
#define OTW_F_Pin GPIO_PIN_10
#define OTW_F_GPIO_Port GPIOB
#define OTW_B_Pin GPIO_PIN_11
#define OTW_B_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_12
#define BUZZER_GPIO_Port GPIOB
#define LED_F_Pin GPIO_PIN_13
#define LED_F_GPIO_Port GPIOB
#define RESET_F_Pin GPIO_PIN_14
#define RESET_F_GPIO_Port GPIOB
#define RESET_B_Pin GPIO_PIN_15
#define RESET_B_GPIO_Port GPIOB
#define PWM_SERVO_Pin GPIO_PIN_8
#define PWM_SERVO_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
#define AMOUNT_BYTES_TO_RECEIVE 24
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
