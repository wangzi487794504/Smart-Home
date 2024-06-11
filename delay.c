# include <reg51.h>
# include <intrins.h>
# include "delay.h"
void delay(unsigned int ms)
{
	unsigned char i; 

  while(ms--)                 

        

 for(i=0;i<100;i++); 
}
//***************延时函数************************************* 
void delay_10us(unsigned char us)
{
	while(us--);
}

void delay_ms(unsigned char ms)
{
	unsigned char i,j;
	for(i=ms;i>0;i--)
		for(j=114;j>0;j--);
}

void delay1()//一个for循环大概需要8个多机器周期一个机器周期为1us晶振为12MHz也就是说本函数延时8us多此延时函数必须德稍微精确一点 

{ 

  unsigned char i; 

  for(i=0;i<1;i++); 

}
 void delay_h(unsigned char ms) //延时模块// 

{ 
 unsigned i; 
  while(ms--)                 
 for(i=0;i<100;i++); 

}  

