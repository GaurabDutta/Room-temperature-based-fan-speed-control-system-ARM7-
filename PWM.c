#include<lpc21xx.h>
#include"header.h"

void pwm_init(void)
{
	PINSEL0 = 1<<17;
	PWMMCR = 1<<1;
	PWMPCR = 1<<12;				//PWMPCR = (1<<12)|(1<<4) --> for double edge
	PWMPR = 14;
	PWMMR0 = 10000;				//for setting time period 10ms
	PWMLER = 1<<0;
	PWMTCR = (1<<0)|(1<<3);		//enabling counter
}

void duty_cycle(int dc)
{
	PWMMR4 = dc;
	PWMLER |= 1<<4;		
	delay(5000);
	lcd_cmd(0xC0);
	lcd_str("Speed: ");
	lcd_num(dc/100);
	lcd_str("%      ");
}
