#include "motor.h"

void motors_init()
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
	
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

void motor_set_direction_and_duty(uint8_t motor, uint8_t dir, uint16_t duty)
{
	switch (motor)
	{
		case 0: (dir) ? (TIM2->CCR1 = duty) : (TIM2->CCR2 = duty); break; //back left motor
		case 1: (dir) ? (TIM2->CCR3 = duty) : (TIM2->CCR4 = duty); break; //back right motor
		case 2: (dir) ? (TIM3->CCR1 = duty) : (TIM3->CCR2 = duty); break; //front right motor
		case 3: (dir) ? (TIM3->CCR3 = duty) : (TIM3->CCR4 = duty); break; //front left motor
		
		case 4: TIM1->CCR1 = duty;break;
		default: break;
	}
}

//void motors_control(uint16_t joys_positions[])
//{
//	
//}