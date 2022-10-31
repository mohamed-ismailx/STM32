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

#define No_EXTI_GPIOx 3
#define No_EXTIx 4


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



typedef enum
{
	EXTI_GPIOA,                     //General-Purpose I/O PORTA
	EXTI_GPIOB,					   //General-Purpose I/O PORTB
	EXTI_GPIOC					   //General-Purpose I/O PORTC

}EXTI_PORTx;



typedef enum
{

	/*----------- Input Mode -------------*/

	EXTI_Input_Floating = 0b0100,			   //Input Floating Mode
	EXTI_Input_PullUp = 0b11000,			       //Input Pull-Up Mode ---> ODR_Pin = 1
	EXTI_Input_PullDown = 0b1000,			   //Input Pull-Down Mode ---> ODR_Pin = 0

}EXTI_Input_Modex;



typedef enum
{
	EXTI_Rising,
	EXTI_Falling,
	EXTI_Rising_And_Falling

}EXTI_Edgex;



typedef struct
{
	EXTI_Lines EXTIx_Line;
	EXTI_PORTx EXTI_PORT;
	EXTI_Input_Modex EXTI_PIN_Mode;
	EXTI_Edgex EXTI_Edge;
	void (*EXTIx_ptr)(void);

}EXTI_Configuration;




u8 __EXTI_Enable_Line__(EXTI_Configuration *Data);
u8 __EXTI_Disable_Line__(EXTI_Configuration *Data);
u8 __EXTI_Event_Masked__(EXTI_Configuration *Data);
u8 __EXTI_Event_Non_Masked__(EXTI_Configuration *Data);
u8 __EXTI_Enable_Rising_Trigger_Selection__(EXTI_Configuration *Data);
u8 __EXTI_Disable_Rising_Trigger_Selection__(EXTI_Configuration *Data);
u8 __EXTI_Enable_Falling_Trigger_Selection__(EXTI_Configuration *Data);
u8 __EXTI_Disable_Falling_Trigger_Selection__(EXTI_Configuration *Data);
u8 __EXTI_Enable_Pending_Flag_Software_Interrupt_Event__(EXTI_Configuration *Data);
u8 __EXTI_Disable_Pending_Flag__(EXTI_Configuration *Data);
u8 __EXTI_Read_Pending_Flag__(EXTI_Configuration *Data);




#endif /* EXTI_INTERFACE_H_ */
