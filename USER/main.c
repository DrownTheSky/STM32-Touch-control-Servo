/*******************************************************************************
 * Copyleft (c) 2020 DrownTheSky
 *
 * @file    main.c
 * @brief   整个程序的入口
 * @author  DrownTheSky
 * @version 1.0.0
 * @date    2020-05-20
 *
 * -----------------------------------------------------------------------------
 *
 * -----------------------------------------------------------------------------
 * 文件修改历史：
 * <时间>       | <版本>    | <作者>       | <描述>
 * 2020-05-20   | v1.0.0    | DrownTheSky  | 修改文件
 * -----------------------------------------------------------------------------
 ******************************************************************************/
 
/*================================= 头 文 件 =================================*/
#include "stm32f4xx.h"
#include "./beep/bsp_beep.h"  
#include "./fmc/bsp_fmc_sdram.h"
#include "./font/bsp_font.h"
#include "./spi/bsp_spi_flash.h"
#include "./lcd/bsp_lcd.h"
#include "./tim_general/bsp_tim_general.h"
#include "./touch/bsp_i2c_touch.h"
#include "./touch/gt9xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./systick/bsp_systick.h"
/*================================= 宏 定 义 =================================*/
#define HANDX   650
#define HANDY   200
#define DUTYX   500
#define DUTYY   150
#define ANGX    400
#define ANGY    150
#define CIRLX		150
#define CIRLY		150
#define CIRRX		150
#define CIRRY		330
#define BLACK		0xFF000000
#define WHITE		0xFFFFFFFF
#define CYAN		0xFF00FFFF
#define CLEAR		0x00000000

/**
  * @brief  main函数
  * @param  None
  * @retval None
  */
int main(void)
{
	char T[30];
	extern __IO uint16_t ChannelPulse;
	extern uint8_t Tag;
	
	Debug_USART_Config(); //打印调试串口初始化
	GTP_Init_Panel();			//触摸芯片初始化
	TIM_GENERAL_Config(); //PWM定时器初始化
	SDRAM_Init();					//LCD显存初始化
	SPI_FLASH_Init();			//字库FLASH初始化
	LCD_Config();					//LCD初始化
	SysTick_Init();				//触摸芯片在SysTick定时中断调用，初始化
	BEEP_Config();				//蜂鸣器初始化
	
	LCD_DispString_EN_CH( HANDX, HANDY, LCD_LAYER2_START_ADDR, BLACK , WHITE,"舵机控制");
	
	sprintf(T,"当前占空比：%d",(ChannelPulse * 100 / 250));
	LCD_DispString_EN_CH( DUTYX, DUTYY, LCD_LAYER2_START_ADDR,BLACK , WHITE,(char*)T);
	
	sprintf(T,"当前角度：%d",(((ChannelPulse - 50) * 180) / 200));
	LCD_DispString_EN_CH(ANGX, ANGY, LCD_LAYER2_START_ADDR,BLACK,WHITE,(char*)T);
	
	LCD_DrawFullCircle(CIRLX,CIRLY,50,LCD_LAYER1_START_ADDR,CYAN);
	LCD_DrawFullCircle(CIRRX,CIRRY,50,LCD_LAYER1_START_ADDR,CYAN);
	
	LCD_DrawCircle(CIRLX,CIRLY,51,LCD_LAYER1_START_ADDR,BLACK);
	LCD_DrawCircle(CIRRX,CIRRY,51,LCD_LAYER1_START_ADDR,BLACK);
	
	LCD_DispString_EN_CH(CIRLX - 12,CIRLY - 24,LCD_LAYER2_START_ADDR,BLACK,CLEAR,"减小");
	LCD_DispString_EN_CH(CIRRX - 12,CIRRY - 24,LCD_LAYER2_START_ADDR,BLACK,CLEAR,"增加");
	
	LCD_DrawFullRect(300, 40, 50, 50,LCD_LAYER1_START_ADDR, BLACK);
	
	while(1)
	{
		
		while(Tag == 1)
		{
			while(ChannelPulse<50)
			ChannelPulse = 50;
			while(ChannelPulse>250)
			ChannelPulse = 250;
			
			TIM_SetCompare1(GENERAL_TIM,ChannelPulse);
			
			
			sprintf(T,"当前占空比；%d%%",(ChannelPulse*100/250));
			LCD_DispString_EN_CH( DUTYX, DUTYY+180, LCD_LAYER2_START_ADDR,WHITE , WHITE," ");
			LCD_DispString_EN_CH( DUTYX, DUTYY, LCD_LAYER2_START_ADDR,BLACK , WHITE,(char*)T);
	
			sprintf(T,"当前角度：%d°",(((ChannelPulse-50)*180)/200));
			LCD_DispString_EN_CH( ANGX, ANGY+120, LCD_LAYER2_START_ADDR,WHITE , WHITE,"     ");
			LCD_DispString_EN_CH( ANGX, ANGY, LCD_LAYER2_START_ADDR,BLACK , WHITE,(char*)T);

			Tag = 0;
		}
	}
}

