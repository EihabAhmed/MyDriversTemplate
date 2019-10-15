#include "lcd.h"
#include <string.h>

void lcd_init()
{
	PIN_WRITE(LCD_CONTROL_DIR, RS_PIN, OUTPUT);
	PIN_WRITE(LCD_CONTROL_DIR, ENABLE_PIN, OUTPUT);
	
	switch (lcdmode)
	{
		case LCD8MODE:
			INIT_PORT(LCD_DATA_DIR, OUTPUT);
			lcd_send_command(LCD8MODE);
			lcd_send_command(DISPLAY_ON_CURSOR_OFF);
			lcd_send_command(CLEAR_SCREEN);
			lcd_send_command(FIRST_LINE);
			break;
		case LCD4MODE:
			#if defined(Eta32Mini)
				PORT_MASK(LCD_DATA_DIR, 0x78);
				lcd_send_command(LCD4MODE2);
				lcd_send_command(LCD4MODE3);
				lcd_send_command(LCD4MODE);
				lcd_send_command(DISPLAY_ON_CURSOR_OFF);
				lcd_send_command(CLEAR_SCREEN);
				lcd_send_command(FIRST_LINE);
				break;
			#elif defined(Proteus)
				HIGHER_NIBBLE_HIGH(LCD_DATA_DIR);
				lcd_send_command(LCD4MODE2);
				lcd_send_command(LCD4MODE3);
				lcd_send_command(LCD4MODE);
				lcd_send_command(DISPLAY_ON_CURSOR_OFF);
				lcd_send_command(CLEAR_SCREEN);
				lcd_send_command(FIRST_LINE);
				break;
			#elif defined(ATmega32)
				HIGHER_NIBBLE_HIGH(LCD_DATA_DIR);
				lcd_send_command(LCD4MODE2);
				lcd_send_command(LCD4MODE3);
				lcd_send_command(LCD4MODE);
				lcd_send_command(DISPLAY_ON_CURSOR_OFF);
				lcd_send_command(CLEAR_SCREEN);
				lcd_send_command(FIRST_LINE);
				break;
			#endif
	}
	
	_delay_ms(1);
}

void enable_active()
{
	PIN_WRITE(LCD_CONTROL_VAL, ENABLE_PIN, GPIO_HIGH);
	lcdwait;
	PIN_WRITE(LCD_CONTROL_VAL, ENABLE_PIN, GPIO_LOW);
	lcdwait;
}

void lcd_send_command(LCD_COMMANDS cmd)
{
	PIN_WRITE(LCD_CONTROL_VAL, RS_PIN, GPIO_LOW);
	
	switch (lcdmode)
	{
		case LCD8MODE:
			WRITE_PORT(LCD_DATA_VAL, cmd);
			enable_active();
			break;
		case LCD4MODE:
			#if defined(Eta32Mini)
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x87) | ((cmd & 0xf0) >> 1));
				enable_active();
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x87) | ((cmd << 4) >> 1));
				enable_active();
				break;
			#elif defined(Proteus)
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x0f) | (cmd & 0xf0));
				enable_active();
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x0f) | (cmd << 4));
				enable_active();
				break;
			#elif defined(ATmega32)
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x0f) | (cmd & 0xf0));
				enable_active();
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x0f) | (cmd << 4));
				enable_active();
				break;
			#endif
	}
	
	_delay_ms(1);
}

void lcd_send_data(uint8_t data)
{
	PIN_WRITE(LCD_CONTROL_VAL, RS_PIN, GPIO_HIGH);
	
	switch (lcdmode)
	{
		case LCD8MODE:
			WRITE_PORT(LCD_DATA_VAL, data);
			enable_active();
			break;
		case LCD4MODE:
			#if defined(Eta32Mini)
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x87) | ((data & 0xf0) >> 1));
				enable_active();
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x87) | ((data << 4) >> 1));
				enable_active();
				break;
			#elif defined(Proteus)
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x0f) | (data & 0xf0));
				enable_active();
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x0f) | (data << 4));
				enable_active();
				break;
			#elif defined(ATmega32)
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x0f) | (data & 0xf0));
				enable_active();
				LCD_DATA_VAL = ((LCD_DATA_VAL & 0x0f) | (data << 4));
				enable_active();
				break;
			#endif
	}
	
	_delay_ms(1);
}

void lcd_set_cursor(uint8_t x, uint8_t y)
{
	if (y == 1)
	{
		lcd_send_command(FIRST_LINE + x);
	}
	else if (y == 2)
	{
		lcd_send_command(SECOND_LINE + x);
	}
	else
	{
		lcd_clear();
		lcd_out(1, 0, "row 1 and 2 only");
	}
}

void lcd_send_string(char* str)
{
	while (*str != '\0')
	{
		lcd_send_data(*str);
		str++;
	}	
}

void lcd_out(uint8_t x, uint8_t y, char* str)
{
	lcd_set_cursor(x, y);
	lcd_send_string(str);	
}

char* convert_data(unsigned int var)
{
	static char data[17];
	char *arr = &data[16];	
	
	*arr = '\0';
	
	if (var == 0)
	{
		arr--;
		*arr = '0';
		return arr;
	}
	
	while (var != 0)
	{
		arr--;
		*arr = (var % 10) + '0';
		var = var / 10;
	}
	
	return arr;
	
	/* another way */
	/*
	itoa(var, data, 10); // 10 for decimal
	return data;
	*/
}

int str_to_int(char* ptr)
{
	char base = 0;
	int number = 1;
	
	for (uint16 i = 0; i < strlen(ptr); i++)
	{
		number = (ptr[i] - 48) + number * base;
		base = 10;
	}	
	
	return number;
}
	
void store_char(char* ptr, char loc)
{
	lcd_send_command(CGRAM + loc * 8);
	
	for (int i = 0; i < 8; i++)
	{
		lcd_send_data(ptr[i]);
	}
	
	lcd_send_command(FIRST_LINE);
}

char m[8] = {0, 0, 14, 9, 25, 6, 0, 0};
char h[8] = {0, 16, 8, 4, 15, 0, 0, 0};
char w[8] = {0, 7, 9, 15, 1, 30, 0, 0};
char d[8] = {0, 2, 2, 2, 2, 28, 0, 0};

void store_chars()
{
	store_char(m, 0);
	store_char(h, 1);
	store_char(w, 2);
	store_char(d, 3);
}

void lcd_clear()
{
	lcd_send_command(CLEAR_SCREEN);
	_delay_ms(1);
}

void lcd_update()
{
	/* task 1 */
	// lcd_out(0, 1, "hello");
	
	/* task 2 */
	/*for (uint8 i = 0; i < 16; i++)
	{
		lcd_out(i, 1, "hello");
		_delay_ms(500);
		lcd_out(0, 1, "                ");
		_delay_ms(10);
	}*/
}

/*void print_stored_chars()
{
	lcd_clear();
	lcd_set_cursor(15, 1);
	lcd_send_data(0);
	lcd_set_cursor(14, 1);
	lcd_send_data(1);
	lcd_set_cursor(13, 1);
	lcd_send_data(0);
	lcd_set_cursor(12, 1);
	lcd_send_data(2);
	lcd_set_cursor(11, 1);
	lcd_send_data(3);
}*/

