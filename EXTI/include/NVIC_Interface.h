/*
 * NVIC_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


#define NVIC_16_Group_0_Sub  	0b011
#define NVIC_8_Group_2_Sub      0b100
#define NVIC_4_Group_4_Sub  	0b101
#define NVIC_2_Group_8_Sub  	0b110
#define NVIC_0_Group_16_Sub  	0b111

#define NVIC_Priority_Field_Configuration   NVIC_4_Group_4_Sub


#define NVIC_Peripherals_In_First_Register   0
#define NVIC_Peripherals_In_Second_Register  1


#define NVIC_Max_EXTI   240



typedef enum
{
	NVIC_Group_Zero,
	NVIC_Group_One,
	NVIC_Group_Two,
	NVIC_Group_Three,
	NVIC_Group_Four,
	NVIC_Group_Five,
	NVIC_Group_Six,
	NVIC_Group_Seven,
	NVIC_Group_Eight,
	NVIC_Group_Nine,
	NVIC_Group_Ten,
	NVIC_Group_Eleven,
	NVIC_Group_Twelve,
	NVIC_Group_Thirteen,
	NVIC_Group_Fourteen,
	NVIC_Group_Fifteen

}NVIC_Group_Numbers;

typedef enum
{
	NVIC_Sub_Zero,
	NVIC_Sub_One,
	NVIC_Sub_Two,
	NVIC_Sub_Three,
	NVIC_Sub_Four,
	NVIC_Sub_Five,
	NVIC_Sub_Six,
	NVIC_Sub_Seven,
	NVIC_Sub_Eight,
	NVIC_Sub_Nine,
	NVIC_Sub_Ten,
	NVIC_Sub_Eleven,
	NVIC_Sub_Twelve,
	NVIC_Sub_Thirteen,
	NVIC_Sub_Fourteen,
	NVIC_Sub_Fifteen

}NVIC_Sub_Numbers;


typedef enum
{
	/* NVIC Peripherals Position */
	NVIC_Position_WWDG,
	NVIC_Position_PVD,
	NVIC_Position_TAMPER,
	NVIC_Position_RTC,
	NVIC_Position_FLASH,
	NVIC_Position_RCC,
	NVIC_Position_EXTI0,
	NVIC_Position_EXTI1,
	NVIC_Position_EXTI2,
	NVIC_Position_EXTI3,
	NVIC_Position_EXTI4,
	NVIC_Position_DMA1_Channel1,
	NVIC_Position_DMA1_Channel2,
	NVIC_Position_DMA1_Channel3,
	NVIC_Position_DMA1_Channel4,
	NVIC_Position_DMA1_Channel5,
	NVIC_Position_DMA1_Channel6,
	NVIC_Position_DMA1_Channel7,
	NVIC_Position_ADC1_2,
	NVIC_Position_USB_HP_CAN_TX,
	NVIC_Position_USB_LP_CAN_RX0,
	NVIC_Position_CAN_RX1,
	NVIC_Position_CAN_SCE,
	NVIC_Position_EXTI9_5,
	NVIC_Position_TIM1_BRK,
	NVIC_Position_TIM1_UP,
	NVIC_Position_TIM1_TRG_COM,
	NVIC_Position_TIM1_CC,
	NVIC_Position_TIM2,
	NVIC_Position_TIM3,
	NVIC_Position_TIM4,
	NVIC_Position_I2C1_EV,
	NVIC_Position_I2C1_ER,
	NVIC_Position_I2C2_EV,
	NVIC_Position_I2C2_ER,
	NVIC_Position_SPI1,
	NVIC_Position_SPI2,
	NVIC_Position_USART1,
	NVIC_Position_USART2,
	NVIC_Position_USART3,
	NVIC_Position_EXTI15_10,
	NVIC_Position_RTCAlarm,
	NVIC_Position_USBWakeup,
	NVIC_Position_TIM8_BRK,
	NVIC_Position_TIM8_UP,
	NVIC_Position_TIM8_TRG_COM,
	NVIC_Position_TIM8_CC,
	NVIC_Position_ADC3,
	NVIC_Position_FSMC,
	NVIC_Position_SDIO,
	NVIC_Position_TIM5,
	NVIC_Position_SPI3,
	NVIC_Position_UART4,
	NVIC_Position_UART5,
	NVIC_Position_TIM6,
	NVIC_Position_TIM7,
	NVIC_Position_DMA2_Channel1,
	NVIC_Position_DMA2_Channel2,
	NVIC_Position_DMA2_Channel3,
	NVIC_Position_DMA2_Channel4_5

}NVIC_Peripherals_Position;


typedef union
{

	struct
	{
		u8 Reserved : 4 ;
		u8 Group    : 4 ;

	}NVIC_16_Group_0_Sub_Access;

	struct
	{
		u8 Reserved : 4 ;
		u8 Sub      : 1 ;
		u8 Group    : 3 ;

	}NVIC_8_Group_2_Sub_Access;

	struct
	{
		u8 Reserved : 4 ;
		u8 Sub      : 2 ;
		u8 Group    : 2 ;

	}NVIC_4_Group_4_Sub_Access;

	struct
	{
		u8 Reserved : 4 ;
		u8 Sub      : 3 ;
		u8 Group    : 1 ;

	}NVIC_2_Group_8_Sub_Access;

	struct
	{
		u8 Reserved : 4 ;
		u8 Sub      : 4 ;

	}NVIC_0_Group_16_Sub_Access;


	u8 IPR_Register;

}NVIC_IPR_Configuration;



void __NVIC_Enable_Interrupt_Peripheral__(u8 NVIC_Peripheral);
void __NVIC_Disable_Interrupt_Peripheral__(u8 NVIC_Peripheral);
void __NVIC_Enable_Pending_Flag_Interrupt_Peripheral__(u8 NVIC_Peripheral);
void __NVIC_Disable_Pending_Flag_Interrupt_Peripheral__(u8 NVIC_Peripheral);
u8 __NVIC_Read_Active_Flag_Interrupt_Peripheral__(u8 NVIC_Peripheral);
void __NVIC_Init_Priority_Field__(void);

#if NVIC_Priority_Field_Configuration == NVIC_16_Group_0_Sub
	u8 __NVIC_Set_Priority__(u8 IRQ,u8 Group);
#elif NVIC_Priority_Field_Configuration == NVIC_0_Group_16_Sub
	u8 __NVIC_Set_Priority__(u8 IRQ,u8 Sub);
#else
	u8 __NVIC_Set_Priority__(u8 IRQ,u8 Group,u8 Sub);
#endif





#endif /* NVIC_INTERFACE_H_ */
