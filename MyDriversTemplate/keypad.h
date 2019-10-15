#ifndef KEYPAD_H_
	#define KEYPAD_H_
	
	#include "hardware.h"
	
	#if defined(Eta32Mini)
		#define COL_NUM 0x04
		#define ROW_INPUT 0xf0
		#define COL_OUTPUT 0x3c
		#define NOT_PRESSED 0xf0
	#elif defined(Proteus)
		#define COL_NUM 0x04
		#define ROW_INPUT_COL_OUTPUT 0xf0
		#define ROW_PULLUP_COL_HIGH 0xff
		#define NOT_PRESSED 0x0f
	#elif defined(ATmega32)
		#define COL_NUM 0x03
		#define ROW_INPUT_COL_OUTPUT 0x70
		#define ROW_PULLUP_COL_HIGH 0x7f
		#define NOT_PRESSED 0x0f
	#endif
	
	void keypad_init();
	uint8_t keypad_get_char();
	uint8_t keypad_get_pressed();
	void keypad_update();
	
#endif /* KEYPAD_H_ */