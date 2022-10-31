/*
 * AFIO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */


#include "LSTD_TYPES.h"
#include "stm32f103xx.h"
#include "AFIO_Interface.h"




u8 __AFIO_EXTI_Configuration__(const AFIO_EXIT_Configuration *Data)
{

	u8 Execution_State = Execution_Correct;

	switch (Data->EXTIx_PIN)
	{

		case AFIO_EXTI0:
			AFIO->EXTICR1.Bits_Access_EXTICR1.EXTI0 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI1:
			AFIO->EXTICR1.Bits_Access_EXTICR1.EXTI1 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI2:
			AFIO->EXTICR1.Bits_Access_EXTICR1.EXTI2 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI3:
			AFIO->EXTICR1.Bits_Access_EXTICR1.EXTI3 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI4:
			AFIO->EXTICR2.Bits_Access_EXTICR2.EXTI4 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI5:
			AFIO->EXTICR2.Bits_Access_EXTICR2.EXTI5 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI6:
			AFIO->EXTICR2.Bits_Access_EXTICR2.EXTI6 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI7:
			AFIO->EXTICR2.Bits_Access_EXTICR2.EXTI7 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI8:
			AFIO->EXTICR3.Bits_Access_EXTICR3.EXTI8 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI9:
			AFIO->EXTICR3.Bits_Access_EXTICR3.EXTI9 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI10:
			AFIO->EXTICR3.Bits_Access_EXTICR3.EXTI10 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI11:
			AFIO->EXTICR3.Bits_Access_EXTICR3.EXTI11 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI12:
			AFIO->EXTICR4.Bits_Access_EXTICR4.EXTI12 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI13:
			AFIO->EXTICR4.Bits_Access_EXTICR4.EXTI13 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI14:
			AFIO->EXTICR4.Bits_Access_EXTICR4.EXTI14 = Data->EXTI_PORT;
			break;

		case AFIO_EXTI15:
			AFIO->EXTICR4.Bits_Access_EXTICR4.EXTI15 = Data->EXTI_PORT;
			break;

		default:
			Execution_State = Execution_Error;
			break;
	}


	return Execution_State;

}
