/*
 * DMA.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef DMA_H_
#define DMA_H_


typedef enum
{
	DMA_Channel_One,
	DMA_Channel_Two,
	DMA_Channel_Three,
	DMA_Channel_Four,
	DMA_Channel_Five,
	DMA_Channel_Six,
	DMA_Channel_Seven

}DMA_Channelx;


typedef enum
{
	DMA_8_Bit_Size,
	DMA_16_Bit_Size,
	DMA_32_Bit_Size

}DMA_Memory_Size_And_Peripheral_Size;



typedef enum
{
	DMA_Priority_Low,
	DMA_Priority_Medium,
	DMA_Priority_High,
	DMA_Priority_Very_High

}DMA_Channel_Priority_Level;



typedef enum
{
	Memory_To_Memory_Mode_Disabled,    //trigger source
	Memory_To_Memory_Mode_Enabled

}DMA_Mode;


typedef enum
{
	DMA_Incremet_Mode_Disabled,
	DMA_Incremet_Mode_Enabled

}DMA_PINC_MINC_Increment;



typedef enum
{
	DMA_Circular_Mode_Disabled,
	DMA_Circular_Mode_Enabled

}DMA_Circular_Mode;



typedef enum
{
	DMA_Read_From_Peripheral,
	DMA_Read_From_Memory

}DMA_Data_Transfer_Direction;


typedef struct
{
	DMA_Channelx  								Channel;
	DMA_Memory_Size_And_Peripheral_Size			Memory_Size;
	DMA_Memory_Size_And_Peripheral_Size			Peripheral_Size;
	DMA_Channel_Priority_Level					Channel_Priority_Level;
	DMA_Mode                                    Mode;
	DMA_PINC_MINC_Increment						MINC_Increment;
	DMA_PINC_MINC_Increment						PINC_Increment;
	DMA_Circular_Mode							Circular_Mode;
	DMA_Data_Transfer_Direction					Data_Transfer_Direction;
//	u16 										No_Of_Data_Transfer;
//	u32  										Peripheral_Address;
//	u32 										Memory_Address;

}DMA_Configuration;




u8 __DMA_Initialization__(DMA_Configuration *Data);

u8 __DMA_Channel_Start_Transfer__(u8 Channel,u32 *Peripheral_Address,u32 *Memory_Address,u16 No_Of_Data_Transfer);


u8 __DMA_Enable_Channel__(DMA_Configuration *Data);
u8 __DMA_Disable_Channel__(DMA_Configuration *Data);


u8 __DMA_Channel_Clear_Transfer_Error_Flag__(DMA_Configuration *Data);
u8 __DMA_Channel_Clear_Half_Transfer_Flag__(DMA_Configuration *Data);
u8 __DMA_Channel_Clear_Transfer_Complete_Flag__(DMA_Configuration *Data);
u8 __DMA_Channel_Clear_Global_Interrupt_Flag__(DMA_Configuration *Data);

u8 __DMA_Channel_Read_Transfer_Error_Flag__(DMA_Configuration *Data);
u8 __DMA_Channel_Read_Half_Transfer_Flag__(DMA_Configuration *Data);
u8 __DMA_Channel_Read_Transfer_Complete_Flag__(DMA_Configuration *Data);
u8 __DMA_Channel_Read_Global_Interrupt_Flag__(DMA_Configuration *Data);


#endif /* DMA_H_ */
