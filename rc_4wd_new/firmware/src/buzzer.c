#include "buzzer.h"


void buzzer_init()
{
	HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_1);
	TIM15->CCR1 = BUZZ_INIT_PWM;
	HAL_Delay(1000);
	TIM15->CCR1 = 0;
}

void buzzer_routine(uint8_t btns_positions[])
{
	if (btns_positions[0])
	{
		TIM15->CCR1 = BUZZ_ROUTINE_PWM;
	}
}
