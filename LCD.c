#include<lpc21xx.h>
#include"header.h"

void lcd_cmd(char c)				//to give commands to the lcd(set, cursor etc.)
{
	IOCLR0 = 0xff<<15;		//clear the pins, if any garbage value is present
	IOSET0 = c << 15;			
	IOCLR0 = RS;					//for command RS=0
	IOCLR0 = RW;					//RW should be always 0, (0=Write, 1=Read)
	IOSET0 = EN;					
	delay(100);						//There should be a fluctuation to get o/p in lcd, i.e we set and clear the enable 
	IOCLR0 = EN;
}

void lcd_data(char c)
{
	IOCLR0 = 0xff<<15;
	IOSET0 = c << 15;
	IOSET0 = RS;					//for data RS=1
	IOCLR0 = RW;					//write mode(0)
	IOSET0 = EN;
	delay(100);
	IOCLR0 = EN;
}

void lcd_str(char*ptr)
{
	while(*ptr!='\0')
	{
		lcd_data(*ptr);
		ptr++;
	}
}

void lcd_num(unsigned int num)
{
	if(num)
	{
		lcd_num(num/10);
		lcd_data((num%10)+0x30);
	}
}

void lcd_init(void)
{
	IODIR0 = (D | RS | RW | EN);
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x80);
	lcd_cmd(0x01);
}
