/*
 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
//#include "Macros.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
//#include "NVIC_Interface.h"
#include "SysTick_Interface.h"
//#include "DMA.h"
//#include "UART_Interface.h"

#include "ESP_Interface.h"

#define No_Of_Peripherals_Enable  2



int main(void)
{
	u8 Character;
	GPIO_Pin_Configuration LED = {GPIOA,Pin_Zero,GPO_Push_Pull_2MHZ_Speed};
	HSE_Configuration        HSE_Initialization = {Clock_Detector_Off,HSE_Bypass_Off,HSE_selected_as_system_clock};   //Object From union To Configuration The HSE
	Buses_Peripherals_Clock_Enable Enb[No_Of_Peripherals_Enable] = {{APB2,USART1EN},{APB2,IOPAEN}};


	__RCC_HSE_Clock_Initialization(&HSE_Initialization);
	__RCC_Enable_Peripherals_Clock__(No_Of_Peripherals_Enable,Enb);

	__GPIO_Set_Pin_Direction__(&LED);

	__SysTick_Initialization__();

//	__NVIC_Init_Priority_Field__();
//	__NVIC_Enable_Interrupt_Peripheral__(NVIC_Position_DMA1_Channel1);

	__ESP_Initialization__();


	for(;;)
	{

		Character = __ESP_Read_Data_State_One__();

		if((Character == '1'))
		{
			__GPIO_Write_Pin_HIGH__(&LED);
		}

		else
		{
			__GPIO_Write_Pin_LOW__(&LED);
		}

	}



	return Null;
}



