/*
 * SysTick_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: kcsstore.com
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


#define SysTick_AHB_Per_8_Clk      0
#define SysTick_AHB_Clk            1


#define SysTick_us                 0
#define SysTick_ms                 1


void __SysTick_Initialization__(void);
u8 __SysTick_Delay__(u32 Time,u8 Time_Scale);
u8 __SysTick_Single_Mode__(u32 Time,u8 Time_Scale,void (*SysTick_ptr)(void));
u8 __SysTick_Mult_Shot_Timer__(u32 Time,u8 Time_Scale,void (*SysTick_ptr)(void));
void __SysTick_Stop_Timer__(void);
void __SysTick_Start_Timer__(void);
void __SysTick_Restart_Timer__(void);
u8 __SysTick_Elapsed_Timer__(u32 *Elapsed_Time,u8 Time_Scale);
u8 __SysTick_Remaining_Timer__(u32 *Remaining_Time,u8 Time_Scale);






#endif /* SYSTICK_INTERFACE_H_ */
