/*
 * Macros.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

#define RCC_Time_Out 5000            //Time Out Mechanism For Polling

#define No_Enable_Peripherals 8      //No Of Peripherals Need To Enable In Function


Buses_Peripherals_Clock_Enable Enable_Clock_Peripherals[No_Enable_Peripherals] = {Null};   //Object From Structure To Define The Peripherals And Buses To Enable Clock Throw Peripherals

MCO Selection_Clock_Mode = {No_Clock};    //Object Form Structure To Configuration MCO Clock

/*  MCO  Options  */
/*------------------------*/
//	No_Clock
//	Sysclock
//	HSI
//	HSE
//	PLL


#if RCC_HSE            //HSE Clock Source

	HSE_Configuration        HSE_Initialization = {Clock_Detector_Off,HSE_Bypass_Off};   //Object From union To Configuration The HSE

// |1-Clock Detector		|2-HSE Bypass
/*--------------------------------------------------------*/
// | Clock_Detector_Off     | HSE_Bypass_Off
// | Clock_Detector_On      | HSE_Bypass_On


#elif RCC_HSI          //HSI Clock Source

	HSI_Configuration        HSI_Initialization = {Null};   //Object From union To Configuration The HSI

//  |1- Clock_Trimming
/*---------------------------------------*/
//  |  Clock Trimming Access By Value


#elif RCC_PLL          //PLL Clock Source

	PLL_Configuration        PLL_Initialization = {HSE_By_1,HSE_Not_Divided,PLL_input_clock_x_6,HSE_selected_as_system_clock,PLL_Divided_By_1_5,PCLK2_divided_by_2,HCLK2_divided_by_4,HCLK1_divided_by_4,SYSCLK_divided_by_4};   //Object From union To Configuration The PLL

// |1-HSI Or HSE   |2-HSE Prescaler      |3-Input Clock Multiplier    |4-SYSCLK Sources                  |5-USB Prescaler       |6-ADC Prescaler       |7-APB2 Prescaler        |8-APB1 Prescaler        |9-AHB Prescaler
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// |  HSI_By_2     |   HSE_Not_Divided   |  PLL_input_clock_x_2       |  HSI_selected_as_system_clock    |PLL_Divided_By_1_5    |PCLK2_divided_by_2    |HCLK2_not_divided       |HCLK1_not_divided       |SYSCLK_not_divided
// |  HSE_By_1     |   HSE_Divided_By_2  |  PLL_input_clock_x_3       |  HSE_selected_as_system_clock    |PLL_Not_Divided       |PCLK2_divided_by_4    |HCLK2_divided_by_2      |HCLK1_divided_by_2      |SYSCLK_divided_by_2
//	      		   |   HSE_Not_allowed   |  PLL_input_clock_x_4       |  PLL_selected_as_system_clock                           |PCLK2_divided_by_6    |HCLK2_divided_by_4      |HCLK1_divided_by_4      |SYSCLK_divided_by_4
//	        						     |  PLL_input_clock_x_5	      |  Not_allowed                                            |PCLK2_divided_by_8    |HCLK2_divided_by_8      |HCLK1_divided_by_8      |SYSCLK_divided_by_8
//	        						     |  PLL_input_clock_x_6                                                                                        |HCLK2_divided_by_16     |HCLK1_divided_by_16     |SYSCLK_divided_by_16
//									     |  PLL_input_clock_x_7                                                                                                                                          |SYSCLK_divided_by_64
//									     |  PLL_input_clock_x_8                                                                                                                                          |SYSCLK_divided_by_128
//									     |  PLL_input_clock_x_9                                                                                                                                          |SYSCLK_divided_by_256
//									     |  PLL_input_clock_x_10                                                                                                                                         |SYSCLK_divided_by_512
//									     |  PLL_input_clock_x_11
//									     |  PLL_input_clock_x_12
//                                       |  PLL_input_clock_x_13
//									     |  PLL_input_clock_x_14
//									     |  PLL_input_clock_x_15
//									     |  PLL_input_clock_x_16

#endif

#endif /* RCC_CONFIG_H */
