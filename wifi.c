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
	ES=0; //�رմ����ж�
	TI=0; //�巢������ж������־λ
	SBUF=dat; //����
	while(TI==0); //�ȴ��������
	TI=0; //�巢������ж������־λ
	ES=1; //�������ж�
}



void ESP8266_SendData(uchar *pbuf)
{
//	ESP8266_SendCmd("AT+CIPSEND=0,1");
	while(*pbuf!='\0') //�����ո�����ѭ��	
	{
		UART_SendByte(*pbuf);
		delay_10us(5);
		pbuf++;	
	}
	delay_10us(5);
	UART_SendByte('\n');//����	
	delay_ms(10);
}
//ESP8266-WIFIģ�鹤��ģʽ��ʼ��
void ESP8266_ModeInit(void)
{
	
	ESP8266_RST_Pin=1;
	ESP8266_CH_PD_Pin=1;

//	ESP8266_SendCmd("AT+CWMODE=3");//����·����ģʽ 1 staTIonģʽ 2 AP�� ·����ģʽ 3 station+AP���ģʽ
//		ESP8266_SendCmd("AT+CWSAP=\"WANGZI\",\"123456789\",11,2");
//	ESP8266_SendCmd("AT+RST"); //��������wifiģ��
//	ESP8266_SendCmd("AT+CWJAP_DEF=\"wangzijie\",\"123456789\"");//���ӵ���wifi
//	ESP8266_SendCmd("AT+CIPMUX=1");//����������
//	ESP8266_SendCmd("AT+CIPSERVER=0");
  //  ESP8266_SendCmd("AT+SAVETRANSLINK=1,\"192.168.31.90\",9999,\"TCP\"");
//	ESP8266_SendCmd("AT+CIPSTART=0,\"TCP\",\"192.168.31.90\",9999");	//����TCP/IP �˿�Ϊ9999 ʵ�ֻ����������
	
	
} 
