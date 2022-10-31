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


u8 Read;

int main(void)
{

	HSE_Configuration        HSE_Initialization = {Clock_Detector_Off,HSE_Bypass_Off,HSE_selected_as_system_clock};   //Object From union To Configuration The HSE
//	Buses_Peripherals_Clock_Enable Enable_Clock_Peripheral_C = {APB2,IOPCEN};    //Object From Structure To Configuration The Bus And Peripheral To Cross It Throw Function That Enable Clock
//	Buses_Peripherals_Clock_Enable Enable_Clock_Peripheral_A = {APB2,IOPAEN};    //Object From Structure To Configuration The Bus And Peripheral To Cross It Throw Function That Enable Clock
	Buses_Peripherals_Clock_Enable Enb[2] = {{APB2,IOPBEN},{APB2,IOPAEN}};
	GPIO_Pin_Initialization LED = {GPIOA,Pin_One,GPO_Push_Pull_2MHZ_Speed};
//	GPIO_Pin_Initialization INPUT = {GPIOA,Pin_Zero,Input_PullDown};
	GPIO_Port_Initialization POTRB = {GPIOB,GPO_Push_Pull_2MHZ_Speed};
	__RCC_HSE_Clock_Initialization(&HSE_Initialization);
//	__RCC_Enable_Peripheral_Clock__(&Enable_Clock_Peripheral_A);
//	__RCC_Enable_Peripheral_Clock__(&Enable_Clock_Peripheral_C);
	__RCC_Enable_Peripherals_Clock__(2,Enb);


	__GPIO_Set_Port_Direction__(&POTRB);
	__GPIO_Write_Port_HIGH__(&POTRB);

	__GPIO_Set_Pin_Direction__(&LED);
//	__GPIO_Set_Pin_Direction__(&INPUT);
//	__GPIO_Write_Pin_HIGH__(&LED);

	__GPIO_Write_Pin_HIGH__(&LED);

	for(;;)
	{
//
//		Read = __GPIO_Read_Pin__(&INPUT);
//
//		if(!Read)
//			__GPIO_Write_Pin_HIGH__(&LED);
//
//		else
//			__GPIO_Write_Pin_LOW__(&LED);

	}



	return Null;
}
