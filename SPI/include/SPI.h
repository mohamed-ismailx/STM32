/*
 * SPI.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef SPI_H_
#define SPI_H_


#define Data_Phase_No_CRC      0
#define Next_Transfer_Is_CRC   1
#define SPI_One_No_Pins        3

#define SPI_One_No_Remapping   0
#define SPI_One_Remapping      1

#define SPI_One_Mapping     SPI_One_No_Remapping



#if SPI_One_Mapping == SPI_One_No_Remapping

typedef enum
{
	/* Pin */
	SPI_One_SCK_Pin = Pin_Five,
	SPI_One_MOSI_Pin = Pin_Seven,
	SPI_One_MISO_Pin = Pin_Six,
	SPIO_One_NSS_Pin = Pin_Four,

	/* Port */
	SPI_One_SCK_Port = GPIOA,
	SPI_One_MOSI_Port = GPIOA,
	SPI_One_MISO_Port = GPIOA,
	SPIO_One_NSS_Port = GPIOA

}SPI_One_Pins;



#else

typedef enum
{
	/* Pin */
	SPI_One_SCK_Pin = Pin_Three,
	SPI_One_MOSI_Pin = Pin_Five,
	SPI_One_MISO_Pin = Pin_Four,
	SPIO_One_NSS_Pin = Pin_Fifteen,

	/* Port */
	SPI_One_SCK_Port = GPIOB,
	SPI_One_MOSI_Port = GPIOB,
	SPI_One_MISO_Port = GPIOB,
	SPIO_One_NSS_Port = GPIOA

}SPI_One_Pins;

#endif


typedef enum
{
	Two_Line_Unidirectional_Data_Mode_Selected,
	One_Line_Unidirectional_Data_Mode_Selected

}SPI_One_Bidirectional;


typedef enum
{
	Output_Disabled,
	Output_Enabled

}SPI_One_Bidirectional_Output;


typedef enum
{
	CRC_Calculation_Disabled,
	CRC_Calculation_Enabled

}SPI_One_CRC_Enable;


typedef enum
{
	Data_Frame_Format_8_Bit,
	Data_Frame_Format_16_Bit

}SPI_One_Data_Frame_Format;



typedef enum
{
	Full_Duplex,
	Receive_Only

}SPI_One_Data_Direction;




typedef enum
{
	Software_Slave_Management_Disabled_HW_NSS_Out_For_PA4,
	Software_Slave_Management_Enabled_NSS_VCC,
	Software_Slave_Management_Enabled_NSS_GND

}SPI_One_SSM;


typedef enum
{
	SPI_One_MSB,
	SPI_One_LSB

}SPI_One_Frame_Format;




typedef enum
{
	 Baud_Rate_fPCLK_Per_2,
	 Baud_Rate_fPCLK_Per_4,
	 Baud_Rate_fPCLK_Per_8,
	 Baud_Rate_fPCLK_Per_16,
	 Baud_Rate_fPCLK_Per_32,
	 Baud_Rate_fPCLK_Per_64,
	 Baud_Rate_fPCLK_Per_128,
	 Baud_Rate_fPCLK_Per_256

}SPI_One_Baud_Rate;



typedef enum
{
	SPI_One_Slave,
	SPI_One_Master

}SPI_One_Master_Slave;




typedef enum
{
	Clk_Start_Rising_Write_Falling_Read,
	Clk_Start_Rising_Read_Falling_Write,
	Clk_Start_Falling_Read_Rising_Write,
	Clk_Start_Falling_Write_Rising_Read

}SPI_One_Clk_Format;



typedef struct
{
	SPI_One_Master_Slave							Master_Slave_Selection;
	SPI_One_Bidirectional   						Bidirectional;
	SPI_One_Bidirectional_Output			 		Bidirectional_Output;
	u16												CRC_Polynomial;
	SPI_One_CRC_Enable 		    					CRC;
	SPI_One_Data_Frame_Format  						Data_Frame_Format;
	SPI_One_Data_Direction							Data_Direction;
	SPI_One_SSM                 					SSM;
	SPI_One_Frame_Format							Frame_Format;
	SPI_One_Baud_Rate								Baud_Rate;
	SPI_One_Clk_Format								Clk_Format;

}SPI_One_Configuration;



u8 __SPI_One_Initialization__(SPI_One_Configuration *Data);
u8 __SPI_One_Transmission_Reception_Data__(u8 Tx_Data,u8 *Rx_Data);
u8 __SPI_One_Transmission_Reception_Data_Ach__(u8 Tx_Data,u8 *Rx_Data,void (*SPI_One_ptr)(void));
void __SPI_One_Disable_CRC__(void);



#endif /* SPI_H_ */
