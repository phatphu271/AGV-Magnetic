#include "Read_bat.h"

uint8_t buffer_tran[7];

/*Mode Select Mode*/
/*
Register_read 	: Read data
Register_write	:	Write data
*/

/*Mode Select Command*/
/*
Read_basic 		: Read basic information and status
Read_battery	:	Read the battery voltage
Read_version	:	Read the BMS hardware version number
*/
void Send_data(uint8_t *buff_array, uint8_t size_buff)
{
	HAL_GPIO_WritePin(UART5_CK_GPIO_Port,UART5_CK_Pin,GPIO_PIN_SET);
	HAL_UART_Transmit(&huart5, buff_array, size_buff, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(UART5_CK_GPIO_Port,UART5_CK_Pin,GPIO_PIN_RESET);
	HAL_Delay(40);
}

void Read_data(uint8_t command)		/*Mode Select Mode : Register_read*/
{
	uint8_t crc;
	buffer_tran[0] = Start_code;
	buffer_tran[1] = Register_read;
	buffer_tran[2] = command;
	buffer_tran[3] = 0x00;
	buffer_tran[4] = 0xFF;
	crc = buffer_tran[2]^buffer_tran[3]^buffer_tran[4];
	crc += 0x01;
	buffer_tran[5] = crc;
	buffer_tran[6] = End_code;
	Send_data(buffer_tran, sizeof(buffer_tran));
}