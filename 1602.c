# include <reg51.h>
# include <intrins.h>
# include"1602.h"
# include "delay.h"
//lcdģ��// 
sbit rw=P2^5;//һ������������lcd1602��ʹ�ܶ�// 
#define uint unsigned int 
#define uchar unsigned char 
sbit rs=P2^6; 
typedef bit BOOL;//������һ�������ͱ���������// 
sbit ep=P2^7; 

bit lcd_bz()//����lcdæµ״̬������ֵΪ��������ֵ�����٪�'1'.'0'��  

{ 
  bit puanduan;
  rs=0;           // ��æ�ź�
  rw=1;
  ep=1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  puanduan = (bit)(P0&0x80);
  ep=0;
  return puanduan ;

}     

void write_cmd(uchar cmd)//дָ��// 

{ 

  while (lcd_bz());
  rs=0;
  rw=0;
  ep=0;
  _nop_();
  _nop_();
  P0=cmd ;
  _nop_();
  _nop_();
  _nop_();
  ep=1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  ep=0;

} 
void write_addr(uchar addr)//д��ַ// 

{ 

  write_cmd(addr|0x80);//LCD��һ�е��׵�ַΪ0x80���ڶ��е��׵�ַΪ0x80+0x40=0xc0 

} 

 

void write_byte(uchar dat) //д�ֽ�// 

{ 

   while (lcd_bz());
  rs=1;
  rw=0;
  ep=0;
  _nop_();
  _nop_();
  P0=dat ;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  ep=1;
  _nop_();
  _nop_();
  _nop_();
  ep=0;

} 
void display(uchar addr,uchar q)//��ĳһ��ַ����ʾ���ݪ�adder��ʾ���ǵ�ַƫ������q��ʾ��ʾ���ַ�������

{ 
  delay_h(10);  
   write_addr(addr); 
  write_byte(q); 
  delay_h(1);//�޸Ĵ�ʱ�䪣���Ըı�LCD����ֵ��������� 
} 
void lcd_init() //lcd��ʼ��// 

{ 

  write_cmd(0x38);//����LCD������ʾ
  delay_h(1); 
  write_cmd(0x0c);//�����Ļ��ʾ 
  delay_h(1); 
  write_cmd(0x06);//�趨���뷽ʽ����������λ 
  delay_h(1); 
  write_cmd(0x01);//����˸ 
  delay_h(1); 

} 


