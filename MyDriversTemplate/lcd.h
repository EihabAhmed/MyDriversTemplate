#ifndef LCD_H_
	#define LCD_H_

	#include "hardware.h"
	
	#if defined(LCD_4_MODE)
		#define lcdmode LCD4MODE
	#elif defined(LCD_8_MODE)
		#define lcdmode LCD8MODE
	#endif

	typedef enum
	{
		CLEAR_SCREEN = 0x01,
		RETURN_HOME = 0x02,
		FIRST_LINE = 0x80,
		SECOND_LINE = 0xc0,
		LCD8MODE = 0x38,
		LCD4MODE = 0x28,
		LCD4MODE2 = 0x33,
		LCD4MODE3 = 0x32,
		DISPLAY_ON_CURSOR_OFF = 0x0c,
		CGRAM = 0x40,
	} LCD_COMMANDS;
	
	void lcd_init();
	void enable_active();
	void lcd_send_command(LCD_COMMANDS cmd);
	void lcd_send_data(uint8_t data);
	void lcd_set_cursor(uint8_t x, uint8_t y);
	void lcd_send_string(char* str);
	void lcd_out(uint8_t x, uint8_t y, char* str);
	char* convert_data(unsigned int var);
	int str_to_int(char* ptr);
	void store_char(char* ptr, char loc);
	void store_chars();
	void lcd_clear();
	void lcd_update();
	
	#define lcdwait _delay_ms(1)

#endif /* LCD_H_ */