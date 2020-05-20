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
 * 2020-05-20   | v1.0.0    | DrownTheSky  | �޸��ļ�
 * -----------------------------------------------------------------------------
 ******************************************************************************/
 
/*================================= ͷ �� �� =================================*/
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
/*================================= �� �� �� =================================*/
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
  * @brief  main����
  * @param  None
  * @retval None
  */
int main(void)
{
	char T[30];
	extern __IO uint16_t ChannelPulse;
	extern uint8_t Tag;
	
	Debug_USART_Config(); //��ӡ���Դ��ڳ�ʼ��
	GTP_Init_Panel();			//����оƬ��ʼ��
	TIM_GENERAL_Config(); //PWM��ʱ����ʼ��
	SDRAM_Init();					//LCD�Դ��ʼ��
	SPI_FLASH_Init();			//�ֿ�FLASH��ʼ��
	LCD_Config();					//LCD��ʼ��
	SysTick_Init();				//����оƬ��SysTick��ʱ�жϵ��ã���ʼ��
	BEEP_Config();				//��������ʼ��
	
	LCD_DispString_EN_CH( HANDX, HANDY, LCD_LAYER2_START_ADDR, BLACK , WHITE,"�������");
	
	sprintf(T,"��ǰռ�ձȣ�%d",(ChannelPulse * 100 / 250));
	LCD_DispString_EN_CH( DUTYX, DUTYY, LCD_LAYER2_START_ADDR,BLACK , WHITE,(char*)T);
	
	sprintf(T,"��ǰ�Ƕȣ�%d",(((ChannelPulse - 50) * 180) / 200));
	LCD_DispString_EN_CH(ANGX, ANGY, LCD_LAYER2_START_ADDR,BLACK,WHITE,(char*)T);
	
	LCD_DrawFullCircle(CIRLX,CIRLY,50,LCD_LAYER1_START_ADDR,CYAN);
	LCD_DrawFullCircle(CIRRX,CIRRY,50,LCD_LAYER1_START_ADDR,CYAN);
	
	LCD_DrawCircle(CIRLX,CIRLY,51,LCD_LAYER1_START_ADDR,BLACK);
	LCD_DrawCircle(CIRRX,CIRRY,51,LCD_LAYER1_START_ADDR,BLACK);
	
	LCD_DispString_EN_CH(CIRLX - 12,CIRLY - 24,LCD_LAYER2_START_ADDR,BLACK,CLEAR,"��С");
	LCD_DispString_EN_CH(CIRRX - 12,CIRRY - 24,LCD_LAYER2_START_ADDR,BLACK,CLEAR,"����");
	
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
			
			
			sprintf(T,"��ǰռ�ձȣ�%d%%",(ChannelPulse*100/250));
			LCD_DispString_EN_CH( DUTYX, DUTYY+180, LCD_LAYER2_START_ADDR,WHITE , WHITE," ");
			LCD_DispString_EN_CH( DUTYX, DUTYY, LCD_LAYER2_START_ADDR,BLACK , WHITE,(char*)T);
	
			sprintf(T,"��ǰ�Ƕȣ�%d��",(((ChannelPulse-50)*180)/200));
			LCD_DispString_EN_CH( ANGX, ANGY+120, LCD_LAYER2_START_ADDR,WHITE , WHITE,"     ");
			LCD_DispString_EN_CH( ANGX, ANGY, LCD_LAYER2_START_ADDR,BLACK , WHITE,(char*)T);

			Tag = 0;
		}
	}
}

