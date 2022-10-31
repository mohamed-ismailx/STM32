/*
 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
#include "Macros.h"
#include "stm32f103xx.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SysTick_Interface.h"
#include "DAC.h"
#include "Song.h"

void DAC_Song(void);

#define No_Of_Peripherals_Enable  2


//xxd -i untitled.raw file.h



int main(void)
{

	u8 Re;
	HSE_Configuration        HSE_Initialization = {Clock_Detector_Off,HSE_Bypass_Off,HSE_selected_as_system_clock};   //Object From union To Configuration The HSE
	Buses_Peripherals_Clock_Enable Enb[No_Of_Peripherals_Enable] = {{APB2,IOPAEN},{APB2,IOPBEN}};
	GPIO_Pin_Configuration PinA_Zero_Inputx = {GPIOB,Pin_Zero,Input_PullDown};


	__RCC_HSE_Clock_Initialization(&HSE_Initialization);
	__RCC_Enable_Peripherals_Clock__(No_Of_Peripherals_Enable,Enb);
	__DAC_Initialization__();
	__SysTick_Initialization__();
	__GPIO_Set_Pin_Direction__(&PinA_Zero_Inputx);
	__SysTick_Single_Mode__(125,SysTick_us,&DAC_Song);

	for(;;)
	{
		Re = __GPIO_Read_Pin__(&PinA_Zero_Inputx);

		if(Re)
		{
			__SysTick_Single_Mode__(125,SysTick_us,&DAC_Song);
		}

	}



	return Null;
}




void DAC_Song(void)
{

	__DAC_Sampling__(untitled_raw);
}

