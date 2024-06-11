//**************************dht11测试某块*************************************// 
# include <reg51.h>
# include <intrins.h>
# include "delay.h"
# include "dht11.h"
typedef unsigned char uint8;
typedef unsigned int uint16;
#define uchar unsigned char 
//unsigned char RH,RL,TH,TL;
sbit io=P1^0;//dht11data端接单片机的P1^0口//
uchar data_byte;  
void start()//开始信号 

{ 

  io=1; 
  delay1(); 
  io=0; 
  delay(25);// 主机把总线拉低必须大于18ms保证DHT11能检测到起始信号 
  io=1;    //发送开始信号结束后拉高电平延时20-40us 
  delay1();
  delay1(); 
  delay1(); 

} 

 

uchar receive_byte()//接收一个字节// 

{ 

  uchar i,temp; 

  for(i=0;i<8;i++)//接收8bit的数据 

  { 

 	while(!io); 
 	delay1();//延时函数 
	 delay1(); 
 	delay1(); 
 	temp=0;//表示接收的为数据'0' 
 	if(io==1) 
	 temp=1; //则表示接收的数据为'1' 
    while(io);//等待数据信号高电平 
 	data_byte<<=1;//接收的数据为高位在前右移 
	 data_byte|=temp; 
  } 
  return data_byte; 
} 
void receive(uint16 R[2],uint16 T[2])//接收数据// 
{ 
  uchar T_H,T_L,R_H,R_L,check,num_check,i; 
  start();//开始信号// 
  io=1;   //主机设为输入判断从机DHT11响应信号 
  if(!io)//判断从机是否有低电平响应信号// 
  {  
	while(!io);//判断从机发出 80us 的低电平响应信号是否结束// 
	while(io);//判断从机发出 80us 的高电平是否结束如结束则主机进入数据接收状态 
	R_H=receive_byte();//湿度高位 
 	R_L=receive_byte();//湿度低位 
	T_H=receive_byte();//温度高位 
	T_L=receive_byte();//温度低位 
	check=receive_byte();//校验位
	io=0; //当最后一bit数据接完毕后从机拉低电平50us// 
	for(i=0;i<7;i++)//差不多50us的延时 
	delay1(); 
	io=1;//总线由上拉电阻拉高进入空闲状态 
	num_check=R_H+R_L+T_H+T_L; 
	if(num_check==check)//判断读到的四个数据之和是否与校验位相同 
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