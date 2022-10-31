/*
 * Macros.h
 *
 *  Created on: ??�/??�/????
 *      Author: kcsstore.com
 */

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define No_GPIOx 3
#define No_Pinx 7

/*  Definition Of Ports In MCU For Pin Configuration */

typedef enum
{
	GPIOA,                     //General-Purpose I/O PORTA
	GPIOB,					   //General-Purpose I/O PORTB
	GPIOC					   //General-Purpose I/O PORTC

}Port_Configuration;


/*  Definition Of Pins In Ports For Pin Configuration */

typedef enum
{
	Pin_Zero,				   //Pin Zero In Any GPIOx
	Pin_One,				   //Pin One In Any GPIOx
	Pin_Two,				   //Pin Two In Any GPIOx
	Pin_Three,				   //Pin Three In Any GPIOx
	Pin_Four,				   //Pin Four In Any GPIOx
	Pin_Five,				   //Pin Five In Any GPIOx
	Pin_Six,      			   //Pin Six In Any GPIOx
	Pin_Seven,				   //Pin Seven In Any GPIOx
	Pin_Eight,				   //Pin Eight In Any GPIOx
	Pin_Nine, 				   //Pin Nine In Any GPIOx
	Pin_Ten,				   //Pin Ten In Any GPIOx
	Pin_Eleven,				   //Pin Eleven In Any GPIOx
	Pin_Twelve,				   //Pin Twelve In Any GPIOx
	Pin_Thirteen,			   //Pin Thirteen In Any GPIOx
	Pin_FourTeen,			   //Pin FourTeen In Any GPIOx
	Pin_Fifteen				   //Pin Fifteen In Any GPIOx

}Pin_Configuration;



/*  Definition Of Modes In MCU For Pin Configuration */

typedef enum
{

	/*----------- Input Mode -------------*/

	Input_Analog = 0b0000,			       //Input Analog Mode For ADC
	Input_Floating = 0b0100,			   //Input Floating Mode
	Input_PullUp = 0b11000,			       //Input Pull-Up Mode ---> ODR_Pin = 1
	Input_PullDown = 0b1000,			   //Input Pull-Down Mode ---> ODR_Pin = 0

	/*---------- Output Mode -------------*/

	/*      10MHZ Speed For Pin      */

	GPO_Push_Pull_10MHZ_Speed = 0b0001,            //General Purpose Output Push-Pull Mode
	GPO_Open_Drain_10MHZ_Speed = 0b0101,		   //General Purpose Output Open-Drain Mode
	AFO_Push_Pull_10MHZ_Speed = 0b1001,			   //Alternate Function Output Push-Pull Mode
	AFO_Open_Drain_10MHZ_Speed = 0b1101,		   //Alternate Function Output Open-Drain Mode

	/*      2MHZ Speed For Pin       */

	GPO_Push_Pull_2MHZ_Speed = 0b0010,             //General Purpose Output Push-Pull Mode
	GPO_Open_Drain_2MHZ_Speed = 0b0110,			   //General Purpose Output Open-Drain Mode
	AFO_Push_Pull_2MHZ_Speed = 0b1010,			   //Alternate Function Output Push-Pull Mode
	AFO_Open_Drain_2MHZ_Speed = 0b1110,			   //Alternate Function Output Open-Drain Mode

	/*      50MHZ Speed For Pin      */

	GPO_Push_Pull_50MHZ_Speed = 0b0011,            //General Purpose Output Push-Pull Mode
	GPO_Open_Drain_50MHZ_Speed = 0b0111,		   //General Purpose Output Open-Drain Mode
	AFO_Push_Pull_50MHZ_Speed = 0b1011,			   //Alternate Function Output Push-Pull Mode
	AFO_Open_Drain_50MHZ_Speed = 0b1111			   //Alternate Function Output Open-Drain Mode


}Mode_Configuration;


typedef enum
{
	LOW,              //Low Output
	HIGH			  //High Output

}Level_Configuration;


/*  Structure For Definition The Port, Pin And Mode For Pin Direction Configuration  */

typedef struct
{
	Port_Configuration Portx;				//Object From Enum For Access Port Configuration
	Pin_Configuration Pinx;					//Object From Enum For Access Pin Configuration
	Mode_Configuration Modex;		//Object From Enum For Access Mode Configuration

}GPIO_Pin_Initialization;


/*  Structure For Definition The Port And Mode For Port Direction Configuration  */

typedef struct
{
	Port_Configuration Portx;				//Object From Enum For Access Port Configuration
	Mode_Configuration Modex;		//Object From Enum For Access Mode Configuration

}GPIO_Port_Initialization;


u8 __GPIO_Set_Pin_Direction__(const GPIO_Pin_Initialization *Data);   //Prototype Of Function That Configuration The Pin Direction
u8 __GPIO_Write_Pin_HIGH__(const GPIO_Pin_Initialization *Data);   //Prototype Of Function That Configuration The Pin Output (HIGH)
u8 __GPIO_Write_Pin_LOW__(const GPIO_Pin_Initialization *Data);   //Prototype Of Function That Configuration The Pin Output (LOW)
u8 __GPIO_Toggle_Pin__(const GPIO_Pin_Initialization *Data);  //Prototype Of Function That Toggle Pin
u8 __GPIO_Read_Pin__(const GPIO_Pin_Initialization *Data);      //Prototype Of Function That Read Pin Value
u8 __GPIO_Set_Port_Direction__(const GPIO_Port_Initialization *Data); //Prototype Of Function That Configuration The Port Direction
u8 __GPIO_Write_Port_HIGH__(const GPIO_Port_Initialization *Data);   //Prototype Of Function That Configuration The Port Output (HIGH)
u8 __GPIO_Write_Port_LOW__(const GPIO_Port_Initialization *Data);    //Prototype Of Function That Configuration The Port Output (LOW)
u8 __GPIO_Read_Port__(const GPIO_Port_Initialization *Data);		//Prototype Of Function That Read Port Value
u8 __GPIO_Toggel_Port__(const GPIO_Port_Initialization *Data);  //Prototype Of Function That Toggle Port
u8 __GPIO_Reverse_Port__(const GPIO_Port_Initialization *Data); //Prototype Of Function That Reverse Port


#endif /* GPIO_INTERFACE_H */
