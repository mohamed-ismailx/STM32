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


void __SysTick_Init__(void);
void __SysTick_Delay__(u32 Time_ms);
u8 __SysTick_Single_Mode__(u32 Ticks,void (*SysTick_ptr)(void));
u8 __SysTick_Mult_Shot_Timer__(u32 Ticks,void (*SysTick_ptr)(void));
void __SysTick_Stop_Timer__(void);
void __SysTick_Start_Timer__(void);
void __SysTick_Restart_Timer__(void);
u8 __SysTick_Elapsed_Timer__(u32 *Elapsed_Time);
u8 __SysTick_Remaining_Timer__(u32 *Remaining_Time);






#endif /* SYSTICK_INTERFACE_H_ */
