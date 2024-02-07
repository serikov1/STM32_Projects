#include "motor.h"

void motors_init()
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

void motor_set_direction_and_duty(uint8_t motor, uint8_t dir, uint16_t duty)
{
	switch (motor)
	{
		case LEFT: (dir) ? (TIM2->CCR1 = duty) : (TIM2->CCR2 = duty); break;   //back left motor (0)
		case RIGHT: (dir) ? (TIM2->CCR3 = duty) : (TIM2->CCR4 = duty); break;  //back right motor (1)
		case SERVO: TIM1->CCR1 = duty;break;                                   //servo (2)
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