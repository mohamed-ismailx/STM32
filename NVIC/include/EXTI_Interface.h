/*
 * EXTI_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define EXTI_Masked        0
#define EXTI_Non_Masked    1


typedef enum
{
	EXTI_Line_Zero,
	EXTI_Line_One,
	EXTI_Line_Two,
	EXTI_Line_Three,
	EXTI_Line_Four,
	EXTI_Line_Five,
	EXTI_Line_Six,
	EXTI_Line_Seven,
	EXTI_Line_Eight,
	EXTI_Line_Nine,
	EXTI_Line_Ten,
	EXTI_Line_Eleven,
	EXTI_Line_Twelve,
	EXTI_Line_Thirteen,
	EXTI_Line_Fourteen,
	EXTI_Line_Fifteen,
	EXTI_Line_Sixteen_PVD,
	EXTI_Line_Seventeen_RTC_Alarm,
	EXTI_Line_Eighteen_USB_Wakeup,
	EXTI_Line_Nineteen_Ethernet_Wakeup

}EXTI_Lines;


//
//u8 __EXTI_Init__();

u8 __EXTI_Disable_Line__(u8 Interrutpt_Line);
u8 __EXTI_Enable_Line__(u8 Interrutpt_Line);
u8 __EXTI_Event_Masked__(u8 Interrutpt_Line);
u8 __EXTI_Event_Non_Masked__(u8 Interrutpt_Line);
u8 __EXTI_Enable_Rising_Trigger_Selection__(u8 Interrutpt_Line);
u8 __EXTI_Disable_Rising_Trigger_Selection__(u8 Interrutpt_Line);
u8 __EXTI_Enable_Falling_Trigger_Selection__(u8 Interrutpt_Line);
u8 __EXTI_Disable_Falling_Trigger_Selection__(u8 Interrutpt_Line);
u8 __EXTI_Enable_Pending_Flag_Software_Interrupt_Event__(u8 Interrutpt_Line);
u8 __EXTI_Disable_Pending_Flag__(u8 Interrutpt_Line);
u8 __EXTI_Read_Pending_Flag__(u8 Interrutpt_Line);





#endif /* EXTI_INTERFACE_H_ */
