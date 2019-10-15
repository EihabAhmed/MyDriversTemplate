#include "led.h"

void leds_out()
{
	PIN_WRITE(LED_DIR, LED_1_PIN, OUTPUT);
	PIN_WRITE(LED_DIR, LED_2_PIN, OUTPUT);
	PIN_WRITE(LED_DIR, LED_3_PIN, OUTPUT);
	
	#if defined(Eta32Mini)
		PIN_WRITE(LED_DIR, LED_4_PIN, OUTPUT);
		PIN_WRITE(LED_DIR, LED_5_PIN, OUTPUT);
		PIN_WRITE(LED_DIR, LED_6_PIN, OUTPUT);
	#endif
	
	/* or we can write like that
	HIGHER_NIBBLE_VALUE(led_dir, 13); */
}

void leds_on()
{
	PIN_WRITE(LED_VAL, LED_1_PIN, GPIO_HIGH);
	PIN_WRITE(LED_VAL, LED_2_PIN, GPIO_HIGH);
	PIN_WRITE(LED_VAL, LED_3_PIN, GPIO_HIGH);
	
	#if defined(Eta32Mini)
		PIN_WRITE(LED_VAL, LED_4_PIN, GPIO_HIGH);
		PIN_WRITE(LED_VAL, LED_5_PIN, GPIO_HIGH);
		PIN_WRITE(LED_VAL, LED_6_PIN, GPIO_HIGH);
	#endif
}

void leds_off()
{
	PIN_WRITE(LED_VAL, LED_1_PIN, GPIO_LOW);
	PIN_WRITE(LED_VAL, LED_2_PIN, GPIO_LOW);
	PIN_WRITE(LED_VAL, LED_3_PIN, GPIO_LOW);
	
	#if defined(Eta32Mini)
		PIN_WRITE(LED_VAL, LED_4_PIN, GPIO_LOW);
		PIN_WRITE(LED_VAL, LED_5_PIN, GPIO_LOW);
		PIN_WRITE(LED_VAL, LED_6_PIN, GPIO_LOW);
	#endif
}

void leds_toggle()
{
	TOG_PIN(LED_VAL, LED_1_PIN);
	TOG_PIN(LED_VAL, LED_2_PIN);
	TOG_PIN(LED_VAL, LED_3_PIN);
	
	#if defined(Eta32Mini)
		TOG_PIN(LED_VAL, LED_4_PIN);
		TOG_PIN(LED_VAL, LED_5_PIN);
		TOG_PIN(LED_VAL, LED_6_PIN);
	#endif
}

uint8 leds_get_state()
{
	#if defined (Eta32Mini)
		return LED_VAL & ((0x01 << LED_1_PIN) | (0x01 << LED_2_PIN) | (0x01 << LED_3_PIN) | (0x01 << LED_4_PIN) | (0x01 << LED_5_PIN) | (0x01 << LED_6_PIN));
	#elif defined (Proteus)
		return LED_VAL & ((0x01 << LED_1_PIN) | (0x01 << LED_2_PIN) | (0x01 << LED_3_PIN));
	#elif defined (ATmega32)
		return LED_VAL & ((0x01 << LED_1_PIN) | (0x01 << LED_2_PIN) | (0x01 << LED_3_PIN));
	#endif	
}

void led_out(led_number led_select)
{
	switch (led_select)
	{
		case led_1:
			PIN_WRITE(LED_DIR, LED_1_PIN, OUTPUT);
			break;
		case led_2:
			PIN_WRITE(LED_DIR, LED_2_PIN, OUTPUT);
			break;
		case led_3:
			PIN_WRITE(LED_DIR, LED_3_PIN, OUTPUT);
			break;
			
		#if defined(Eta32Mini)
			case led_4:
				PIN_WRITE(LED_DIR, LED_4_PIN, OUTPUT);
				break;
			case led_5:
				PIN_WRITE(LED_DIR, LED_5_PIN, OUTPUT);
				break;
			case led_6:
				PIN_WRITE(LED_DIR, LED_6_PIN, OUTPUT);
				break;
		#endif
	}
}

uint8 led_get_state(led_number led_select)
{
	volatile uint8 led_state;
	switch (led_select)
	{
		case led_1:
			led_state = GET_PIN(LED_VAL, LED_1_PIN);
			break;
		case led_2:
			led_state = GET_PIN(LED_VAL, LED_2_PIN);
			break;
		case led_3:
			led_state = GET_PIN(LED_VAL, LED_3_PIN);
			break;
			
		#if defined(Eta32Mini)
			case led_4:
				led_state = GET_PIN(LED_VAL, LED_4_PIN);
				break;
			case led_5:
				led_state = GET_PIN(LED_VAL, LED_5_PIN);
				break;
			case led_6:
				led_state = GET_PIN(LED_VAL, LED_6_PIN);
				break;
		#endif
	}
	
	return led_state;
}

void led_write(led_number led_select, uint8 val)
{
	switch (led_select)
	{
		case led_1:
			PIN_WRITE(LED_VAL, LED_1_PIN, val);
			break;
		case led_2:
			PIN_WRITE(LED_VAL, LED_2_PIN, val);
			break;
		case led_3:
			PIN_WRITE(LED_VAL, LED_3_PIN, val);
			break;
			
		#if defined(Eta32Mini)
			case led_4:
				PIN_WRITE(LED_VAL, LED_4_PIN, val);
				break;
			case led_5:
				PIN_WRITE(LED_VAL, LED_5_PIN, val);
				break;
			case led_6:
				PIN_WRITE(LED_VAL, LED_6_PIN, val);
				break;
		#endif
	}
}

void led_toggle(led_number led_select)
{
	switch (led_select)
	{
		case led_1:
			TOG_PIN(LED_VAL, LED_1_PIN);
			break;
		case led_2:
			TOG_PIN(LED_VAL, LED_2_PIN);
			break;
		case led_3:
			TOG_PIN(LED_VAL, LED_3_PIN);
			break;
			
		#if defined(Eta32Mini)
			case led_4:
				TOG_PIN(LED_VAL, LED_4_PIN);
				break;
			case led_5:
				TOG_PIN(LED_VAL, LED_5_PIN);
				break;
			case led_6:
				TOG_PIN(LED_VAL, LED_6_PIN);
				break;
		#endif
	}
}

void led_update()
{
	//leds_toggle();
	//_delay_ms(500);
}