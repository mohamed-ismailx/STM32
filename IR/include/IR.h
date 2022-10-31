/*
 * IR.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef IR_H_
#define IR_H_

#define RGB_Pins          3
#define Frame_Size        50


typedef enum
{
	IR_RGB_Red_Pin = Pin_Three,
	IR_RGB_Green_Pin = Pin_Two,
	IR_RGB_Blue_Pin = Pin_One

}IR_RGB_Pins;


typedef enum
{
	IR_RGB_Blue,
	IR_RGB_Green,
	IR_RGB_Red,
	IR_RGB_Color_one,
	IR_RGB_Color_Two,
	IR_RGB_Color_Three,
	IR_RGB_Color_Four


}IR_RGB_Colors;



typedef enum
{
	IR_Off = 69,
	IR_Mode = 70,
	IR_Mute = 71,
	IR_Play_Pause = 68,
	IR_Previous = 64,
	IR_Next = 67,
	IR_EQ = 7,
	IR_Low_Vol = 21,
	IR_High_Vol = 9,
	IR_RPT = 25,
	IR_USD = 13,
	IR_Zero = 22,
	IR_One = 12,
	IR_Two = 24,
	IR_Three = 94,
	IR_Four = 8,
	IR_Five = 28,
	IR_Six = 90,
	IR_Seven = 66,
	IR_Eight = 82,
	IR_Nine = 74

}IR_Remote_Buttons;


void __IR_RGB_Initialization__(void);

void __IR_Get_Data_By_SysTick__(void);
void __IR_Get_Frame_By_EXTI__(void);
void __IR_RGB_Control__(void);
void __IR_RGB_Mix_Color__(u8 Color);
void __IR_RGB_Off__(void);
//void __IR_RGB_Control__(u8 Data);






#endif /* IR_H_ */
