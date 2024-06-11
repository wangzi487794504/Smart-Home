# include <reg51.h>
# include <intrins.h>
#ifndef __1602_H__
#define	__1602_H__
bit lcd_bz();
 void write_cmd(unsigned char cmd);
void write_addr(unsigned char addr);
void write_byte(unsigned char dat);
void display(unsigned char addr,unsigned char q);
void lcd_init();
#endif