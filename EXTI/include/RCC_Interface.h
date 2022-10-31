/*
 * Macros.h
 *
 *  Created on: ??�/??�/????
 *      Author: kcsstore.com
 */

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H



#define Enable  1              //Macro Used To Switching The System Clock
#define Disable  0			   //Macro Used To Switching The System Clock

#define On  1                  //Macro Used To Enable Clock Selection In Bit Register
#define Off  0                 //Macro Used To Disable Clock Selection In Bit Register


#define RCC_HSI    Disable     //Macro Used To Chose HSI To Be The System Clock Of Microcontroller
#define RCC_HSE    Enable     //Macro Used To Chose HSE To Be The System Clock Of Microcontroller
#define RCC_PLL    Disable      //Macro Used To Chose PLL To Be The System Clock Of Microcontroller


#define  Max_Buses 3         //Max Number Of The Buses Which Connect All The Peripherals

typedef enum                 //Definition For The Buses
{
    AHB,                     //AHB Bus
    APB2,					 //APB2 Bus
    APB1					 //APB1 Bus

}Buses;

/*   All Bits Of RCC Register (AHBENR,AHB2ENR,AHB1ENR)  To Enable/Disable Clock On Their   */

typedef enum 
{
    /* AHB Peripherals */
	DMA1EN = Null,           //DMA
	DMA2EN, 				 //DMA
	SRAMEN,                  //SRAM
	FLITFEN = 4,			 //FLITF
	CRCEN = 6,				 //CRC
	OTGFSEN = 12,            //OTGFS
	ETHMACEN = 14,           //ETHMAC
	ETHMACTXEN,				 //ETHMACTX
	ETHMACRXEN,              //ETHMACRX

    /* APB2 Peripherals */
    AFIOEN = Null,           //AFIO
    IOPAEN = 2,              //IOPA
    IOPBEN,                  //IOPB
    IOPCEN,                  //IOPC
    IOPDEN,                  //IOPD
    IOPEEN,                  //IOPE
    ADC1EN = 9,              //ADC1
    ADC2EN,                  //ADC2
    TIM1EN,                  //TIM1
    SPI1EN,                  //SPI1
    USART1EN = 14,           //USART1

    /* APB1 Peripherals */
    TIM2EN = Null,           //TIM2
    TIM3EN,                  //TIM3
    TIM4EN,                  //TIM4
    TIM5EN,                  //TIM5
    TIM6EN,                  //TIM6
    TIM7EN,                  //TIM7
    WWDGEN = 11,             //WWDG
    SPI2EN = 14,             //SPI2
    SPI3EN,                  //SPI3
    USART2EN = 17,           //USART2
    USART3EN,                //USART3
    UART4EN,                 //UART4
    UART5EN,                 //UART5
    I2C1EN,                  //I2C1
    I2C2EN,                  //I2C2
    CAN1EN = 25,             //CAN1
    CAN2EN,                  //CAN2
    BKPEN,                   //BKP
    PWREN,                   //PWR
    DACEN                    //DAC

}Peripherals;



/*  Structure For Definition The Peripheral And His Bus To Enable/Disable His Clock  */

typedef struct 
{
    Buses Bus;                     //Object From Enum Buses To Configuration It
    Peripherals Peripheral;		   //Object From Enum Peripherals To Configuration It

}Buses_Peripherals_Clock_Enable;



/*  Definition Of MCO (Microcontroller Clock Output) For Clock Output Configuration */

typedef enum
{
    No_Clock = 0b000,       //MCO No Clock Output
    Sysclock = 0b100,       //MCO SYSCLK Output
    HSI = 0b101,            //MCO HSI Output
	HSE = 0b110,		    //MCO HSE Output
    PLL = 0b111				//MCO PLL Output

}MCO_Types;

/* Structure For Select The Mode Of MCO By Object */

typedef struct
{
	MCO_Types MCO_Type;     //Object From Enum MCO_Types To Configuration It

}MCO;


/*  Definition Of PLL USB Prescaler For Clock Configuration  */

typedef enum
{
	PLL_Divided_By_1_5,     //USB Prescaler Divided By 1.5
	PLL_Not_Divided			//USB Prescaler Not Divided

}PLL_USB_Prescaler;


/*  Definition Of PLL ADC Prescaler For Clock Configuration  */

typedef enum
{
	PCLK2_divided_by_2,     //ADC Prescaler Divided By 2
	PCLK2_divided_by_4,     //ADC Prescaler Divided By 4
	PCLK2_divided_by_6,     //ADC Prescaler Divided By 6
	PCLK2_divided_by_8      //ADC Prescaler Divided By 8

}PLL_ADC_Prescaler;


/*  Definition Of PLL APB2 Bus Prescaler For Clock Configuration  */

typedef enum
{
	HCLK2_not_divided = 0b000,    //APB2 Bus Prescaler Not Divided
	HCLK2_divided_by_2 = 0b100,   //APB2 Bus Prescaler Divided By 2
	HCLK2_divided_by_4 = 0b101,   //APB2 Bus Prescaler Divided By 4
	HCLK2_divided_by_8 = 0b110,   //APB2 Bus Prescaler Divided By 8
	HCLK2_divided_by_16 = 0b111   //APB2 Bus Prescaler Divided By 16

}PLL_APB2_Prescaler;


/*  Definition Of PLL APB1 Bus Prescaler For Clock Configuration  */

typedef enum
{
	HCLK1_not_divided = 0b000,    //APB1 Bus Prescaler Not Divided
	HCLK1_divided_by_2 = 0b100,   //APB1 Bus Prescaler Divided By 2
	HCLK1_divided_by_4 = 0b101,   //APB1 Bus Prescaler Divided By 4
	HCLK1_divided_by_8 = 0b110,   //APB1 Bus Prescaler Divided By 8
	HCLK1_divided_by_16 = 0b111   //APB1 Bus Prescaler Divided By 16

}PLL_APB1_Prescaler;


/*  Definition Of PLL APB1 Bus Prescaler For Clock Configuration  */

typedef enum
{
	SYSCLK_not_divided = 0b0000,      //AHB Bus Prescaler Not Divided
	SYSCLK_divided_by_2 = 0b1000,     //AHB Bus Prescaler Divided By 2
	SYSCLK_divided_by_4 = 0b1001,     //AHB Bus Prescaler Divided By 4
	SYSCLK_divided_by_8 = 0b1010,     //AHB Bus Prescaler Divided By 8
	SYSCLK_divided_by_16 = 0b1011,    //AHB Bus Prescaler Divided By 16
	SYSCLK_divided_by_64 = 0b1100,    //AHB Bus Prescaler Divided By 64
	SYSCLK_divided_by_128 = 0b1101,   //AHB Bus Prescaler Divided By 128
	SYSCLK_divided_by_256 = 0b1110,   //AHB Bus Prescaler Divided By 256
	SYSCLK_divided_by_512 = 0b1111    //AHB Bus Prescaler Divided By 512

}PLL_AHB_Prescaler;


/*  Definition Of PLL HSE Prescaler Entry For Clock Configuration  */

typedef enum
{
	HSE_Not_Divided,        //HSE Prescaler Entry With It Value
	HSE_Divided_By_2,       //HSE Prescaler Entry Divided By 2
	HSE_Not_allowed         //No HSE Entry

}PLL_HSE_Prescaler_Entry;


/*  Definition Of PLL Selection Between HSI And HSE Entry For Clock Configuration  */

typedef enum
{
	HSI_By_2,               //HSI Divided By 512
	HSE_By_1                //HSE Not Divided

}PLL_Selection_HSI_HSE_Entry;



/*  Definition Of PLL Multiplication Factor For Clock Configuration  */

typedef enum
{
	PLL_input_clock_x_2,         //The Input Clock Multiplied By 2
	PLL_input_clock_x_3,         //The Input Clock Multiplied By 3
	PLL_input_clock_x_4,         //The Input Clock Multiplied By 4
	PLL_input_clock_x_5,         //The Input Clock Multiplied By 5
	PLL_input_clock_x_6,         //The Input Clock Multiplied By 6
	PLL_input_clock_x_7,         //The Input Clock Multiplied By 7
	PLL_input_clock_x_8,         //The Input Clock Multiplied By 8
	PLL_input_clock_x_9,         //The Input Clock Multiplied By 9
	PLL_input_clock_x_10,        //The Input Clock Multiplied By 10
	PLL_input_clock_x_11,        //The Input Clock Multiplied By 11
	PLL_input_clock_x_12,        //The Input Clock Multiplied By 12
	PLL_input_clock_x_13,        //The Input Clock Multiplied By 13
	PLL_input_clock_x_14,        //The Input Clock Multiplied By 14
	PLL_input_clock_x_15,        //The Input Clock Multiplied By 15
	PLL_input_clock_x_16         //The Input Clock Multiplied By 16

}PLL_Multiplication_Factor;


/*  Definition Of SYSCLK Sources For Chose The Clock Source Entry To SYSCLK  */

typedef enum
{
	HSI_selected_as_system_clock,      //HSI Selected As System Clock
	HSE_selected_as_system_clock,	   //HSE Selected As System Clock
	PLL_selected_as_system_clock,      //PLL Selected As System Clock
	Not_allowed                        //No System Clock

}SYSCLK_Sources;


/*  Definition Of SYSCLK Sources For Check What Is The Selected System Clock When Happen Failure In The System  */

typedef enum
{
	HSI_oscillator_used_as_system_clock,    //HSI Is Used As SYSCLK
	HSE_oscillator_used_as_system_clock,    //HSE Is Used As SYSCLK
	PLL_used_as_system_clock,				//PLL Is Used As SYSCLK
	not_applicable							//No Clock

}SYSCLK_Status;


/*  Structure For Definition All PLL Configuration  */

typedef struct
{
	PLL_Selection_HSI_HSE_Entry PLL_HSI_HSE_Selection_Configuration;      //Object From Enum PLL Selection Between HSI And HSE Entry To Configuration It
	PLL_HSE_Prescaler_Entry PLL_HSE_Prescaler_Configuration;              //Object From Enum PLL HSE Prescaler Entry To Configuration It
	PLL_Multiplication_Factor PLL_Multiplication_Factor_Configuration;    //Object From Enum PLL Multiplication Factor To Configuration It
	SYSCLK_Sources SYSCLK_Source_Selection;                               //Object From Enum SYSCLK Sources To Configuration It
	PLL_USB_Prescaler PLL_USB_Prescaler_Configuration;                    //Object From Enum PLL USB Prescaler To Configuration It
	PLL_ADC_Prescaler PLL_ADC_Prescaler_Configuration;                    //Object From Enum PLL ADC Prescaler To Configuration It
	PLL_APB2_Prescaler PLL_APB2_Prescaler_Configuration;                  //Object From Enum PLL APB2 Prescaler To Configuration It
	PLL_APB1_Prescaler PLL_APB1_Prescaler_Configuration;                  //Object From Enum PLL APB1 Prescaler To Configuration It
	PLL_AHB_Prescaler PLL_AHB_Prescaler_Configuration;                    //Object From Enum PLL AHB Prescaler To Configuration It

}PLL_Configuration;



/*  Definition Of Clock Detection For Clock Configuration  */

typedef enum
{
	Clock_Detector_Off,     //Clock Detector Disable
	Clock_Detector_On		//Clock Detector Enable

}Clock_Detector;


/*  Definition Of HSE Bypass For HSE Clock Configuration  */

typedef enum
{
	HSE_Bypass_Off,          //HSE Bypass Disable
	HSE_Bypass_On            //HSE Bypass Enable

}HSE_Bypass;


/* Structure For Configuration The Clock Detector And HSE Bypass */

typedef struct
{
	Clock_Detector Clock_Detector_Configuration;       //Object From Enum Clock Detector To Configuration It
 	HSE_Bypass HSE_Bypass_Configuration;               //Object From Enum HSE Bypass To Configuration It
	SYSCLK_Sources SYSCLK_Source_Selection;                               //Object From Enum SYSCLK Sources To Configuration It

}HSE_Configuration;


/*  Structure For Configuration The HSI Clock Trimming  */

typedef struct
{
	u16 Clock_Trimming;       //Object To Configuration The HSI Clock Trimming
	SYSCLK_Sources SYSCLK_Source_Selection;   //Object From Enum SYSCLK Sources To Configuration It

}HSI_Configuration;


#if RCC_HSE            //HSE Clock Source

	void __RCC_HSE_Clock_Initialization(HSE_Configuration *RCC_HSE_Configuration);    //Prototype Of Function To Initialization The HSE Clock

#elif RCC_HSI          //HSI Clock Source

	void __RCC_HSI_Clock_Initialization(HSI_Configuration *RCC_HSI_Configuration);    //Prototype Of Function To Initialization The HSI Clock

#elif RCC_PLL          //PLL Clock Source

	void __RCC_PLL_Clock_Initialization(PLL_Configuration *RCC_PLL_Configuration);    //Prototype Of Function To Initialization The PLL Clock

#endif

void __RCC_MCO__(MCO *Type);								//Prototype Of Function To Enable And Select Clock Of MCO
SYSCLK_Status __RCC_Check_System_Clock_Status__(void);      //Prototype Of Function To Check The System Clock Status
u8 __RCC_Enable_Peripheral_Clock__(Buses_Peripherals_Clock_Enable *Peripheral_Bus);   //Prototype Of Function To Enable Clock Throw Peripheral By The Bus And Name Of Peripheral
u8 __RCC_Disable_Peripheral_Clock__(Buses_Peripherals_Clock_Enable *Peripheral_Bus);  //Prototype Of Function To Disable Clock Throw Peripheral By The Bus And Name Of Peripheral
u8 __RCC_Enable_Peripherals_Clock__(u8 No_Enable_Peripheral_Clock,Buses_Peripherals_Clock_Enable *Data);     //Definition Of Function To Enable Clock Throw Peripherals By The Number Of Peripherals



#endif /* RCC_INTERFACE_H */
