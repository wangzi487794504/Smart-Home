# include <reg51.h>
# include <intrins.h>
# include "delay.h"
void delay(unsigned int ms)
{
	unsigned char i; 

  while(ms--)                 

        

 for(i=0;i<100;i++); 
}
//***************��ʱ����************************************* 
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

void delay1()//һ��forѭ�������Ҫ8����������ڪ�һ����������Ϊ1us������Ϊ12MHz����Ҳ����˵��������ʱ8us�ડ����ʱ�����������΢��ȷһ�㪢 

{ 

  unsigned char i; 

  for(i=0;i<1;i++); 

}
 void delay_h(unsigned char ms) //��ʱģ��// 

{ 
 unsigned i; 
  while(ms--)                 
 for(i=0;i<100;i++); 

}  

