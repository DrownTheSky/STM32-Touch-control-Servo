#ifndef __DEBUG_USART_H
#define	__DEBUG_USART_H

#include "stm32f4xx.h"
#include <stdio.h>


#define USART_TX_CLK            RCC_AHB1Periph_GPIOA
#define USART_TX_PIN            GPIO_Pin_9
#define USART_TX_PORT      		  GPIOA
#define USART_TX_PinSource    	GPIO_PinSource9

#define USART_RX_CLK            RCC_AHB1Periph_GPIOA
#define USART_RX_PIN            GPIO_Pin_10
#define USART_RX_PORT      		  GPIOA
#define USART_RX_PinSource    	GPIO_PinSource10

#define USART_X          				USART1
#define USART_CLK               RCC_APB2Periph_USART1
#define USART_BAUDRATE          115200
#define USART_NVIC_IRQChannel   USART1_IRQn
#define DEBUG_USART_IRQHandler  USART1_IRQHandler


void Debug_USART_Config(void);
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);



#endif /* __USART1_H */


