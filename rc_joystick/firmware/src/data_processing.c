#include "data_processing.h"
#include "crc.h"
#include "usart.h"
#include "gpio.h"

uint8_t arr_for_gpio_data[4];
uint8_t arr_for_convert[4];
uint8_t data_to_transmit[AMOUNT_BYTES_TO_TRANSMIT];

uint8_t* gpio_joystick_read_in(uint8_t joybtn_right_state, uint8_t joybtn_left_state, uint8_t btn_left_state, uint8_t btn_right_state)
{
	arr_for_gpio_data[0] = joybtn_right_state;
	arr_for_gpio_data[1] = joybtn_left_state;
	arr_for_gpio_data[2] = btn_left_state;
	arr_for_gpio_data[3] = btn_right_state;

	return arr_for_gpio_data;
}


uint8_t* convert32_to_8(uint32_t* data)
{
	arr_for_convert[0] = (*data & 0xFF000000) >> 24;
	arr_for_convert[1] = (*data & 0x00FF0000) >> 16;
	arr_for_convert[2] = (*data & 0x0000FF00) >> 8;
	arr_for_convert[3] = (*data & 0x000000FF);
	
	return arr_for_convert;
}

void transmit_data_to_usart(uint16_t* adc_raw_data, uint8_t* gpio_data)
{
	for (uint8_t i = 0; i < 4; i++)
	{
		data_to_transmit[i] = convert32_to_8(&adc_raw_data[0])[i];
		data_to_transmit[i + 4] = convert32_to_8(&adc_raw_data[1])[i];
		data_to_transmit[i + 8] = convert32_to_8(&adc_raw_data[2])[i];
		data_to_transmit[i + 12] = convert32_to_8(&adc_raw_data[3])[i];
	}
	  
	data_to_transmit[16] = *gpio_data;
	data_to_transmit[17] = *(gpio_data+1);
	data_to_transmit[18] = *(gpio_data+2);
	data_to_transmit[19] = *(gpio_data+3);
	  
	uint32_t crc_result =  HAL_CRC_Calculate(&hcrc, (uint32_t*)data_to_transmit, 4);
	for (uint8_t i = 0; i < 4; i++)
	{
		data_to_transmit[AMOUNT_BYTES_TO_TRANSMIT - 4 + i] = convert32_to_8(&crc_result)[i];
	}
	
	HAL_UART_Transmit_IT(&huart1, data_to_transmit, 24);
}

void led_control(uint8_t btn_left_state, uint8_t btn_right_state)
{	
	if (btn_left_state)
	{
		HAL_GPIO_WritePin(LED_LEFT_GPIO_Port, LED_LEFT_Pin, GPIO_PIN_SET);
	}
	else if (!btn_left_state)
	{
		HAL_GPIO_WritePin(LED_LEFT_GPIO_Port, LED_LEFT_Pin, GPIO_PIN_RESET);
	}
	
	if (btn_right_state)
	{
		HAL_GPIO_WritePin(LED_RIGHT_GPIO_Port, LED_RIGHT_Pin, GPIO_PIN_SET);
	}
	else if (!btn_right_state)
	{
		HAL_GPIO_WritePin(LED_RIGHT_GPIO_Port, LED_RIGHT_Pin, GPIO_PIN_RESET);
	}
}
