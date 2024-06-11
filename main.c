# include <reg51.h>
# include <intrins.h>
# include "shou.h"
# include "delay.h"
# include "1602.h"
# include "dht11.h"
# include "wifi.h"
# include"yidi.h"
typedef unsigned char BYTE;
typedef unsigned int WORD;
#define uint unsigned int 
#define uchar unsigned char 
#define RELOAD_COUNT 0xFA //宏定义波特率发生器的载入值 9600
sbit moto=P1^3;
sbit weishengjian= P2^0;	//卫生间灯
sbit keting= P2^1;
sbit wodshi=P2^2;
sbit chufang=P2^3;
uchar Time;
char biaozhi;

//***************************************************************  
/*
*@author 王子杰
*@version 1.1
*@group 蚌埠医学院
*/
void UART_Init()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X80;			//波特率加倍
	TH1=0XF3;	//计数器初始值设置
	TL1=0XF3;
	ES=0;				//关闭接收中断
	EA=1;				//打开总中断
	TR1=1;				//打开计数器
}
void denginit()//灯的初始化
{
   	 weishengjian=1;
	 keting=1;
	 wodshi=1;
	 chufang=1;
}

void jieshou(uchar value)//处理wifi模块接受的数据 ,按照java知识，应该降低耦合,但它类似于主线程，写其他地方会失效。
{
 	if(value=='0')
	{
	   moto=1;//低电平亮
	}
	if(value=='1')
	{
	   weishengjian=0;//低电平亮
	}
	if(value=='2')
	{
	   keting=0;
	}
	if(value=='3')
	{
	   wodshi=0;
	}
	if(value=='4')
	{
	   chufang=0;
	}
	if(value=='5')
	{
	   moto=0;
	}
	if(value=='6')
	{
	   weishengjian=1;
	}
	if(value=='7')
	{
	  keting=1;
	}
	if(value=='8')
	{
	  wodshi=1;
	}
	if(value=='9')
	{
	  chufang=1;
	} 
}
void main()
{
  	 ESP8266_ModeInit();
     UART_Init();
	 denginit();
	 moto=0;
	 while(1)
	 {
	     datashow();
		 delay_h(3000);

	 }
}
void Uart() interrupt 4		   //利用串口中断接收wifi数据
{
   
   if(RI==1)
   {
    	uchar receiveData;
	   receiveData=SBUF;//出去接收到的数据
    	RI = 0;//清除接收中断标志位
	    jieshou(receiveData);
 }
}
