/*
 * GPIO_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */


#include "Macros.h"
#include "LSTD_TYPES.h"
#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "stm32f103xx.h"


static GPIO_Registers *GPIOx[No_GPIOx] = {GPIOA_Base_Address,GPIOB_Base_Address,GPIOC_Base_Address};  //Array Of Pointers To Structure To Access GPIO Registers By Base Address Of GPIOA,GPIOB And GPIOC


u8 __GPIO_Set_Pin_Direction__(const GPIO_Pin_Initialization *Data)  //Definition Of Function That Configuration The Pin Direction
{

	u8 Execution_State = Execution_Correct;         //Variable To Check Error In The Function

	if(Data != NULL)      //Check If The Content Of Structure Is Not Empty And It Hold The Address
	{

		switch(Data->Pinx)        //Switching The Value Of Pinx That In Structure
		{

		case Pin_Zero:      //case Pin Is Zero
			GPIOx[Data->Portx]->CRL.Bits_Access.CNF_MODE0 = Data->Modex;   //Take The Port Data And Update The Mode To Pin Zero
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR0 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR0 = Set_Bit : Null;     //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin Zero
			break;   //End Case For Pin Zero

		case Pin_One:      //case Pin Is One
			GPIOx[Data->Portx]->CRL.Bits_Access.CNF_MODE1 = Data->Modex;   //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR1 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR1 = Set_Bit : Null;     //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Two:      //case Pin Is Two
			GPIOx[Data->Portx]->CRL.Bits_Access.CNF_MODE2 = Data->Modex;   //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR2 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR2 = Set_Bit : Null;     //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Three:    //case Pin Is Three
			GPIOx[Data->Portx]->CRL.Bits_Access.CNF_MODE3 = Data->Modex;   //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR3 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR3 = Set_Bit : Null;     //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Four:     //case Pin Is Four
			GPIOx[Data->Portx]->CRL.Bits_Access.CNF_MODE4 = Data->Modex;   //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR4 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR4 = Set_Bit : Null;     //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Five:     //case Pin Is Five
			GPIOx[Data->Portx]->CRL.Bits_Access.CNF_MODE5 = Data->Modex;   //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR5 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR5 = Set_Bit : Null;     //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Six:      //case Pin Is Six
			GPIOx[Data->Portx]->CRL.Bits_Access.CNF_MODE6 = Data->Modex;   //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR6 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR6 = Set_Bit : Null;     //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Seven:    //case Pin Is Seven
			GPIOx[Data->Portx]->CRL.Bits_Access.CNF_MODE7 = Data->Modex;   //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR7 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR7 = Set_Bit : Null;     //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Eight:    //case Pin Is Eight
			GPIOx[Data->Portx]->CRH.Bits_Access.CNF_MODE8 = Data->Modex;   //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR8 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR8 = Set_Bit : Null;     //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Nine:     //case Pin Is Nine
			GPIOx[Data->Portx]->CRH.Bits_Access.CNF_MODE9 = Data->Modex;   //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR9 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR9 = Set_Bit : Null;     //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Ten:      //case Pin Is Ten
			GPIOx[Data->Portx]->CRH.Bits_Access.CNF_MODE10 = Data->Modex;  //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR10 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR10 = Set_Bit : Null;   //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Eleven:   //case Pin Is Eleven
			GPIOx[Data->Portx]->CRH.Bits_Access.CNF_MODE11 = Data->Modex;  //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR11 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR11 = Set_Bit : Null;   //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Twelve:   //case Pin Is Twelve
			GPIOx[Data->Portx]->CRH.Bits_Access.CNF_MODE12 = Data->Modex;  //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR12 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR12 = Set_Bit : Null;   //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Thirteen: //case Pin Is Thirteen
			GPIOx[Data->Portx]->CRH.Bits_Access.CNF_MODE13 = Data->Modex;  //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR13 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR13 = Set_Bit : Null;   //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_FourTeen: //case Pin Is Fourteen
			GPIOx[Data->Portx]->CRH.Bits_Access.CNF_MODE14 = Data->Modex;  //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR14 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR14 = Set_Bit : Null;   //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		case Pin_Fifteen:  //case Pin Is Fifteen
			GPIOx[Data->Portx]->CRH.Bits_Access.CNF_MODE15 = Data->Modex;  //Take The Port Data And Update The Mode To Pin
			Data->Modex == Input_PullDown?  GPIOx[Data->Portx]->ODR.Bits_Access.ODR15 = Clear_Bit : Data->Modex == Input_PullUp? GPIOx[Data->Portx]->ODR.Bits_Access.ODR15 = Set_Bit : Null;   //Check If The Mode Is Input Pullup / PullDown  And Update The Mode To Pin
			break;   //End Case

		default:      //Default The Pin Value Is Error
			Execution_State = Execution_Error;      //Update The Error State To The Variable
			break;   //End Default
		}   //End Switch
	}    //End If

	else          //Else The Structure Is Empty Address
		Execution_State = Execution_Error;          //Update The Error State To The Variable

	return Execution_State;    //Return The Error State

}    //End Function Of Pin Direction


u8 __GPIO_Write_Pin_HIGH__(const GPIO_Pin_Initialization *Data)       //Definition Of Function That Configuration The Pin Output (HIGH)
{

	u8 Execution_State = Execution_Correct;    //Variable To Check Error In The Function

	if(Data != NULL)     //Check If The Content Of Structure Is Not Empty And It Hold The Address
	{

		switch(Data->Pinx)    //Switching The Value Of Pinx That In Structure
		{

		case Pin_Zero:      //case Pin Is Zero
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR0 = HIGH;
			break;   //End Case

		case Pin_One:       //case Pin Is One
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR1 = HIGH;
			break;   //End Case

		case Pin_Two:	    //case Pin Is Two
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR2 = HIGH;
			break;   //End Case

		case Pin_Three:     //case Pin Is Three
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR3 = HIGH;
			break;   //End Case

		case Pin_Four:      //case Pin Is Four
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR4 = HIGH;
			break;   //End Case

		case Pin_Five:      //case Pin Is Five
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR5 = HIGH;
			break;   //End Case

		case Pin_Six:       //case Pin Is Six
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR6 = HIGH;
			break;   //End Case

		case Pin_Seven:     //case Pin Is Seven
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR7 = HIGH;
			break;   //End Case

		case Pin_Eight:     //case Pin Is Eight
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR8 = HIGH;
			break;   //End Case

		case Pin_Nine:      //case Pin Is Nine
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR9 = HIGH;
			break;   //End Case

		case Pin_Ten:       //case Pin Is Ten
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR10 = HIGH;
			break;   //End Case

		case Pin_Eleven:    //case Pin Is Eleven
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR11 = HIGH;
			break;   //End Case

		case Pin_Twelve:    //case Pin Is Twelve
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR12 = HIGH;
			break;   //End Case

		case Pin_Thirteen:  //case Pin Is Thirteen
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR13 = HIGH;
			break;   //End Case

		case Pin_FourTeen:  //case Pin Is FourTeen
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR14 = HIGH;
			break;   //End Case

		case Pin_Fifteen:  //case Pin Is Fifteen
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR15 = HIGH;
			break;   //End Case

		default:
			Execution_State = Execution_Error;
			break;   //End Case
		}
	}

	else
		Execution_State = Execution_Error;

	return Execution_State;


}


u8 __GPIO_Write_Pin_LOW__(const GPIO_Pin_Initialization *Data)
{

	u8 Execution_State = Execution_Correct;

	if(Data != NULL)
	{

		switch(Data->Pinx)
		{

		case Pin_Zero:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR0 = LOW;
			break;

		case Pin_One:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR1 = LOW;
			break;

		case Pin_Two:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR2 = LOW;
			break;

		case Pin_Three:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR3 = LOW;
			break;

		case Pin_Four:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR4 = LOW;
			break;

		case Pin_Five:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR5 = LOW;
			break;

		case Pin_Six:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR6 = LOW;
			break;

		case Pin_Seven:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR7 = LOW;
			break;

		case Pin_Eight:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR8 = LOW;
			break;

		case Pin_Nine:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR9 = LOW;
			break;

		case Pin_Ten:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR10 = LOW;
			break;

		case Pin_Eleven:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR11 = LOW;
			break;

		case Pin_Twelve:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR12 = LOW;
			break;

		case Pin_Thirteen:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR13 = LOW;
			break;

		case Pin_FourTeen:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR14 = LOW;
			break;

		case Pin_Fifteen:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR15 = LOW;
			break;

		default:
			Execution_State = Execution_Error;
			break;
		}
	}

	else
		Execution_State = Execution_Error;

	return Execution_State;


}



u8 __GPIO_Toggle_Pin__(const GPIO_Pin_Initialization *Data)
{

	u8 Execution_State = Execution_Correct;

	if(Data != NULL)
	{

		switch(Data->Pinx)
		{

		case Pin_Zero:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR0 ^= HIGH;
			break;

		case Pin_One:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR1 ^= HIGH;
			break;

		case Pin_Two:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR2 ^= HIGH;
			break;

		case Pin_Three:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR3 ^= HIGH;
			break;

		case Pin_Four:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR4 ^= HIGH;
			break;

		case Pin_Five:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR5 ^= HIGH;
			break;

		case Pin_Six:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR6 ^= HIGH;
			break;

		case Pin_Seven:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR7 ^= HIGH;
			break;

		case Pin_Eight:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR8 ^= HIGH;
			break;

		case Pin_Nine:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR9 ^= HIGH;
			break;

		case Pin_Ten:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR10 ^= HIGH;
			break;

		case Pin_Eleven:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR11 ^= HIGH;
			break;

		case Pin_Twelve:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR12 ^= HIGH;
			break;

		case Pin_Thirteen:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR13 ^= HIGH;
			break;

		case Pin_FourTeen:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR14 ^= HIGH;
			break;

		case Pin_Fifteen:
			GPIOx[Data->Portx]->ODR.Bits_Access.ODR15 ^= HIGH;
			break;

		default:
			Execution_State = Execution_Error;
			break;
		}
	}

	else
		Execution_State = Execution_Error;

	return Execution_State;

}


u8 __GPIO_Read_Pin__(const GPIO_Pin_Initialization *Data)
{
	u8 Execution_State = Execution_Correct;
	u8 Pin_Value;

	if(Data != NULL)
	{

		switch(Data->Pinx)
		{

		case Pin_Zero:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR0;
			break;

		case Pin_One:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR1;
			break;

		case Pin_Two:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR2;
			break;

		case Pin_Three:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR3;
			break;

		case Pin_Four:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR4;
			break;

		case Pin_Five:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR5;
			break;

		case Pin_Six:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR6;
			break;

		case Pin_Seven:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR7;
			break;

		case Pin_Eight:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR8;
			break;

		case Pin_Nine:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR9;
			break;

		case Pin_Ten:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR10;
			break;

		case Pin_Eleven:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR11;
			break;

		case Pin_Twelve:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR12;
			break;

		case Pin_Thirteen:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR13;
			break;

		case Pin_FourTeen:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR14;
			break;

		case Pin_Fifteen:
			Pin_Value = GPIOx[Data->Portx]->IDR.Bits_Access.IDR15;
			break;

		default:
			Execution_State = Execution_Error;
			break;
		}
	}

	else
		Execution_State = Execution_Error;


	return Execution_State == Execution_Error? Execution_State: Pin_Value;
}


u8 __GPIO_Set_Port_Direction__(const GPIO_Port_Initialization *Data)
{
	u8 Execution_State = Execution_Correct;
	u8 Loop;

	if((Data != NULL) && (Data->Portx < No_GPIOx))
	{
		GPIOx[Data->Portx]->CRL.Register_Access = Null;
		GPIOx[Data->Portx]->CRH.Register_Access = Null;

		for(Loop = Null;Loop <= No_Pinx;Loop++)
		{
				GPIOx[Data->Portx]->CRL.Register_Access |= (Data->Modex << (Loop * 4));
				GPIOx[Data->Portx]->CRH.Register_Access |= (Data->Modex << (Loop * 4));
		}
	}

	return Execution_State;

}



u8 __GPIO_Write_Port_HIGH__(const GPIO_Port_Initialization *Data)
{

	u8 Execution_State = Execution_Correct;

	if(Data != NULL)
		GPIOx[Data->Portx]->ODR.Register_Access = 0x0000FFFF;

	else
		Execution_State = Execution_Error;

	return Execution_State;
}


u8 __GPIO_Write_Port_LOW__(const GPIO_Port_Initialization *Data)
{

	u8 Execution_State = Execution_Correct;

	if(Data != NULL)
		GPIOx[Data->Portx]->ODR.Register_Access = 0x00000000;

	else
		Execution_State = Execution_Error;

	return Execution_State;

}


u8 __GPIO_Read_Port__(const GPIO_Port_Initialization *Data)
{

	u32 Execution_State = Execution_Correct;
	u8 Port_Value;

	if(Data != NULL)
		Port_Value = GPIOx[Data->Portx]->IDR.Register_Access;

	else
		Execution_State = Execution_Error;

	return Execution_State == Execution_Error? Execution_State: Port_Value;
}


u8 __GPIO_Toggel_Port__(const GPIO_Port_Initialization *Data)
{
	u32 Execution_State = Execution_Correct;

	if(Data != NULL)
		GPIOx[Data->Portx]->ODR.Register_Access ^= 0x0000FFFF;

	else
		Execution_State = Execution_Error;

	return Execution_State;

}

u8 __GPIO_Reverse_Port__(const GPIO_Port_Initialization *Data)
{
	u32 Execution_State = Execution_Correct;

	if(Data != NULL)
		GPIOx[Data->Portx]->ODR.Register_Access = ~GPIOx[Data->Portx]->ODR.Register_Access;

	else
		Execution_State = Execution_Error;

	return Execution_State;

}

