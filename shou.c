# include <reg51.h>
# include <intrins.h>
# include "shou.h"
# include "delay.h"
# include "1602.h"
# include "dht11.h"
# include "wifi.h"
# include"yidi.h"
unsigned int temp[2],humi[2];
unsigned char str[8];
void datashow()	//数据处理函数，这里我写错了，wifi的第一格是是温度，我给了湿度，所以要倒着写
{					//傻逼了我	    
	unsigned char temp_buf[2],humi_buf[2];
	unsigned yu; 
	receive(temp,humi);//接收dht11的数据
	yu=panduanyu();//检测雨滴的状态
	temp_buf[0]=temp[0]/10+0x30;//asc 0开始为16进制0x30,十进制48	
	temp_buf[1]=temp[0]%10+0x30;
	humi_buf[0]=humi[0]/10+0x30;	
	humi_buf[1]=humi[0]%10+0x30;
	str[0]=temp_buf[0];
	str[1]=temp_buf[1];
 	str[2]=44;	//逗号的asc为44
 	str[3]=humi_buf[0];		
 	str[4]=humi_buf[1];
	str[5]=44;
	str[6]=yu%10+0x30;
 	ESP8266_SendData(str);
	
	lcd_init();
	write_cmd(0x85);	
	display(0x00,'S');//LCD的第一行显示 
	display(0x01,'h');//LCD的第一行显示
	display(0x02,'i');//LCD的第一行显示
	display(0x03,'D');//LCD的第一行显示
	display(0x04,'u');//LCD的第一行显示
    display(0x05,':'); 
   	display(0x06,temp_buf[0]); 
    display(0x07,temp_buf[1]); 
 	display(0X08,'%'); 
 	display(0x40,'W');//LCD的第二行显示 
	display(0x41,'e');//LCD的第二行显示 
	display(0x42,'n');//LCD的第二行显示
	display(0x43,'D');//LCD的第二行显示
	display(0x44,'u');//LCD的第二行显示 
 	display(0x45,':'); 
 	display(0x46,humi_buf[0]); 	
 	display(0x47,humi_buf[1]); 
    display(0x48,0xdf);//以下两个是温度单位的处理，查ASI表， 
    display(0x49,0x43);
	delay(5000);//每五秒更新一次数据 
}