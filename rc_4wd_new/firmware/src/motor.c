#include "motor.h"

void motors_init()
{
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1); //PWM1_FR
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2); //PWM2_FR
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3); //PWM3_FR
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4); //PWM0_FR
	
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //PWM2_BL
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //PWM0_BL
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //PWM3_BL
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); //PWM1_BL
	
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1); //PWM0_BR
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); //PWM1_BR
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3); //PWM2_BR
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4); //PWM3_BR
	
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1); //PWM1_FL
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2); //PWM3_FL
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3); //PWM2_FL
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4); //PWM0_FL
	
	HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_1); //BUZZER
	HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_2); //PWM_SERVO
}


// 2 high, 0 PWM - rotation
// 1 high, 3 PWM - reverse
// 0 high, 3 high - brake

void motor_set_direction_and_duty(uint8_t motor, uint8_t dir, uint16_t duty)
{
	switch (motor)
	{
		case B_LEFT: (dir) ? (TIM2->CCR2 = duty) && (TIM2->CCR1 = htim2.Init.Period) : (TIM2->CCR3 = duty) && (TIM2->CCR4 = htim2.Init.Period); break;   //back left motor (1)
		case B_RIGHT: (dir) ? (TIM3->CCR1 = duty) && (TIM3->CCR3 = htim3.Init.Period) : (TIM3->CCR4 = duty) && (TIM3->CCR2 = htim3.Init.Period); break;  //back right motor (2)
		case F_LEFT: (dir) ? (TIM4->CCR4 = duty) && (TIM4->CCR3 = htim4.Init.Period) : (TIM4->CCR2 = duty) && (TIM4->CCR1 = htim4.Init.Period); break;   //front left motor (3)
		case F_RIGHT: (dir) ? (TIM1->CCR4 = duty) && (TIM1->CCR2 = htim1.Init.Period) : (TIM1->CCR3 = duty) && (TIM1->CCR1 = htim1.Init.Period); break;  //front right motor (4)
		
		case SERVO: TIM15->CCR2 = duty;break; //servo (5)
		default: break;
	}
}

int abs(int value)
{
	return value > 0 ? value : -value;
}

void routine(uint16_t joys_positions[])
{
	double motors_pwm_prescaler = htim2.Init.Period / 100;                                        //normalization the infill of motors pwm 
	uint16_t adc_prescaler = 4096 / 100;                                                          //normalization for the adc value from joystick
	
	int16_t motors_result_value = joys_positions[0] / adc_prescaler * motors_pwm_prescaler - 50;
	int16_t servo_result_value = joys_positions[3] / adc_prescaler * motors_pwm_prescaler;
	
	motor_set_direction_and_duty(0, motors_result_value > 0, abs(motors_result_value));
	motor_set_direction_and_duty(1, motors_result_value > 0, abs(motors_result_value));
	motor_set_direction_and_duty(2, servo_result_value);
	
}