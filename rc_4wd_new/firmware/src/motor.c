#include "motor.h"


int16_t ABS(int16_t value)
{
	return value > 0 ? value : -value;
}

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
	
	HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_2);//PWM_SERVO
	TIM15->CCR2 = ((MAX_SERVO - MIN_SERVO) / 2 + MIN_SERVO);
}

// 3 high, 0 PWM - rotation    0  -  1
// 2 high, 1 PWM - reverse     2  -  3

void motor_set_direction_and_duty(uint8_t motor, int16_t duty)
{
	_Bool dir = duty > 0;
	duty = ABS(duty);
	switch (motor)
	{
		case B_LEFT: (dir) ? (TIM2->CCR2 = duty) && (TIM2->CCR3 = htim2.Init.Period) : (TIM2->CCR4 = duty) && (TIM2->CCR1 = htim2.Init.Period + 1); break;   //back left motor (1)
		case B_RIGHT: (dir) ? (TIM3->CCR1 = duty) && (TIM3->CCR4 = htim3.Init.Period) : (TIM3->CCR2 = duty) && (TIM3->CCR3 = htim3.Init.Period + 1); break;  //back right motor (2)
		case F_LEFT: (dir) ? (TIM4->CCR4 = duty) && (TIM4->CCR2 = htim4.Init.Period) : (TIM4->CCR1 = duty) && (TIM4->CCR3 = htim4.Init.Period + 1); break;   //front left motor (3)
		case F_RIGHT: (dir) ? (TIM1->CCR4 = duty) && (TIM1->CCR3 = htim1.Init.Period) : (TIM1->CCR1 = duty) && (TIM1->CCR2 = htim1.Init.Period + 1); break;  //front right motor (4)
		
		case SERVO: TIM15->CCR2 = duty;break; //servo (5)
		default: break;
	}
}



void motors_routine(uint16_t joys_positions[])
{
//	double motors_pwm_prescaler_FR = htim1.Init.Period + 1 / 100;                                                 //normalization the infill of motors pwm
//	double motors_pwm_prescaler_BL = htim2.Init.Period + 1 / 100;                                                 //normalization the infill of motors pwm
//	double motors_pwm_prescaler_BR = htim3.Init.Period + 1 / 100;                                                 //normalization the infill of motors pwm
//	double motors_pwm_prescaler_FL = htim4.Init.Period + 1 / 100;                                                 //normalization the infill of motors pwm
	
	double motors_pwm_prescaler = (htim4.Init.Period + 1) / 100;                                                    //normalization the infill of motors pwm
																									          
	uint16_t motor_adc_prescaler = 4096 / 100;                                                                    //normalization for the adc value from joystick for motors
	uint16_t servo_adc_prescaler = 4096 / (MAX_SERVO - MIN_SERVO);                                                //normalization for the adc value from joystick for servo
	
//	int16_t motor_result_value_FR = joys_positions[0] / motor_adc_prescaler * motors_pwm_prescaler_FR - (htim1.Init.Period + 1) / 2;
//	int16_t motor_result_value_BL = joys_positions[0] / motor_adc_prescaler * motors_pwm_prescaler_BL - (htim2.Init.Period + 1) / 2;
//	int16_t motor_result_value_BR = joys_positions[0] / motor_adc_prescaler * motors_pwm_prescaler_BR - (htim3.Init.Period + 1) / 2;
//	int16_t motor_result_value_FL = joys_positions[0] / motor_adc_prescaler * motors_pwm_prescaler_FL - (htim4.Init.Period + 1) / 2;
	
	int16_t motor_result_value = joys_positions[0] / motor_adc_prescaler * motors_pwm_prescaler - (htim4.Init.Period + 1) / 2;
	
	uint16_t servo_result_value = joys_positions[3] / servo_adc_prescaler + MIN_SERVO;
	
//	if (motor_result_value_FR < 300 && motor_result_value_FR > -300) motor_result_value_FR = 0;
//	if (motor_result_value_BL < 300 && motor_result_value_BL > -300) motor_result_value_BL = 0;
//	if (motor_result_value_BR < 300 && motor_result_value_BR > -300) motor_result_value_BR = 0;
//	if (motor_result_value_FL < 300 && motor_result_value_FL > -300) motor_result_value_FL = 0;
	
	if (motor_result_value < 300 && motor_result_value > -300) motor_result_value = 0;
	if (motor_result_value > 5000) motor_result_value = 5000;
	if (motor_result_value < -5000) motor_result_value = -5000;
	
	motor_set_direction_and_duty(F_RIGHT, motor_result_value * 2);
	motor_set_direction_and_duty(B_LEFT, motor_result_value * 2);
	motor_set_direction_and_duty(B_RIGHT, motor_result_value * 2);
	motor_set_direction_and_duty(F_LEFT, motor_result_value * 2);
	
	motor_set_direction_and_duty(SERVO, servo_result_value);
	
}