# include <reg51.h>
# include <intrins.h>
# include"1602.h"
# include "delay.h"
//lcd模块// 
sbit rw=P2^5;//一下三行是设置lcd1602的使能端// 
#define uint unsigned int 
#define uchar unsigned char 
sbit rs=P2^6; 
typedef bit BOOL;//此声明一个布尔型变量即真或假// 
sbit ep=P2^7; 

bit lcd_bz()//测试lcd忙碌状态返回值为布尔型数值真或假'1'.'0'  

{ 
  bit puanduan;
  rs=0;           // 读忙信号
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

void write_cmd(uchar cmd)//写指令// 

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
void write_addr(uchar addr)//写地址// 

{ 

  write_cmd(addr|0x80);//LCD第一行的首地址为0x80第二行的首地址为0x80+0x40=0xc0 

} 

 

void write_byte(uchar dat) //写字节// 

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
void display(uchar addr,uchar q)//在某一地址上显示内容adder表示的是地址偏移量q表示显示的字符或数字

{ 
  delay_h(10);  
   write_addr(addr); 
  write_byte(q); 
  delay_h(1);//修改此时间可以改变LCD上数值跳变的数度 
} 
void lcd_init() //lcd初始化// 

{ 

  write_cmd(0x38);//设置LCD两行显示
  delay_h(1); 
  write_cmd(0x0c);//清除屏幕显示 
  delay_h(1); 
  write_cmd(0x06);//设定输入方式增量不移位 
  delay_h(1); 
  write_cmd(0x01);//不闪烁 
  delay_h(1); 

} 


