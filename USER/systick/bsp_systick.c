#include "./systick/bsp_systick.h"


static  __IO u32 TimingDelay;


/*启动系统滴答定时器 SysTick */
void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms中断一次
	 * SystemFrequency / 100000	 10us中断一次
	 * SystemFrequency / 1000000 1us中断一次
	 */
	if (SysTick_Config(SystemCoreClock / 100000))  /*默认SystemCoreClock = 180000000;*/
	{ 
		/* Capture error */ 
		while (1);
	}
}

/*记录中断个数,在 SysTick 中断函数 SysTick_Handler()调用*/
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)  /*判断是否  不等于零，等于零跳出*/
	{ 
		TimingDelay--;          /*中断个数减一个*/
	}
}

