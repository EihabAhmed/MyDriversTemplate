#include "adc.h"

static float vref = 0;

void adc_init(division_factor fact, used_voltage used)
{
	ADC_ENABLE; // ADEN = 1
	//ADLAR = 0;
	
	switch (used)
	{
		case Internal:
			vref = 2.56;
			INTERNAL_VOLTAGES;
			break;
		case ExternalAREF:
			vref = 5;
			AREF_VOLTAGES;
			break;
		case ExternalAVCC:
			vref = 5;
			AVCC_VOLTAGES;
			break;
	}
	
	switch (fact)
	{
		case divFact2:
			DIVISION_FACTOR_2;
			break;
		case divFact4:
			DIVISION_FACTOR_4;
			break;
		case divFact8:
			DIVISION_FACTOR_8;
			break;
		case divFact16:
			DIVISION_FACTOR_16;
			break;
		case divFact32:
			DIVISION_FACTOR_32;
			break;
		case divFact64:
			DIVISION_FACTOR_64;
			break;
		case divFact128:
			DIVISION_FACTOR_128;
			break;
	}
}

short int adc_read(input_pins adc_pin)
{
	SELECTED_PIN(adc_pin);
	ADC_START_CONVERSION;
	while (ADC_FLAG);
	int _adcl = ADCL;
	int _adch = ADCH;
	return _adcl | (_adch << 8) /*ADC*/ /*ADCL | (ADCH << 8)*/;
}

float adc_read_voltage(input_pins adc_pin)
{
	float adc_val = adc_read(adc_pin);
	adc_val = adc_val * (vref / 1024.0); 
	return adc_val;
}

void adc_update()
{
	/*int x = adc_read_voltage(ADC0) * 100;
	lcd_out(1, 1, convert_data(x));
	_delay_ms(1000);
	lcd_clear();*/
}