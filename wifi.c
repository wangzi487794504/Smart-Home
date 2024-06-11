# include <reg51.h>
# include <intrins.h>
# include "delay.h"
# include "wifi.h"
#define uint unsigned int 
#define uchar unsigned char  
sbit ESP8266_RST_Pin=P3^5;
sbit ESP8266_CH_PD_Pin=P3^6; 
void UART_SendByte(uchar dat)
{
	ES=0; //关闭串口中断
	TI=0; //清发送完毕中断请求标志位
	SBUF=dat; //发送
	while(TI==0); //等待发送完毕
	TI=0; //清发送完毕中断请求标志位
	ES=1; //允许串口中断
}



void ESP8266_SendData(uchar *pbuf)
{
//	ESP8266_SendCmd("AT+CIPSEND=0,1");
	while(*pbuf!='\0') //遇到空格跳出循环	
	{
		UART_SendByte(*pbuf);
		delay_10us(5);
		pbuf++;	
	}
	delay_10us(5);
	UART_SendByte('\n');//换行	
	delay_ms(10);
}
//ESP8266-WIFI模块工作模式初始化
void ESP8266_ModeInit(void)
{
	
	ESP8266_RST_Pin=1;
	ESP8266_CH_PD_Pin=1;

//	ESP8266_SendCmd("AT+CWMODE=3");//设置路由器模式 1 staTIon模式 2 AP点 路由器模式 3 station+AP混合模式
//		ESP8266_SendCmd("AT+CWSAP=\"WANGZI\",\"123456789\",11,2");
//	ESP8266_SendCmd("AT+RST"); //重新启动wifi模块
//	ESP8266_SendCmd("AT+CWJAP_DEF=\"wangzijie\",\"123456789\"");//连接电脑wifi
//	ESP8266_SendCmd("AT+CIPMUX=1");//启动多连接
//	ESP8266_SendCmd("AT+CIPSERVER=0");
  //  ESP8266_SendCmd("AT+SAVETRANSLINK=1,\"192.168.31.90\",9999,\"TCP\"");
//	ESP8266_SendCmd("AT+CIPSTART=0,\"TCP\",\"192.168.31.90\",9999");	//启动TCP/IP 端口为9999 实现基于网络控制
	
	
} 
