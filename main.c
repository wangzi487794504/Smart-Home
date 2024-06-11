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
#define RELOAD_COUNT 0xFA //�궨�岨���ʷ�����������ֵ 9600
sbit moto=P1^3;
sbit weishengjian= P2^0;	//�������
sbit keting= P2^1;
sbit wodshi=P2^2;
sbit chufang=P2^3;
uchar Time;
char biaozhi;

//***************************************************************  
/*
*@author ���ӽ�
*@version 1.1
*@group ����ҽѧԺ
*/
void UART_Init()
{
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD=0X20;			//���ü�����������ʽ2
	PCON=0X80;			//�����ʼӱ�
	TH1=0XF3;	//��������ʼֵ����
	TL1=0XF3;
	ES=0;				//�رս����ж�
	EA=1;				//�����ж�
	TR1=1;				//�򿪼�����
}
void denginit()//�Ƶĳ�ʼ��
{
   	 weishengjian=1;
	 keting=1;
	 wodshi=1;
	 chufang=1;
}

void jieshou(uchar value)//����wifiģ����ܵ����� ,����java֪ʶ��Ӧ�ý������,�������������̣߳�д�����ط���ʧЧ��
{
 	if(value=='0')
	{
	   moto=1;//�͵�ƽ��
	}
	if(value=='1')
	{
	   weishengjian=0;//�͵�ƽ��
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
void Uart() interrupt 4		   //���ô����жϽ���wifi����
{
   
   if(RI==1)
   {
    	uchar receiveData;
	   receiveData=SBUF;//��ȥ���յ�������
    	RI = 0;//��������жϱ�־λ
	    jieshou(receiveData);
 }
}
