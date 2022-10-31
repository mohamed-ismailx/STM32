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


#define No_Of_Peripherals_Enable  2


	GPIO_Pin_Initialization LED = {GPIOA,Pin_One,GPO_Push_Pull_2MHZ_Speed};


int main(void)
{

	HSE_Configuration        HSE_Initialization = {Clock_Detector_Off,HSE_Bypass_Off,HSE_selected_as_system_clock};   //Object From union To Configuration The HSE
	Buses_Peripherals_Clock_Enable Enb[No_Of_Peripherals_Enable] = {{APB2,IOPAEN},{APB2,AFIOEN}};

	__RCC_HSE_Clock_Initialization(&HSE_Initialization);
	__RCC_Enable_Peripherals_Clock__(No_Of_Peripherals_Enable,Enb);
	__GPIO_Set_Pin_Direction__(&LED);
	__NVIC_Enable_Interrupt_Peripheral__(NVIC_Position_EXTI0);


	__NVIC_Init_Priority_Field__();
//	__NVIC_Set_Priority__(NVIC_Position_EXTI0,NVIC_Group_One,NVIC_Sub_Three);
//	__NVIC_Set_Priority__(NVIC_Position_SPI1,NVIC_Group_Two,NVIC_Sub_Zero);

	__NVIC_Set_Priority__(NVIC_Position_EXTI0,NVIC_Group_One,NVIC_Sub_Three);
	__NVIC_Set_Priority__(NVIC_Position_SPI1,NVIC_Group_Two,NVIC_Sub_Zero);


	__NVIC_Enable_Interrupt_Peripheral__(NVIC_Position_EXTI0);
	__NVIC_Enable_Interrupt_Peripheral__(NVIC_Position_SPI1);


	__NVIC_Enable_Pending_Flag_Interrupt_Peripheral__(NVIC_Position_EXTI0);




	for(;;)
	{


	}



	return Null;
}




void EXTI0_IRQHandler(void)
{

	__NVIC_Enable_Pending_Flag_Interrupt_Peripheral__(NVIC_Position_SPI1);

	for(;;);

}



void SPI1_IRQHandler(void)
{
	__GPIO_Write_Pin_HIGH__(&LED);
	for(;;);
}



