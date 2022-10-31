/*
 * NVIC_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#include "LSTD_TYPES.h"
#include "Macros.h"
#include "NVIC_Interface.h"
#include "stm32f103xx.h"


#define SCB_Priority_Field  *((volatile u32*)(0xE000ED00 + 0x0C))

NVIC_IPR_Configuration Register_Configuration;



void __NVIC_Enable_Interrupt_Peripheral__(u8 NVIC_Peripheral)
{

	if(NVIC_Peripheral > 31)
	{
		NVIC_Peripheral -= 32;
		NVIC->ISER[NVIC_Peripherals_In_Second_Register] = 1 << NVIC_Peripheral;

	}
	else
		NVIC->ISER[NVIC_Peripherals_In_First_Register] = 1 << NVIC_Peripheral;

}


void __NVIC_Disable_Interrupt_Peripheral__(u8 NVIC_Peripheral)
{



	if(NVIC_Peripheral > 31)
	{
		NVIC_Peripheral -= 32;
		NVIC->ICER[NVIC_Peripherals_In_Second_Register] = 1 << NVIC_Peripheral;

	}
	else
		NVIC->ICER[NVIC_Peripherals_In_First_Register] = 1 << NVIC_Peripheral;

}



void __NVIC_Enable_Pending_Flag_Interrupt_Peripheral__(u8 NVIC_Peripheral)
{


	if(NVIC_Peripheral > 31)
	{
		NVIC_Peripheral -= 32;
		NVIC->ISPR[NVIC_Peripherals_In_Second_Register] = 1 << NVIC_Peripheral;

	}
	else
		NVIC->ISPR[NVIC_Peripherals_In_First_Register] = 1 << NVIC_Peripheral;

}



void __NVIC_Disable_Pending_Flag_Interrupt_Peripheral__(u8 NVIC_Peripheral)
{

	if(NVIC_Peripheral > 31)
	{
		NVIC_Peripheral -= 32;
		NVIC->ICPR[NVIC_Peripherals_In_Second_Register] = 1 << NVIC_Peripheral;

	}
	else
		NVIC->ICPR[NVIC_Peripherals_In_First_Register] = 1 << NVIC_Peripheral;

}


u8 __NVIC_Read_Active_Flag_Interrupt_Peripheral__(u8 NVIC_Peripheral)
{

	u8 Active_Flag_Read = Null;

	if(NVIC_Peripheral > 31)
	{
		NVIC_Peripheral -= 32;
		Active_Flag_Read = Get_Bit(NVIC->IABR[NVIC_Peripherals_In_Second_Register],NVIC_Peripheral);

	}
	else
		Active_Flag_Read = Get_Bit(NVIC->IABR[NVIC_Peripherals_In_First_Register],NVIC_Peripheral);


	return Active_Flag_Read;
}

void __NVIC_Init_Priority_Field__(void)
{

	#if NVIC_Priority_Field_Configuration == NVIC_16_Group_0_Sub
		SCB_Priority_Field = 0x05FA0300;

	#elif NVIC_Priority_Field_Configuration == NVIC_8_Group_2_Sub
		SCB_Priority_Field = 0x05FA0400;

	#elif NVIC_Priority_Field_Configuration == NVIC_4_Group_4_Sub
		SCB_Priority_Field = 0x05FA0500;

	#elif NVIC_Priority_Field_Configuration == NVIC_2_Group_8_Sub
		SCB_Priority_Field = 0x05FA0600;

	#elif NVIC_Priority_Field_Configuration == NVIC_0_Group_16_Sub
		SCB_Priority_Field = 0x05FA0700;

	#endif

}



#if NVIC_Priority_Field_Configuration == NVIC_16_Group_0_Sub

	u8 __NVIC_Set_Priority__(u8 IRQ,u8 Group)
	{
		u8 Execution_State = Execution_Correct;    //Variable To Check Error In The Function

		if(IRQ < NVIC_Max_EXTI)
		{
			Register_Configuration.NVIC_16_Group_0_Sub_Access.Group = Group;
			NVIC->IPR[IRQ] = Register_Configuration.IPR_Register;
		}
		else
			Execution_State = Execution_Error;


		return Execution_State;

	}

#elif NVIC_Priority_Field_Configuration == NVIC_0_Group_16_Sub

	u8 __NVIC_Set_Priority__(u8 IRQ,u8 Sub)
	{
		u8 Execution_State = Execution_Correct;    //Variable To Check Error In The Function

			if(IRQ < NVIC_Max_EXTI)
			{
				Register_Configuration.NVIC_0_Group_16_Sub_Access.Sub = Sub;
				NVIC->IPR[IRQ] = Register_Configuration.IPR_Register;

			}
			else
				Execution_State = Execution_Error;


			return Execution_State;
	}

#else

	u8 __NVIC_Set_Priority__(u8 IRQ,u8 Group,u8 Sub)
	{
		u8 Execution_State = Execution_Correct;    //Variable To Check Error In The Function

		if(IRQ < NVIC_Max_EXTI)
		{

			#if NVIC_Priority_Field_Configuration == NVIC_8_Group_2_Sub
				Register_Configuration.NVIC_8_Group_2_Sub_Access.Group = Group;
				Register_Configuration.NVIC_8_Group_2_Sub_Access.Sub = Sub;
				NVIC->IPR[IRQ] = Register_Configuration.IPR_Register;

			#elif NVIC_Priority_Field_Configuration == NVIC_4_Group_4_Sub
				Register_Configuration.NVIC_4_Group_4_Sub_Access.Group = Group;
				Register_Configuration.NVIC_4_Group_4_Sub_Access.Sub = Sub;
				NVIC->IPR[IRQ] = Register_Configuration.IPR_Register;

			#elif NVIC_Priority_Field_Configuration == NVIC_2_Group_8_Sub
				Register_Configuration.NVIC_2_Group_8_Sub_Access.Group = Group;
				Register_Configuration.NVIC_2_Group_8_Sub_Access.Sub = Sub;
				NVIC->IPR[IRQ] = Register_Configuration.IPR_Register;

			#endif

		}

		else
			Execution_State = Execution_Error;


		return Execution_State;

	}

#endif


