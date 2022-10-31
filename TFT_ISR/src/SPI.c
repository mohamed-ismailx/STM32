/*
 * SPI.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
#include "stm32f103xx.h"
#include "GPIO_Interface.h"
#include "AFIO_Interface.h"
#include "SPI.h"


GPIO_Pin_Configuration   SPI_One_Pinx[SPI_One_No_Pins] = {{SPI_One_SCK_Port,SPI_One_SCK_Pin,AFO_Push_Pull_10MHZ_Speed},
														  {SPI_One_MOSI_Port,SPI_One_MOSI_Pin,AFO_Push_Pull_10MHZ_Speed},
														  {SPI_One_MISO_Port,SPI_One_MISO_Pin,Input_Floating}};

void (*SPI_One_Set_Call_Back)(void);
static volatile u8 *SPI_One_Rx = Null;
static volatile u8 SPI_One_Flag = Null;


u8 __SPI_One_Initialization__(SPI_One_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;       //Variable To Indicate The Execution State In This Function
	u8 Loop;

	AFIO->MAPR.Bits_Access.SPI1_REMAP = SPI_One_Mapping;

	for(Loop = Null;Loop < SPI_One_No_Pins;Loop++)
	{
		__GPIO_Set_Pin_Direction__(&SPI_One_Pinx[Loop]);
	}

	SPI_One->CR1.Bit_Access.MSTR = Data->Master_Slave_Selection;
	SPI_One->CR1.Bit_Access.BIDIMODE = Data->Bidirectional;
	SPI_One->CR1.Bit_Access.BIDIOE = Data->Bidirectional_Output;
	SPI_One->CR1.Bit_Access.CRCEN = Data->CRC;
	SPI_One->CR1.Bit_Access.DFF = Data->Data_Frame_Format;
	SPI_One->CR1.Bit_Access.RXONLY = Data->Data_Direction;

	switch(Data->SSM)
	{

		case Software_Slave_Management_Disabled_HW_NSS_Out_For_PA4:
			SPI_One->CR1.Bit_Access.SSM = Disable;
			SPI_One->CR2.Bit_Access.SSOE = Enable;
			break;

		case Software_Slave_Management_Enabled_NSS_VCC:
			SPI_One->CR1.Bit_Access.SSM = Enable;
			SPI_One->CR1.Bit_Access.SSI = Enable;
			break;

		case Software_Slave_Management_Enabled_NSS_GND:
			SPI_One->CR1.Bit_Access.SSM = Enable;
			SPI_One->CR1.Bit_Access.SSI = Disable;
			break;

		default:
			Execution_State = Execution_Error;     //Update The Execution Error To The Execution State Variable
			break;
	}


	SPI_One->CR1.Bit_Access.LSBFIRST = Data->Frame_Format;

	SPI_One->CR1.Bit_Access.BR = Data->Baud_Rate;



	switch(Data->Clk_Format)
	{

		case Clk_Start_Rising_Write_Falling_Read:
			SPI_One->CR1.Bit_Access.CPOL = Disable;
			SPI_One->CR1.Bit_Access.CPHA = Enable;
			break;

		case Clk_Start_Rising_Read_Falling_Write:
			SPI_One->CR1.Bit_Access.CPOL = Disable;
			SPI_One->CR1.Bit_Access.CPHA = Disable;
			break;

		case Clk_Start_Falling_Read_Rising_Write:
			SPI_One->CR1.Bit_Access.CPOL = Enable;
			SPI_One->CR1.Bit_Access.CPHA = Disable;
			break;

		case Clk_Start_Falling_Write_Rising_Read:
			SPI_One->CR1.Bit_Access.CPOL = Enable;
			SPI_One->CR1.Bit_Access.CPHA = Enable;
			break;

		default:
			Execution_State = Execution_Error;     //Update The Execution Error To The Execution State Variable
			break;
	}


	SPI_One->CR1.Bit_Access.SPE = Enable;




	return Execution_State;      //Return The Execution State Of This Function


}



u8 __SPI_One_Transmission_Reception_Data__(u8 Tx_Data,u8 *Rx_Data)
{

	u8 Execution_State = Execution_Correct;       //Variable To Indicate The Execution State In This Function


	if((Rx_Data != NULL))
	{
		SPI_One->DR = Tx_Data;
		while(SPI_One->SR.Bit_Access.BSY != Null);
		*Rx_Data = SPI_One->DR;
	}

	else
		Execution_State = Execution_Error;     //Update The Execution Error To The Execution State Variable



	return Execution_State;      //Return The Execution State Of This Function

}





u8 __SPI_One_Transmission_Reception_Data_Ach__(u8 Tx_Data,u8 *Rx_Data,void (*SPI_One_ptr)(void))
{

	u8 Execution_State = Execution_Correct;       //Variable To Indicate The Execution State In This Function


	if((SPI_One_ptr != NULL) && (SPI_One_Flag == Null))
	{
		SPI_One_Set_Call_Back = SPI_One_ptr;
		SPI_One_Rx = Rx_Data;
		SPI_One_Flag = 1;
		SPI_One->CR2.Bit_Access.TXEIE = Enable;
		SPI_One->DR = Tx_Data;
	}

	else
		Execution_State = Execution_Error;     //Update The Execution Error To The Execution State Variable


	return Execution_State;      //Return The Execution State Of This Function
}





void SPI1_IRQHandler(void)
{

	SPI_One_Set_Call_Back();
	*SPI_One_Rx = SPI_One->DR;
	SPI_One->CR2.Bit_Access.TXEIE = Disable;
	SPI_One_Flag = Null;
}




