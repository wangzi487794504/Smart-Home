# include <reg51.h>
# include <intrins.h>
# include "delay.h"
#ifndef __WIFI_H__
#define __WIFI_H__
void UART_SendByte(unsigned char dat);
//void ESP8266_SendCmd(unsigned char *pbuf);
void ESP8266_SendData(unsigned char *pbuf);
void ESP8266_ModeInit(void);
#endif