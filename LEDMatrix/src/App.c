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
#include "LEDMXD.h"

#define No_Of_Peripherals_Enable  2


//xxd -i untitled.raw file.h

int main(void)
{

	HSE_Configuration        HSE_Initialization = {Clock_Detector_Off,HSE_Bypass_Off,HSE_selected_as_system_clock};   //Object From union To Configuration The HSE
	Buses_Peripherals_Clock_Enable Enb[No_Of_Peripherals_Enable] = {{APB2,IOPBEN},{APB2,IOPAEN}};


	__RCC_HSE_Clock_Initialization(&HSE_Initialization);
	__RCC_Enable_Peripherals_Clock__(No_Of_Peripherals_Enable,Enb);
	__SysTick_Init__();



	for(;;)
	{


	}



	return Null;
}



