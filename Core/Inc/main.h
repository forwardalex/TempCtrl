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
#include "stm32g4xx_hal.h"

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
#define NTC_IN2_Pin GPIO_PIN_0
#define NTC_IN2_GPIO_Port GPIOC
#define NTC_IN1_Pin GPIO_PIN_1
#define NTC_IN1_GPIO_Port GPIOC
#define NTC_IN3_Pin GPIO_PIN_3
#define NTC_IN3_GPIO_Port GPIOC
#define NTC_IN4_Pin GPIO_PIN_0
#define NTC_IN4_GPIO_Port GPIOA
#define BTN_AD1_Pin GPIO_PIN_1
#define BTN_AD1_GPIO_Port GPIOA
#define NTC_IN5_Pin GPIO_PIN_2
#define NTC_IN5_GPIO_Port GPIOA
#define BTN_AD4_Pin GPIO_PIN_3
#define BTN_AD4_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_4
#define LED1_GPIO_Port GPIOA
#define LCD_DC_Pin GPIO_PIN_6
#define LCD_DC_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_4
#define LCD_CS_GPIO_Port GPIOC
#define SWITCH1_Pin GPIO_PIN_11
#define SWITCH1_GPIO_Port GPIOB
#define NTN_AD2_Pin GPIO_PIN_12
#define NTN_AD2_GPIO_Port GPIOB
#define SWITCH2_Pin GPIO_PIN_13
#define SWITCH2_GPIO_Port GPIOB
#define BTN_AD3_Pin GPIO_PIN_14
#define BTN_AD3_GPIO_Port GPIOB
#define SWITCH3_Pin GPIO_PIN_15
#define SWITCH3_GPIO_Port GPIOB
#define SWITCH4_Pin GPIO_PIN_6
#define SWITCH4_GPIO_Port GPIOC
#define LCD_BLK_Pin GPIO_PIN_8
#define LCD_BLK_GPIO_Port GPIOA
#define LCD_RST_Pin GPIO_PIN_11
#define LCD_RST_GPIO_Port GPIOC
#define LED5_Pin GPIO_PIN_3
#define LED5_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_5
#define LED4_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_7
#define LED3_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_9
#define LED2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
