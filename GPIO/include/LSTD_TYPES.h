/**
 * @file    LSTDTYPES.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This header file contains C created data types.
 * @version 1.0
 * @date    2020-09-18
 *
 * @copyright Copyright (c) 2020
 * 
 */

/*Header file guard*/
#ifndef _LSTDTYPES_H_
#define _LSTDTYPES_H_

/*Integer 8bits data type*/
typedef unsigned char       u8;
typedef signed char         s8;

/*Integer 16bits data type*/
typedef unsigned short int u16;
typedef signed short int   s16;

/*Integer 32bits data type*/
typedef unsigned long int  u32;
typedef signed long int    s32;

/*Float 32bits data type*/
typedef float              f32;

/*Float 64bits data type*/
typedef double             f64;


#define Execution_Correct 1
#define Execution_Error 0

#define Set_Bit 1
#define Clear_Bit 0

#define Null 0
#define NULL ((void*)0)


#endif/*_LSTDTYPES_H_*/
