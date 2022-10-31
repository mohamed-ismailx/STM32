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
#include "DMA.h"


#define No_Of_Peripherals_Enable  2


GPIO_Pin_Configuration LED = {GPIOA,Pin_Zero,GPO_Push_Pull_2MHZ_Speed};
int i;

int main(void)
{

	u32 var = 0;
	u32 v = (0x40010800 + 0x0c);
//	u32 Arr1[1000] = {0};
//	u32 Arr6[1000];

//
//	u32 Arr3[1000] = {0};
//	u32 Arr4[1000];

	DMA_Configuration     DMA_Array = {DMA_Channel_One,DMA_32_Bit_Size,DMA_32_Bit_Size,DMA_Priority_Medium,Memory_To_Memory_Mode_Enabled,DMA_Incremet_Mode_Enabled,DMA_Incremet_Mode_Enabled,DMA_Circular_Mode_Disabled,DMA_Read_From_Peripheral};
	HSE_Configuration        HSE_Initialization = {Clock_Detector_Off,HSE_Bypass_Off,HSE_selected_as_system_clock};   //Object From union To Configuration The HSE
	Buses_Peripherals_Clock_Enable Enb[No_Of_Peripherals_Enable] = {{AHB,DMA1EN},{APB2,IOPAEN}};


	__RCC_HSE_Clock_Initialization(&HSE_Initialization);
	__RCC_Enable_Peripherals_Clock__(No_Of_Peripherals_Enable,Enb);

	__SysTick_Initialization__();
	__GPIO_Set_Pin_Direction__(&LED);
	__GPIO_Write_Pin_HIGH__(&LED);

//	__SysTick_Delay__(1000, SysTick_ms);
//
//	__GPIO_Write_Pin_LOW__(&LED);

	__NVIC_Init_Priority_Field__();
	__NVIC_Enable_Interrupt_Peripheral__(NVIC_Position_DMA1_Channel1);

	__DMA_Initialization__(&DMA_Array);
	__DMA_Channel_Start_Transfer__(DMA_Channel_One,v,&var,1);



//	for(i = 0;i < 1000;i++)
//	{
//		Arr4[i] = Arr3[i];
//	}


	for(;;)
	{


	}



	return Null;
}



void DMA1_Channel1_IRQHandler(void)
{



}
