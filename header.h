#define RS (1 << 10)
#define RW (1 << 12)
#define EN (1 << 13)
#define D (0xff << 15)

void delay(int);
void lcd_cmd(char);
void lcd_data(char);
void lcd_str(char*);
void lcd_num(unsigned int);
void lcd_init(void);
void adc_init(void);
void pwm_init(void);
void duty_cycle(int);
