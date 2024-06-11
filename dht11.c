//**************************dht11����ĳ��*************************************// 
# include <reg51.h>
# include <intrins.h>
# include "delay.h"
# include "dht11.h"
typedef unsigned char uint8;
typedef unsigned int uint16;
#define uchar unsigned char 
//unsigned char RH,RL,TH,TL;
sbit io=P1^0;//dht11data�˽ӵ�Ƭ����P1^0��//
uchar data_byte;  
void start()//��ʼ�ź� 

{ 

  io=1; 
  delay1(); 
  io=0; 
  delay(25);// �������������ͱ������18ms����֤DHT11�ܼ�⵽��ʼ�ź� 
  io=1;    //���Ϳ�ʼ�źŽ��������ߵ�ƽ��ʱ20-40us 
  delay1();
  delay1(); 
  delay1(); 

} 

 

uchar receive_byte()//����һ���ֽ�// 

{ 

  uchar i,temp; 

  for(i=0;i<8;i++)//����8bit������ 

  { 

 	while(!io); 
 	delay1();//��ʱ������ 
	 delay1(); 
 	delay1(); 
 	temp=0;//��ʾ���յ�Ϊ����'0' 
 	if(io==1) 
	 temp=1; //���ʾ���յ�����Ϊ'1' 
    while(io);//�ȴ������źŸߵ�ƽ�� 
 	data_byte<<=1;//���յ�����Ϊ��λ��ǰ�����ƪ� 
	 data_byte|=temp; 
  } 
  return data_byte; 
} 
void receive(uint16 R[2],uint16 T[2])//��������// 
{ 
  uchar T_H,T_L,R_H,R_L,check,num_check,i; 
  start();//��ʼ�ź�// 
  io=1;   //������Ϊ���몣�жϴӻ���DHT11����Ӧ�ź� 
  if(!io)//�жϴӻ��Ƿ��е͵�ƽ��Ӧ�ź�// 
  {  
	while(!io);//�жϴӻ����� 80us �ĵ͵�ƽ��Ӧ�ź��Ƿ����// 
	while(io);//�жϴӻ����� 80us �ĸߵ�ƽ�Ƿ������������������������ݽ���״̬ 
	R_H=receive_byte();//ʪ�ȸ�λ 
 	R_L=receive_byte();//ʪ�ȵ�λ 
	T_H=receive_byte();//�¶ȸ�λ 
	T_L=receive_byte();//�¶ȵ�λ 
	check=receive_byte();//У��λ
	io=0; //�����һbit���ݽ���Ϻ󪣴ӻ����͵�ƽ50us// 
	for(i=0;i<7;i++)//���50us����ʱ 
	delay1(); 
	io=1;//�����������������ߪ��������״̬ 
	num_check=R_H+R_L+T_H+T_L; 
	if(num_check==check)//�ж϶������ĸ�����֮���Ƿ���У��λ��ͬ 
 	{ 
	R[0]=R_H; 
	R[1]=R_L; 
	T[0]=T_H;
	T[1]=T_L;
   check=num_check; 
 	} 
  } 

} 

//*****************************************************************************