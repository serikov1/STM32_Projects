#include "buzzer.h"


void buzzer_init()
{
	HAL_GPIO_TogglePin(BUZZER_GPIO_Port, BUZZER_Pin);
	HAL_Delay(50);
	HAL_GPIO_TogglePin(BUZZER_GPIO_Port, BUZZER_Pin);
	HAL_Delay(50);
	HAL_GPIO_TogglePin(BUZZER_GPIO_Port, BUZZER_Pin);
	HAL_Delay(50);
	HAL_GPIO_TogglePin(BUZZER_GPIO_Port, BUZZER_Pin);
	HAL_Delay(50);
	HAL_GPIO_TogglePin(BUZZER_GPIO_Port, BUZZER_Pin);
}
