#include "main.h"
#include "led.h"

void led_init()
{
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1);
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 0);
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1);
	HAL_Delay(500);
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 0);
}