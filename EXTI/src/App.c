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
#include "AFIO_Interface.h"
#include "EXTI_Interface.h"

#define No_Of_Peripherals_Enable  3

void __Test__(void);

	GPIO_Pin_Initialization  LED = {GPIOA,Pin_Two,GPO_Push_Pull_2MHZ_Speed};
	EXTI_Configuration EXTI1_ENB = {EXTI_Line_One,EXTI_GPIOB,EXTI_Input_PullDown,EXTI_Rising,&__Test__};


int main(void)
{

	HSE_Configuration        HSE_Initialization = {Clock_Detector_Off,HSE_Bypass_Off,HSE_selected_as_system_clock};   //Object From union To Configuration The HSE
	Buses_Peripherals_Clock_Enable Enb[No_Of_Peripherals_Enable] = {{APB2,IOPBEN},{APB2,IOPAEN},{APB2,AFIOEN}};

	__NVIC_Init_Priority_Field__();
	__RCC_HSE_Clock_Initialization(&HSE_Initialization);
	__RCC_Enable_Peripherals_Clock__(No_Of_Peripherals_Enable,Enb);

	__GPIO_Set_Pin_Direction__(&LED);

	__NVIC_Enable_Interrupt_Peripheral__(NVIC_Position_EXTI1);

	__EXTI_Enable_Line__(&EXTI1_ENB);

	for(;;)
	{


	}



	return Null;
}



void __Test__(void)
{

	__GPIO_Toggle_Pin__(&LED);
	__EXTI_Disable_Pending_Flag__(&EXTI1_ENB);

}


