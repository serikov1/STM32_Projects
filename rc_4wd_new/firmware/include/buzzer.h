#pragma once
#include "main.h"

#define BUZZ_INIT_PWM 1000
#define BUZZ_ROUTINE_PWM 1000
extern TIM_HandleTypeDef htim15;

void buzzer_init();
void buzzer_routine(uint8_t btns_positions[]);
