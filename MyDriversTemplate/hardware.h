#ifndef HARDWARE_H_
	#define HARDWARE_H_

	#include "micro.h"

	/********************************** LED port **************************************/
	#if defined(Eta32Mini)
		#define LED_DIR GPIO_PORTC_CONTROL
		#define LED_VAL GPIO_PORTC_DATA
		#define LEDS_COUNT 6
		
		#define LED_1_PIN PIN_2
		#define LED_2_PIN PIN_1
		#define LED_3_PIN PIN_0
		#define LED_4_PIN PIN_4
		#define LED_5_PIN PIN_3
		#define LED_6_PIN PIN_5
	#elif defined(Proteus)
		#define LED_DIR GPIO_PORTC_CONTROL
		#define LED_VAL GPIO_PORTC_DATA
		#define LEDS_COUNT 3
		
		#define LED_1_PIN PIN_0
		#define LED_2_PIN PIN_1
		#define LED_3_PIN PIN_2		
	#elif defined(ATmega32)
		#define LED_DIR GPIO_PORTA_CONTROL
		#define LED_VAL GPIO_PORTA_DATA
		#define LEDS_COUNT 3
		
		#define LED_1_PIN PIN_4
		#define LED_2_PIN PIN_6
		#define LED_3_PIN PIN_7
	#endif
	/********************************** LED port **************************************/
	
	/******************************** Button port *************************************/
	#if defined(Eta32Mini)
		#define BUTTON_DIR GPIO_PORTD_CONTROL
		#define BUTTON_PULLUP GPIO_PORTD_DATA
		#define BUTTON_VAL GPIO_PORTD_INPUT
		#define BUTTONS_COUNT 4
	
		#define BUTTON_1_PIN PIN_2
		#define BUTTON_2_PIN PIN_3
		#define BUTTON_3_PIN PIN_4
		#define BUTTON_4_PIN PIN_5
	#elif defined(Proteus)
		#define BUTTON_DIR GPIO_PORTD_CONTROL
		#define BUTTON_PULLUP GPIO_PORTD_DATA
		#define BUTTON_VAL GPIO_PORTD_INPUT
		#define BUTTONS_COUNT 4
		
		#define BUTTON_1_PIN PIN_0
		#define BUTTON_2_PIN PIN_1
		#define BUTTON_3_PIN PIN_2
		#define BUTTON_4_PIN PIN_3
	#elif defined(ATmega32)
		#define BUTTON_DIR GPIO_PORTD_CONTROL
		#define BUTTON_PULLUP GPIO_PORTD_DATA
		#define BUTTON_VAL GPIO_PORTD_INPUT
		#define BUTTONS_COUNT 4
		
		#define BUTTON_1_PIN PIN_0
		#define BUTTON_2_PIN PIN_1
		#define BUTTON_3_PIN PIN_2
		#define BUTTON_4_PIN PIN_3
	#endif
	/******************************** Button port *************************************/

	/********************************** LCD port **************************************/
	#define LCD_4_MODE
	//#define LCD_8_MODE
	
	#if defined(Eta32Mini)
		#define LCD_DATA_DIR GPIO_PORTA_CONTROL
		#define LCD_DATA_VAL GPIO_PORTA_DATA
		
		#if defined(LCD_8_MODE)
			#define LCD_CONTROL_DIR GPIO_PORTB_CONTROL
			#define LCD_CONTROL_VAL GPIO_PORTB_DATA
		#elif defined(LCD_4_MODE)
			#define LCD_CONTROL_DIR GPIO_PORTA_CONTROL
			#define LCD_CONTROL_VAL GPIO_PORTA_DATA
		#endif
		
		#define RS_PIN 1
		#define ENABLE_PIN 2
	#elif defined(Proteus)
		#define LCD_DATA_DIR GPIO_PORTA_CONTROL
		#define LCD_DATA_VAL GPIO_PORTA_DATA
		
		#if defined(LCD_8_MODE)
			#define LCD_CONTROL_DIR GPIO_PORTB_CONTROL
			#define LCD_CONTROL_VAL GPIO_PORTB_DATA
		#elif defined(LCD_4_MODE)
			#define LCD_CONTROL_DIR GPIO_PORTA_CONTROL
			#define LCD_CONTROL_VAL GPIO_PORTA_DATA
		#endif
		
		#define RS_PIN 1
		#define ENABLE_PIN 2
	#elif defined(ATmega32)
		#define LCD_DATA_DIR GPIO_PORTA_CONTROL
		#define LCD_DATA_VAL GPIO_PORTA_DATA
	
		#if defined(LCD_8_MODE)
			#define LCD_CONTROL_DIR GPIO_PORTB_CONTROL
			#define LCD_CONTROL_VAL GPIO_PORTB_DATA
		#elif defined(LCD_4_MODE)
			#define LCD_CONTROL_DIR GPIO_PORTA_CONTROL
			#define LCD_CONTROL_VAL GPIO_PORTA_DATA
		#endif
	
		#define RS_PIN 1
		#define ENABLE_PIN 2
	#endif
	/********************************** LCD port **************************************/
	
	/********************************* Keypad port ************************************/
	#define keypad4X4_KIT
	//#define keypad4X4_PROTEUS
	//#define keypad4X3_ATmega32
	
	#if defined(Eta32Mini)
		#define KEYPAD_COL_CONTROL GPIO_PORTD_CONTROL
		#define KEYPAD_ROW_CONTROL GPIO_PORTB_CONTROL
		#define KEYPAD_DATA GPIO_PORTD_DATA
		#define KEYPAD_INPUT GPIO_PORTB_INPUT
		#define KEYPAD_PULLUP GPIO_PORTB_DATA
	#elif defined(Proteus)
		#define KEYPAD_CONTROL GPIO_PORTD_CONTROL
		#define KEYPAD_DATA GPIO_PORTD_DATA
		#define KEYPAD_INPUT GPIO_PORTD_INPUT
	#elif defined(ATmega32)
		#define KEYPAD_CONTROL GPIO_PORTD_CONTROL
		#define KEYPAD_DATA GPIO_PORTD_DATA
		#define KEYPAD_INPUT GPIO_PORTD_INPUT
	#endif
	/********************************* Keypad port ************************************/
	
	/******************************** 7 SEGMENT port **********************************/
	//#define BCD

	#define COMMON_CATHODE
	//#define COMMON_ANODE
	
	#if defined(Eta32Mini)
		#define SEG_DIR GPIO_PORTA_CONTROL
		#define SEG_VAL GPIO_PORTA_DATA
		#define SEG_EN_DIR GPIO_PORTC_CONTROL
		#define SEG_EN_VAL GPIO_PORTC_DATA
		#define SEG_EN_1 PIN_6
		#define SEG_EN_2 PIN_7
	#elif defined(Proteus)
		#define SEG_DIR GPIO_PORTC_CONTROL
		#define SEG_VAL GPIO_PORTC_DATA
		#define SEG_EN_DIR GPIO_PORTD_CONTROL
		#define SEG_EN_VAL GPIO_PORTD_DATA
		#define SEG_EN_1 PIN_0
		#define SEG_EN_2 PIN_1
	#elif defined(ATmega32)
		#define SEG_DIR GPIO_PORTA_CONTROL
		#define SEG_VAL GPIO_PORTA_DATA
		#define SEG_EN_DIR GPIO_PORTB_CONTROL
		#define SEG_EN_VAL GPIO_PORTB_DATA
		#define SEG_EN_1 PIN_0
		#define SEG_EN_2 PIN_1
	#endif
	/******************************** 7 SEGMENT port **********************************/	
	
	/************************************* ADC ****************************************/	
	/* NOT USED, for demonstration only */
	#define POT_1 ADC0
	#define POT_2 ADC1
	/************************************* ADC ****************************************/	
	
#endif /* HARDWARE_H_ */