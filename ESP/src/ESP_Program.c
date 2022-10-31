/*
 * ESP_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
#include "UART_Interface.h"
#include "ESP_Interface.h"
#include "SysTick_Interface.h"

UART_One_Configuartion   Putty = {UART_One_Baud_Rate_115200,UART_One_Data_Size_8_bit,UART_One_1_Stop_Bit};


void __ESP_Initialization__(void)
{

	__UART_One_Initialization__(&Putty);

	__UART_One_Transmit_Data__("ATE0\r\n");

	__SysTick_Delay__(500, SysTick_ms);

	__UART_One_Transmit_Data__("AT+CWMODE=1\r\n");

	__SysTick_Delay__(500, SysTick_ms);


	__UART_One_Transmit_Data__("AT+CWJAP_CUR=\"Embedded\",\"oliverweka123\"\r\n");


	__SysTick_Delay__(500, SysTick_ms);

}



u8 __ESP_Read_Data_State_One__(void)
{

	u8 State = Null;


	__UART_One_Transmit_Data__("AT+CIPSTART=\"TCP\",\"162.253.155.226\",80\r\n");

	__SysTick_Delay__(500, SysTick_ms);

	__UART_One_Transmit_Data__("AT+CIPSEND=50\r\n");

	__SysTick_Delay__(500, SysTick_ms);

	__UART_One_Transmit_Data__("GET http://projectembedded.freevar.com/State.txt\r\n");

	State = __ESP_Get_Data__();


	return State;
}



u8 __ESP_Get_Data__(void)
{

	u8 ESP_Data[41] = {Null};
	u8 Data = Null,Counter = Null,Check = Null;


	while(Counter < 41)
	{
		__UART_One_Receive_Data_ESP__(&Data);
		ESP_Data[Counter++] = Data;
	}

	Check = __ESP_Get_State__(ESP_Data);


	return Check;
}




u8 __ESP_Get_State__(u8 *Arr)
{

    u8 Counter = Null;
    u8 State = Null;

    for (Counter = 0; Counter < 41; Counter++)
    {

        if((Arr[Counter] == '+') && (Arr[Counter + 1] == 'I'))
        {
            State = Arr[Counter + 7];
            break;
        }
        //+IPD,1:0

    }

    return State;
}


