/*
 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
#include "Macros.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"
#include "SysTick_Interface.h"
#include "SPI.h"



#define No_Of_Peripherals_Enable  4



int main(void)
{

	HSE_Configuration        HSE_Initialization = {Clock_Detector_Off,HSE_Bypass_Off,HSE_selected_as_system_clock};   //Object From union To Configuration The HSE
	Buses_Peripherals_Clock_Enable Enb[No_Of_Peripherals_Enable] = {{APB2,IOPBEN},{APB2,IOPAEN},{APB2,AFIOEN},{APB2,SPI1EN}};
	SPI_One_Configuration SPIx = {SPI_One_Master,Two_Line_Unidirectional_Data_Mode_Selected,Output_Disabled,Null,CRC_Calculation_Disabled,Data_Frame_Format_8_Bit,Full_Duplex,Software_Slave_Management_Enabled_NSS_VCC,SPI_One_MSB,Baud_Rate_fPCLK_Per_2,Clk_Start_Falling_Write_Rising_Read};


	__RCC_HSE_Clock_Initialization(&HSE_Initialization);
	__RCC_Enable_Peripherals_Clock__(No_Of_Peripherals_Enable,Enb);

	__SysTick_Initialization__();

//	__NVIC_Init_Priority_Field__();
//	__NVIC_Enable_Interrupt_Peripheral__(NVIC_Position_SPI1);



	for(;;)
	{


	}



	return Null;
}

