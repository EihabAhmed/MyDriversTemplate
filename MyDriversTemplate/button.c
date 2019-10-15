#include "button.h"

void buttons_init()
{
	PIN_WRITE(BUTTON_DIR, BUTTON_1_PIN, INPUT);
	PIN_WRITE(BUTTON_DIR, BUTTON_2_PIN, INPUT);
	PIN_WRITE(BUTTON_DIR, BUTTON_3_PIN, INPUT);
	PIN_WRITE(BUTTON_DIR, BUTTON_4_PIN, INPUT);
}

void button_init(button_number bt_number)
{
	switch (bt_number)
	{
		case button_1:
			PIN_WRITE(BUTTON_DIR, BUTTON_1_PIN, INPUT);
			break;
		case button_2:
			PIN_WRITE(BUTTON_DIR, BUTTON_2_PIN, INPUT);
			break;
		case button_3:
			PIN_WRITE(BUTTON_DIR, BUTTON_3_PIN, INPUT);
			break;
		case button_4:
			PIN_WRITE(BUTTON_DIR, BUTTON_4_PIN, INPUT);
			break;
	}
}

void pullup_button(uint8 index)
{
	PIN_WRITE(BUTTON_PULLUP, index, GPIO_HIGH);	
}

void pullup_buttons()
{
	PIN_WRITE(BUTTON_PULLUP, BUTTON_1_PIN, GPIO_HIGH);
	PIN_WRITE(BUTTON_PULLUP, BUTTON_2_PIN, GPIO_HIGH);
	PIN_WRITE(BUTTON_PULLUP, BUTTON_3_PIN, GPIO_HIGH);
	PIN_WRITE(BUTTON_PULLUP, BUTTON_4_PIN, GPIO_HIGH);
}

char button_read(button_number bt_number)
{
	char x = 0;
	switch (bt_number)
	{
		case button_1:
			x = GET_PIN(BUTTON_VAL, BUTTON_1_PIN);
			break;
		case button_2:
			x = GET_PIN(BUTTON_VAL, BUTTON_2_PIN);
			break;
		case button_3:
			x = GET_PIN(BUTTON_VAL, BUTTON_3_PIN);
			break;
		case button_4:
			x = GET_PIN(BUTTON_VAL, BUTTON_4_PIN);
			break;
	}
	
	return x;
}

char *buttons_read()
{
	static char button_value[BUTTONS_COUNT] = {0};
	
	for (int i = 0; i < BUTTONS_COUNT; i++)
	{
		button_value[i] = button_read(i);
	}
	
	return button_value;
}

void button_update()
{
	/*if (button_read(button_1) == GPIO_LOW)
		PIN_WRITE(led_val, ledrpin, GPIO_HIGH);
	else
		PIN_WRITE(led_val, ledrpin, GPIO_LOW);
	if (button_read(button_2) == GPIO_LOW)
		PIN_WRITE(led_val, ledypin, GPIO_HIGH);
	else
		PIN_WRITE(led_val, ledypin, GPIO_LOW);
	if (button_read(button_3) == GPIO_LOW)
		PIN_WRITE(led_val, ledgpin, GPIO_HIGH);
	else
		PIN_WRITE(led_val, ledgpin, GPIO_LOW);*/
}