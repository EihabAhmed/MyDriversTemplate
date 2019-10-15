#include "seg.h"

#ifndef BCD
	#if defined (COMMON_CATHODE)
		static char seg_num[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
	#elif defined (COMMON_ANODE)
		static char seg_num[] = {0b01000000, 0b01111001, 0b00100100, 0b00110000, 0b00011001, 0b00010010, 0b00000010, 0b01111000, 0b00000000, 0b00010000};
	#endif
#endif

void seg_init()
{
	#if defined(Eta32Mini)
		#if defined(BCD)
			HIGHER_NIBBLE_HIGH(SEG_DIR);
		#else
			SEG_DIR |= 0xfe;
		#endif
	#elif defined(Proteus)
		#if defined(BCD)
			HIGHER_NIBBLE_HIGH(SEG_DIR);
		#else
			SEG_DIR |= 0x7f;
		#endif
	#elif defined(ATmega32)
		#if defined(BCD)
			HIGHER_NIBBLE_HIGH(SEG_DIR);
		#else
			SEG_DIR |= 0x7f;
		#endif
	#endif
	
	PIN_WRITE(SEG_EN_DIR, SEG_EN_1, OUTPUT);
	PIN_WRITE(SEG_EN_DIR, SEG_EN_2, OUTPUT);
	PIN_WRITE(SEG_EN_VAL, SEG_EN_1, GPIO_HIGH);
	PIN_WRITE(SEG_EN_VAL, SEG_EN_2, GPIO_HIGH);
}

void seg_write(seg_select seg, uint8 value)
{
	#if defined(Eta32Mini)
		#if defined(BCD)
			HIGHER_NIBBLE_VALUE(SEG_VAL, value);
		#else
			SEG_VAL = (SEG_VAL & 0x01) | (seg_num[value] << 1);
		#endif
	#elif defined(Proteus)
		#if defined(BCD)
			HIGHER_NIBBLE_VALUE(SEG_VAL, value);
		#else
			SEG_VAL = (SEG_VAL & 0x80) | (seg_num[value]);
		#endif
	#elif defined(ATmega32)
		#if defined(BCD)
			HIGHER_NIBBLE_VALUE(SEG_VAL, value);
		#else
			SEG_VAL = (SEG_VAL & 0x80) | (seg_num[value]);
		#endif
	#endif
		
	switch (seg)
	{
		case (seg_1):
			PIN_WRITE(SEG_EN_VAL, SEG_EN_2, GPIO_LOW);
			PIN_WRITE(SEG_EN_VAL, SEG_EN_1, GPIO_HIGH);
			break;
		case (seg_2):
			PIN_WRITE(SEG_EN_VAL, SEG_EN_1, GPIO_LOW);
			PIN_WRITE(SEG_EN_VAL, SEG_EN_2, GPIO_HIGH);
			break;
		case (seg_both):
			PIN_WRITE(SEG_EN_VAL, SEG_EN_2, GPIO_HIGH);
			PIN_WRITE(SEG_EN_VAL, SEG_EN_1, GPIO_HIGH);
			break;
	}
}

void seg_update()
{
	//seg_write(seg_both, 7);
}