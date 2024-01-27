#include "data_processing.h"
#include "crc.h"
#include "usart.h"
#include "gpio.h"

uint8_t arr_for_convert[4];

uint8_t* convert32_to_8(uint32_t* data)
{
	arr_for_convert[0] = (*data & 0xFF000000) >> 24;
	arr_for_convert[1] = (*data & 0x00FF0000) >> 16;
	arr_for_convert[2] = (*data & 0x0000FF00) >> 8;
	arr_for_convert[3] = (*data & 0x000000FF);
	
	return arr_for_convert;
}

uint8_t check_crc(uint8_t data[], size_t size)
{
	uint32_t crc_result =  HAL_CRC_Calculate(&hcrc, (uint32_t*)data, AMOUNT_BYTES_TO_RECEIVE - 4);
	uint8_t sum = 0;
	for (uint8_t i = 0; i < 4; i++)
	{
		if (data[AMOUNT_BYTES_TO_RECEIVE - 4 + i] == convert32_to_8(&crc_result)[i]) sum++;
		else sum = 0;
	}
	if (sum == 4) return 1;
	else return 0;
}

void read_data_in(uint8_t data[], uint16_t joys_positions[], uint8_t btns_positions[])
{
	for(uint8_t i = 0; i < 4; i++)
	{
		joys_positions[i] = data[4*i + 1] | (data[4*i] << 8);
	}
	
	for (uint8_t i = 0; i < 4; i++)
	{
		btns_positions[i] = data[16 + i];
	}
}

