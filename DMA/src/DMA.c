/*
 * DMA.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
#include "Macros.h"
#include "stm32f103xx.h"
#include "DMA.h"




u8 __DMA_Initialization__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;

	if(Data != NULL)
	{

		DMA->Channel[Data->Channel].CCR.Bit_Access.MEM2MEM = Data->Mode;
		DMA->Channel[Data->Channel].CCR.Bit_Access.PL = Data->Channel_Priority_Level;
		DMA->Channel[Data->Channel].CCR.Bit_Access.MSIZE = Data->Memory_Size;
		DMA->Channel[Data->Channel].CCR.Bit_Access.PSIZE = Data->Peripheral_Size;

		DMA->Channel[Data->Channel].CCR.Bit_Access.MINC = Data->MINC_Increment;
		DMA->Channel[Data->Channel].CCR.Bit_Access.PINC = Data->PINC_Increment;

		DMA->Channel[Data->Channel].CCR.Bit_Access.CIRC = Data->Circular_Mode;
		DMA->Channel[Data->Channel].CCR.Bit_Access.DIR = Data->Data_Transfer_Direction;

		DMA->Channel[Data->Channel].CCR.Bit_Access.TCIE = Enable;

	}

	else
		Execution_State = Execution_Error;

	return Execution_State;

}



u8 __DMA_Channel_Start_Transfer__(u8 Channel,u32 *Peripheral_Address,u32 *Memory_Address,u16 No_Of_Data_Transfer)
{
	u8 Execution_State = Execution_Correct;

	if(Channel <= 7)
	{
		DMA->Channel[Channel].CNDTR = No_Of_Data_Transfer;
		DMA->Channel[Channel].CMAR = Memory_Address;
		DMA->Channel[Channel].CPAR = Peripheral_Address;
		DMA->Channel[Channel].CCR.Bit_Access.EN = Enable;
	}

	else
		Execution_State = Execution_Error;

	return Execution_State;

}




u8 __DMA_Channel_Clear_Transfer_Error_Flag__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;


	switch(Data->Channel)
	{

		case DMA_Channel_One:
			DMA->IFCR.Bit_Access.CTEIF1 = Enable;
			break;

		case DMA_Channel_Two:
			DMA->IFCR.Bit_Access.CTEIF2 = Enable;
			break;

		case DMA_Channel_Three:
			DMA->IFCR.Bit_Access.CTEIF3 = Enable;
			break;

		case DMA_Channel_Four:
			DMA->IFCR.Bit_Access.CTEIF4 = Enable;
			break;

		case DMA_Channel_Five:
			DMA->IFCR.Bit_Access.CTEIF5 = Enable;
			break;

		case DMA_Channel_Six:
			DMA->IFCR.Bit_Access.CTEIF6 = Enable;
			break;

		case DMA_Channel_Seven:
			DMA->IFCR.Bit_Access.CTEIF7 = Enable;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;
}


u8 __DMA_Channel_Clear_Half_Transfer_Flag__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;


	switch(Data->Channel)
	{

		case DMA_Channel_One:
			DMA->IFCR.Bit_Access.CHTIF1 = Enable;
			break;

		case DMA_Channel_Two:
			DMA->IFCR.Bit_Access.CHTIF2 = Enable;
			break;

		case DMA_Channel_Three:
			DMA->IFCR.Bit_Access.CHTIF3 = Enable;
			break;

		case DMA_Channel_Four:
			DMA->IFCR.Bit_Access.CHTIF4 = Enable;
			break;

		case DMA_Channel_Five:
			DMA->IFCR.Bit_Access.CHTIF5 = Enable;
			break;

		case DMA_Channel_Six:
			DMA->IFCR.Bit_Access.CHTIF6 = Enable;
			break;

		case DMA_Channel_Seven:
			DMA->IFCR.Bit_Access.CHTIF7 = Enable;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;

}


u8 __DMA_Channel_Clear_Transfer_Complete_Flag__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;


	switch(Data->Channel)
	{

		case DMA_Channel_One:
			DMA->IFCR.Bit_Access.CTCIF1 = Enable;
			break;

		case DMA_Channel_Two:
			DMA->IFCR.Bit_Access.CTCIF2 = Enable;
			break;

		case DMA_Channel_Three:
			DMA->IFCR.Bit_Access.CTCIF3 = Enable;
			break;

		case DMA_Channel_Four:
			DMA->IFCR.Bit_Access.CTCIF4 = Enable;
			break;

		case DMA_Channel_Five:
			DMA->IFCR.Bit_Access.CTCIF5 = Enable;
			break;

		case DMA_Channel_Six:
			DMA->IFCR.Bit_Access.CTCIF6 = Enable;
			break;

		case DMA_Channel_Seven:
			DMA->IFCR.Bit_Access.CTCIF7 = Enable;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;

}


u8 __DMA_Channel_Clear_Global_Interrupt_Flag__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;


	switch(Data->Channel)
	{

		case DMA_Channel_One:
			DMA->IFCR.Bit_Access.CGIF1 = Enable;
			break;

		case DMA_Channel_Two:
			DMA->IFCR.Bit_Access.CGIF2 = Enable;
			break;

		case DMA_Channel_Three:
			DMA->IFCR.Bit_Access.CGIF3 = Enable;
			break;

		case DMA_Channel_Four:
			DMA->IFCR.Bit_Access.CGIF4 = Enable;
			break;

		case DMA_Channel_Five:
			DMA->IFCR.Bit_Access.CGIF5 = Enable;
			break;

		case DMA_Channel_Six:
			DMA->IFCR.Bit_Access.CGIF6 = Enable;
			break;

		case DMA_Channel_Seven:
			DMA->IFCR.Bit_Access.CGIF7 = Enable;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;

}


u8 __DMA_Channel_Read_Transfer_Error_Flag__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;
	u8 Read;

		switch(Data->Channel)
		{

			case DMA_Channel_One:
				Read = DMA->ISR.Bit_Access.TEIF1;
				break;

			case DMA_Channel_Two:
				Read = DMA->ISR.Bit_Access.TEIF2;
				break;

			case DMA_Channel_Three:
				Read = DMA->ISR.Bit_Access.TEIF3;
				break;

			case DMA_Channel_Four:
				Read = DMA->ISR.Bit_Access.TEIF4;
				break;

			case DMA_Channel_Five:
				Read = DMA->ISR.Bit_Access.TEIF5;
				break;

			case DMA_Channel_Six:
				Read = DMA->ISR.Bit_Access.TEIF6;
				break;

			case DMA_Channel_Seven:
				Read = DMA->ISR.Bit_Access.TEIF7;
				break;

			default:
				Execution_State = Execution_Error;
				break;

		}


		return Execution_State == Execution_Error? Execution_State : Read;
}



u8 __DMA_Channel_Read_Half_Transfer_Flag__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;
	u8 Read;

		switch(Data->Channel)
		{

			case DMA_Channel_One:
				Read = DMA->ISR.Bit_Access.HTIF1;
				break;

			case DMA_Channel_Two:
				Read = DMA->ISR.Bit_Access.HTIF2;
				break;

			case DMA_Channel_Three:
				Read = DMA->ISR.Bit_Access.HTIF3;
				break;

			case DMA_Channel_Four:
				Read = DMA->ISR.Bit_Access.HTIF4;
				break;

			case DMA_Channel_Five:
				Read = DMA->ISR.Bit_Access.HTIF5;
				break;

			case DMA_Channel_Six:
				Read = DMA->ISR.Bit_Access.HTIF6;
				break;

			case DMA_Channel_Seven:
				Read = DMA->ISR.Bit_Access.HTIF7;
				break;

			default:
				Execution_State = Execution_Error;
				break;

		}


		return Execution_State == Execution_Error? Execution_State : Read;
}



u8 __DMA_Channel_Read_Transfer_Complete_Flag__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;
	u8 Read;

		switch(Data->Channel)
		{

			case DMA_Channel_One:
				Read = DMA->ISR.Bit_Access.TCIF1;
				break;

			case DMA_Channel_Two:
				Read = DMA->ISR.Bit_Access.TCIF2;
				break;

			case DMA_Channel_Three:
				Read = DMA->ISR.Bit_Access.TCIF3;
				break;

			case DMA_Channel_Four:
				Read = DMA->ISR.Bit_Access.TCIF4;
				break;

			case DMA_Channel_Five:
				Read = DMA->ISR.Bit_Access.TCIF5;
				break;

			case DMA_Channel_Six:
				Read = DMA->ISR.Bit_Access.TCIF6;
				break;

			case DMA_Channel_Seven:
				Read = DMA->ISR.Bit_Access.TCIF7;
				break;

			default:
				Execution_State = Execution_Error;
				break;

		}


		return Execution_State == Execution_Error? Execution_State : Read;
}


u8 __DMA_Channel_Read_Global_Interrupt_Flag__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;
	u8 Read;

		switch(Data->Channel)
		{

			case DMA_Channel_One:
				Read = DMA->ISR.Bit_Access.GIF1;
				break;

			case DMA_Channel_Two:
				Read = DMA->ISR.Bit_Access.GIF2;
				break;

			case DMA_Channel_Three:
				Read = DMA->ISR.Bit_Access.GIF3;
				break;

			case DMA_Channel_Four:
				Read = DMA->ISR.Bit_Access.GIF4;
				break;

			case DMA_Channel_Five:
				Read = DMA->ISR.Bit_Access.GIF5;
				break;

			case DMA_Channel_Six:
				Read = DMA->ISR.Bit_Access.GIF6;
				break;

			case DMA_Channel_Seven:
				Read = DMA->ISR.Bit_Access.GIF7;
				break;

			default:
				Execution_State = Execution_Error;
				break;

		}


		return Execution_State == Execution_Error? Execution_State : Read;
}




u8 __DMA_Enable_Channel__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;

	if(Data->Channel <= 7)
	{
		DMA->Channel[Data->Channel].CCR.Bit_Access.EN = Enable;
	}

	else
		Execution_State = Execution_Error;

	return Execution_State;
}


u8 __DMA_Disable_Channel__(DMA_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;

	if(Data->Channel <= 7)
	{
		DMA->Channel[Data->Channel].CCR.Bit_Access.EN = Disable;
	}

	else
		Execution_State = Execution_Error;

	return Execution_State;
}
