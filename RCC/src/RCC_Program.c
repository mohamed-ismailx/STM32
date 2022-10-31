/*
 * RCC_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */
#include "LSTD_TYPES.h"
#include "Macros.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"
#include "stm32f103xx.h"


#if RCC_HSE            //HSE Clock Source

	void __RCC_HSE_Clock_Initialization(HSE_Configuration *RCC_HSE_Configuration)  //Definition Of Function To Initialization The HSE Clock
	{
		u16 Time = Null;         //Variable To Count The Time Out Mechanism For Polling
		RCC->CR.Bits_Access.CSSON = RCC_HSE_Configuration->Clock_Detector_Configuration;    //Update The Clock Detector Enable/Disable Mode To CSSON Bit
		RCC->CR.Bits_Access.HSEBYP = RCC_HSE_Configuration->HSE_Bypass_Configuration;       //Update The HSE Bypass Enable/Disable To HSEBY Bit
		RCC->CR.Bits_Access.HSEON = On;      //Enable HSE Clock
		while((!(RCC->CR.Bits_Access.HSERDY)) && ((Time++) <= RCC_Time_Out));   //Wait For HSE Clock To Be Ready with Time Out Mechanism

	} //End Of Function Of HSE Initialization

#elif RCC_HSI          //HSI Clock Source

	void __RCC_HSI_Clock_Initialization(HSI_Configuration *RCC_HSI_Configuration)  //Definition Of Function To Initialization The HSI Clock
	{
		u16 Time = Null;        //Variable To Count The Time Out Mechanism For Polling
		RCC->CR.Bits_Access.HSION = On;      //Enable HSI Clock
		while((!(RCC->CR.Bits_Access.HSIRDY)) && ((Time++) <= RCC_Time_Out));    //Wait For HSI Clock To Be Ready with Time Out Mechanism

		if(RCC_HSI_Configuration->Clock_Trimming > Null)          //Check If The Use Need To Edit The Clock Trimming
			RCC->CR.Bits_Access.HSITRIM = RCC_HSI_Configuration->Clock_Trimming;   //Update The Clock Trimming Value To HSITRIM Bits
	} //End Of Function Of HSI Initialization

#elif RCC_PLL          //PLL Clock Source

	void __RCC_PLL_Clock_Initialization(PLL_Configuration *RCC_PLL_Configuration)  //Definition Of Function To Initialization The PLL Clock
	{

		u16 Time = Null;       //Variable To Count The Time Out Mechanism For Polling

		RCC->CFGR.Bits_Access.PLLSRC = RCC_PLL_Configuration->PLL_HSI_HSE_Selection_Configuration;   //Update The Entry Clock To PLL (HSE/HSI)

		if(RCC_PLL_Configuration->PLL_HSI_HSE_Selection_Configuration == HSE_By_1)     //Check If The Entry Clock Is HSE To Configuration The Prescaler
			RCC->CFGR.Bits_Access.PLLXTPRE = RCC_PLL_Configuration->PLL_HSE_Prescaler_Configuration;   //Update The HSE Prescaler

		RCC->CFGR.Bits_Access.PLLMUL = RCC_PLL_Configuration->PLL_Multiplication_Factor_Configuration;   //Update The Multiplication Factor To PLLMUL Bits

		RCC->CR.Bits_Access.PLLON = On;  	//Enable PLL Clock
		while((RCC->CR.Bits_Access.PLLRDY) && ((Time++) <= RCC_Time_Out));    //Wait For PLL Clock To Be Ready with Time Out Mechanism

		RCC->CFGR.Bits_Access.SW = RCC_PLL_Configuration->SYSCLK_Source_Selection;  //Update The SYSCLK Source Selection(HSI/HSE/PLL) To SW Bits

		RCC->CFGR.Bits_Access.PPRE2 = RCC_PLL_Configuration->PLL_APB2_Prescaler_Configuration;  //Update The APB2 Bus Prescaler To PPRE2 Bits

		RCC->CFGR.Bits_Access.PPRE1 = RCC_PLL_Configuration->PLL_APB1_Prescaler_Configuration;  //Update The APB1 Bus Prescaler To PPRE1 Bits

		RCC->CFGR.Bits_Access.HPRE = RCC_PLL_Configuration->PLL_AHB_Prescaler_Configuration;    //Update The AHB Bus Prescaler To HPRE Bits

		RCC->CFGR.Bits_Access.ADCPRE = RCC_PLL_Configuration->PLL_ADC_Prescaler_Configuration;  //Update The ADC Prescaler To ADCPRE Bits

		RCC->CFGR.Bits_Access.USBPRE = RCC_PLL_Configuration->PLL_USB_Prescaler_Configuration;  //Update The USB Prescaler To USBPRE Bits

	}  //End Of Function Of PLL Initialization

#endif


void __RCC_MCO__(MCO *Type)        //Definition Of Function To Enable And Select Clock Of MCO
{
	RCC->CFGR.Bits_Access.MCO = Type->MCO_Type;       //Update The Selection Of MCO Mode To MCO Bits

}   //End Of The Function Of MCO Selection Clock


SYSCLK_Status __RCC_Check_System_Clock_Status__(void)    //Definition Of Function That Check System Clock Status
{
	SYSCLK_Status Status;       //Variable To Update The Status Of System Clock

	Status = RCC->CFGR.Bits_Access.SWS;    //Read The Status Of System Clock

	return Status;    //Return The Status Of System Clock

}   //End Of The Function Of Check System Clock Status


u8 __RCC_Enable_Peripheral_Clock__(Buses_Peripherals_Clock_Enable *Peripheral_Bus)    //Definition Of Function That Enable Clock Throw Peripheral
{

	u8 Execution_State = Execution_Correct;       //Variable To Indicate The Execution State In This Function

	if(Peripheral_Bus->Bus <= Max_Buses)          //Check If The Bus Is Correct Or Not
	{

		switch (Peripheral_Bus->Bus)              //Get The Bus Value
		{
			case AHB:                   //Case For AHB Bus
				Set(RCC->AHBENR,Peripheral_Bus->Peripheral);  //Enable The Clock Of Peripheral That Throw The Bus
				break;    //End Case

			case APB2:                  //Case For APB2 Bus
				Set(RCC->AHB2ENR,Peripheral_Bus->Peripheral); //Enable The Clock Of Peripheral That Throw The Bus
				break;    //End Case

			case APB1:                  //Case For APB2 Bus
				Set(RCC->AHB1ENR,Peripheral_Bus->Peripheral); //Enable The Clock Of Peripheral That Throw The Bus
				break;    //End Case
		}  //End Of Cases Configuration

	} //End Of Check Buses

	else   //If The Input Bus Is Not Correct
		Execution_State = Execution_Error;     //Update The Execution Error To The Execution State Variable


	return Execution_State;      //Return The Execution State Of This Function

}   //End Of The Function Enable Peripherals Clock


u8 __RCC_Disable_Peripheral_Clock__(Buses_Peripherals_Clock_Enable *Peripheral_Bus)   //Definition Of Function That Disable Clock Throw Peripheral
{

	u8 Execution_State = Execution_Correct;       //Variable To Indicate The Execution State In This Function

	if(Peripheral_Bus->Bus <= Max_Buses)          //Check If The Bus Is Correct Or Not
	{

		switch (Peripheral_Bus->Bus)              //Get The Bus Value
		{
			case AHB:                    //Case For AHB Bus
				Clear(RCC->AHBENR,Peripheral_Bus->Peripheral);   //Disable The Clock Of Peripheral That Throw The Bus
				break;    //End Case

			case APB2:                   //Case For APB2 Bus
				Clear(RCC->AHB2ENR,Peripheral_Bus->Peripheral);  //Disable The Clock Of Peripheral That Throw The Bus
				break;    //End Case

			case APB1:                   //Case For APB1 Bus
				Clear(RCC->AHB1ENR,Peripheral_Bus->Peripheral);  //Disable The Clock Of Peripheral That Throw The Bus
				break;    //End Case
		}   //End Of Cases Configuration

	} //End Of Check Buses

	else    //If The Input Bus Is Not Correct
		Execution_State = Execution_Error;   //Update The Execution Error To The Execution State Variable


	return Execution_State;       //Return The Execution State Of This Function

} //End Of The Function Enable Peripherals Clock



u8 __RCC_Enable_Peripherals_Clock__(u8 No_Enable_Peripheral_Clock)     //Definition Of Function To Enable Clock Throw Peripherals By The Number Of Peripherals
{

	u8 Loop,Execution_State = Execution_Correct;        //Variable To Count The No Of Peripheral, Variable To Indicate The Execution State In This Function

	for(Loop = Null;Loop<No_Enable_Peripheral_Clock;Loop++)      //Enable Peripherals Clock By Loop And Change The Parameter Of Peripheral And Bus
	{
		Execution_State = __RCC_Enable_Peripheral_Clock__(&Enable_Clock_Peripherals[Loop]);   //Call The Function Of Enable Peripheral By Bus And Peripheral Parameters
						//The Function Return The Execution State To Detect Errors

	} //End Of Loop Of Enable Peripherals


	return Execution_State;      //Return The Execution State Of This Function

}  //End Of The Function Of Enable Peripherals

