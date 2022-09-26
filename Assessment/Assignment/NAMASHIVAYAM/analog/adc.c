#include<nxp\iolpc2148.h>
#include<stdio.h>
#include"uart.h"
unsigned int val=0;
void main(void)
{
PINSEL1=0x01000000;
uart_inital();
AD0CR_bit.SEL=0x02;
AD0CR_bit.CLKDIV=0x03;
AD0CR_bit.BURST=1;
AD0CR_bit.CLKS=0000;
AD0CR_bit.PDN=1;
while(1)
{

while(AD0DR1_bit.DONE==0);
val=AD0DR1_bit.RESULT;
printf("adc=%d\n\n",val);
}
}