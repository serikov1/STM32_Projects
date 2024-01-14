#pragma once
#include "main.h"

extern UART_HandleTypeDef huart1;

uint8_t* gpio_joystick_read_in(uint8_t joybtn_right_state, uint8_t joybtn_left_state, uint8_t btn_left_state, uint8_t btn_right_state);
uint8_t* convert32_to_8(uint32_t* data);
void transmit_data_to_usart(uint16_t* adc_data, uint8_t* gpio_data);
void led_control(uint8_t btn_left_state, uint8_t btn_right_state);
