#include "Press_button.h"
#include "modbus_master.h"
#include "trans_recieve_buff_control.h"

extern uint16_t   usSRegHoldBuf[] ;

void Press_button(void)
{		
		if(HAL_GPIO_ReadPin(X2_GPIO_Port,X2_Pin) == GPIO_PIN_RESET) //Button Start
		{
			ModbusMaster_writeSingleRegister(0x09,0x7D0,0x01);
			ModbusMaster_writeSingleRegister(0x09,0x7D1,0x01);
		}
		else if(HAL_GPIO_ReadPin(X6_GPIO_Port,X6_Pin) == 0 || HAL_GPIO_ReadPin(X16_GPIO_Port,X16_Pin) == 0 || HAL_GPIO_ReadPin(X18_GPIO_Port,X18_Pin) == 0)	//Button Stop
		{
			ModbusMaster_writeSingleRegister(0x09,0x7D1,0x03);
		}
		else if(HAL_GPIO_ReadPin(X4_GPIO_Port,X4_Pin) == GPIO_PIN_RESET) // Button Reser
		{
			ModbusMaster_writeSingleRegister(0x09,0x7D0,0x00);
		}	
		else if(HAL_GPIO_ReadPin(X8_GPIO_Port,X8_Pin) == 0)
		{
			ModbusMaster_writeSingleRegister(0x09,0x7D1,0x03);
		}
}