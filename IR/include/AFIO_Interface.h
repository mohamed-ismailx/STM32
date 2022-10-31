/*
 * AFIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_



typedef enum
{
	AFIO_EXTI0,
	AFIO_EXTI1,
	AFIO_EXTI2,
	AFIO_EXTI3,
	AFIO_EXTI4,
	AFIO_EXTI5,
	AFIO_EXTI6,
	AFIO_EXTI7,
	AFIO_EXTI8,
	AFIO_EXTI9,
	AFIO_EXTI10,
	AFIO_EXTI11,
	AFIO_EXTI12,
	AFIO_EXTI13,
	AFIO_EXTI14,
	AFIO_EXTI15

}AFIO_EXITx_PIN;


typedef enum
{
	AFIO_EXTI_PORTA,
	AFIO_EXTI_PORTB,
	AFIO_EXTI_PORTC,
	AFIO_EXTI_PORTD,
	AFIO_EXTI_PORTE,
	AFIO_EXTI_PORTF,
	AFIO_EXTI_PORTG

}AFIO_EXTI_PORT;




typedef struct
{
	AFIO_EXITx_PIN       EXTIx_PIN;
	AFIO_EXTI_PORT   EXTI_PORT;

}AFIO_EXIT_Configuration;


u8 __AFIO_EXTI_Configuration__(const AFIO_EXIT_Configuration *Data);



#endif /* AFIO_INTERFACE_H_ */
