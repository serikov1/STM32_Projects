#pragma once
#include "main.h"

#define MAX_SERVO 1500
#define MIN_SERVO 500
	
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim15;

void motors_init();                                                            //PWM settings
void motor_set_direction_and_duty(uint8_t motor, int16_t duty);                //main function for control motor or servo
void routine(uint16_t joys_positions[]);                                       //proccessing transmited data from joystick for control motors