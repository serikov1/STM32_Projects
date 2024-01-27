#pragma once
#include "main.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim1;

void motors_init();
void motor_set_direction_and_duty(uint8_t motor, uint8_t dir, uint16_t duty);
//void motors_control(uint16_t joys_positions[]);