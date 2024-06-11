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
void datashow()	//���ݴ�������������д���ˣ�wifi�ĵ�һ�������¶ȣ��Ҹ���ʪ�ȣ�����Ҫ����д
{					//ɵ������	    
	unsigned char temp_buf[2],humi_buf[2];
	unsigned yu; 
	receive(temp,humi);//����dht11������
	yu=panduanyu();//�����ε�״̬
	temp_buf[0]=temp[0]/10+0x30;//asc 0��ʼΪ16����0x30,ʮ����48	
	temp_buf[1]=temp[0]%10+0x30;
	humi_buf[0]=humi[0]/10+0x30;	
	humi_buf[1]=humi[0]%10+0x30;
	str[0]=temp_buf[0];
	str[1]=temp_buf[1];
 	str[2]=44;	//���ŵ�ascΪ44
 	str[3]=humi_buf[0];		
 	str[4]=humi_buf[1];
	str[5]=44;
	str[6]=yu%10+0x30;
 	ESP8266_SendData(str);
	
	lcd_init();
	write_cmd(0x85);	
	display(0x00,'S');//LCD�ĵ�һ����ʾ 
	display(0x01,'h');//LCD�ĵ�һ����ʾ
	display(0x02,'i');//LCD�ĵ�һ����ʾ
	display(0x03,'D');//LCD�ĵ�һ����ʾ
	display(0x04,'u');//LCD�ĵ�һ����ʾ
    display(0x05,':'); 
   	display(0x06,temp_buf[0]); 
    display(0x07,temp_buf[1]); 
 	display(0X08,'%'); 
 	display(0x40,'W');//LCD�ĵڶ�����ʾ 
	display(0x41,'e');//LCD�ĵڶ�����ʾ 
	display(0x42,'n');//LCD�ĵڶ�����ʾ
	display(0x43,'D');//LCD�ĵڶ�����ʾ
	display(0x44,'u');//LCD�ĵڶ�����ʾ 
 	display(0x45,':'); 
 	display(0x46,humi_buf[0]); 	
 	display(0x47,humi_buf[1]); 
    display(0x48,0xdf);//�����������¶ȵ�λ�Ĵ�����ASI�� 
    display(0x49,0x43);
	delay(5000);//ÿ�������һ������ 
}