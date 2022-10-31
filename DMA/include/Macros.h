/*
 * Macros.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef MACROS_H_
#define MACROS_H_


#define Clear(Register,Bit) Register&=~(1<<Bit)
#define Set(Register,Bit) Register|=(1<<Bit)
#define Tog(Register,Bit) Register^=(1<<Bit)
#define Get_Bit(Register,Bit) !!(Register & (1<<Bit))
#define Write_Bit (Variable,Value) Variable=Value
#define Read(Register) Register


#define IS_PIN_SET(Register,Pin)  (Register & (1<<Pin)))
#define IS_PIN_CLR(Register,Pin)  (!(Register & (1<<Pin)))


#endif /* MACROS_H_ */
