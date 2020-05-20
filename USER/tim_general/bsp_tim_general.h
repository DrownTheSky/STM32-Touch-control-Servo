#ifndef __BSP_TIM_GENERAL_H
#define __BSP_TIM_GENERAL_H


#include "stm32f4xx.h"

/* ͨ�ö�ʱ��PWM��� */
/* PWM������� */
#define GENERAL_OCPWM_PIN             GPIO_Pin_5              
#define GENERAL_OCPWM_GPIO_PORT       GPIOA                      
#define GENERAL_OCPWM_GPIO_CLK        RCC_AHB1Periph_GPIOA
#define GENERAL_OCPWM_PINSOURCE				GPIO_PinSource5
#define GENERAL_OCPWM_AF							GPIO_AF_TIM2

/* ͨ�ö�ʱ�� */
#define GENERAL_TIM           		    TIM2
#define GENERAL_TIM_CLK       		    RCC_APB1Periph_TIM2

void TIM_GENERAL_Config(void);

#endif /* __BSP_TIM_GENERAL_H */
