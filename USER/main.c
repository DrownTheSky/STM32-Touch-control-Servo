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
 * 2020-07-14   | v2.0.0    | DrownTheSky  | 修改文件
 * -----------------------------------------------------------------------------
 ******************************************************************************/

/*================================= 头 文 件 =================================*/
#include "stm32f4xx.h"
#include "./beep/bsp_beep.h"
#include "./tim_general/bsp_tim_general.h"
#include "./fmc/bsp_fmc_sdram.h"
#include "./lcd/bsp_lcd.h"
#include "./lcd/bsp_touch.h"
#include "./spi/bsp_spi.h"
#include "./usart/bsp_usart.h"
/*================================= 宏 定 义 =================================*/
#define HANDX 650
#define HANDY 200
#define DUTYX 500
#define DUTYY 150
#define ANGX 400
#define ANGY 150
#define CIRLX 150
#define CIRLY 150
#define CIRRX 150
#define CIRRY 330
#define BLACK 0xFF000000
#define WHITE 0xFFFFFFFF
#define CYAN 0xFF00FFFF
#define CLEAR 0x00000000

extern __IO uint16_t ChannelPulse;
uint8_t Tag = 0;
/**
  * @brief  main函数
  * @param  None
  * @retval None
  */
int main(void)
{
	char T[30];

	USART_init();		  //打印调试串口初始化
	I2C_Touch_Init();	  //触摸芯片初始化
	TIM_GENERAL_Config(); //PWM定时器初始化
	FMC_SDRAM_Init();	  //LCD显存初始化
	SPIx_Init();		  //字库FLASH初始化
	LCD_Init();			  //LCD初始化
	BEEP_Config();		  //蜂鸣器初始化

	LCD_DispString_EN_CH(HANDX, HANDY, LCD_TOP_START_ADDR, BLACK, WHITE, "舵机控制");

	sprintf(T, "当前占空比：%d", (ChannelPulse * 100 / 250));
	LCD_DispString_EN_CH(DUTYX, DUTYY, LCD_TOP_START_ADDR, BLACK, WHITE, (char *)T);

	sprintf(T, "当前角度：%d", (((ChannelPulse - 50) * 180) / 200));
	LCD_DispString_EN_CH(ANGX, ANGY, LCD_TOP_START_ADDR, BLACK, WHITE, (char *)T);

	LCD_DrawFullCircle(CIRLX, CIRLY, 50, LCD_GROUND_START_ADDR, CYAN);
	LCD_DrawFullCircle(CIRRX, CIRRY, 50, LCD_GROUND_START_ADDR, CYAN);

	LCD_DrawCircle(CIRLX, CIRLY, 51, LCD_GROUND_START_ADDR, BLACK);
	LCD_DrawCircle(CIRRX, CIRRY, 51, LCD_GROUND_START_ADDR, BLACK);

	LCD_DispString_EN_CH(CIRLX - 12, CIRLY - 24, LCD_TOP_START_ADDR, BLACK, CLEAR, "减小");
	LCD_DispString_EN_CH(CIRRX - 12, CIRRY - 24, LCD_TOP_START_ADDR, BLACK, CLEAR, "增加");

	LCD_DrawFullRect(300, 40, 50, 50, LCD_GROUND_START_ADDR, BLACK);

	while (1)
	{

		while (Tag)
		{
			while (ChannelPulse < 50)
				ChannelPulse = 50;
			while (ChannelPulse > 250)
				ChannelPulse = 250;
			TIM_SetCompare1(GENERAL_TIM, ChannelPulse);

			sprintf(T, "当前占空比；%d%%", (ChannelPulse * 100 / 250));
			LCD_DispString_EN_CH(DUTYX, DUTYY + 180, LCD_TOP_START_ADDR, WHITE, WHITE, " ");
			LCD_DispString_EN_CH(DUTYX, DUTYY, LCD_TOP_START_ADDR, BLACK, WHITE, (char *)T);

			sprintf(T, "当前角度：%d°", (((ChannelPulse - 50) * 180) / 200));
			LCD_DispString_EN_CH(ANGX, ANGY + 120, LCD_TOP_START_ADDR, WHITE, WHITE, "     ");
			LCD_DispString_EN_CH(ANGX, ANGY, LCD_TOP_START_ADDR, BLACK, WHITE, (char *)T);

			Tag = 0;
		}
	}
}

/* 按键按下执行函数 */
void GT91x_Touch_Down(uint8_t TrackID, int16_t PointX, int16_t PointY, int16_t PointS)
{
	if ((PointX < 200) && (PointX > 100) && (PointY < 200) && (PointY > 100))
	{
		BEEP_ON;
		LCD_DrawFullCircle(150, 150, 50, LCD_GROUND_START_ADDR, 0xFFFFFFFF);
	}

	if ((PointX < 200) && (PointX > 100) && (PointY < 380) && (PointY > 280))
	{
		BEEP_ON;
		LCD_DrawFullCircle(150, 330, 50, LCD_GROUND_START_ADDR, 0xFFFFFFFF);
	}

	if ((PointX < 375) && (PointX > 250) && (PointY < 440) && (PointY > 40))
	{

		LCD_DrawFullRect(300, PointY - 25, 50, 50, LCD_TOP_START_ADDR, 0xFF000000);
		LCD_DrawFullRect(300, 0, 50, PointY - 25, LCD_TOP_START_ADDR, 0xFFFFFFFF);
		LCD_DrawFullRect(300, PointY + 25, 50, 480, LCD_TOP_START_ADDR, 0xFFFFFFFF);

		ChannelPulse = (((PointY - 40) / 2) + 50);
		TIM_SetCompare1(GENERAL_TIM, ChannelPulse);
		Tag = 1;
	}
}

/* 按键释放执行函数 */
void GT91x_Touch_UP(uint8_t TrackID, int16_t PointX, int16_t PointY, int16_t PointS)
{
	BEEP_OFF;

	if ((PointX < 200) && (PointX > 100) && (PointY < 200) && (PointY > 100))
	{
		LCD_DrawFullCircle(150, 150, 50, LCD_GROUND_START_ADDR, 0xFF00FFFF);
		ChannelPulse -= 10;
		Tag = 1;
	}

	if ((PointX < 200) && (PointX > 100) && (PointY < 380) && (PointY > 280))
	{
		LCD_DrawFullCircle(150, 330, 50, LCD_GROUND_START_ADDR, 0xFF00FFFF);
		ChannelPulse += 10;
		Tag = 1;
	}

	if ((PointX < 375) && (PointX > 250) && (PointY < 440) && (PointY > 40))
	{
		LCD_DrawFullRect(300, PointY - 25, 50, 50, LCD_GROUND_START_ADDR, 0xFF000000);
		ChannelPulse = (((PointY - 40) / 2) + 50);
		Tag = 1;
	}
}
