/*
 * TFT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
#include "stm32f103xx.h"
#include "GPIO_Interface.h"
#include "SPI.h"
#include "SysTick_Interface.h"
#include "TFT.h"



GPIO_Pin_Configuration  TFT_Pinx[TFT_No_Pins] = {{TFT_A0_Port,TFT_A0_Pin,GPO_Push_Pull_10MHZ_Speed},
												 {TFT_Reset_Port,TFT_Reset_Pin,GPO_Push_Pull_10MHZ_Speed}};


SPI_One_Configuration SPIx = {SPI_One_Master,Two_Line_Unidirectional_Data_Mode_Selected,
							  Output_Disabled,CRC_Calculation_Disabled,Data_Frame_Format_8_Bit,Full_Duplex,
							  Software_Slave_Management_Enabled_NSS_VCC,SPI_One_MSB,Baud_Rate_fPCLK_Per_2,
							  Clk_Start_Falling_Write_Rising_Read};



void __TFT_Initialization__(void)
{

	u8 Loop;

	for(Loop = Null;Loop < TFT_No_Pins;Loop++)
	{
		__GPIO_Set_Pin_Direction__(&TFT_Pinx[Loop]);
	}

	__SysTick_Initialization__();

	__SPI_One_Initialization__(&SPIx);

	__TFT_Reset_Pulse__();

	__TFT_Send_Command__(Sleep_Out_Command);

	__SysTick_Delay__(150, SysTick_ms);

	__TFT_Send_Command__(Color_RGB_Selection_Command);

	__TFT_Send_Data__(Color_RGB_Selection_Data);

	__TFT_Send_Command__(Display_On);

}





void __TFT_Reset_Pulse__(void)
{

	__GPIO_Write_Pin_HIGH__(&TFT_Pinx[TFT_Reset]);

	__SysTick_Delay__(100, SysTick_us);

	__GPIO_Write_Pin_LOW__(&TFT_Pinx[TFT_Reset]);

	__SysTick_Delay__(1, SysTick_us);

	__GPIO_Write_Pin_HIGH__(&TFT_Pinx[TFT_Reset]);

	__SysTick_Delay__(100, SysTick_us);

	__GPIO_Write_Pin_LOW__(&TFT_Pinx[TFT_Reset]);

	__SysTick_Delay__(100, SysTick_us);

	__GPIO_Write_Pin_HIGH__(&TFT_Pinx[TFT_Reset]);

	__SysTick_Delay__(120, SysTick_ms);

}





void __TFT_Send_Command__(u8 Command)
{
	u8 Read;

	__GPIO_Write_Pin_LOW__(&TFT_Pinx[TFT_A0]);

	__SPI_One_Transmission_Reception_Data__(Command, &Read);

}



void __TFT_Send_Data__(u8 Data)
{

	u8 Read;

	__GPIO_Write_Pin_HIGH__(&TFT_Pinx[TFT_A0]);

	__SPI_One_Transmission_Reception_Data__(Data, &Read);

}



void __TFT_Display__(const u16 *Data)
{

	u16 TFT_Counter;


	__TFT_Send_Command__(Write_RAM);   //RAM Write


	for(TFT_Counter = Null;TFT_Counter < Max_X_Y;TFT_Counter++)
	{

		__TFT_Send_Data__(Data[TFT_Counter] >> 8);     //MSB First
		__TFT_Send_Data__(Data[TFT_Counter] & 0xFF);   //LSB Last


	}

}


void __TFT_Set_Position_Start_To_End__(void)
{

	__TFT_Send_Command__(Set_X_Address_Command);   //Set X Address

	/* Start 2 Byte */
	__TFT_Send_Data__(0);  //1st byte
	__TFT_Send_Data__(0);  //2sd byte

	/* End 2 Byte */
	__TFT_Send_Data__(0);  //1st byte
	__TFT_Send_Data__(End_X_Position);  //2sd byte


	__TFT_Send_Command__(Set_Y_Address_Command);   //Set Y Address

	/* Start 2 Byte */
	__TFT_Send_Data__(0);  //1st byte
	__TFT_Send_Data__(0);  //2sd byte

	/* End 2 Byte */
	__TFT_Send_Data__(0);  //1st byte
	__TFT_Send_Data__(End_Y_Position);  //2sd byte


}


