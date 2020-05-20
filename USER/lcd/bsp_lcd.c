#include "./lcd/bsp_lcd.h"
#include "./spi/bsp_spi_flash.h"



static void LCD_GPIO_Config(void)
{ 
	GPIO_InitTypeDef GPIO_InitStruct;
  
  /* 使能LCD使用到的引脚时钟 */
                          //红色数据线
  RCC_AHB1PeriphClockCmd(LTDC_R0_GPIO_CLK | LTDC_R1_GPIO_CLK | LTDC_R2_GPIO_CLK| 
                         LTDC_R3_GPIO_CLK | LTDC_R4_GPIO_CLK | LTDC_R5_GPIO_CLK|
                         LTDC_R6_GPIO_CLK | LTDC_R7_GPIO_CLK |
                          //绿色数据线
                          LTDC_G0_GPIO_CLK|LTDC_G1_GPIO_CLK|LTDC_G2_GPIO_CLK|
                          LTDC_G3_GPIO_CLK|LTDC_G4_GPIO_CLK|LTDC_G5_GPIO_CLK|
                          LTDC_G6_GPIO_CLK|LTDC_G7_GPIO_CLK|
                          //蓝色数据线
                          LTDC_B0_GPIO_CLK|LTDC_B1_GPIO_CLK|LTDC_B2_GPIO_CLK|
                          LTDC_B3_GPIO_CLK|LTDC_B4_GPIO_CLK|LTDC_B5_GPIO_CLK|
                          LTDC_B6_GPIO_CLK|LTDC_B7_GPIO_CLK|
                          //控制信号线
                          LTDC_CLK_GPIO_CLK | LTDC_HSYNC_GPIO_CLK |LTDC_VSYNC_GPIO_CLK|
                          LTDC_DE_GPIO_CLK  | LTDC_BL_GPIO_CLK    |LTDC_DISP_GPIO_CLK ,ENABLE);

/* GPIO配置 */

 /* 红色数据线 */
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
  
  //绿色数据线
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
  
  //蓝色数据线
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
  
  //控制信号线
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
  
  //背光BL 及液晶使能信号DISP
  GPIO_InitStruct.GPIO_Pin = LTDC_DISP_GPIO_PIN;                             
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  
  GPIO_Init(LTDC_DISP_GPIO_PORT, &GPIO_InitStruct);
  
  
  GPIO_InitStruct.GPIO_Pin = LTDC_BL_GPIO_PIN; 
  GPIO_Init(LTDC_BL_GPIO_PORT, &GPIO_InitStruct);
  
  //拉高使能lcd
  GPIO_SetBits(LTDC_DISP_GPIO_PORT,LTDC_DISP_GPIO_PIN);
  GPIO_SetBits(LTDC_BL_GPIO_PORT,LTDC_BL_GPIO_PIN);


}
/* 配置LTDC外设:配置像素同步时钟CLK，配置LTDC时间参数及信号极性 */
static void LCD_Mode_Init(void)
{ 
  LTDC_InitTypeDef       LTDC_InitStruct;
  
  /* 使能LTDC外设时钟 */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_LTDC, ENABLE);
	/* 使能DMA2D时钟 */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2D, ENABLE);

	
	/* 配置 PLLSAI 分频器，它的输出作为像素同步时钟CLK*/
	/* LTDC时钟太高会导花屏，若对刷屏速度要求不高，降低时钟频率可减少花屏现象*/
  /* PLLSAI_VCO 输入时钟 = HSE_VALUE/PLL_M = 1 Mhz */
  /* PLLSAI_VCO 输出时钟 = PLLSAI_VCO输入 * PLLSAI_N  */
  /* PLLLCDCLK = PLLSAI_VCO 输出/PLLSAI_R */
  /* LTDC 时钟频率 = PLLLCDCLK / DIV */
	/* 以下函数三个参数分别为：PLLSAIN,PLLSAIQ,PLLSAIR，其中PLLSAIQ与LTDC无关*/
	
  RCC_PLLSAIConfig(200,20,2);         //200/2/4=25MHZ
	/*以下函数的参数为DIV值*/
  RCC_LTDCCLKDivConfig(RCC_PLLSAIDivR_Div8);
  /* 使能 PLLSAI 时钟 */
  RCC_PLLSAICmd(ENABLE);
  /* 等待 PLLSAI 初始化完成 */
  while(RCC_GetFlagStatus(RCC_FLAG_PLLSAIRDY) == RESET)
  {
  }
  
  /* LTDC配置*********************************************************/  
  /*信号极性配置*/
  /* 行同步信号极性 */
  LTDC_InitStruct.LTDC_HSPolarity = LTDC_HSPolarity_AL;     
  /* 垂直同步信号极性 */  
  LTDC_InitStruct.LTDC_VSPolarity = LTDC_VSPolarity_AL;     
  /* 数据使能信号极性 */
  LTDC_InitStruct.LTDC_DEPolarity = LTDC_DEPolarity_AL;     
  /* 像素同步时钟极性 */ 
  LTDC_InitStruct.LTDC_PCPolarity = LTDC_PCPolarity_IPC;
  
  /* 配置LCD背景颜色 */                   
  LTDC_InitStruct.LTDC_BackgroundRedValue = 0xFF;            
  LTDC_InitStruct.LTDC_BackgroundGreenValue = 255;          
  LTDC_InitStruct.LTDC_BackgroundBlueValue = 0xFF;    
 
  /* 时间参数配置 */  
 /* 配置行同步信号宽度(HSW-1) */
 LTDC_InitStruct.LTDC_HorizontalSync =HSW-1;
 /* 配置垂直同步信号宽度(VSW-1) */
 LTDC_InitStruct.LTDC_VerticalSync = VSW-1;
 /* 配置(HSW+HBP-1) */
 LTDC_InitStruct.LTDC_AccumulatedHBP =HSW+HBP-1;
 /* 配置(VSW+VBP-1) */
 LTDC_InitStruct.LTDC_AccumulatedVBP = VSW+VBP-1;
 /* 配置(HSW+HBP+有效像素宽度-1) */
 LTDC_InitStruct.LTDC_AccumulatedActiveW = HSW+HBP+LCD_PIXEL_WIDTH-1;
 /* 配置(VSW+VBP+有效像素高度-1) */
 LTDC_InitStruct.LTDC_AccumulatedActiveH = VSW+VBP+LCD_PIXEL_HEIGHT-1;
 /* 配置总宽度(HSW+HBP+有效像素宽度+HFP-1) */
 LTDC_InitStruct.LTDC_TotalWidth =HSW+ HBP+LCD_PIXEL_WIDTH  + HFP-1; 
 /* 配置总高度(VSW+VBP+有效像素高度+VFP-1) */
 LTDC_InitStruct.LTDC_TotalHeigh =VSW+ VBP+LCD_PIXEL_HEIGHT  + VFP-1;

  LTDC_Init(&LTDC_InitStruct);
  
  LTDC_Cmd(ENABLE);
}  



/* 初始化LTD的 顶层 参数,设置显存空间,设置分辨率 */
static void LCD_Top_LayerInit(void)
{
  LTDC_Layer_InitTypeDef LTDC_Layer_InitStruct; 
  
  /* 层窗口配置 */
  /* 配置本层的窗口边界，注意这些参数是包含HBP HSW VBP VSW的 */    
	//一行的第一个起始像素，该成员值应用为 (LTDC_InitStruct.LTDC_AccumulatedHBP+1)的值
	LTDC_Layer_InitStruct.LTDC_HorizontalStart = HBP + HSW;
	//一行的最后一个像素，该成员值应用为 (LTDC_InitStruct.LTDC_AccumulatedActiveW)的值
	LTDC_Layer_InitStruct.LTDC_HorizontalStop = HSW+HBP+LCD_PIXEL_WIDTH-1;
	//一列的第一个起始像素，该成员值应用为 (LTDC_InitStruct.LTDC_AccumulatedVBP+1)的值
	LTDC_Layer_InitStruct.LTDC_VerticalStart =  VBP + VSW;
	//一列的最后一个像素，该成员值应用为 (LTDC_InitStruct.LTDC_AccumulatedActiveH)的值
	LTDC_Layer_InitStruct.LTDC_VerticalStop = VSW+VBP+LCD_PIXEL_HEIGHT-1;
	
  /* 像素格式配置*/
  LTDC_Layer_InitStruct.LTDC_PixelFormat = LTDC_Pixelformat_ARGB8888;
  /* 恒定Alpha值配置，0-255 */
  LTDC_Layer_InitStruct.LTDC_ConstantAlpha = 0xFF; 
  /* 默认背景颜色，该颜色在定义的层窗口外或在层禁止时使用。 */          
  LTDC_Layer_InitStruct.LTDC_DefaultColorRed = 255;        
  LTDC_Layer_InitStruct.LTDC_DefaultColorGreen = 255;       
  LTDC_Layer_InitStruct.LTDC_DefaultColorBlue = 255;         
  LTDC_Layer_InitStruct.LTDC_DefaultColorAlpha = 0;
  /* 配置混合因子 CA 表示层透明度，PAxCA 表示层和像素透明度共同作用 */       
  LTDC_Layer_InitStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_PAxCA;    
  LTDC_Layer_InitStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_PAxCA; 
  
  /* 配置本层的显存首地址 */    
  LTDC_Layer_InitStruct.LTDC_CFBStartAdress = LCD_LAYER2_START_ADDR;
	
	 /* 该成员应写入(一行像素数据占用的字节数+3)
  Line Lenth = 行有效像素个数 x 每个像素的字节数 + 3 
  行有效像素个数 = LCD_PIXEL_WIDTH 
  每个像素的字节数 = 2（RGB565/RGB1555）/ 3 (RGB888)/ 4（ARGB8888） 
  */
	LTDC_Layer_InitStruct.LTDC_CFBLineLength = ((LCD_PIXEL_WIDTH * 4) + 3);
	
	 /* 从某行的起始位置到下一行起始位置处的像素增量
  Pitch = 行有效像素个数 x 每个像素的字节数 */ 
  LTDC_Layer_InitStruct.LTDC_CFBPitch = (LCD_PIXEL_WIDTH * 4);
	
	 /* 配置有效的行数 */  
  LTDC_Layer_InitStruct.LTDC_CFBLineNumber = LCD_PIXEL_HEIGHT;
  
  /* 以上面的配置初始化第 2 层*/
		LTDC_LayerInit(LTDC_Layer2, &LTDC_Layer_InitStruct);
	 
		LTDC_LayerCmd(LTDC_Layer2, ENABLE);
	
	  /* 立即重载配置 */  
		LTDC_ReloadConfig(LTDC_IMReload);
		
}




/* 初始化LTD的 底层 参数,设置显存空间,设置分辨率 */
static void LCD_Ground_LayerInit(void)
{
  LTDC_Layer_InitTypeDef LTDC_Layer_InitStruct; 
  
  /* 层窗口配置 */
  /* 配置本层的窗口边界，注意这些参数是包含HBP HSW VBP VSW的 */    
	//一行的第一个起始像素，该成员值应用为 (LTDC_InitStruct.LTDC_AccumulatedHBP+1)的值
	LTDC_Layer_InitStruct.LTDC_HorizontalStart = HBP + HSW;
	//一行的最后一个像素，该成员值应用为 (LTDC_InitStruct.LTDC_AccumulatedActiveW)的值
	LTDC_Layer_InitStruct.LTDC_HorizontalStop = HSW+HBP+LCD_PIXEL_WIDTH-1;
	//一列的第一个起始像素，该成员值应用为 (LTDC_InitStruct.LTDC_AccumulatedVBP+1)的值
	LTDC_Layer_InitStruct.LTDC_VerticalStart =  VBP + VSW;
	//一列的最后一个像素，该成员值应用为 (LTDC_InitStruct.LTDC_AccumulatedActiveH)的值
	LTDC_Layer_InitStruct.LTDC_VerticalStop = VSW+VBP+LCD_PIXEL_HEIGHT-1;
	
  /* 像素格式配置*/
  LTDC_Layer_InitStruct.LTDC_PixelFormat = LTDC_Pixelformat_ARGB8888;
  /* 恒定Alpha值配置，0-255 */
  LTDC_Layer_InitStruct.LTDC_ConstantAlpha = 0xFF; 
  /* 默认背景颜色，该颜色在定义的层窗口外或在层禁止时使用。 */          
  LTDC_Layer_InitStruct.LTDC_DefaultColorRed = 255;        
  LTDC_Layer_InitStruct.LTDC_DefaultColorGreen = 255;       
  LTDC_Layer_InitStruct.LTDC_DefaultColorBlue = 255;         
  LTDC_Layer_InitStruct.LTDC_DefaultColorAlpha = 0;
  /* 配置混合因子 CA 表示层透明度，PAxCA 表示层和像素透明度共同作用 */       
  LTDC_Layer_InitStruct.LTDC_BlendingFactor_1 = LTDC_BlendingFactor1_PAxCA;    
  LTDC_Layer_InitStruct.LTDC_BlendingFactor_2 = LTDC_BlendingFactor2_PAxCA; 
  
  /* 配置本层的显存首地址 */    
  LTDC_Layer_InitStruct.LTDC_CFBStartAdress = LCD_LAYER1_START_ADDR;
	
	 /* 该成员应写入(一行像素数据占用的字节数+3)
  Line Lenth = 行有效像素个数 x 每个像素的字节数 + 3 
  行有效像素个数 = LCD_PIXEL_WIDTH 
  每个像素的字节数 = 2（RGB565/RGB1555）/ 3 (RGB888)/ 4（ARGB8888） 
  */
	LTDC_Layer_InitStruct.LTDC_CFBLineLength = ((LCD_PIXEL_WIDTH * 4) + 3);
	
	 /* 从某行的起始位置到下一行起始位置处的像素增量
  Pitch = 行有效像素个数 x 每个像素的字节数 */ 
  LTDC_Layer_InitStruct.LTDC_CFBPitch = (LCD_PIXEL_WIDTH * 4);
	
	 /* 配置有效的行数 */  
  LTDC_Layer_InitStruct.LTDC_CFBLineNumber = LCD_PIXEL_HEIGHT;
  
    /* 以上面的配置初始化第 1 层*/
		LTDC_LayerInit(LTDC_Layer1, &LTDC_Layer_InitStruct);
	
		LTDC_LayerCmd(LTDC_Layer1, ENABLE);

		/* 立即重载配置 */  
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
	
		/* 使能抖动单元 */
		LTDC_DitherCmd(ENABLE);
		/* 清屏 */
		LCD_QingPing();
}





/*-----------------------------------------------------------------------------------------------------------------------------------------*/

/**
  * @brief  显示一个像素点
  * @param  x: 像素点的x坐标
  * @param  y: 像素点的y坐标
  * @param Current_Addr: 层数
  * @param Current_ARGB: ARGB值
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
#else /*这样直接描点效率估计会高点*/
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
  * @brief 显示一条直线
  * @param Xpos: 直线起点的x坐标
  * @param Ypos: 直线起点的y坐标
  * @param Length: 直线的长度
  * @param Direction: 直线的方向，可输入LCD_DIR_HORIZONTAL(水平方向) LCD_DIR_VERTICAL(垂直方向).
  * @param Current_Addr: 层数
  * @param Current_ARGB: ARGB值
  * @retval None
  */
void LCD_DrawLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length, uint8_t Direction,uint32_t Current_Addr,uint32_t Current_ARGB)
{
  DMA2D_InitTypeDef      DMA2D_InitStruct;
  
  uint32_t  Xaddress = 0;
  uint16_t Red_Value = 0, Green_Value = 0, Blue_Value = 0, Alpha_Value = 0;
  
	/*计算目标地址*/
  Xaddress = Current_Addr + 4*(LCD_PIXEL_WIDTH*Ypos + Xpos);
 
	/*提取颜色分量*/
	Alpha_Value = (0xFF000000 & Current_ARGB) >>24;
  Red_Value = (0x00FF0000 & Current_ARGB) >>16;
  Green_Value = (0x0000FF00 &Current_ARGB)>>8 ;
	Blue_Value = 0x000000FF & Current_ARGB;
  /* 配置DMA2D */    
  DMA2D_DeInit();  
  DMA2D_InitStruct.DMA2D_Mode = DMA2D_R2M;       
  DMA2D_InitStruct.DMA2D_CMode = DMA2D_ARGB8888;      
  DMA2D_InitStruct.DMA2D_OutputGreen = Green_Value;      
  DMA2D_InitStruct.DMA2D_OutputBlue = Blue_Value;     
  DMA2D_InitStruct.DMA2D_OutputRed = Red_Value;                
  DMA2D_InitStruct.DMA2D_OutputAlpha = Alpha_Value;                  
  DMA2D_InitStruct.DMA2D_OutputMemoryAdd = Xaddress;                  
  
	/*水平方向*/
  if(Direction == LCD_DIR_HORIZONTAL)
  {                                                      
    DMA2D_InitStruct.DMA2D_OutputOffset = 0;                
    DMA2D_InitStruct.DMA2D_NumberOfLine = 1;            
    DMA2D_InitStruct.DMA2D_PixelPerLine = Length; 
  }
  else /*垂直方向*/
  {                                                            
    DMA2D_InitStruct.DMA2D_OutputOffset = LCD_PIXEL_WIDTH - 1;                
    DMA2D_InitStruct.DMA2D_NumberOfLine = Length;            
    DMA2D_InitStruct.DMA2D_PixelPerLine = 1;  
  }
  
  DMA2D_Init(&DMA2D_InitStruct);  
  /*开始DMA2D传输 */ 
  DMA2D_StartTransfer();  
  /*等待传输结束 */
  while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET)
  {
  }  
}



/**
  * @brief  显示一条单线(两点之间)。
  * @param  x1: x1:指定点 x1 的位置。
  * @param  y1: x1:指定点 y1 的位置。
  * @param  x2: x1:指定点 x2 的位置。
  * @param  y2: x1:指定点 y2 的位置。
  * @param Current_Addr: 层数
  * @param Current_ARGB: ARGB值
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
    PutPixel(x, y, Current_Addr, Current_ARGB);             /* 原始当前像素 */
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
  * @brief  显示一个矩形。
  * @param  Xpos:指定X位置，可以是0到240之间的值。
  * @param  Ypos:指定Y位置，可以是0到320之间的值。
  * @param  Height:显示矩形的高度，可以是0到320之间的值。
  * @param  Width:显示矩形宽度，可以是0到240之间的值。
  * @param Current_Addr: 层数
  * @param Current_ARGB: ARGB值
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
  * @brief  绘制实心矩形
  * @param  Xpos: 起始X坐标
  * @param  Ypos: 起始Y坐标
  * @param  Height: 矩形高
  * @param  Width: 矩形宽
  * @param Current_Addr: 层数
  * @param Current_ARGB: ARGB值
  * @retval None
  */
void LCD_DrawFullRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint32_t Current_Addr, uint32_t Current_ARGB)
{
  DMA2D_InitTypeDef      DMA2D_InitStruct;
  
  uint32_t  Xaddress = 0;
  uint16_t Red_Value = 0, Green_Value = 0, Blue_Value = 0, Alpha_Value = 0;
  
	/*计算目标地址*/
  Xaddress = Current_Addr + 4*(LCD_PIXEL_WIDTH*Ypos + Xpos);
 
	/*提取颜色分量*/
	Alpha_Value = (0xFF000000 & Current_ARGB) >>24;
  Red_Value = (0x00FF0000 & Current_ARGB) >>16;
  Green_Value = (0x0000FF00 &Current_ARGB)>>8 ;
	Blue_Value = 0x000000FF & Current_ARGB;
  
  /* 配置DMA2D DMA2D */
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
  
  /* 开始DMA2D传输 */ 
  DMA2D_StartTransfer();
  
  /* 等待传输结束 */
  while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET)
  {
  } 

//  LCD_SetTextColor(CurrentTextColor);
}




/**
  * @brief  填充一个三角形(在3个点之间)。
  * @param  x1..3: x position of triangle point 1..3.
  * @param  y1..3: y position of triangle point 1..3.
	* @param Current_Addr: 层数
  * @param Current_ARGB: ARGB值
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
  * @brief  画一个圆。
  * @param  Xpos:指定X位置，可以是0到240之间的值。
  * @param  Ypos:指定Y位置，可以是0到320之间的值。
  * @param  Radius:圆的半径。
  * @param Current_Addr: 层数
  * @param Current_ARGB: ARGB值
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
  * @brief  显示一个完整的圆。
  * @param  Xpos:指定X位置，可以是0到240之间的值。
  * @param  Ypos:指定Y位置，可以是0到320之间的值。
  * @param  半径
  * @param Current_Addr: 层数
  * @param Current_ARGB: ARGB值
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
  * @brief  显示一个椭圆。
  * @param  Xpos:指定X位置，可以是0到240之间的值。
  * @param  Ypos:指定Y位置，可以是0到320之间的值。
  * @param  Radius:指定半径。
  * @param  Radius2:指定半径。
  * @param Current_Addr: 层数
  * @param Current_ARGB: ARGB值
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
  * @brief  画一个完整的椭圆。
  * @param  Xpos:指定X位置，可以是0到240之间的值。
  * @param  Ypos:指定Y位置，可以是0到320之间的值。
  * @param  Radius:指定半径。
  * @param  Radius2:指定半径。
  * @param Current_Addr: 层数
  * @param Current_ARGB: ARGB值
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
	
	/* 颜色值 */
	DMA2D_InitStruct.DMA2D_OutputRed = 0;
	DMA2D_InitStruct.DMA2D_OutputGreen = 0;
	DMA2D_InitStruct.DMA2D_OutputBlue = 255;
	DMA2D_InitStruct.DMA2D_OutputAlpha = 0x7f;
	
	DMA2D_InitStruct.DMA2D_OutputMemoryAdd = LCD_LAYER2_START_ADDR+LCD_PIXEL_WIDTH*140*4+300*4;//传输到的显存地址
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
	
	/* 颜色值 */
	DMA2D_InitStruct.DMA2D_OutputRed = 255;
	DMA2D_InitStruct.DMA2D_OutputGreen = 0;
	DMA2D_InitStruct.DMA2D_OutputBlue = 0;
	DMA2D_InitStruct.DMA2D_OutputAlpha = 0x7f;
	
	DMA2D_InitStruct.DMA2D_OutputMemoryAdd = LCD_LAYER1_START_ADDR+LCD_PIXEL_WIDTH*100*4+250*4;//传输到的显存地址
	DMA2D_InitStruct.DMA2D_OutputOffset = 800-200;
	DMA2D_InitStruct.DMA2D_PixelPerLine = 200;
	DMA2D_InitStruct.DMA2D_NumberOfLine = 200;
	
	DMA2D_Init(&DMA2D_InitStruct);
	
	DMA2D_StartTransfer();
	while(DMA2D_GetFlagStatus(DMA2D_FLAG_TC) == RESET)
	{
	}
}





