/*
 * UART.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */


#include "LSTD_TYPES.h"
#include "stm32f103xx.h"
#include "GPIO_Interface.h"
#include "UART_Interface.h"


GPIO_Pin_Configuration   UART_One_Pinx[No_Of_UART_One_Pins] = {{UART_One_Tx_Port,UART_One_Tx_Pin,AFO_Push_Pull_10MHZ_Speed},
															  {UART_One_Rx_Port,UART_One_Rx_Pin,Input_Floating}};



u8 __UART_One_Initialization__(UART_One_Configuartion *Data)
{

	u8 Execution_State = Execution_Correct;         //Variable To Check Error In The Function
	u8 Loop;

	if(Data != NULL)
	{

		for(Loop = Null;Loop < No_Of_UART_One_Pins;Loop++)
		{
			__GPIO_Set_Pin_Direction__(&UART_One_Pinx[Loop]);
		}

		UART_One->BRR.Register_Access = Data->Baud_Rate;
		UART_One->CR1.Bit_Access.UE = Enable;
		UART_One->CR1.Bit_Access.RE = Enable;
		UART_One->CR1.Bit_Access.TE = Enable;
		UART_One->CR1.Bit_Access.M = Data->Data_Size;
		UART_One->CR2.Bit_Access.STOP = Data->Stop_Bit;
	}

	else          //Else The Structure Is Empty Address
		Execution_State = Execution_Error;          //Update The Error State To The Variable


	return Execution_State;    //Return The Error State
}




u8 __UART_One_Transmit_Data__(char *Data)
{

	u8 Execution_State = Execution_Correct;         //Variable To Check Error In The Function
	u8 Counter = Null;

	if(Data != NULL)
	{

		while(Data[Counter] != '\0')
		{
			while(UART_One->SR.Bit_Access.TXE == Null);
			UART_One->DR = Data[Counter];
			Counter++;
		}

	}

	else          //Else The Structure Is Empty Address
		Execution_State = Execution_Error;          //Update The Error State To The Variable


	return Execution_State;    //Return The Error State


}



void __UART_One_Receive_Data__(u8 *Data)
{

	u8 Counter = Null;
	Data[Counter] = Null;

	while(Data[Counter] != '#')
	{
		while(UART_One->SR.Bit_Access.RXNE == Null);
		Data[Counter] = UART_One->DR;
		Counter++;
	}


}




void __UART_One_Receive_Data_ESP__(u8 *Data)
{

	u32 Time_Out = Null;

	while((UART_One->SR.Bit_Access.RXNE == Null))
	{
		Time_Out++;

		if(Time_Out == 50000)
		{
			*Data = 255;
			break;
		}

	}

	if((UART_One->SR.Bit_Access.RXNE == 1))
	{
		*Data = UART_One->DR;
	}

}
