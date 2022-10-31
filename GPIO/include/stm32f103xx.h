/*
 * Macros.h
 *
 *  Created on: ??�/??�/????
 *      Author: kcsstore.com
 */

#ifndef STM32F103XX_H
#define STM32F103XX_H

/*************************************************************************************************/

/*********************************      RCC Registers      ***************************************/

#define RCC_Base_Address   0x40021000    //RCC Peripheral Base Address

/*  CR Register Bits By Structure */

typedef struct
{
	u32 HSION:1;            //One Bit For HSI Enable/Disable
	u32 HSIRDY:2;           //One Bit For HSI Flag One Reserved Bit
	u32 HSITRIM:5;          //Five Bits For HSI Clock Trimming Configuration
	u32 HSICAL:8;			//Eight Bits For calibration At Startup Code
	u32 HSEON:1; 			//One Bit For HSE Enable/Disable
	u32 HSERDY:1;			//One Bit For HSE Flag
	u32 HSEBYP:1; 			//One Bit For HSE Bypass Enable/Disable
	u32 CSSON:5;			//One Bits For Clock Detector Enable/Disable And Four Reserved Bits
	u32 PLLON:1;            //One Bit For PLL Enable/Disable
	u32 PLLRDY:7;			//One Bit For PLL Flag And Six Reserved Bits

}CR_Bits;

/*  CFGR Register Bits By Structure */

typedef struct
{
	u32 SW:2;               //Two Bits For System Clock Switch Configuration
	u32 SWS:2;				//Two Bits For Read System Clock Switch Status
	u32 HPRE:4;				//Four Bits For AHB Prescaler Configuration
	u32 PPRE1:3;			//Three Bits For APB Low-Speed Prescaler Configuration
	u32 PPRE2:3;			//Three Bits For APB High-Speed Prescaler Configuration
	u32 ADCPRE:2;			//Two Bits For ADC prescaler Configuration
	u32 PLLSRC:1;			//One Bit For PLL Entry Clock Source Configuration
	u32 PLLXTPRE:1;			//One Bit For HSE Divider For PLL Entry Configuration
	u32 PLLMUL:4;			//Four Bits For PLL Multiplication Factor Configuration
	u32 USBPRE:2;      		//One Bit For USB Prescaler Configuration And One Reserved Bit
	u32 MCO:8;              //Three Bits For Microcontroller Clock Output Configuration And Five Reserved Bits

}CFGR_Bits;

/*   union To Mix The Size Between Register And His Bits   */

typedef union
{
	u32 Register_Access;      //Variable To Access All Register
	CR_Bits Bits_Access;	  //Object From Structure Bit To Access Register Bits

}CR_Access;                   //Register And Bits For CR Register


typedef union
{
	u32 Register_Access;      //Variable To Access All Register
	CFGR_Bits Bits_Access;    //Object From Structure Bit To Access Register Bits

}CFGR_Access;                 //Register And Bits For CFGR Register


/*    Structure For RCC Register Handling    */

typedef struct 
{
	volatile CR_Access CR;          	  //Clock Control Register By Base Address
	volatile CFGR_Access CFGR;		  //Clock Configuration Register
	volatile u32 CIR;				  //Clock Interrupt Register
	volatile u32 APB2RSTR;			  //APB2 Peripheral Reset Register
	volatile u32 APB1RSTR;			  //APB1 Peripheral Reset Register
	volatile u32 AHBENR;               //AHB Peripheral Clock Enable Register
	volatile u32 AHB2ENR;              //APB2 Peripheral Clock Enable Register
	volatile u32 AHB1ENR;              //APB1 Peripheral Clock Enable Register
	volatile u32 BDCR;                 //Backup Domain Control Register
	volatile u32 CSR;                  //Control/Status Register

}RCC_Registers;

#define RCC ((RCC_Registers *) RCC_Base_Address)       //Pointer To Structure To Access RCC Registers By Base Address


/**************************************************************************************************/

/*********************************      GPIO Registers      ***************************************/



/*  CRL Register Bits By Structure */

typedef struct
{
	u32 CNF_MODE0:4;               //Select Configuration And Mode (Input/Output) For Bit 0
	u32 CNF_MODE1:4;			   //Select Configuration And Mode (Input/Output) For Bit 1
	u32 CNF_MODE2:4;			   //Select Configuration And Mode (Input/Output) For Bit 2
	u32 CNF_MODE3:4;			   //Select Configuration And Mode (Input/Output) For Bit 3
	u32 CNF_MODE4:4;			   //Select Configuration And Mode (Input/Output) For Bit 4
	u32 CNF_MODE5:4;			   //Select Configuration And Mode (Input/Output) For Bit 5
	u32 CNF_MODE6:4;			   //Select Configuration And Mode (Input/Output) For Bit 6
	u32 CNF_MODE7:4;			   //Select Configuration And Mode (Input/Output) For Bit 7

}CRL_Bits;



/*  CRH Register Bits By Structure */

typedef struct
{
	u32 CNF_MODE8:4;               //Select Configuration And Mode (Input/Output) For Bit 8
	u32 CNF_MODE9:4;			   //Select Configuration And Mode (Input/Output) For Bit 9
	u32 CNF_MODE10:4;			   //Select Configuration And Mode (Input/Output) For Bit 10
	u32 CNF_MODE11:4;			   //Select Configuration And Mode (Input/Output) For Bit 11
	u32 CNF_MODE12:4;			   //Select Configuration And Mode (Input/Output) For Bit 12
	u32 CNF_MODE13:4;			   //Select Configuration And Mode (Input/Output) For Bit 13
	u32 CNF_MODE14:4;			   //Select Configuration And Mode (Input/Output) For Bit 14
	u32 CNF_MODE15:4;			   //Select Configuration And Mode (Input/Output) For Bit 15

}CRH_Bits;



/*  IDR Register Bits By Structure */

typedef struct
{
	u32 IDR0:1;				   //Read Operation For Bit 0
	u32 IDR1:1;				   //Read Operation For Bit 1
	u32 IDR2:1;				   //Read Operation For Bit 2
	u32 IDR3:1;				   //Read Operation For Bit 3
	u32 IDR4:1;				   //Read Operation For Bit 4
	u32 IDR5:1;				   //Read Operation For Bit 5
	u32 IDR6:1;				   //Read Operation For Bit 6
	u32 IDR7:1;				   //Read Operation For Bit 7
	u32 IDR8:1;				   //Read Operation For Bit 8
	u32 IDR9:1;				   //Read Operation For Bit 9
	u32 IDR10:1;			   //Read Operation For Bit 10
	u32 IDR11:1;			   //Read Operation For Bit 11
	u32 IDR12:1;			   //Read Operation For Bit 12
	u32 IDR13:1;			   //Read Operation For Bit 13
	u32 IDR14:1;			   //Read Operation For Bit 14
	u32 IDR15:17;		       //Read Operation For Bit 15

}IDR_Bits;


/*  ODR Register Bits By Structure */

typedef struct
{
	u32 ODR0:1;				   //Configuration Of Output Mode For Bit 0
	u32 ODR1:1;                //Configuration Of Output Mode For Bit 1
	u32 ODR2:1;                //Configuration Of Output Mode For Bit 2
	u32 ODR3:1;                //Configuration Of Output Mode For Bit 3
	u32 ODR4:1;                //Configuration Of Output Mode For Bit 4
	u32 ODR5:1;                //Configuration Of Output Mode For Bit 5
	u32 ODR6:1;                //Configuration Of Output Mode For Bit 6
	u32 ODR7:1;                //Configuration Of Output Mode For Bit 7
	u32 ODR8:1;                //Configuration Of Output Mode For Bit 8
	u32 ODR9:1;                //Configuration Of Output Mode For Bit 9
	u32 ODR10:1;               //Configuration Of Output Mode For Bit 10
	u32 ODR11:1;               //Configuration Of Output Mode For Bit 11
	u32 ODR12:1;               //Configuration Of Output Mode For Bit 12
	u32 ODR13:1;               //Configuration Of Output Mode For Bit 13
	u32 ODR14:1;               //Configuration Of Output Mode For Bit 14
	u32 ODR15:17;              //Configuration Of Output Mode For Bit 15

}ODR_Bits;


/*  LCKR Register Bits By Structure */

typedef struct
{
	u32 LCK0:1;				   //Lock The Configuration of the Bit 0
	u32 LCK1:1;				   //Lock The Configuration of the Bit 1
	u32 LCK2:1;				   //Lock The Configuration of the Bit 2
	u32 LCK3:1;				   //Lock The Configuration of the Bit 3
	u32 LCK4:1;				   //Lock The Configuration of the Bit 4
	u32 LCK5:1;				   //Lock The Configuration of the Bit 5
	u32 LCK6:1;				   //Lock The Configuration of the Bit 6
	u32 LCK7:1;				   //Lock The Configuration of the Bit 7
	u32 LCK8:1;				   //Lock The Configuration of the Bit 8
	u32 LCK9:1;				   //Lock The Configuration of the Bit 9
	u32 LCK10:1;			   //Lock The Configuration of the Bit 10
	u32 LCK11:1;			   //Lock The Configuration of the Bit 11
	u32 LCK12:1;			   //Lock The Configuration of the Bit 12
	u32 LCK13:1;			   //Lock The Configuration of the Bit 13
	u32 LCK14:1;			   //Lock The Configuration of the Bit 14
	u32 LCK15:1;			   //Lock The Configuration of the Bit 15
	u32 LCKK:16;			   //This Bit Confirm The Lock Of Bits Selected

}LCKR_Bits;


/*   union To Mix The Size Between Register And His Bits   */

typedef union
{
	u32 Register_Access;      //Variable To Access All Register
	CRL_Bits Bits_Access;	  //Object From Structure Bit To Access Register Bits

}CRL_Access;                  //Register And Bits For CR Register



/*   union To Mix The Size Between Register And His Bits   */

typedef union
{
	u32 Register_Access;      //Variable To Access All Register
	CRH_Bits Bits_Access;	  //Object From Structure Bit To Access Register Bits

}CRH_Access;                  //Register And Bits For CR Register



/*   union To Mix The Size Between Register And His Bits   */

typedef union
{
	u32 Register_Access;      //Variable To Access All Register
	IDR_Bits Bits_Access;	  //Object From Structure Bit To Access Register Bits

}IDR_Access;                  //Register And Bits For CR Register



/*   union To Mix The Size Between Register And His Bits   */

typedef union
{
	u32 Register_Access;      //Variable To Access All Register
	ODR_Bits Bits_Access;	  //Object From Structure Bit To Access Register Bits

}ODR_Access;                  //Register And Bits For CR Register


/*   union To Mix The Size Between Register And His Bits   */

typedef union
{
	u32 Register_Access;      //Variable To Access All Register
	LCKR_Bits Bits_Access;	  //Object From Structure Bit To Access Register Bits

}LCKR_Access;                 //Register And Bits For CR Register


/*    Structure For GPIO Register Handling    */

typedef struct
{
	volatile CRL_Access CRL;		   	   //Port Configuration Register Low For First 8 Bit (0 --> 7)
	volatile CRH_Access CRH;		       //Port Configuration Register HIGH For Last 8 Bit (8 --> 15)
	volatile IDR_Access IDR;		       //Port Input Data Register For Read Input Data On Pin
	volatile ODR_Access ODR;		       //Port Output Data Register For Configuration The Output State (High/Low) || --> For Pull Up (1) High (0) Low || --> For Open Drain (1) Floating (0) Low
	volatile u32 BSRR;				       //Port Bit Set/Reset Register For Configuration ODR Atomic Access By High State (1)
	volatile u32 BRR;				       //Port Bit Reset Register For Configuration ODR Atomic Access By Low State (0)
	volatile LCKR_Access LCKR;		       //Port Configuration Lock Register For Lock Bit Configuration In RunTime

}GPIO_Registers;

#define GPIOC_Base_Address     ((GPIO_Registers*)0x40011000)    //Pointer To Structure To Access GPIO Registers By Base Address Of GPIOA
#define GPIOB_Base_Address     ((GPIO_Registers*)0x40010C00)	 //Pointer To Structure To Access GPIO Registers By Base Address Of GPIOB
#define GPIOA_Base_Address     ((GPIO_Registers*)0x40010800)    //Pointer To Structure To Access GPIO Registers By Base Address Of GPIOC



/**************************************************************************************************/


#endif /* STM32F103XX_H */
