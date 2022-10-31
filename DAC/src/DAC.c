/*
 * App.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */


#include "LSTD_TYPES.h"
#include "stm32f103xx.h"
#include "GPIO_Interface.h"
#include "DAC.h"


volatile u16 Sampling_Index = Null;

GPIO_Pin_Configuration DACx[DAC_No_Pins] = {{GPIOA,Pin_Zero,GPO_Push_Pull_2MHZ_Speed},
											{GPIOA,Pin_One,GPO_Push_Pull_2MHZ_Speed},
											{GPIOA,Pin_Two,GPO_Push_Pull_2MHZ_Speed},
											{GPIOA,Pin_Three,GPO_Push_Pull_2MHZ_Speed},
											{GPIOA,Pin_Four,GPO_Push_Pull_2MHZ_Speed},
											{GPIOA,Pin_Five,GPO_Push_Pull_2MHZ_Speed},
											{GPIOA,Pin_Six,GPO_Push_Pull_2MHZ_Speed},
											{GPIOA,Pin_Seven,GPO_Push_Pull_2MHZ_Speed}};



void __DAC_Initialization__(void)
{
	u8 Loop;

	for(Loop = Null;Loop < DAC_No_Pins;Loop++)
	{
		__GPIO_Set_Pin_Direction__(&DACx[Loop]);
	}

}



void __DAC_Sampling__(const u8 *Sample)
{

	__GPIO_Write_Port__(GPIOA,Sample[Sampling_Index]);
	Sampling_Index++;
	if(Sampling_Index == 9566)
	{
		Sampling_Index = Null;
	}

}


