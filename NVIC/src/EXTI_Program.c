/*
 * EXTI_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
#include "EXTI_Interface.h"
#include "stm32f103xx.h"


//
//u8 __EXTI_Init__()
//{
//
//}




u8 __EXTI_Disable_Line__(u8 Interrutpt_Line)
{

	u8 Execution_State = Execution_Correct;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			EXTI->IMR.Bits_Access.MR0 = EXTI_Masked;
			break;

		case EXTI_Line_One:
			EXTI->IMR.Bits_Access.MR1 = EXTI_Masked;
			break;

		case EXTI_Line_Two:
			EXTI->IMR.Bits_Access.MR2 = EXTI_Masked;
			break;

		case EXTI_Line_Three:
			EXTI->IMR.Bits_Access.MR3 = EXTI_Masked;
			break;

		case EXTI_Line_Four:
			EXTI->IMR.Bits_Access.MR4 = EXTI_Masked;
			break;

		case EXTI_Line_Five:
			EXTI->IMR.Bits_Access.MR5 = EXTI_Masked;
			break;

		case EXTI_Line_Six:
			EXTI->IMR.Bits_Access.MR6 = EXTI_Masked;
			break;

		case EXTI_Line_Seven:
			EXTI->IMR.Bits_Access.MR7 = EXTI_Masked;
			break;

		case EXTI_Line_Eight:
			EXTI->IMR.Bits_Access.MR8 = EXTI_Masked;
			break;

		case EXTI_Line_Nine:
			EXTI->IMR.Bits_Access.MR9 = EXTI_Masked;
			break;

		case EXTI_Line_Ten:
			EXTI->IMR.Bits_Access.MR10 = EXTI_Masked;
			break;

		case EXTI_Line_Eleven:
			EXTI->IMR.Bits_Access.MR11 = EXTI_Masked;
			break;

		case EXTI_Line_Twelve:
			EXTI->IMR.Bits_Access.MR12 = EXTI_Masked;
			break;

		case EXTI_Line_Thirteen:
			EXTI->IMR.Bits_Access.MR13 = EXTI_Masked;
			break;

		case EXTI_Line_Fourteen:
			EXTI->IMR.Bits_Access.MR14 = EXTI_Masked;
			break;

		case EXTI_Line_Fifteen:
			EXTI->IMR.Bits_Access.MR15 = EXTI_Masked;
			break;

		case EXTI_Line_Sixteen_PVD:
			EXTI->IMR.Bits_Access.MR16 = EXTI_Masked;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			EXTI->IMR.Bits_Access.MR17 = EXTI_Masked;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			EXTI->IMR.Bits_Access.MR18 = EXTI_Masked;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			EXTI->IMR.Bits_Access.MR19 = EXTI_Masked;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}



	return Execution_State;
}



u8 __EXTI_Enable_Line__(u8 Interrutpt_Line)
{

	u8 Execution_State = Execution_Correct;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			EXTI->IMR.Bits_Access.MR0 = EXTI_Non_Masked;
			break;

		case EXTI_Line_One:
			EXTI->IMR.Bits_Access.MR1 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Two:
			EXTI->IMR.Bits_Access.MR2 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Three:
			EXTI->IMR.Bits_Access.MR3 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Four:
			EXTI->IMR.Bits_Access.MR4 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Five:
			EXTI->IMR.Bits_Access.MR5 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Six:
			EXTI->IMR.Bits_Access.MR6 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Seven:
			EXTI->IMR.Bits_Access.MR7 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Eight:
			EXTI->IMR.Bits_Access.MR8 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Nine:
			EXTI->IMR.Bits_Access.MR9 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Ten:
			EXTI->IMR.Bits_Access.MR10 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Eleven:
			EXTI->IMR.Bits_Access.MR11 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Twelve:
			EXTI->IMR.Bits_Access.MR12 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Thirteen:
			EXTI->IMR.Bits_Access.MR13 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Fourteen:
			EXTI->IMR.Bits_Access.MR14 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Fifteen:
			EXTI->IMR.Bits_Access.MR15 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Sixteen_PVD:
			EXTI->IMR.Bits_Access.MR16 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			EXTI->IMR.Bits_Access.MR17 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			EXTI->IMR.Bits_Access.MR18 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			EXTI->IMR.Bits_Access.MR19 = EXTI_Non_Masked;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}



	return Execution_State;

}


u8 __EXTI_Event_Masked__(u8 Interrutpt_Line)
{

	u8 Execution_State = Execution_Correct;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			EXTI->EMR.Bits_Access.MR0 = EXTI_Masked;
			break;

		case EXTI_Line_One:
			EXTI->EMR.Bits_Access.MR1 = EXTI_Masked;
			break;

		case EXTI_Line_Two:
			EXTI->EMR.Bits_Access.MR2 = EXTI_Masked;
			break;

		case EXTI_Line_Three:
			EXTI->EMR.Bits_Access.MR3 = EXTI_Masked;
			break;

		case EXTI_Line_Four:
			EXTI->EMR.Bits_Access.MR4 = EXTI_Masked;
			break;

		case EXTI_Line_Five:
			EXTI->EMR.Bits_Access.MR5 = EXTI_Masked;
			break;

		case EXTI_Line_Six:
			EXTI->EMR.Bits_Access.MR6 = EXTI_Masked;
			break;

		case EXTI_Line_Seven:
			EXTI->EMR.Bits_Access.MR7 = EXTI_Masked;
			break;

		case EXTI_Line_Eight:
			EXTI->EMR.Bits_Access.MR8 = EXTI_Masked;
			break;

		case EXTI_Line_Nine:
			EXTI->EMR.Bits_Access.MR9 = EXTI_Masked;
			break;

		case EXTI_Line_Ten:
			EXTI->EMR.Bits_Access.MR10 = EXTI_Masked;
			break;

		case EXTI_Line_Eleven:
			EXTI->EMR.Bits_Access.MR11 = EXTI_Masked;
			break;

		case EXTI_Line_Twelve:
			EXTI->EMR.Bits_Access.MR12 = EXTI_Masked;
			break;

		case EXTI_Line_Thirteen:
			EXTI->EMR.Bits_Access.MR13 = EXTI_Masked;
			break;

		case EXTI_Line_Fourteen:
			EXTI->EMR.Bits_Access.MR14 = EXTI_Masked;
			break;

		case EXTI_Line_Fifteen:
			EXTI->EMR.Bits_Access.MR15 = EXTI_Masked;
			break;

		case EXTI_Line_Sixteen_PVD:
			EXTI->EMR.Bits_Access.MR16 = EXTI_Masked;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			EXTI->EMR.Bits_Access.MR17 = EXTI_Masked;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			EXTI->EMR.Bits_Access.MR18 = EXTI_Masked;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			EXTI->EMR.Bits_Access.MR19 = EXTI_Masked;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;

}


u8 __EXTI_Event_Non_Masked__(u8 Interrutpt_Line)
{

	u8 Execution_State = Execution_Correct;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			EXTI->EMR.Bits_Access.MR0 = EXTI_Non_Masked;
			break;

		case EXTI_Line_One:
			EXTI->EMR.Bits_Access.MR1 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Two:
			EXTI->EMR.Bits_Access.MR2 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Three:
			EXTI->EMR.Bits_Access.MR3 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Four:
			EXTI->EMR.Bits_Access.MR4 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Five:
			EXTI->EMR.Bits_Access.MR5 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Six:
			EXTI->EMR.Bits_Access.MR6 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Seven:
			EXTI->EMR.Bits_Access.MR7 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Eight:
			EXTI->EMR.Bits_Access.MR8 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Nine:
			EXTI->EMR.Bits_Access.MR9 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Ten:
			EXTI->EMR.Bits_Access.MR10 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Eleven:
			EXTI->EMR.Bits_Access.MR11 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Twelve:
			EXTI->EMR.Bits_Access.MR12 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Thirteen:
			EXTI->EMR.Bits_Access.MR13 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Fourteen:
			EXTI->EMR.Bits_Access.MR14 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Fifteen:
			EXTI->EMR.Bits_Access.MR15 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Sixteen_PVD:
			EXTI->EMR.Bits_Access.MR16 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			EXTI->EMR.Bits_Access.MR17 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			EXTI->EMR.Bits_Access.MR18 = EXTI_Non_Masked;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			EXTI->EMR.Bits_Access.MR19 = EXTI_Non_Masked;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;

}



u8 __EXTI_Enable_Rising_Trigger_Selection__(u8 Interrutpt_Line)
{

	u8 Execution_State = Execution_Correct;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			EXTI->RTSR.Bits_Access.TR0 = Enable;
			break;

		case EXTI_Line_One:
			EXTI->RTSR.Bits_Access.TR1 = Enable;
			break;

		case EXTI_Line_Two:
			EXTI->RTSR.Bits_Access.TR2 = Enable;
			break;

		case EXTI_Line_Three:
			EXTI->RTSR.Bits_Access.TR3 = Enable;
			break;

		case EXTI_Line_Four:
			EXTI->RTSR.Bits_Access.TR4 = Enable;
			break;

		case EXTI_Line_Five:
			EXTI->RTSR.Bits_Access.TR5 = Enable;
			break;

		case EXTI_Line_Six:
			EXTI->RTSR.Bits_Access.TR6 = Enable;
			break;

		case EXTI_Line_Seven:
			EXTI->RTSR.Bits_Access.TR7 = Enable;
			break;

		case EXTI_Line_Eight:
			EXTI->RTSR.Bits_Access.TR8 = Enable;
			break;

		case EXTI_Line_Nine:
			EXTI->RTSR.Bits_Access.TR9 = Enable;
			break;

		case EXTI_Line_Ten:
			EXTI->RTSR.Bits_Access.TR10 = Enable;
			break;

		case EXTI_Line_Eleven:
			EXTI->RTSR.Bits_Access.TR11 = Enable;
			break;

		case EXTI_Line_Twelve:
			EXTI->RTSR.Bits_Access.TR12 = Enable;
			break;

		case EXTI_Line_Thirteen:
			EXTI->RTSR.Bits_Access.TR13 = Enable;
			break;

		case EXTI_Line_Fourteen:
			EXTI->RTSR.Bits_Access.TR14 = Enable;
			break;

		case EXTI_Line_Fifteen:
			EXTI->RTSR.Bits_Access.TR15 = Enable;
			break;

		case EXTI_Line_Sixteen_PVD:
			EXTI->RTSR.Bits_Access.TR16 = Enable;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			EXTI->RTSR.Bits_Access.TR17 = Enable;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			EXTI->RTSR.Bits_Access.TR18 = Enable;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			EXTI->RTSR.Bits_Access.TR19 = Enable;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;

}


u8 __EXTI_Disable_Rising_Trigger_Selection__(u8 Interrutpt_Line)
{

	u8 Execution_State = Execution_Correct;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			EXTI->RTSR.Bits_Access.TR0 = Disable;
			break;

		case EXTI_Line_One:
			EXTI->RTSR.Bits_Access.TR1 = Disable;
			break;

		case EXTI_Line_Two:
			EXTI->RTSR.Bits_Access.TR2 = Disable;
			break;

		case EXTI_Line_Three:
			EXTI->RTSR.Bits_Access.TR3 = Disable;
			break;

		case EXTI_Line_Four:
			EXTI->RTSR.Bits_Access.TR4 = Disable;
			break;

		case EXTI_Line_Five:
			EXTI->RTSR.Bits_Access.TR5 = Disable;
			break;

		case EXTI_Line_Six:
			EXTI->RTSR.Bits_Access.TR6 = Disable;
			break;

		case EXTI_Line_Seven:
			EXTI->RTSR.Bits_Access.TR7 = Disable;
			break;

		case EXTI_Line_Eight:
			EXTI->RTSR.Bits_Access.TR8 = Disable;
			break;

		case EXTI_Line_Nine:
			EXTI->RTSR.Bits_Access.TR9 = Disable;
			break;

		case EXTI_Line_Ten:
			EXTI->RTSR.Bits_Access.TR10 = Disable;
			break;

		case EXTI_Line_Eleven:
			EXTI->RTSR.Bits_Access.TR11 = Disable;
			break;

		case EXTI_Line_Twelve:
			EXTI->RTSR.Bits_Access.TR12 = Disable;
			break;

		case EXTI_Line_Thirteen:
			EXTI->RTSR.Bits_Access.TR13 = Disable;
			break;

		case EXTI_Line_Fourteen:
			EXTI->RTSR.Bits_Access.TR14 = Disable;
			break;

		case EXTI_Line_Fifteen:
			EXTI->RTSR.Bits_Access.TR15 = Disable;
			break;

		case EXTI_Line_Sixteen_PVD:
			EXTI->RTSR.Bits_Access.TR16 = Disable;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			EXTI->RTSR.Bits_Access.TR17 = Disable;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			EXTI->RTSR.Bits_Access.TR18 = Disable;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			EXTI->RTSR.Bits_Access.TR19 = Disable;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;

}


u8 __EXTI_Enable_Falling_Trigger_Selection__(u8 Interrutpt_Line)
{


	u8 Execution_State = Execution_Correct;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			EXTI->FTSR.Bits_Access.TR0 = Enable;
			break;

		case EXTI_Line_One:
			EXTI->FTSR.Bits_Access.TR1 = Enable;
			break;

		case EXTI_Line_Two:
			EXTI->FTSR.Bits_Access.TR2 = Enable;
			break;

		case EXTI_Line_Three:
			EXTI->FTSR.Bits_Access.TR3 = Enable;
			break;

		case EXTI_Line_Four:
			EXTI->FTSR.Bits_Access.TR4 = Enable;
			break;

		case EXTI_Line_Five:
			EXTI->FTSR.Bits_Access.TR5 = Enable;
			break;

		case EXTI_Line_Six:
			EXTI->FTSR.Bits_Access.TR6 = Enable;
			break;

		case EXTI_Line_Seven:
			EXTI->FTSR.Bits_Access.TR7 = Enable;
			break;

		case EXTI_Line_Eight:
			EXTI->FTSR.Bits_Access.TR8 = Enable;
			break;

		case EXTI_Line_Nine:
			EXTI->FTSR.Bits_Access.TR9 = Enable;
			break;

		case EXTI_Line_Ten:
			EXTI->FTSR.Bits_Access.TR10 = Enable;
			break;

		case EXTI_Line_Eleven:
			EXTI->FTSR.Bits_Access.TR11 = Enable;
			break;

		case EXTI_Line_Twelve:
			EXTI->FTSR.Bits_Access.TR12 = Enable;
			break;

		case EXTI_Line_Thirteen:
			EXTI->FTSR.Bits_Access.TR13 = Enable;
			break;

		case EXTI_Line_Fourteen:
			EXTI->FTSR.Bits_Access.TR14 = Enable;
			break;

		case EXTI_Line_Fifteen:
			EXTI->FTSR.Bits_Access.TR15 = Enable;
			break;

		case EXTI_Line_Sixteen_PVD:
			EXTI->FTSR.Bits_Access.TR16 = Enable;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			EXTI->FTSR.Bits_Access.TR17 = Enable;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			EXTI->FTSR.Bits_Access.TR18 = Enable;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			EXTI->FTSR.Bits_Access.TR19 = Enable;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;


}


u8 __EXTI_Disable_Falling_Trigger_Selection__(u8 Interrutpt_Line)
{

	u8 Execution_State = Execution_Correct;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			EXTI->FTSR.Bits_Access.TR0 = Disable;
			break;

		case EXTI_Line_One:
			EXTI->FTSR.Bits_Access.TR1 = Disable;
			break;

		case EXTI_Line_Two:
			EXTI->FTSR.Bits_Access.TR2 = Disable;
			break;

		case EXTI_Line_Three:
			EXTI->FTSR.Bits_Access.TR3 = Disable;
			break;

		case EXTI_Line_Four:
			EXTI->FTSR.Bits_Access.TR4 = Disable;
			break;

		case EXTI_Line_Five:
			EXTI->FTSR.Bits_Access.TR5 = Disable;
			break;

		case EXTI_Line_Six:
			EXTI->FTSR.Bits_Access.TR6 = Disable;
			break;

		case EXTI_Line_Seven:
			EXTI->FTSR.Bits_Access.TR7 = Disable;
			break;

		case EXTI_Line_Eight:
			EXTI->FTSR.Bits_Access.TR8 = Disable;
			break;

		case EXTI_Line_Nine:
			EXTI->FTSR.Bits_Access.TR9 = Disable;
			break;

		case EXTI_Line_Ten:
			EXTI->FTSR.Bits_Access.TR10 = Disable;
			break;

		case EXTI_Line_Eleven:
			EXTI->FTSR.Bits_Access.TR11 = Disable;
			break;

		case EXTI_Line_Twelve:
			EXTI->FTSR.Bits_Access.TR12 = Disable;
			break;

		case EXTI_Line_Thirteen:
			EXTI->FTSR.Bits_Access.TR13 = Disable;
			break;

		case EXTI_Line_Fourteen:
			EXTI->FTSR.Bits_Access.TR14 = Disable;
			break;

		case EXTI_Line_Fifteen:
			EXTI->FTSR.Bits_Access.TR15 = Disable;
			break;

		case EXTI_Line_Sixteen_PVD:
			EXTI->FTSR.Bits_Access.TR16 = Disable;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			EXTI->FTSR.Bits_Access.TR17 = Disable;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			EXTI->FTSR.Bits_Access.TR18 = Disable;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			EXTI->FTSR.Bits_Access.TR19 = Disable;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;

}

u8 __EXTI_Enable_Pending_Flag_Software_Interrupt_Event__(u8 Interrutpt_Line)
{

	u8 Execution_State = Execution_Correct;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			EXTI->SWIER.Bits_Access.SWIER0 = Enable;
			break;

		case EXTI_Line_One:
			EXTI->SWIER.Bits_Access.SWIER1 = Enable;
			break;

		case EXTI_Line_Two:
			EXTI->SWIER.Bits_Access.SWIER2 = Enable;
			break;

		case EXTI_Line_Three:
			EXTI->SWIER.Bits_Access.SWIER3 = Enable;
			break;

		case EXTI_Line_Four:
			EXTI->SWIER.Bits_Access.SWIER4 = Enable;
			break;

		case EXTI_Line_Five:
			EXTI->SWIER.Bits_Access.SWIER5 = Enable;
			break;

		case EXTI_Line_Six:
			EXTI->SWIER.Bits_Access.SWIER6 = Enable;
			break;

		case EXTI_Line_Seven:
			EXTI->SWIER.Bits_Access.SWIER7 = Enable;
			break;

		case EXTI_Line_Eight:
			EXTI->SWIER.Bits_Access.SWIER8 = Enable;
			break;

		case EXTI_Line_Nine:
			EXTI->SWIER.Bits_Access.SWIER9 = Enable;
			break;

		case EXTI_Line_Ten:
			EXTI->SWIER.Bits_Access.SWIER10 = Enable;
			break;

		case EXTI_Line_Eleven:
			EXTI->SWIER.Bits_Access.SWIER11 = Enable;
			break;

		case EXTI_Line_Twelve:
			EXTI->SWIER.Bits_Access.SWIER12 = Enable;
			break;

		case EXTI_Line_Thirteen:
			EXTI->SWIER.Bits_Access.SWIER13 = Enable;
			break;

		case EXTI_Line_Fourteen:
			EXTI->SWIER.Bits_Access.SWIER14 = Enable;
			break;

		case EXTI_Line_Fifteen:
			EXTI->SWIER.Bits_Access.SWIER15 = Enable;
			break;

		case EXTI_Line_Sixteen_PVD:
			EXTI->SWIER.Bits_Access.SWIER16 = Enable;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			EXTI->SWIER.Bits_Access.SWIER17 = Enable;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			EXTI->SWIER.Bits_Access.SWIER18 = Enable;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			EXTI->SWIER.Bits_Access.SWIER19 = Enable;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;

}


u8 __EXTI_Disable_Pending_Flag__(u8 Interrutpt_Line)
{

	u8 Execution_State = Execution_Correct;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			EXTI->PR.Bits_Access.PR0 = Enable;
			break;

		case EXTI_Line_One:
			EXTI->PR.Bits_Access.PR1 = Enable;
			break;

		case EXTI_Line_Two:
			EXTI->PR.Bits_Access.PR2 = Enable;
			break;

		case EXTI_Line_Three:
			EXTI->PR.Bits_Access.PR3 = Enable;
			break;

		case EXTI_Line_Four:
			EXTI->PR.Bits_Access.PR4 = Enable;
			break;

		case EXTI_Line_Five:
			EXTI->PR.Bits_Access.PR5 = Enable;
			break;

		case EXTI_Line_Six:
			EXTI->PR.Bits_Access.PR6 = Enable;
			break;

		case EXTI_Line_Seven:
			EXTI->PR.Bits_Access.PR7 = Enable;
			break;

		case EXTI_Line_Eight:
			EXTI->PR.Bits_Access.PR8 = Enable;
			break;

		case EXTI_Line_Nine:
			EXTI->PR.Bits_Access.PR9 = Enable;
			break;

		case EXTI_Line_Ten:
			EXTI->PR.Bits_Access.PR10 = Enable;
			break;

		case EXTI_Line_Eleven:
			EXTI->PR.Bits_Access.PR11 = Enable;
			break;

		case EXTI_Line_Twelve:
			EXTI->PR.Bits_Access.PR12 = Enable;
			break;

		case EXTI_Line_Thirteen:
			EXTI->PR.Bits_Access.PR13 = Enable;
			break;

		case EXTI_Line_Fourteen:
			EXTI->PR.Bits_Access.PR14 = Enable;
			break;

		case EXTI_Line_Fifteen:
			EXTI->PR.Bits_Access.PR15 = Enable;
			break;

		case EXTI_Line_Sixteen_PVD:
			EXTI->PR.Bits_Access.PR16 = Enable;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			EXTI->PR.Bits_Access.PR17 = Enable;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			EXTI->PR.Bits_Access.PR18 = Enable;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			EXTI->PR.Bits_Access.PR19 = Enable;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State;


}


u8 __EXTI_Read_Pending_Flag__(u8 Interrutpt_Line)
{

	u8 Execution_State = Execution_Correct;
	u8 Read_Value;

	switch(Interrutpt_Line)
	{
		case EXTI_Line_Zero:
			Read_Value = EXTI->PR.Bits_Access.PR0;
			break;

		case EXTI_Line_One:
			Read_Value = EXTI->PR.Bits_Access.PR1;
			break;

		case EXTI_Line_Two:
			Read_Value = EXTI->PR.Bits_Access.PR2;
			break;

		case EXTI_Line_Three:
			Read_Value = EXTI->PR.Bits_Access.PR3;
			break;

		case EXTI_Line_Four:
			Read_Value = EXTI->PR.Bits_Access.PR4;
			break;

		case EXTI_Line_Five:
			Read_Value = EXTI->PR.Bits_Access.PR5;
			break;

		case EXTI_Line_Six:
			Read_Value = EXTI->PR.Bits_Access.PR6;
			break;

		case EXTI_Line_Seven:
			Read_Value = EXTI->PR.Bits_Access.PR7;
			break;

		case EXTI_Line_Eight:
			Read_Value = EXTI->PR.Bits_Access.PR8;
			break;

		case EXTI_Line_Nine:
			Read_Value = EXTI->PR.Bits_Access.PR9;
			break;

		case EXTI_Line_Ten:
			Read_Value = EXTI->PR.Bits_Access.PR10;
			break;

		case EXTI_Line_Eleven:
			Read_Value = EXTI->PR.Bits_Access.PR11;
			break;

		case EXTI_Line_Twelve:
			Read_Value = EXTI->PR.Bits_Access.PR12;
			break;

		case EXTI_Line_Thirteen:
			Read_Value = EXTI->PR.Bits_Access.PR13;
			break;

		case EXTI_Line_Fourteen:
			Read_Value = EXTI->PR.Bits_Access.PR14;
			break;

		case EXTI_Line_Fifteen:
			Read_Value = EXTI->PR.Bits_Access.PR15;
			break;

		case EXTI_Line_Sixteen_PVD:
			Read_Value = EXTI->PR.Bits_Access.PR16;
			break;

		case EXTI_Line_Seventeen_RTC_Alarm:
			Read_Value = EXTI->PR.Bits_Access.PR17;
			break;

		case EXTI_Line_Eighteen_USB_Wakeup:
			Read_Value = EXTI->PR.Bits_Access.PR18;
			break;

		case EXTI_Line_Nineteen_Ethernet_Wakeup:
			Read_Value = EXTI->PR.Bits_Access.PR19;
			break;

		default:
			Execution_State = Execution_Error;
			break;

	}


	return Execution_State == Execution_Error? Execution_State : Read_Value;

}


