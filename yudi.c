#include<reg51.h>
# include"1602.h"
# include"yidi.h"
#include"delay.h"
sbit yudi=P1^7;
sbit beep=P3^7;	
unsigned char panduanyu()
{
   beep=1;
   if(yudi==0)	 //λ0ʱ��ˮ
   {
      sound();
	  return 0; 
   }
   else
   {
		return 1; 
   }
}
void sound()  //����
{
	unsigned char b=50;
	while(b--)
	{
		beep=!beep;
		delay(10);
	}
}