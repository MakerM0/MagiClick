#ifndef __LCD_INIT_H
#define __LCD_INIT_H

#include "CH58x_common.h"
#include  "lcd.h"
#define USE_HORIZONTAL 0  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����


#define LCD_W 128
#define LCD_H 128


//-----------------LCD�˿ڶ���---------------- 




#define PORT_LCD_RST GPIOB
#define PIN_LCD_RST GPIO_Pin_15
#define LCD_RES_Set() GPIOB_SetBits(PIN_LCD_RST)
#define LCD_RES_Clr() GPIOB_ResetBits(PIN_LCD_RST)

#define PORT_LCD_CS GPIOA
#define PIN_LCD_CS GPIO_Pin_15
#define LCD_CS_Set() GPIOA_SetBits(PIN_LCD_CS)
#define LCD_CS_Clr() GPIOA_ResetBits(PIN_LCD_CS)


#define PORT_LCD_DC GPIOB
#define PIN_LCD_DC GPIO_Pin_4
#define LCD_DC_Set() GPIOB_SetBits(PIN_LCD_DC)
#define LCD_DC_Clr() GPIOB_ResetBits(PIN_LCD_DC)

#define PORT_LCD_BL GPIOB
#define PIN_LCD_BL GPIO_Pin_7
#define LCD_BLK_Set() GPIOB_SetBits(PIN_LCD_BL)
#define LCD_BLK_Clr() GPIOB_ResetBits(PIN_LCD_BL)




void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(u8 dat);//ģ��SPIʱ��
void LCD_WR_DATA8(u8 dat);//д��һ���ֽ�
void LCD_WR_DATA(u16 dat);//д�������ֽ�
void LCD_WR_REG(u8 dat);//д��һ��ָ��
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��
#endif




