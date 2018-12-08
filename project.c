#include<lpc21xx.h>
#include"header.h"

int y;
int ch;
int temp,speed;
	
void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++)
	for(j=0;j<x;j++);
}

int main()
{
	lcd_init();
	adc_init();
	pwm_init();
	
	while(1)
	{
		while(!(ADDR & (1<<31)));
		ch = ADDR & (7<<24);
		ch >>= 24;
		y = ADDR & (0x3FF<<6);
		y >>= 6;
		
		lcd_cmd(0x01);
		lcd_cmd(0x80);
//	lcd_num(ch);
		lcd_str("Temperature: ");
		temp=y*0.32;
		lcd_num(temp);			//sensor calibration
		delay(1000);
		
		if(temp<10)
			duty_cycle(1);
		else if(temp<15)
			duty_cycle(2000);
		else if(temp<20)
			duty_cycle(4000);
		else if(temp<25)
			duty_cycle(6000);
		else if(temp<30)
			duty_cycle(8000);
//		if(temp<30)
//			duty_cycle(1);
		else if(temp>=30)
			duty_cycle(9999);
	}
}
