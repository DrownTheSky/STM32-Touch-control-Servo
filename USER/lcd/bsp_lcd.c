#include "./lcd/bsp_lcd.h"
#include "./spi/bsp_spi_flash.h"



static void LCD_GPIO_Config(void)
{ 
	GPIO_InitTypeDef GPIO_InitStruct;
  
  /* ʹ��LCDʹ�õ�������ʱ�� */
                          //��ɫ������
  RCC_AHB1PeriphClockCmd(LTDC_R0_GPIO_CLK | LTDC_R1_GPIO_CLK | LTDC_R2_GPIO_CLK| 
                         LTDC_R3_GPIO_CLK | LTDC_R4_GPIO_CLK | LTDC_R5_GPIO_CLK|
                         LTDC_R6_GPIO_CLK | LTDC_R7_GPIO_CLK |
                          //��ɫ������
                          LTDC_G0_GPIO_CLK|LTDC_G1_GPIO_CLK|LTDC_G2_GPIO_CLK|
                          LTDC_G3_GPIO_CLK|LTDC_G4_GPIO_CLK|LTDC_G5_GPIO_CLK|
                          LTDC_G6_GPIO_CLK|LTDC_G7_GPIO_CLK|
                          //��ɫ������
                          LTDC_B0_GPIO_CLK|LTDC_B1_GPIO_CLK|LTDC_B2_GPIO_CLK|
                          LTDC_B3_GPIO_CLK|LTDC_B4_GPIO_CLK|LTDC_B5_GPIO_CLK|
                          LTDC_B6_GPIO_CLK|LTDC_B7_GPIO_CLK|
                          //�����ź���
                          LTDC_CLK_GPIO_CLK | LTDC_HSYNC_GPIO_CLK |LTDC_VSYNC_GPIO_CLK|
                          LTDC_DE_GPIO_CLK  | LTDC_BL_GPIO_CLK    |LTDC_DISP_GPIO_CLK ,ENABLE);

/* GPIO���� */

 /* ��ɫ������ */
  GPIO_InitStruct.GPIO_Pin = LTDC_R0_GPIO_PIN;                             
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  
  GPIO_Init(LTDC_R0_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_R0_GPIO_PORT, LTDC_R0_PINSOURCE, LTDC_R0_AF);

  GPIO_InitStruct.GPIO_Pin = LTDC_R1_GPIO_PIN;
  GPIO_Init(LTDC_R1_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_R1_GPIO_PORT, LTDC_R1_PINSOURCE, LTDC_R1_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_R2_GPIO_PIN;
  GPIO_Init(LTDC_R2_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_R2_GPIO_PORT, LTDC_R2_PINSOURCE, LTDC_R2_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_R3_GPIO_PIN;
  GPIO_Init(LTDC_R3_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_R3_GPIO_PORT, LTDC_R3_PINSOURCE, LTDC_R3_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_R4_GPIO_PIN;
  GPIO_Init(LTDC_R4_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_R4_GPIO_PORT, LTDC_R4_PINSOURCE, LTDC_R4_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_R5_GPIO_PIN;
  GPIO_Init(LTDC_R5_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_R5_GPIO_PORT, LTDC_R5_PINSOURCE, LTDC_R5_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_R6_GPIO_PIN;
  GPIO_Init(LTDC_R6_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_R6_GPIO_PORT, LTDC_R6_PINSOURCE, LTDC_R6_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_R7_GPIO_PIN;
  GPIO_Init(LTDC_R7_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_R7_GPIO_PORT, LTDC_R7_PINSOURCE, LTDC_R7_AF);
  
  //��ɫ������
  GPIO_InitStruct.GPIO_Pin = LTDC_G0_GPIO_PIN;
  GPIO_Init(LTDC_G0_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_G0_GPIO_PORT, LTDC_G0_PINSOURCE, LTDC_G0_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_G1_GPIO_PIN;
  GPIO_Init(LTDC_G1_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_G1_GPIO_PORT, LTDC_G1_PINSOURCE, LTDC_G1_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_G2_GPIO_PIN;
  GPIO_Init(LTDC_G2_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_G2_GPIO_PORT, LTDC_G2_PINSOURCE, LTDC_G2_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_G3_GPIO_PIN;
  GPIO_Init(LTDC_G3_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_G3_GPIO_PORT, LTDC_G3_PINSOURCE, LTDC_G3_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_G4_GPIO_PIN;
  GPIO_Init(LTDC_G4_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_G4_GPIO_PORT, LTDC_G4_PINSOURCE, LTDC_G4_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_G5_GPIO_PIN;
  GPIO_Init(LTDC_G5_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_G5_GPIO_PORT, LTDC_G5_PINSOURCE, LTDC_G5_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_G6_GPIO_PIN;
  GPIO_Init(LTDC_G6_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_G6_GPIO_PORT, LTDC_G6_PINSOURCE, LTDC_G6_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_G7_GPIO_PIN;
  GPIO_Init(LTDC_G7_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_G7_GPIO_PORT, LTDC_G7_PINSOURCE, LTDC_G7_AF);
  
  //��ɫ������
  GPIO_InitStruct.GPIO_Pin = LTDC_B0_GPIO_PIN;
  GPIO_Init(LTDC_B0_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_B0_GPIO_PORT, LTDC_B0_PINSOURCE, LTDC_B0_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_B1_GPIO_PIN;
  GPIO_Init(LTDC_B1_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_B1_GPIO_PORT, LTDC_B1_PINSOURCE, LTDC_B1_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_B2_GPIO_PIN;
  GPIO_Init(LTDC_B2_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_B2_GPIO_PORT, LTDC_B2_PINSOURCE, LTDC_B2_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_B3_GPIO_PIN;
  GPIO_Init(LTDC_B3_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_B3_GPIO_PORT, LTDC_B3_PINSOURCE, LTDC_B3_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_B4_GPIO_PIN;
  GPIO_Init(LTDC_B4_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_B4_GPIO_PORT, LTDC_B4_PINSOURCE, LTDC_B4_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_B5_GPIO_PIN;
  GPIO_Init(LTDC_B5_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_B5_GPIO_PORT, LTDC_B5_PINSOURCE, LTDC_B5_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_B6_GPIO_PIN;
  GPIO_Init(LTDC_B6_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_B6_GPIO_PORT, LTDC_B6_PINSOURCE, LTDC_B6_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_B7_GPIO_PIN;
  GPIO_Init(LTDC_B7_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_B7_GPIO_PORT, LTDC_B7_PINSOURCE, LTDC_B7_AF);
  
  //�����ź���
  GPIO_InitStruct.GPIO_Pin = LTDC_CLK_GPIO_PIN;
  GPIO_Init(LTDC_CLK_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_CLK_GPIO_PORT, LTDC_CLK_PINSOURCE, LTDC_CLK_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_HSYNC_GPIO_PIN;
  GPIO_Init(LTDC_HSYNC_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_HSYNC_GPIO_PORT, LTDC_HSYNC_PINSOURCE, LTDC_HSYNC_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_VSYNC_GPIO_PIN;
  GPIO_Init(LTDC_VSYNC_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_VSYNC_GPIO_PORT, LTDC_VSYNC_PINSOURCE, LTDC_VSYNC_AF);
  
  GPIO_InitStruct.GPIO_Pin = LTDC_DE_GPIO_PIN;
  GPIO_Init(LTDC_DE_GPIO_PORT, &GPIO_InitStruct);
  GPIO_PinAFConfig(LTDC_DE_GPIO_PORT, LTDC_DE_PINSOURCE, LTDC_DE_AF);
  
  //����BL ��Һ��ʹ���ź�DISP
  GPIO_InitStruct.GPIO_Pin = LTDC_DISP_GPIO_PIN;                             
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  
  GPIO_Init(LTDC_DISP_GPIO_PORT, &GPIO_InitStruct);
  
  
  GPIO_InitStruct.GPIO_Pin = LTDC_BL_GPIO_PIN; 
  GPIO_Init(LTDC_BL_GPIO_PORT, &GPIO_InitStruct);
  
  //����ʹ��lcd
  GPIO_SetBits(LTDC_DISP_GPIO_PORT,LTDC_DISP_GPIO_PIN);
  GPIO_SetBits(LTDC_BL_GPIO_PORT,LTDC_BL_GPIO_PIN);


}
/* ����LTDC����:��������ͬ��ʱ��CLK������LTDCʱ��������źż��� */
static void LCD_Mode_Init(void)
{ 
  LTDC_InitTypeDef       LTDC_InitStruct;
  
  /* ʹ��LTDC����ʱ�� */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_LTDC, ENABLE);
	/* ʹ��DMA2Dʱ�� */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2D, ENABLE);

	
	/* ���� PLLSAI ��Ƶ�������������Ϊ����ͬ��ʱ��CLK*/
	/* LTDCʱ��̫�߻ᵼ����������ˢ���ٶ�Ҫ�󲻸ߣ�����ʱ��Ƶ�ʿɼ��ٻ�������*/
  /* PLLSAI_VCO ����ʱ�� = HSE_VALUE/PLL_M = 1 Mhz */
  /* PLLSAI_VCO ���ʱ�� = PLLSAI_VCO���� * PLLSAI_N  */
  /* PLLLCDCLK = PLLSAI_VCO ���/PLLSAI_R */
  /* LTDC ʱ��Ƶ�� = PLLLCDCLK / DIV */
	/* ���º������������ֱ�Ϊ��PLLSAIN,PLLSAIQ,PLLSAIR������PLLSAIQ��LTDC�޹�*/
	
  RCC_PLLSAIConfig(200,20,2);         //200/2/4=25MHZ
	/*���º����Ĳ���ΪDIVֵ*/
  RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div8);
  /* ʹ�� PLLSAI ʱ�� */
  RCC_PLLSAICmd(ENABLE);
  /* �ȴ� PLLSAI ��ʼ����� */
  while(RCC_GetFlagStatus(RCC_FLAG_PLLSAIRDY) == RESET)
  {
  }
  
  /* LTDC����*********************************************************/  
  /*�źż�������*/
  /* ��ͬ���źż��� */
  LTDC_InitStruct.LTDC_HSPolarity = LTDC_HSPolarity_AL;     
  /* ��ֱͬ���źż��� */  
  LTDC_InitStruct.LTDC_VSPolarity = LTDC_VSPolarity_AL;     
  /* ����ʹ���źż��� */
  LTDC_InitStruct.LTDC_DEPolarity = LTDC_DEPolarity_AL;     
  /* ����ͬ��ʱ�Ӽ��� */ 
  LTDC_InitStruct.LTDC_PCPolarity = LTDC_PCPolarity_IPC;
  
  /* ����LCD������ɫ */                   
  LTDC_InitStruct.LTDC_BackgroundRedValue = 0xFF;            
  LTDC_InitStruct.LTDC_BackgroundGreenValue = 255;          
  LTDC_InitStruct.LTDC_BackgroundBlueValue = 0xFF;    
 
  /* ʱ��������� */  
 /* ������ͬ���źſ��(HSW-1) */
 LTDC_InitStruct.LTDC_HorizontalSync =HSW-1;
 /* ���ô�ֱͬ���źſ��(VSW-1) */
 LTDC_InitStruct.LTDC_VerticalSync = VSW-1;
 /* ����(HSW+HBP-1) */
 LTDC_InitStruct.LTDC_AccumulatedHBP =HSW+HBP-1;
 /* ����(VSW+VBP-1) */
 LTDC_InitStruct.LTDC_AccumulatedVBP = VSW+VBP-1;
 /* ����(HSW+HBP+��Ч���ؿ��-1) */
 LTDC_InitStruct.LTDC_AccumulatedActiveW = HSW+HBP+LCD_PIXEL_WIDTH-1;
 /* ����(VSW+VBP+��Ч���ظ߶�-1) */
 LTDC_InitStruct.LTDC_AccumulatedActiveH = VSW+VBP+LCD_PIXEL_HEIGHT-1;
 /* �����ܿ��(HSW+HBP+��Ч���ؿ��+HFP-1) */
 LTDC_InitStruct.LTDC_TotalWidth =HSW+ HBP+LCD_PIXEL_WIDTH  + HFP-1; 
 /* �����ܸ߶�(VSW+VBP+��Ч���ظ߶�+VFP-1) */
 LTDC_InitStruct.LTDC_TotalHeigh =VSW+ VBP+LCD_PIXEL_HEIGHT  + VFP-1;

  LTDC_Init(&LTDC_InitStruct);
  
  LTDC_Cmd(ENABLE);
}  



/* ��ʼ��LTD�� ���� ����,�����Դ�ռ�,���÷ֱ��� */
static void LCD_Top_LayerInit(void)
{
  LTDC_Layer_InitTypeDef LTDC_Layer_InitStruct; 
  
  /* �㴰������ */
  /* ���ñ���Ĵ��ڱ߽磬ע����Щ�����ǰ���HBP HSW VBP VSW�� */    
	//һ�еĵ�һ����ʼ���أ��ó�ԱֵӦ��Ϊ (LTDC_InitStruct.LTDC_AccumulatedHBP+1)��ֵ
	LTDC_Layer_InitStruct.LTDC_HorizontalStart = HBP + HSW;
	//һ�е����һ�����أ��ó�ԱֵӦ��Ϊ (LTDC_InitStruct.LTDC_AccumulatedActiveW)��ֵ
	LTDC_Layer_InitStruct.LTDC_HorizontalStop = HSW+HBP+LCD_PIXEL_WIDTH-1;
	//һ�еĵ�һ����ʼ���أ��ó�ԱֵӦ��Ϊ (LTDC_InitStruct.LTDC_AccumulatedVBP+1)��ֵ
	LTDC_Layer_InitStruct.LTDC_VerticalStart =  VBP + VSW;
	//һ�е����һ�����أ��ó�ԱֵӦ��Ϊ (LTDC_InitStruct.LTDC_AccumulatedActiveH)��ֵ
	LTDC_Layer_InitStruct.LTDC_VerticalStop = VSW+VBP+LCD_PIXEL_HEIGHT-1;
	
  /* ���ظ�ʽ����*/
  LTDC_Layer_InitStruct.LTDC_PixelFormat = LTDC_Pixelformat_ARGB8888;
  /* �㶨Alphaֵ���ã�0-255 */
  LTDC_Layer_InitStruct.LTDC_ConstantAlpha = 0xFF; 
  /* Ĭ�ϱ�����ɫ������ɫ�ڶ���Ĳ㴰������ڲ��ֹʱʹ�á� */          
  LTDC_Layer_InitStruct.LTDC_DefaultColorRed = 255;        
  LTDC_Layer_InitStruct.LTDC_DefaultColorGreen = 255;       
  LTDC_Layer_InitStruct.LTDC_DefaultColorBlue = 255;         
  LTDC_Layer_InitStruct.LTDC_DefaultColorAlpha = 0;
  /* ���û������ CA ��ʾ��͸���ȣ�PAxCA ��ʾ�������͸���ȹ�ͬ���� */       
  LTDC_Layer_InitStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_PAxCA;    
  LTDC_Layer_InitStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_PAxCA; 
  
  /* ���ñ�����Դ��׵�ַ */    
  LTDC_Layer_InitStruct.LTDC_CFBStartAdress = LCD_LAYER2_START_ADDR;
	
	 /* �ó�ԱӦд��(һ����������ռ�õ��ֽ���+3)
  Line Lenth = ����Ч���ظ��� x ÿ�����ص��ֽ��� + 3 
  ����Ч���ظ��� = LCD_PIXEL_WIDTH 
  ÿ�����ص��ֽ��� = 2��RGB565/RGB1555��/ 3 (RGB888)/ 4��ARGB8888�� 
  */
	LTDC_Layer_InitStruct.LTDC_CFBLineLength = ((LCD_PIXEL_WIDTH * 4) + 3);
	
	 /* ��ĳ�е���ʼλ�õ���һ����ʼλ�ô�����������
  Pitch = ����Ч���ظ��� x ÿ�����ص��ֽ��� */ 
  LTDC_Layer_InitStruct.LTDC_CFBPitch = (LCD_PIXEL_WIDTH * 4);
	
	 /* ������Ч������ */  
  LTDC_Layer_InitStruct.LTDC_CFBLineNumber = LCD_PIXEL_HEIGHT;
  
  /* ����������ó�ʼ���� 2 ��*/
		LTDC_LayerInit(LTDC_Layer2, &LTDC_Layer_InitStruct);
	 
		LTDC_LayerCmd(LTDC_Layer2, ENABLE);
	
	  /* ������������ */  
		LTDC_ReloadConfig(LTDC_IMReload);
		
}




/* ��ʼ��LTD�� �ײ� ����,�����Դ�ռ�,���÷ֱ��� */
static void LCD_Ground_LayerInit(void)
{
  LTDC_Layer_InitTypeDef LTDC_Layer_InitStruct; 
  
  /* �㴰������ */
  /* ���ñ���Ĵ��ڱ߽磬ע����Щ�����ǰ���HBP HSW VBP VSW�� */    
	//һ�еĵ�һ����ʼ���أ��ó�ԱֵӦ��Ϊ (LTDC_InitStruct.LTDC_AccumulatedHBP+1)��ֵ
	LTDC_Layer_InitStruct.LTDC_HorizontalStart = HBP + HSW;
	//һ�е����һ�����أ��ó�ԱֵӦ��Ϊ (LTDC_InitStruct.LTDC_AccumulatedActiveW)��ֵ
	LTDC_Layer_InitStruct.LTDC_HorizontalStop = HSW+HBP+LCD_PIXEL_WIDTH-1;
	//һ�еĵ�һ����ʼ���أ��ó�ԱֵӦ��Ϊ (LTDC_InitStruct.LTDC_AccumulatedVBP+1)��ֵ
	LTDC_Layer_InitStruct.LTDC_VerticalStart =  VBP + VSW;
	//һ�е����һ�����أ��ó�ԱֵӦ��Ϊ (LTDC_InitStruct.LTDC_AccumulatedActiveH)��ֵ
	LTDC_Layer_InitStruct.LTDC_VerticalStop = VSW+VBP+LCD_PIXEL_HEIGHT-1;
	
  /* ���ظ�ʽ����*/
  LTDC_Layer_InitStruct.LTDC_PixelFormat = LTDC_Pixelformat_ARGB8888;
  /* �㶨Alphaֵ���ã�0-255 */
  LTDC_Layer_InitStruct.LTDC_ConstantAlpha = 0xFF; 
  /* Ĭ�ϱ�����ɫ������ɫ�ڶ���Ĳ㴰������ڲ��ֹʱʹ�á� */          
  LTDC_Layer_InitStruct.LTDC_DefaultColorRed = 255;        
  LTDC_Layer_InitStruct.LTDC_DefaultColorGreen = 255;       
  LTDC_Layer_InitStruct.LTDC_DefaultColorBlue = 255;         
  LTDC_Layer_InitStruct.LTDC_DefaultColorAlpha = 0;
  /* ���û������ CA ��ʾ��͸���ȣ�PAxCA ��ʾ�������͸���ȹ�ͬ���� */       
  LTDC_Layer_InitStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_PAxCA;    
  LTDC_Layer_InitStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_PAxCA; 
  
  /* ���ñ�����Դ��׵�ַ */    
  LTDC_Layer_InitStruct.LTDC_CFBStartAdress = LCD_LAYER1_START_ADDR;
	
	 /* �ó�ԱӦд��(һ����������ռ�õ��ֽ���+3)
  Line Lenth = ����Ч���ظ��� x ÿ�����ص��ֽ��� + 3 
  ����Ч���ظ��� = LCD_PIXEL_WIDTH 
  ÿ�����ص��ֽ��� = 2��RGB565/RGB1555��/ 3 (RGB888)/ 4��ARGB8888�� 
  */
	LTDC_Layer_InitStruct.LTDC_CFBLineLength = ((LCD_PIXEL_WIDTH * 4) + 3);
	
	 /* ��ĳ�е���ʼλ�õ���һ����ʼλ�ô�����������
  Pitch = ����Ч���ظ��� x ÿ�����ص��ֽ��� */ 
  LTDC_Layer_InitStruct.LTDC_CFBPitch = (LCD_PIXEL_WIDTH * 4);
	
	 /* ������Ч������ */  
  LTDC_Layer_InitStruct.LTDC_CFBLineNumber = LCD_PIXEL_HEIGHT;
  
    /* ����������ó�ʼ���� 1 ��*/
		LTDC_LayerInit(LTDC_Layer1, &LTDC_Layer_InitStruct);
	
		LTDC_LayerCmd(LTDC_Layer1, ENABLE);

		/* ������������ */  
		LTDC_ReloadConfig(LTDC_IMReload);

}



static void LCD_QingPing(void)
{
	uint16_t i,j;
	
	uint32_t *p = (uint32_t*)(LCD_LAYER1_START_ADDR);
	uint32_t *q = (uint32_t*)(LCD_LAYER2_START_ADDR);
	for(j=0;j<480;j++)
	for(i=0;i<800;i++)
	{
		*p = 0x00000000;
		*q = 0x00000000;
		p++;
		q++;
	}
}


void LCD_Config(void)
{
		LCD_GPIO_Config();
		LCD_Mode_Init();
		LCD_Top_LayerInit();
		LCD_Ground_LayerInit();
	
		/* ʹ�ܶ�����Ԫ */
		LTDC_DitherCmd(ENABLE);
		/* ���� */
		LCD_QingPing();
}





/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/**
  * @brief  ��ʾһ�����ص�
  * @param  x: ���ص��x����
  * @param  y: ���ص��y����
  * @param Current_Addr: ����
  * @param Current_ARGB: ARGBֵ
  * @retval None
  */
void PutPixel(int16_t x, int16_t y, uint32_t Current_Addr, uint32_t Current_ARGB)
{ 
  if(x < 0 || x > LCD_PIXEL_WIDTH || y < 0 || y > LCD_PIXEL_HEIGHT)
  {
    return;  
  }
#if 0
 LCD_DrawLine(x, y, 1, LCD_DIR_HORIZONTAL);
#else /*����ֱ�����Ч�ʹ��ƻ�ߵ�*/
 {
	  /*ARGB8888*/
	  uint32_t  Xaddress =0;
    Xaddress =  Current_Addr + 4*(LCD_PIXEL_WIDTH*y + x);
	  *(__IO uint16_t*) Xaddress= (0x00FFFF & Current_ARGB);              //GB
  	*(__IO uint16_t*)( Xaddress+2)= (0xFFFF0000 & Current_ARGB) >> 16;  //AR
  }
#endif
}





/**
  * @brief ��ʾһ��ֱ��
  * @param Xpos: ֱ������x����
  * @param Ypos: ֱ������y����
  * @param Length: ֱ�ߵĳ���
  * @param Direction: ֱ�ߵķ��򣬿�����LCD_DIR_HORIZONTAL(ˮƽ����) LCD_DIR_VERTICAL(��ֱ����).
  * @param Current_Addr: ����
  * @param Current_ARGB: ARGBֵ
  * @retval None
  */
void LCD_DrawLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint8_t Direction,uint32_t Current_Addr,uint32_t Current_ARGB)
{
  DMA2D_InitTypeDef      DMA2D_InitStruct;
  
  uint32_t  Xaddress = 0;
  uint16_t Red_Value = 0, Green_Value = 0, Blue_Value = 0, Alpha_Value = 0;
  
	/*����Ŀ���ַ*/
  Xaddress = Current_Addr + 4*(LCD_PIXEL_WIDTH*Ypos + Xpos);
 
	/*��ȡ��ɫ����*/
	Alpha_Value = (0xFF000000 & Current_ARGB) >>24;
  Red_Value = (0x00FF0000 & Current_ARGB) >>16;
  Green_Value = (0x0000FF00 &Current_ARGB)>>8 ;
	Blue_Value = 0x000000FF & Current_ARGB;
  /* ����DMA2D */    
  DMA2D_DeInit();  
  DMA2D_InitStruct.DMA2D_Mode = DMA2D_R2M;       
  DMA2D_InitStruct.DMA2D_CMode = DMA2D_ARGB8888;      
  DMA2D_InitStruct.DMA2D_OutputGreen = Green_Value;      
  DMA2D_InitStruct.DMA2D_OutputBlue = Blue_Value;     
  DMA2D_InitStruct.DMA2D_OutputRed = Red_Value;                
  DMA2D_InitStruct.DMA2D_OutputAlpha = Alpha_Value;                  
  DMA2D_InitStruct.DMA2D_OutputMemoryAdd = Xaddress;                  
  
	/*ˮƽ����*/
  if(Direction == LCD_DIR_HORIZONTAL)
  {                                                      
    DMA2D_InitStruct.DMA2D_OutputOffset = 0;                
    DMA2D_InitStruct.DMA2D_NumberOfLine = 1;            
    DMA2D_InitStruct.DMA2D_PixelPerLine = Length; 
  }
  else /*��ֱ����*/
  {                                                            
    DMA2D_InitStruct.DMA2D_OutputOffset = LCD_PIXEL_WIDTH - 1;                
    DMA2D_InitStruct.DMA2D_NumberOfLine = Length;            
    DMA2D_InitStruct.DMA2D_PixelPerLine = 1;  
  }
  
  DMA2D_Init(&DMA2D_InitStruct);  
  /*��ʼDMA2D���� */ 
  DMA2D_StartTransfer();  
  /*�ȴ�������� */
  while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET)
  {
  }  
}



/**
  * @brief  ��ʾһ������(����֮��)��
  * @param  x1: x1:ָ���� x1 ��λ�á�
  * @param  y1: x1:ָ���� y1 ��λ�á�
  * @param  x2: x1:ָ���� x2 ��λ�á�
  * @param  y2: x1:ָ���� y2 ��λ�á�
  * @param Current_Addr: ����
  * @param Current_ARGB: ARGBֵ
  * @retval None
  */
void LCD_DrawUniLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint32_t Current_Addr, uint32_t Current_ARGB)
{
  int16_t deltax = 0, deltay = 0, x = 0, y = 0, xinc1 = 0, xinc2 = 0, 
  yinc1 = 0, yinc2 = 0, den = 0, num = 0, numadd = 0, numpixels = 0, 
  curpixel = 0;
  
  deltax = ABS(x2 - x1);        /* The difference between the x's */
  deltay = ABS(y2 - y1);        /* The difference between the y's */
  x = x1;                       /* Start x off at the first pixel */
  y = y1;                       /* Start y off at the first pixel */
  
  if (x2 >= x1)                 /* The x-values are increasing */
  {
    xinc1 = 1;
    xinc2 = 1;
  }
  else                          /* The x-values are decreasing */
  {
    xinc1 = -1;
    xinc2 = -1;
  }
  
  if (y2 >= y1)                 /* The y-values are increasing */
  {
    yinc1 = 1;
    yinc2 = 1;
  }
  else                          /* The y-values are decreasing */
  {
    yinc1 = -1;
    yinc2 = -1;
  }
  
  if (deltax >= deltay)         /* There is at least one x-value for every y-value */
  {
    xinc1 = 0;                  /* Don't change the x when numerator >= denominator */
    yinc2 = 0;                  /* Don't change the y for every iteration */
    den = deltax;
    num = deltax / 2;
    numadd = deltay;
    numpixels = deltax;         /* There are more x-values than y-values */
  }
  else                          /* There is at least one y-value for every x-value */
  {
    xinc2 = 0;                  /* Don't change the x for every iteration */
    yinc1 = 0;                  /* Don't change the y when numerator >= denominator */
    den = deltay;
    num = deltay / 2;
    numadd = deltax;
    numpixels = deltay;         /* There are more y-values than x-values */
  }
  
  for (curpixel = 0; curpixel <= numpixels; curpixel++)
  {
    PutPixel(x, y, Current_Addr, Current_ARGB);             /* ԭʼ��ǰ���� */
    num += numadd;              /* Increase the numerator by the top of the fraction */
    if (num >= den)             /* Check if numerator >= denominator */
    {
      num -= den;               /* Calculate the new numerator value */
      x += xinc1;               /* Change the x as appropriate */
      y += yinc1;               /* Change the y as appropriate */
    }
    x += xinc2;                 /* Change the x as appropriate */
    y += yinc2;                 /* Change the y as appropriate */
  }
}






/**
  * @brief  ��ʾһ�����Ρ�
  * @param  Xpos:ָ��Xλ�ã�������0��240֮���ֵ��
  * @param  Ypos:ָ��Yλ�ã�������0��320֮���ֵ��
  * @param  Height:��ʾ���εĸ߶ȣ�������0��320֮���ֵ��
  * @param  Width:��ʾ���ο�ȣ�������0��240֮���ֵ��
  * @param Current_Addr: ����
  * @param Current_ARGB: ARGBֵ
  * @retval None
  */
void LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint32_t Current_Addr, uint32_t Current_ARGB)
{
  /* draw horizontal lines */
  LCD_DrawLine(Xpos, Ypos, Width, LCD_DIR_HORIZONTAL, Current_Addr, Current_ARGB);
  LCD_DrawLine(Xpos, (Ypos+ Height), Width, LCD_DIR_HORIZONTAL, Current_Addr, Current_ARGB);
  
  /* draw vertical lines */
  LCD_DrawLine(Xpos, Ypos, Height, LCD_DIR_VERTICAL, Current_Addr, Current_ARGB);
  LCD_DrawLine((Xpos + Width), Ypos, Height, LCD_DIR_VERTICAL, Current_Addr, Current_ARGB);
}





/**
  * @brief  ����ʵ�ľ���
  * @param  Xpos: ��ʼX����
  * @param  Ypos: ��ʼY����
  * @param  Height: ���θ�
  * @param  Width: ���ο�
  * @param Current_Addr: ����
  * @param Current_ARGB: ARGBֵ
  * @retval None
  */
void LCD_DrawFullRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint32_t Current_Addr, uint32_t Current_ARGB)
{
  DMA2D_InitTypeDef      DMA2D_InitStruct;
  
  uint32_t  Xaddress = 0;
  uint16_t Red_Value = 0, Green_Value = 0, Blue_Value = 0, Alpha_Value = 0;
  
	/*����Ŀ���ַ*/
  Xaddress = Current_Addr + 4*(LCD_PIXEL_WIDTH*Ypos + Xpos);
 
	/*��ȡ��ɫ����*/
	Alpha_Value = (0xFF000000 & Current_ARGB) >>24;
  Red_Value = (0x00FF0000 & Current_ARGB) >>16;
  Green_Value = (0x0000FF00 &Current_ARGB)>>8 ;
	Blue_Value = 0x000000FF & Current_ARGB;
  
  /* ����DMA2D DMA2D */
  DMA2D_DeInit();
  DMA2D_InitStruct.DMA2D_Mode = DMA2D_R2M;       
  DMA2D_InitStruct.DMA2D_CMode = DMA2D_ARGB8888;      
  DMA2D_InitStruct.DMA2D_OutputGreen = Green_Value;      
  DMA2D_InitStruct.DMA2D_OutputBlue = Blue_Value;     
  DMA2D_InitStruct.DMA2D_OutputRed = Red_Value;                
  DMA2D_InitStruct.DMA2D_OutputAlpha = Alpha_Value;                  
  DMA2D_InitStruct.DMA2D_OutputMemoryAdd = Xaddress;                
  DMA2D_InitStruct.DMA2D_OutputOffset = (LCD_PIXEL_WIDTH - Width);                
  DMA2D_InitStruct.DMA2D_NumberOfLine = Height;            
  DMA2D_InitStruct.DMA2D_PixelPerLine = Width;
  DMA2D_Init(&DMA2D_InitStruct); 
  
  /* ��ʼDMA2D���� */ 
  DMA2D_StartTransfer();
  
  /* �ȴ�������� */
  while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET)
  {
  } 

//  LCD_SetTextColor(CurrentTextColor);
}




/**
  * @brief  ���һ��������(��3����֮��)��
  * @param  x1..3: x position of triangle point 1..3.
  * @param  y1..3: y position of triangle point 1..3.
	* @param Current_Addr: ����
  * @param Current_ARGB: ARGBֵ
  * @retval None
  */
void LCD_FillTriangle(uint16_t x1, uint16_t x2, uint16_t x3, uint16_t y1, uint16_t y2, uint16_t y3, uint32_t Current_Addr, uint32_t Current_ARGB)
{ 
  
  int16_t deltax = 0, deltay = 0, x = 0, y = 0, xinc1 = 0, xinc2 = 0, 
  yinc1 = 0, yinc2 = 0, den = 0, num = 0, numadd = 0, numpixels = 0, 
  curpixel = 0;
  
  deltax = ABS(x2 - x1);        /* The difference between the x's */
  deltay = ABS(y2 - y1);        /* The difference between the y's */
  x = x1;                       /* Start x off at the first pixel */
  y = y1;                       /* Start y off at the first pixel */
  
  if (x2 >= x1)                 /* The x-values are increasing */
  {
    xinc1 = 1;
    xinc2 = 1;
  }
  else                          /* The x-values are decreasing */
  {
    xinc1 = -1;
    xinc2 = -1;
  }
  
  if (y2 >= y1)                 /* The y-values are increasing */
  {
    yinc1 = 1;
    yinc2 = 1;
  }
  else                          /* The y-values are decreasing */
  {
    yinc1 = -1;
    yinc2 = -1;
  }
  
  if (deltax >= deltay)         /* There is at least one x-value for every y-value */
  {
    xinc1 = 0;                  /* Don't change the x when numerator >= denominator */
    yinc2 = 0;                  /* Don't change the y for every iteration */
    den = deltax;
    num = deltax / 2;
    numadd = deltay;
    numpixels = deltax;         /* There are more x-values than y-values */
  }
  else                          /* There is at least one y-value for every x-value */
  {
    xinc2 = 0;                  /* Don't change the x for every iteration */
    yinc1 = 0;                  /* Don't change the y when numerator >= denominator */
    den = deltay;
    num = deltay / 2;
    numadd = deltax;
    numpixels = deltay;         /* There are more y-values than x-values */
  }
  
  for (curpixel = 0; curpixel <= numpixels; curpixel++)
  {
    LCD_DrawUniLine(x, y, x3, y3,Current_Addr,Current_ARGB);
    
    num += numadd;              /* Increase the numerator by the top of the fraction */
    if (num >= den)             /* Check if numerator >= denominator */
    {
      num -= den;               /* Calculate the new numerator value */
      x += xinc1;               /* Change the x as appropriate */
      y += yinc1;               /* Change the y as appropriate */
    }
    x += xinc2;                 /* Change the x as appropriate */
    y += yinc2;                 /* Change the y as appropriate */
  }  
  
  
}



/**
  * @brief  ��һ��Բ��
  * @param  Xpos:ָ��Xλ�ã�������0��240֮���ֵ��
  * @param  Ypos:ָ��Yλ�ã�������0��320֮���ֵ��
  * @param  Radius:Բ�İ뾶��
  * @param Current_Addr: ����
  * @param Current_ARGB: ARGBֵ
  * @retval None
  */
void LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius, uint32_t Current_Addr, uint32_t Current_ARGB)
{
  
    int x = -Radius, y = 0, err = 2-2*Radius, e2;
    do {
      

        *(__IO uint16_t*) (Current_Addr + (4*((Xpos-x) + LCD_PIXEL_WIDTH*(Ypos+y))))= (0x0000FFFF & Current_ARGB);       //GB
        *(__IO uint16_t*)(Current_Addr + (4*((Xpos-x) + LCD_PIXEL_WIDTH*(Ypos+y))+2))= (0xFFFF0000 & Current_ARGB) >> 16;//AR
      
        *(__IO uint16_t*) (Current_Addr + (4*((Xpos+x) + LCD_PIXEL_WIDTH*(Ypos+y)))) = (0x0000FFFF & Current_ARGB);      //GB
        *(__IO uint16_t*)(Current_Addr + (4*((Xpos+x) + LCD_PIXEL_WIDTH*(Ypos+y))+2))= (0xFFFF0000 & Current_ARGB) >> 16;//AR
      
        *(__IO uint16_t*) (Current_Addr + (4*((Xpos+x) + LCD_PIXEL_WIDTH*(Ypos-y)))) = (0x0000FFFF & Current_ARGB);      //GB
        *(__IO uint16_t*)(Current_Addr + (4*((Xpos+x) + LCD_PIXEL_WIDTH*(Ypos-y))+2))= (0xFFFF0000 & Current_ARGB) >> 16;//AR
      
        *(__IO uint16_t*) (Current_Addr + (4*((Xpos-x) + LCD_PIXEL_WIDTH*(Ypos-y)))) = (0x0000FFFF & Current_ARGB);      //GB
        *(__IO uint16_t*)(Current_Addr + (4*((Xpos-x) + LCD_PIXEL_WIDTH*(Ypos-y))+2))= (0xFFFF0000 & Current_ARGB) >> 16;//AR


        e2 = err;
        if (e2 <= y) {
            err += ++y*2+1;
            if (-x == y && e2 <= x) e2 = 0;
        }
        if (e2 > x) err += ++x*2+1;
    }
    while (x <= 0);
    
}

/**
  * @brief  ��ʾһ��������Բ��
  * @param  Xpos:ָ��Xλ�ã�������0��240֮���ֵ��
  * @param  Ypos:ָ��Yλ�ã�������0��320֮���ֵ��
  * @param  �뾶
  * @param Current_Addr: ����
  * @param Current_ARGB: ARGBֵ
  * @retval None
  */
void LCD_DrawFullCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius, uint32_t Current_Addr, uint32_t Current_ARGB)
{
  int32_t  D;    /* Decision Variable */ 
  uint32_t  CurX;/* Current X Value */
  uint32_t  CurY;/* Current Y Value */ 
  
  D = 3 - (Radius << 1);
  
  CurX = 0;
  CurY = Radius;
  
  while (CurX <= CurY)
  {
    if(CurY > 0) 
    {
      LCD_DrawLine(Xpos - CurX, Ypos - CurY, 2*CurY, LCD_DIR_VERTICAL,Current_Addr,Current_ARGB);
      LCD_DrawLine(Xpos + CurX, Ypos - CurY, 2*CurY, LCD_DIR_VERTICAL,Current_Addr,Current_ARGB);
    }
    
    if(CurX > 0) 
    {
      LCD_DrawLine(Xpos - CurY, Ypos - CurX, 2*CurX, LCD_DIR_VERTICAL,Current_Addr,Current_ARGB);
      LCD_DrawLine(Xpos + CurY, Ypos - CurX, 2*CurX, LCD_DIR_VERTICAL,Current_Addr,Current_ARGB);
    }
    if (D < 0)
    { 
      D += (CurX << 2) + 6;
    }
    else
    {
      D += ((CurX - CurY) << 2) + 10;
      CurY--;
    }
    CurX++;
  }
  
  LCD_DrawCircle(Xpos, Ypos, Radius,Current_Addr,Current_ARGB);  
}





/**
  * @brief  ��ʾһ����Բ��
  * @param  Xpos:ָ��Xλ�ã�������0��240֮���ֵ��
  * @param  Ypos:ָ��Yλ�ã�������0��320֮���ֵ��
  * @param  Radius:ָ���뾶��
  * @param  Radius2:ָ���뾶��
  * @param Current_Addr: ����
  * @param Current_ARGB: ARGBֵ
  * @retval None
  */
void LCD_DrawEllipse(int Xpos, int Ypos, int Radius, int Radius2, uint32_t Current_Addr, uint32_t Current_ARGB)
{
  int x = -Radius, y = 0, err = 2-2*Radius, e2;
  float K = 0, rad1 = 0, rad2 = 0;
   
  rad1 = Radius;
  rad2 = Radius2;
  
  if (Radius > Radius2)
  { 
    do {
      K = (float)(rad1/rad2);
   
      *(__IO uint16_t*)(Current_Addr + (4*((Xpos-x) + LCD_PIXEL_WIDTH*(Ypos+(uint16_t)(y/K))))) = (0x0000FFFF & Current_ARGB);        //GB
      *(__IO uint8_t*)(Current_Addr + (4*((Xpos-x) + LCD_PIXEL_WIDTH*(Ypos+(uint16_t)(y/K)))+2)) = (0xFFFF0000 & Current_ARGB) >> 16; //AR
     
      *(__IO uint16_t*)(Current_Addr + (4*((Xpos+x) + LCD_PIXEL_WIDTH*(Ypos+(uint16_t)(y/K))))) = (0x0000FFFF & Current_ARGB);        //GB
      *(__IO uint8_t*)(Current_Addr + (4*((Xpos+x) + LCD_PIXEL_WIDTH*(Ypos+(uint16_t)(y/K)))+2)) = (0xFFFF0000 & Current_ARGB) >> 16; //AR

      *(__IO uint16_t*)(Current_Addr + (4*((Xpos+x) + LCD_PIXEL_WIDTH*(Ypos-(uint16_t)(y/K))))) = (0x0000FFFF & Current_ARGB);        //GB
      *(__IO uint8_t*)(Current_Addr + (4*((Xpos+x) + LCD_PIXEL_WIDTH*(Ypos-(uint16_t)(y/K)))+2)) = (0xFFFF0000 & Current_ARGB) >> 16; //AR

      *(__IO uint16_t*)(Current_Addr + (4*((Xpos-x) + LCD_PIXEL_WIDTH*(Ypos-(uint16_t)(y/K))))) = (0x0000FFFF & Current_ARGB);        //GB
      *(__IO uint8_t*)(Current_Addr + (4*((Xpos-x) + LCD_PIXEL_WIDTH*(Ypos-(uint16_t)(y/K)))+2)) = (0xFFFF0000 & Current_ARGB) >> 16; //AR

      
      e2 = err;
      if (e2 <= y) {
        err += ++y*2+1;
        if (-x == y && e2 <= x) e2 = 0;
      }
      if (e2 > x) err += ++x*2+1;
    }
    while (x <= 0);
  }
  else
  {
    y = -Radius2; 
    x = 0;
    do { 
      K = (float)(rad2/rad1);

      *(__IO uint16_t*)(Current_Addr + (4*((Xpos-(uint16_t)(x/K)) + LCD_PIXEL_WIDTH*(Ypos+y))))= (0x0000FFFF & Current_ARGB);        //GB
      *(__IO uint8_t*)(Current_Addr + (4*((Xpos-(uint16_t)(x/K)) + LCD_PIXEL_WIDTH*(Ypos+y))+2)) = (0xFFFF0000 & Current_ARGB) >> 16;//AR

      *(__IO uint16_t*)(Current_Addr + (4*((Xpos+(uint16_t)(x/K)) + LCD_PIXEL_WIDTH*(Ypos+y))))= (0x0000FFFF & Current_ARGB);        //GB
      *(__IO uint8_t*)(Current_Addr + (4*((Xpos+(uint16_t)(x/K)) + LCD_PIXEL_WIDTH*(Ypos+y))+2)) = (0xFFFF0000 & Current_ARGB) >> 16;//AR

      *(__IO uint16_t*)(Current_Addr + (4*((Xpos+(uint16_t)(x/K)) + LCD_PIXEL_WIDTH*(Ypos-y))))= (0x0000FFFF & Current_ARGB);        //GB
      *(__IO uint8_t*)(Current_Addr + (4*((Xpos+(uint16_t)(x/K)) + LCD_PIXEL_WIDTH*(Ypos-y))+2)) = (0xFFFF0000 & Current_ARGB) >> 16;//AR

      *(__IO uint16_t*)(Current_Addr + (4*((Xpos-(uint16_t)(x/K)) + LCD_PIXEL_WIDTH*(Ypos-y))))= (0x0000FFFF & Current_ARGB);        //GB
      *(__IO uint8_t*)(Current_Addr + (4*((Xpos-(uint16_t)(x/K)) + LCD_PIXEL_WIDTH*(Ypos-y))+2)) = (0xFFFF0000 & Current_ARGB) >> 16;//AR

      
      e2 = err;
      if (e2 <= x) {
        err += ++x*3+1;
        if (-y == x && e2 <= y) e2 = 0;
      }
      if (e2 > y) err += ++y*3+1;     
    }
    while (y <= 0);
  }
}


/**
  * @brief  ��һ����������Բ��
  * @param  Xpos:ָ��Xλ�ã�������0��240֮���ֵ��
  * @param  Ypos:ָ��Yλ�ã�������0��320֮���ֵ��
  * @param  Radius:ָ���뾶��
  * @param  Radius2:ָ���뾶��
  * @param Current_Addr: ����
  * @param Current_ARGB: ARGBֵ
  * @retval None
  */
void LCD_DrawFullEllipse(int Xpos, int Ypos, int Radius, int Radius2,uint32_t Current_Addr,uint32_t Current_ARGB)
{
  int x = -Radius, y = 0, err = 2-2*Radius, e2;
  float K = 0, rad1 = 0, rad2 = 0;
  
  rad1 = Radius;
  rad2 = Radius2;
  
  if (Radius > Radius2)
  { 
    do 
    {
      K = (float)(rad1/rad2);
      LCD_DrawLine((Xpos+x), (Ypos-(uint16_t)(y/K)), (2*(uint16_t)(y/K) + 1), LCD_DIR_VERTICAL,Current_Addr,Current_ARGB);
      LCD_DrawLine((Xpos-x), (Ypos-(uint16_t)(y/K)), (2*(uint16_t)(y/K) + 1), LCD_DIR_VERTICAL,Current_Addr,Current_ARGB);
      
      e2 = err;
      if (e2 <= y) 
      {
        err += ++y*2+1;
        if (-x == y && e2 <= x) e2 = 0;
      }
      if (e2 > x) err += ++x*2+1;
      
    }
    while (x <= 0);
  }
  else
  {
    y = -Radius2; 
    x = 0;
    do 
    { 
      K = (float)(rad2/rad1);       
      LCD_DrawLine((Xpos-(uint16_t)(x/K)), (Ypos+y), (2*(uint16_t)(x/K) + 1), LCD_DIR_HORIZONTAL,Current_Addr,Current_ARGB);
      LCD_DrawLine((Xpos-(uint16_t)(x/K)), (Ypos-y), (2*(uint16_t)(x/K) + 1), LCD_DIR_HORIZONTAL,Current_Addr,Current_ARGB);
      
      e2 = err;
      if (e2 <= x) 
      {
        err += ++x*2+1;
        if (-y == x && e2 <= y) e2 = 0;
      }
      if (e2 > y) err += ++y*2+1;
    }
    while (y <= 0);
  }
}
/*-----------------------------------------------------------------------------------------------------------------------------*/






/*------------------------------------------------------------------------------------------------------------------------------------*/

void DMA2D_TOP_DIS_RECT(void)
{
	DMA2D_InitTypeDef DMA2D_InitStruct;
	
	DMA2D_InitStruct.DMA2D_Mode = DMA2D_R2M;
	DMA2D_InitStruct.DMA2D_CMode = DMA2D_ARGB8888;
	
	/* ��ɫֵ */
	DMA2D_InitStruct.DMA2D_OutputRed = 0;
	DMA2D_InitStruct.DMA2D_OutputGreen = 0;
	DMA2D_InitStruct.DMA2D_OutputBlue = 255;
	DMA2D_InitStruct.DMA2D_OutputAlpha = 0x7f;
	
	DMA2D_InitStruct.DMA2D_OutputMemoryAdd = LCD_LAYER2_START_ADDR+LCD_PIXEL_WIDTH*140*4+300*4;//���䵽���Դ��ַ
	DMA2D_InitStruct.DMA2D_OutputOffset = 800-300;
	DMA2D_InitStruct.DMA2D_PixelPerLine = 300;
	DMA2D_InitStruct.DMA2D_NumberOfLine = 300;
	
	DMA2D_Init(&DMA2D_InitStruct);
	
	DMA2D_StartTransfer();
	while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET)
	{
	}
}

void DMA2D_GROUND_DIS_RECT(void)
{
	DMA2D_InitTypeDef DMA2D_InitStruct;
	
	DMA2D_InitStruct.DMA2D_Mode = DMA2D_R2M;
	DMA2D_InitStruct.DMA2D_CMode = DMA2D_ARGB8888;
	
	/* ��ɫֵ */
	DMA2D_InitStruct.DMA2D_OutputRed = 255;
	DMA2D_InitStruct.DMA2D_OutputGreen = 0;
	DMA2D_InitStruct.DMA2D_OutputBlue = 0;
	DMA2D_InitStruct.DMA2D_OutputAlpha = 0x7f;
	
	DMA2D_InitStruct.DMA2D_OutputMemoryAdd = LCD_LAYER1_START_ADDR+LCD_PIXEL_WIDTH*100*4+250*4;//���䵽���Դ��ַ
	DMA2D_InitStruct.DMA2D_OutputOffset = 800-200;
	DMA2D_InitStruct.DMA2D_PixelPerLine = 200;
	DMA2D_InitStruct.DMA2D_NumberOfLine = 200;
	
	DMA2D_Init(&DMA2D_InitStruct);
	
	DMA2D_StartTransfer();
	while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET)
	{
	}
}





