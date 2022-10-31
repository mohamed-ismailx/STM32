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

#define No_Of_Peripherals_Enable  2


void LEDX(void);

GPIO_Pin_Initialization  LED = {GPIOA,Pin_Two,GPO_Push_Pull_2MHZ_Speed};


int main(void)
{

	HSE_Configuration        HSE_Initialization = {Clock_Detector_Off,HSE_Bypass_Off,HSE_selected_as_system_clock};   //Object From union To Configuration The HSE
	Buses_Peripherals_Clock_Enable Enb[No_Of_Peripherals_Enable] = {{APB2,IOPBEN},{APB2,IOPAEN}};


	__RCC_HSE_Clock_Initialization(&HSE_Initialization);
	__RCC_Enable_Peripherals_Clock__(No_Of_Peripherals_Enable,Enb);
	__SysTick_Init__();
	__GPIO_Set_Pin_Direction__(&LED);
	__GPIO_Write_Pin_HIGH__(&LED);
//	__SysTick_Single_Mode__(1000000,&LEDX);


	for(;;)
	{
		__GPIO_Write_Pin_HIGH__(&LED);
		__SysTick_Delay__(2000);
		__GPIO_Write_Pin_LOW__(&LED);
		__SysTick_Delay__(2000);
	}



	return Null;
}

//
//void LEDX(void)
//{
//
//	__GPIO_Toggle_Pin__(&LED);
//}

