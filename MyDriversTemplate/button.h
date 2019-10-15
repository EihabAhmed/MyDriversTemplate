#ifndef BUTTON_H_
	#define BUTTON_H_
	
	#include "hardware.h"
	
	typedef enum
	{
		button_1,
		button_2,
		button_3,
		button_4,
	} button_number;

	void buttons_init();
	void button_init(button_number bt_number);
	void pullup_button(uint8 index);
	void pullup_buttons();
	char button_read(button_number bt_number);
	char *buttons_read();
	void button_update();
#endif /* BUTTON_H_ */