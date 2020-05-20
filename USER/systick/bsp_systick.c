#include "./systick/bsp_systick.h"


static  __IO u32 TimingDelay;


/*����ϵͳ�δ�ʱ�� SysTick */
void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms�ж�һ��
	 * SystemFrequency / 100000	 10us�ж�һ��
	 * SystemFrequency / 1000000 1us�ж�һ��
	 */
	if (SysTick_Config(SystemCoreClock / 100000))  /*Ĭ��SystemCoreClock = 180000000;*/
	{ 
		/* Capture error */ 
		while (1);
	}
}

/*��¼�жϸ���,�� SysTick �жϺ��� SysTick_Handler()����*/
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)  /*�ж��Ƿ�  �������㣬����������*/
	{ 
		TimingDelay--;          /*�жϸ�����һ��*/
	}
}

