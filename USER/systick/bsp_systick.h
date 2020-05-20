#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H
#include "stm32f4xx.h"

//void __Delay(__IO uint32_t nCount);

void SysTick_Init(void);

void TimingDelay_Decrement(void);

//void Delay_us(__IO u32 nTime);

#define Delay_ms(x) Delay_us(100*x)	 //µ¥Î»ms


#endif  /*__BSP_SYSTICK_H*/

