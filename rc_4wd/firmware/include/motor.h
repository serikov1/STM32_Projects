#pragma once
#include "main.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

void motors_init();                                                            //PWM settings
void motor_set_direction_and_duty(uint8_t motor, uint8_t dir, uint16_t duty);  //main function for control motor or servo
void routine(uint16_t joys_positions[]);                                       //proccessing transmited data from joystick for control motors