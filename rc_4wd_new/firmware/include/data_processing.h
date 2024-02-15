#pragma once
#include "main.h"

extern UART_HandleTypeDef huart1;

uint8_t check_crc(uint8_t data[], size_t size);                                          //function for checking crc in received data 

void read_data_in(uint8_t data[], uint16_t joys_positions[], uint8_t btns_positions[]);  //processing data from joystick


