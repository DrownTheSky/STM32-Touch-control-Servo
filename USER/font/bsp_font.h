#ifndef __BSP_FONT_H
#define	__BSP_FONT_H

#include "stm32f4xx.h"

#define     vertical     1


#define     Standard_Address          1360*4096
#define     vertical_Address          3812*4096

void CH_Char(uint16_t Xpos, uint16_t Ypos, uint32_t Current_Addr,uint32_t Font_Color , uint32_t Groung_Color,char *pString);
void EN_Char(uint16_t Xpos, uint16_t Ypos, uint32_t Current_Addr,uint32_t Font_Color , uint32_t Groung_Color, char *ptr);
void LCD_DispString_EN_CH( uint16_t Xpos, uint16_t Ypos, uint32_t Current_Addr,uint32_t Font_Color , uint32_t Groung_Color,char *pString );



#endif /* __BSP_FONT_H */
