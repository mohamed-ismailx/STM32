/*
 * LEDMXD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef LEDMXD_H_
#define LEDMXD_H_


#define LEDMXD_No_Rows              8
#define LEDMXD_No_Columns           8
#define LEDMXD_No_Row_Column        8



typedef enum
{
	LEDMXD_Row_Zero,
	LEDMXD_Row_One,
	LEDMXD_Row_Two,
	LEDMXD_Row_Three,
	LEDMXD_Row_Four,
	LEDMXD_Row_Five,
	LEDMXD_Row_Six,
	LEDMXD_Row_Seven

}LEDMXD_Rows;


typedef enum
{
	LEDMXD_Column_Zero,
	LEDMXD_Column_One,
	LEDMXD_Column_Two,
	LEDMXD_Column_Three,
	LEDMXD_Column_Four,
	LEDMXD_Column_Five,
	LEDMXD_Column_Six,
	LEDMXD_Column_Seven

}LEDMXD_Columns;




typedef enum
{
	LEDMXD_Row_Zero_Pin = Pin_Eight,
	LEDMXD_Row_One_Pin = Pin_Nine,
	LEDMXD_Row_Two_Pin = Pin_Ten,
	LEDMXD_Row_Three_Pin = Pin_Eleven,
	LEDMXD_Row_Four_Pin = Pin_Twelve,
	LEDMXD_Row_Five_Pin = Pin_Thirteen,
	LEDMXD_Row_Six_Pin = Pin_FourTeen,
	LEDMXD_Row_Seven_Pin = Pin_Fifteen

}LEDMXD_Rows_Pins;




typedef enum
{
	LEDMXD_Row_Zero_Port = GPIOB,
	LEDMXD_Row_One_Port = GPIOB,
	LEDMXD_Row_Two_Port = GPIOB,
	LEDMXD_Row_Three_Port = GPIOB,
	LEDMXD_Row_Four_Port = GPIOB,
	LEDMXD_Row_Five_Port = GPIOB,
	LEDMXD_Row_Six_Port = GPIOB,
	LEDMXD_Row_Seven_Port = GPIOB

}LEDMXD_Rows_Ports;


typedef enum
{
	LEDMXD_Column_Zero_Pin = Pin_Zero,
	LEDMXD_Column_One_Pin = Pin_One,
	LEDMXD_Column_Two_Pin = Pin_Two,
	LEDMXD_Column_Three_Pin = Pin_Three,
	LEDMXD_Column_Four_Pin = Pin_Four,
	LEDMXD_Column_Five_Pin = Pin_Five,
	LEDMXD_Column_Six_Pin  = Pin_Six,
	LEDMXD_Column_Seven_Pin = Pin_Seven

}LEDMXD_Columns_Pins;



typedef enum
{
	LEDMXD_Column_Zero_Port = GPIOA,
	LEDMXD_Column_One_Port = GPIOA,
	LEDMXD_Column_Two_Port = GPIOA,
	LEDMXD_Column_Three_Port = GPIOA,
	LEDMXD_Column_Four_Port = GPIOA,
	LEDMXD_Column_Five_Port = GPIOA,
	LEDMXD_Column_Six_Port  = GPIOA,
	LEDMXD_Column_Seven_Port = GPIOA

}LEDMXD_Columns_Ports;





void __LEDMXD_Initialization__(void);
void __LEDMXD_Disable_Columns__(void);
void __LEDMXD_Disable_Rows__(void);
void __LEDMXD_Display__(u8 *Character);
void __LEDMXD_Set_Rows__(u8 *Row);





#endif /* LEDMXD_H_ */
