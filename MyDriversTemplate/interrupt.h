#ifndef INTERRUPT_H_
	#define INTERRUPT_H_
	
	#include "micro.h"
	
	#define INT0_LOW_LEVEL PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE00, GPIO_LOW), PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE01, GPIO_LOW)
	#define INT0_LOGICAL_CHANGE PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE00, GPIO_HIGH), PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE01, GPIO_LOW)
	#define INT0_FALLING_EDGE PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE00, GPIO_LOW), PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE01, GPIO_HIGH)
	#define INT0_RISING_EDGE PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE00, GPIO_HIGH), PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE01, GPIO_HIGH)
	
	#define INT1_LOW_LEVEL PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE10, GPIO_LOW), PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE11, GPIO_LOW)
	#define INT1_LOGICAL_CHANGE PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE10, GPIO_HIGH), PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE11, GPIO_LOW)
	#define INT1_FALLING_EDGE PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE10, GPIO_LOW), PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE11, GPIO_HIGH)
	#define INT1_RISING_EDGE PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE10, GPIO_HIGH), PIN_WRITE(MICRO_CONTROL, INTERRUPT_SENSE11, GPIO_HIGH)

	#define INT2_FALLING_EDGE PIN_WRITE(MICRO_CONTROL_STATUS, INTERRUPT_SENSE2, GPIO_LOW)
	#define INT2_RISING_EDGE PIN_WRITE(MICRO_CONTROL_STATUS, INTERRUPT_SENSE2, GPIO_HIGH)

	typedef enum
	{
		Interrupt0,
		Interrupt1,
		Interrupt2,
	} interrupt_pins;
	
	typedef enum
	{
		LowLevel,
		LogicalChange,
		FallingEdge,
		RisingEdge,
	} trigger;
	
	void interrupt_init(interrupt_pins intrpt, trigger trig);
#endif /* INTERRUPT_H_ */