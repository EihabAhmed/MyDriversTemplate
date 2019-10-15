/*
 * MyDriversTemplate.c
 *
 * Created: 9/15/2019 1:13:44 AM
 * Author : Eihab
 */ 

#include <avr/io.h>

#include "led.h"
#include "button.h"
#include "lcd.h"
#include "keypad.h"
#include "seg.h"
#include "adc.h"
#include "interrupt.h"

//#define RGB_LED_TEST
#define LED_TEST
//#define BUTTON_TEST
//#define LCD_TEST
//#define KEYPAD_TEST
//#define SEG_TEST
//#define ADC_TEST
//#define INTERRUPT_TEST

void Interrupt0_handler()
{
	led_toggle(led_1);
	_delay_ms(50);
}

void Interrupt1_handler()
{
	led_toggle(led_2);
	_delay_ms(50);
}

void Interrupt2_handler()
{
	led_toggle(led_3);
	_delay_ms(50);
}

int main(void)
{
	/**************************** RGB LED *********************************/
	#if defined (RGB_LED_TEST)
		leds_out();
		keypad_init();
	
		int i = 0;
	
		while (1)
		{
			keypad_get_pressed();
			i++;
			if (i == 8)
				i = 0;
		
			LED_VAL = (LED_VAL & 0b11111000) | i;
		}
	#endif
	/**************************** RGB LED *********************************/
	
    /****************************** LED ***********************************/
	#if defined(LED_TEST)
		leds_out();
	
		int index = 0;
		led_toggle(index);
		while(1)
		{
			_delay_ms(200);
			led_toggle(index);
			index++;
			if (index == LEDS_COUNT)
			index = 0;
			led_toggle(index);
		
			/*leds_on();
			_delay_ms(200);
			leds_off();
			_delay_ms(1000);*/
		}
	#endif
	/****************************** LED ***********************************/
	
	/***************************** BUTTON *********************************/
	#if defined(BUTTON_TEST)
		buttons_init();
		pullup_buttons();
		leds_out();
	
		while(1)
		{
			if (button_read(button_1) == GPIO_LOW)
				PIN_WRITE(LED_VAL, LED_1_PIN, GPIO_HIGH);
			else
				PIN_WRITE(LED_VAL, LED_1_PIN, GPIO_LOW);
				
			if (button_read(button_2) == GPIO_LOW)
				PIN_WRITE(LED_VAL, LED_2_PIN, GPIO_HIGH);
			else
				PIN_WRITE(LED_VAL, LED_2_PIN, GPIO_LOW);
				
			if (button_read(button_3) == GPIO_LOW)
				PIN_WRITE(LED_VAL, LED_3_PIN, GPIO_HIGH);
			else
				PIN_WRITE(LED_VAL, LED_3_PIN, GPIO_LOW);
				
			#if defined(Eta32Mini)				
				if (button_read(button_4) == GPIO_LOW)
					PIN_WRITE(LED_VAL, LED_4_PIN, GPIO_HIGH);
				else
					PIN_WRITE(LED_VAL, LED_4_PIN, GPIO_LOW);
			#endif
		}
	#endif
	/***************************** BUTTON *********************************/
	
	/****************************** LCD ***********************************/
	#if defined(LCD_TEST)
		lcd_init();
		
		while (1)
		{
			for (uint8 i = 0; i < 16; i++)
			{
				lcd_out(i, 1, "hello");
				_delay_ms(500);
				lcd_out(0, 1, "                ");
				_delay_ms(10);
			}
		}
	#endif
	/****************************** LCD ***********************************/
	
	/***************************** KEYPAD *********************************/
	#if defined(KEYPAD_TEST)
		keypad_init();
		lcd_init();
		
		lcd_clear();
		lcd_set_cursor(0, 1);
		
		while(1)
		{
			unsigned char ch = keypad_get_pressed();
			lcd_send_data(ch);
		}
	#endif
	/***************************** KEYPAD *********************************/
	
	/**************************** 7 SEGMENT *******************************/
	#if defined(SEG_TEST)
		seg_init();
		
		int count = 0;
		
		PIN_WRITE(DDRB, PIN_0, OUTPUT);
		PIN_WRITE(PORTB, PIN_0, GPIO_HIGH);
		
		while (1)
		{
			seg_write(seg_both, count);
			_delay_ms(1000);
			
			count++;
			if (count == 10)
			{
				count = 0;
			}
		}
	#endif
	/**************************** 7 SEGMENT *******************************/
	
	/****************************** ADC ***********************************/
	#if defined(ADC_TEST)
		adc_init(divFact32, Internal);
		//DDRA &= ~(1 << 0);
		lcd_init();
		
		float x;
		int whole;
		int fract;
		
		while (1)
		{
			//x = adc_read(ADC0);
			x = adc_read_voltage(ADC0) * 100;
			whole = x;
			fract = (x - whole) * 10;
			lcd_out(1, 1, convert_data(whole));
			lcd_send_data('.');
			lcd_send_string(convert_data(fract));
			_delay_ms(1000);
			lcd_clear();
		}
	#endif
	/****************************** ADC ***********************************/
	
	/*************************** INTERRUPT ********************************/
	#if defined(INTERRUPT_TEST)
		leds_out();
		leds_on();
		
		interrupt_init(Interrupt0, FallingEdge);
		interrupt_init(Interrupt1, FallingEdge);
		interrupt_init(Interrupt2, FallingEdge);
		
		while (1);
	#endif
	/*************************** INTERRUPT ********************************/
}

