# include <reg51.h>
# include <intrins.h>
# include "delay.h"
#ifndef __DHT11_H__
#define __DHT11_H__
void start();
unsigned char receive_byte();
void receive(unsigned int R[2],unsigned int T[2]);
#endif