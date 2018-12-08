#include<lpc21xx.h>
#include"header.h"

void adc_init(void)
{
	PINSEL1 |= (1<<24);
	ADCR |= (1<<1)|(4<<8)|(1<<16)|(0<<17)|(1<<21);
//					ch1 |clkdiv| brust |clks/conv| powerup
}
