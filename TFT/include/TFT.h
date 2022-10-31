/*
 * TFT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef TFT_H_
#define TFT_H_

/* 78 data sheet */

#define TFT_No_Pins    2

#define TFT_A0         0
#define TFT_Reset      1

#define TFT_Write_Command   0
#define TFT_Write_Data      1


#define Start_X_Position    0
#define Start_Y_Position    0

#define End_X_Position    127
#define End_Y_Position    159

#define Max_X_Y  20480


#define Set_Y_Address_Command 0x2B
#define Set_X_Address_Command 0x2A

#define Write_RAM     0x2C

#define Sleep_Out_Command  0x11

#define Color_RGB_Selection_Command   0x3A
#define Color_RGB_Selection_Data      0x05

#define Display_On      0x29


typedef enum
{
	/* Pin */
	TFT_A0_Pin = Pin_Zero,
	TFT_Reset_Pin = Pin_One,

	/* Port */
	TFT_A0_Port = GPIOB,
	TFT_Reset_Port = GPIOB

}TFT_Pins;



void __TFT_Initialization__(void);
void __TFT_Reset_Pulse__(void);
void __TFT_Display__(const u16 *Data);
void __TFT_Send_Command__(u8 Command);
void __TFT_Send_Data__(u8 Data);
void __TFT_Set_Position_Start_To_End__(void);



#endif /* TFT_H_ */
