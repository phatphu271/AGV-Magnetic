#ifndef __READ_BAT_H
#define __READ_BAT_H

#include "main.h"


extern UART_HandleTypeDef huart5;


#define Start_code 				0xDD
#define End_code 					0x77

#define Register_read 		0xA5
#define Register_write 		0x5A	

#define Read_basic 				0x03
#define Read_battery 			0x04
#define Read_version 			0x05

void Send_data(uint8_t *buff_array, uint8_t size_buff);
void Read_data(uint8_t command);
#endif