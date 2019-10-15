#ifndef LED_H_
	#define LED_H_

	#include "hardware.h"

	typedef enum
	{
		led_1,
		led_2,
		led_3,
		
		#if defined(Eta32Mini)
			led_4,
			led_5,
			led_6,
		#endif
	} led_number;

	void leds_out();
	void leds_on();
	void leds_off();
	void leds_toggle();
	uint8 leds_get_state();

	void led_out(led_number led_select);
	void led_write(led_number led_select, uint8 val);
	void led_toggle(led_number led_select);
	uint8 led_get_state(led_number led_select);

	void led_update();

#endif /* LED_H_ */