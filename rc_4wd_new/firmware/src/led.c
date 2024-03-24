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

void led_routine(uint8_t btns_positions[])
{
	if (btns_positions[2])
	{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1);
	}
	else
	{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 0);
	}
}