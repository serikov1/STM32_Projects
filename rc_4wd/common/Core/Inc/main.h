/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#define LED_Pin GPIO_PIN_3
#define LED_GPIO_Port GPIOC
#define PWM2_BL_Pin GPIO_PIN_0
#define PWM2_BL_GPIO_Port GPIOA
#define PWM0_BL_Pin GPIO_PIN_1
#define PWM0_BL_GPIO_Port GPIOA
#define PWM3_BL_Pin GPIO_PIN_10
#define PWM3_BL_GPIO_Port GPIOB
#define PWM1_BL_Pin GPIO_PIN_11
#define PWM1_BL_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_14
#define BUZZER_GPIO_Port GPIOB
#define PWM_SERVO_Pin GPIO_PIN_15
#define PWM_SERVO_GPIO_Port GPIOB
#define PWM0_BR_Pin GPIO_PIN_6
#define PWM0_BR_GPIO_Port GPIOC
#define PWM1_BR_Pin GPIO_PIN_7
#define PWM1_BR_GPIO_Port GPIOC
#define PWM2_BR_Pin GPIO_PIN_8
#define PWM2_BR_GPIO_Port GPIOC
#define PWM3_BR_Pin GPIO_PIN_9
#define PWM3_BR_GPIO_Port GPIOC
#define PWM1_FR_Pin GPIO_PIN_8
#define PWM1_FR_GPIO_Port GPIOA
#define PWM2_FR_Pin GPIO_PIN_9
#define PWM2_FR_GPIO_Port GPIOA
#define PWM3_FR_Pin GPIO_PIN_10
#define PWM3_FR_GPIO_Port GPIOA
#define PWM0_FR_Pin GPIO_PIN_11
#define PWM0_FR_GPIO_Port GPIOA
#define PWM1_FL_Pin GPIO_PIN_6
#define PWM1_FL_GPIO_Port GPIOB
#define PWM3_FL_Pin GPIO_PIN_7
#define PWM3_FL_GPIO_Port GPIOB
#define PWM2_FL_Pin GPIO_PIN_8
#define PWM2_FL_GPIO_Port GPIOB
#define PWM0_FL_Pin GPIO_PIN_9
#define PWM0_FL_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
