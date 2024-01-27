#pragma once
#include "main.h"

extern UART_HandleTypeDef huart1;

uint8_t check_crc(uint8_t data[], size_t size);

void read_data_in(uint8_t data[], uint16_t joys_positions[], uint8_t btns_positions[]);


