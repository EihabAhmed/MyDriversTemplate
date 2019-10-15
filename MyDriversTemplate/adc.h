#ifndef ADC_H_
	#define ADC_H_
	
	#include "micro.h"
	
	/**************************** Reference and pin select ******************************/
	#define INTERNAL_VOLTAGES ADC_MULTIPLEXER |= (1 << ADC_REFERENCE0) | (1 << ADC_REFERENCE1)
	#define AREF_VOLTAGES ADC_MULTIPLEXER &= (~(1 << ADC_REFERENCE0)) & (~(1 << ADC_REFERENCE1))
	#define AVCC_VOLTAGES PIN_WRITE(ADC_MULTIPLEXER, ADC_REFERENCE0, GPIO_HIGH), PIN_WRITE(ADC_MULTIPLEXER, ADC_REFERENCE1, GPIO_LOW)
	#define SELECTED_PIN(pin) ADC_MULTIPLEXER = (ADC_MULTIPLEXER & 0xe0) | (pin & 0x1f)
	
	/**************************** Reading process ******************************/
	#define ADC_FLAG ADC_CONTROL & (1 << ADC_START_BIT)  // ADIF ??
	#define ADC_START_CONVERSION ADC_CONTROL |= 1 << ADC_START_BIT
	#define ADC_ENABLE ADC_CONTROL |= 1 << ADC_ENABLE_BIT
	#define ADC_DISABLE ADC_CONTROL &= ~(1 << ADC_ENABLE_BIT)
	
	/**************************** Prescaler values ******************************/
	#define DIVISION_FACTOR_2 ADC_CONTROL |= 1 << ADC_PRESCALER0
	#define DIVISION_FACTOR_4 ADC_CONTROL |= 1 << ADC_PRESCALER1
	#define DIVISION_FACTOR_8 ADC_CONTROL |= (1 << ADC_PRESCALER0) | (1 << ADC_PRESCALER1)
	#define DIVISION_FACTOR_16 ADC_CONTROL |= 1 << ADC_PRESCALER2
	#define DIVISION_FACTOR_32 ADC_CONTROL |= (1 << ADC_PRESCALER0) | (1 << ADC_PRESCALER2)
	#define DIVISION_FACTOR_64 ADC_CONTROL |= (1 << ADC_PRESCALER1) | (1 << ADC_PRESCALER2)
	#define DIVISION_FACTOR_128 ADC_CONTROL |= (1 << ADC_PRESCALER0) | (1 << ADC_PRESCALER1) | (1 << ADC_PRESCALER2)
	
	/**************************** Names of inputs ******************************/
	typedef enum
	{
		ADC0,
		ADC1,
		ADC2,
		ADC3,
		ADC4,
		ADC5,
		ADC6,
		ADC7,
	} input_pins;
	
	typedef enum
	{
		divFact2,
		divFact4,
		divFact8,
		divFact16,
		divFact32,
		divFact64,
		divFact128,
	} division_factor;
	
	typedef enum
	{
		Internal,
		ExternalAREF,
		ExternalAVCC,
	} used_voltage;
		
	/**************************** Prototypes of functions ******************************/
	void adc_init(division_factor fact, used_voltage used);
	short int adc_read(input_pins adc_pin);
	float adc_read_voltage(input_pins adc_pin);
	void adc_update();
	
#endif /* ADC_H_ */