#include "keypad.h"

#ifdef keypad4X4_KIT
	static uint8_t keypadchars[4][4] = { {'1', '2', '3', 'a'},
										 {'4', '5', '6', 'b'},
										 {'7', '8', '9', 'c'},
										 {'*', '0', '#', 'd'} };
#elif defined(keypad4X4_PROTEUS)
	static uint8_t keypadchars[4][4] = { {'7', '8', '9', '/'},
										 {'4', '5', '6', '*'},
										 {'1', '2', '3', '-'},
										 {'a', '0', '=', '+'} };	
#elif defined(keypad4X3_ATmega32)
	static uint8_t keypadchars[4][3] = { {'1', '2', '3'},
										 {'4', '5', '6'},
										 {'7', '8', '9'},
										 {'*', '0', '#'} };												 												
#endif

void keypad_init()
{
	#if defined(Eta32Mini)
		/* rows input (4, 5, 6, 7) */
		KEYPAD_ROW_CONTROL = KEYPAD_ROW_CONTROL & 0b00001111;
		/* cols output (2, 3, 4, 5) */
		KEYPAD_COL_CONTROL = KEYPAD_COL_CONTROL | 0b00111100;
		/* rows pullup (4, 5, 6, 7) */
		KEYPAD_PULLUP = KEYPAD_PULLUP | 0b11110000;
		/* cols high (2, 3, 4, 5) */
		KEYPAD_DATA = KEYPAD_DATA | 0b00111100;
	#elif defined(Proteus)
		WRITE_PORT(KEYPAD_CONTROL, ROW_INPUT_COL_OUTPUT);					// 0xf0
		WRITE_PORT(KEYPAD_DATA, ROW_PULLUP_COL_HIGH);						// 0xff
	#elif defined(ATmega32)
		KEYPAD_CONTROL = (KEYPAD_CONTROL & 0x80) | ROW_INPUT_COL_OUTPUT;	// 0x70
		PORT_MASK(KEYPAD_DATA, ROW_PULLUP_COL_HIGH);						// 0x7f
	#endif
}

uint8_t keypad_get_char()
{
	unsigned char col = 0; // counter for loop
	unsigned char row = 0; // get value of row
	unsigned char key = 0;
	
	for (col = 0; col < COL_NUM; col++)
	{
		#if defined(Eta32Mini)
			KEYPAD_DATA = KEYPAD_DATA | 0b00111100;
			PIN_WRITE(KEYPAD_DATA, (col + 2), GPIO_LOW);
		#elif defined(Proteus)
			HIGHER_NIBBLE_HIGH(KEYPAD_DATA);
			PIN_WRITE(KEYPAD_DATA, (col + 4), GPIO_LOW);
		#elif defined(ATmega32)
			KEYPAD_DATA = KEYPAD_DATA | 0b01110000;
			PIN_WRITE(KEYPAD_DATA, (col + 4), GPIO_LOW);			
		#endif
		
		_delay_ms(10);
		
		#if defined(Eta32Mini)
			row = GET_HIGHER_NIBBLE(KEYPAD_INPUT);
		#elif defined(Proteus)
			row = GET_LOWER_NIBBLE(KEYPAD_INPUT);
		#elif defined(ATmega32)
			row = GET_LOWER_NIBBLE(KEYPAD_INPUT);
		#endif
		
		if (row != NOT_PRESSED)
		{
			#if defined(Eta32Mini)
				while (GET_HIGHER_NIBBLE(KEYPAD_INPUT) != NOT_PRESSED);
			#elif defined(Proteus)
				while (GET_LOWER_NIBBLE(KEYPAD_INPUT) != NOT_PRESSED);
			#elif defined(ATmega32)
				while (GET_LOWER_NIBBLE(KEYPAD_INPUT) != NOT_PRESSED);
			#endif
			
			break;
		}
	}
	
	if (col == COL_NUM)
	{
		return 0;
	}
	else
	{
		switch (row)
		{
			#if defined(Eta32Mini)
				case 0b11100000:
					row = 0;
					break;
				case 0b11010000:
					row = 1;
					break;
				case 0b10110000:
					row = 2;
					break;
				case 0b01110000:
					row = 3;
					break;
			#elif defined(Proteus)
				case 0b00001110:
					row = 0;
					break;
				case 0b00001101:
					row = 1;
					break;
				case 0b00001011:
					row = 2;
					break;
				case 0b00000111:
					row = 3;
					break;
			#elif defined(ATmega32)
				case 0b00001110:
					row = 0;
					break;
				case 0b00001101:
					row = 1;
					break;
				case 0b00001011:
					row = 2;
					break;
				case 0b00000111:
					row = 3;
					break;
			#endif
		}
		
		key = keypadchars[row][col];
	}
	
	return key;
}

uint8_t keypad_get_pressed()
{
	uint8_t key = 0;
	
	do 
	{
		key = keypad_get_char();
	} while (key == 0);
	
	return key;
}

void keypad_update()
{
	/* Display on LCD */
	//char keypad_val = keypad_get_pressed();
	//lcd_out(1, 1, &keypad_val);
	//lcd_send_data(keypad_val);
	
	/* Display on 7 Seg */
	//char seg_val = keypad_get_pressed() - 48;
	//seg_write(seg_both, keypad_val - 48);
}