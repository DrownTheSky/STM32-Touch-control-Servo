#include "./usart/bsp_debug_usart.h"


static void USART_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_InitStruct.NVIC_IRQChannel = USART_NVIC_IRQChannel;
	NVIC_Init(&NVIC_InitStruct);
}

static void USARET_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_AHB1PeriphClockCmd(USART_TX_CLK|USART_RX_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Fast_Speed;
	
	GPIO_InitStruct.GPIO_Pin = USART_TX_PIN;
	GPIO_PinAFConfig(USART_TX_PORT, USART_TX_PinSource, GPIO_AF_USART1);
	GPIO_Init(USART_TX_PORT , &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = USART_RX_PIN;
	GPIO_PinAFConfig(USART_RX_PORT, USART_RX_PinSource, GPIO_AF_USART1);
	GPIO_Init(USART_RX_PORT , &GPIO_InitStruct);
}

static void USART_Config(void)
{
	USART_InitTypeDef USART_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	USART_InitStruct.USART_BaudRate = USART_BAUDRATE;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	
	USART_ITConfig(USART_X,USART_IT_RXNE,ENABLE);//�жϽ���
	
	USART_Init(USART_X,&USART_InitStruct);
	
	USART_Cmd(USART_X,ENABLE);
}

void Debug_USART_Config(void)
{
	USART_NVIC_Config();
	USARET_GPIO_Config();
	USART_Config();
}


/*****************  ����һ���ַ� **********************/
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
	/* ����һ���ֽ����ݵ�USART */
	USART_SendData(pUSARTx,ch);
		
	/* �ȴ��������ݼĴ���Ϊ�� */
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	
}


/*****************  �����ַ��� **********************/
void Usart_SendString( USART_TypeDef * pUSARTx, char *str)
{
	unsigned int k=0;
  do 
  {
      Usart_SendByte( pUSARTx, *(str + k) );
      k++;
  } while(*(str + k)!='\0');
  
  /* �ȴ�������� */
  while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET)
  {}
}

/*****************  ����һ��16λ�� **********************/
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch)
{
	uint8_t temp_h, temp_l;
	
	/* ȡ���߰�λ */
	temp_h = (ch&0XFF00)>>8;
	/* ȡ���Ͱ�λ */
	temp_l = ch&0XFF;
	
	/* ���͸߰�λ */
	USART_SendData(pUSARTx,temp_h);	
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
	
	/* ���͵Ͱ�λ */
	USART_SendData(pUSARTx,temp_l);	
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	
}

///�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����
int fputc(int ch, FILE *f)
{
		/* ����һ���ֽ����ݵ����� */
		USART_SendData(USART_X, (uint8_t) ch);
		
		/* �ȴ�������� */
		while (USART_GetFlagStatus(USART_X, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

///�ض���c�⺯��scanf�����ڣ���д����ʹ��scanf��getchar�Ⱥ���
int fgetc(FILE *f)
{
		/* �ȴ������������� */
		while (USART_GetFlagStatus(USART_X, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USART_X);
}


///*�жϽ��ջ��Ժ���*/
//void DEBUG_USART_IRQHandler(void)
//{
//  uint8_t ucTemp;
//	if(USART_GetITStatus(DEBUG_USART,USART_IT_RXNE)!=RESET)  //���ú�������ж��Ƿ���
//	{		
//		ucTemp = USART_ReceiveData( DEBUG_USART );             //�Ҳ�����������
//    USART_SendData(DEBUG_USART,ucTemp);                    //���պ���
//	}	 
//}
