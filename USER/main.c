/*******************************************************************************
 * Copyleft (c) 2020 DrownTheSky
 *
 * @file    main.c
 * @brief   ������������
 * @author  DrownTheSky
 * @version 1.0.0
 * @date    2020-05-20
 *
 * -----------------------------------------------------------------------------
 *
 * -----------------------------------------------------------------------------
 * �ļ��޸���ʷ��
 * <ʱ��>       | <�汾>    | <����>       | <����>
 * 2020-07-14   | v2.0.0    | DrownTheSky  | �޸��ļ�
 * -----------------------------------------------------------------------------
 ******************************************************************************/

/*================================= ͷ �� �� =================================*/
#include "stm32f4xx.h"
#include "./beep/bsp_beep.h"
#include "./tim_general/bsp_tim_general.h"
#include "./fmc/bsp_fmc_sdram.h"
#include "./lcd/bsp_lcd.h"
#include "./lcd/bsp_touch.h"
#include "./spi/bsp_spi.h"
#include "./usart/bsp_usart.h"
/*================================= �� �� �� =================================*/
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
  * @brief  main����
  * @param  None
  * @retval None
  */
int main(void)
{
	char T[30];

	USART_init();		  //��ӡ���Դ��ڳ�ʼ��
	I2C_Touch_Init();	  //����оƬ��ʼ��
	TIM_GENERAL_Config(); //PWM��ʱ����ʼ��
	FMC_SDRAM_Init();	  //LCD�Դ��ʼ��
	SPIx_Init();		  //�ֿ�FLASH��ʼ��
	LCD_Init();			  //LCD��ʼ��
	BEEP_Config();		  //��������ʼ��

	LCD_DispString_EN_CH(HANDX, HANDY, LCD_TOP_START_ADDR, BLACK, WHITE, "�������");

	sprintf(T, "��ǰռ�ձȣ�%d", (ChannelPulse * 100 / 250));
	LCD_DispString_EN_CH(DUTYX, DUTYY, LCD_TOP_START_ADDR, BLACK, WHITE, (char *)T);

	sprintf(T, "��ǰ�Ƕȣ�%d", (((ChannelPulse - 50) * 180) / 200));
	LCD_DispString_EN_CH(ANGX, ANGY, LCD_TOP_START_ADDR, BLACK, WHITE, (char *)T);

	LCD_DrawFullCircle(CIRLX, CIRLY, 50, LCD_GROUND_START_ADDR, CYAN);
	LCD_DrawFullCircle(CIRRX, CIRRY, 50, LCD_GROUND_START_ADDR, CYAN);

	LCD_DrawCircle(CIRLX, CIRLY, 51, LCD_GROUND_START_ADDR, BLACK);
	LCD_DrawCircle(CIRRX, CIRRY, 51, LCD_GROUND_START_ADDR, BLACK);

	LCD_DispString_EN_CH(CIRLX - 12, CIRLY - 24, LCD_TOP_START_ADDR, BLACK, CLEAR, "��С");
	LCD_DispString_EN_CH(CIRRX - 12, CIRRY - 24, LCD_TOP_START_ADDR, BLACK, CLEAR, "����");

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

			sprintf(T, "��ǰռ�ձȣ�%d%%", (ChannelPulse * 100 / 250));
			LCD_DispString_EN_CH(DUTYX, DUTYY + 180, LCD_TOP_START_ADDR, WHITE, WHITE, " ");
			LCD_DispString_EN_CH(DUTYX, DUTYY, LCD_TOP_START_ADDR, BLACK, WHITE, (char *)T);

			sprintf(T, "��ǰ�Ƕȣ�%d��", (((ChannelPulse - 50) * 180) / 200));
			LCD_DispString_EN_CH(ANGX, ANGY + 120, LCD_TOP_START_ADDR, WHITE, WHITE, "     ");
			LCD_DispString_EN_CH(ANGX, ANGY, LCD_TOP_START_ADDR, BLACK, WHITE, (char *)T);

			Tag = 0;
		}
	}
}

/* ��������ִ�к��� */
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

/* �����ͷ�ִ�к��� */
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
