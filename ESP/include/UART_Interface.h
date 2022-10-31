/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef UART_H_
#define UART_H_


#define No_Of_UART_One_Pins     2


#define UART_One_Tx_Pin    9
#define UART_One_Rx_Pin    10

#define UART_One_Tx_Port    0
#define UART_One_Rx_Port    0


typedef enum
{
	UART_One_Baud_Rate_9800 = 0x341,
	UART_One_Baud_Rate_115200 = 0x45

}UART_One_Baud_Rate;



typedef enum
{
	UART_One_Data_Size_8_bit,
	UART_One_Data_Size_9_bit

}UART_One_Data_Size;



typedef enum
{
	UART_One_1_Stop_Bit,
	UART_One_0_5_Stop_Bit,
	UART_One_2_Stop_Bit,
	UART_One_1_5_Stop_Bit

}UART_One_Stop_Bit;



typedef struct
{
	UART_One_Baud_Rate Baud_Rate;
	UART_One_Data_Size Data_Size;
	UART_One_Stop_Bit Stop_Bit;


}UART_One_Configuartion;



u8 __UART_One_Initialization__(UART_One_Configuartion *Data);
u8 __UART_One_Transmit_Data__(char *Data);
void __UART_One_Receive_Data__(u8 *Data);


void __UART_One_Receive_Data_ESP__(u8 *Data);


#endif /* UART_H_ */
