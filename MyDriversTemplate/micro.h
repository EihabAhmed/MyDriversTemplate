#ifndef MICRO_H_
	#define MICRO_H_

	#include "config.h"

	/* GPIO definitions */
	/* GPIO Pins */
	#define PIN_0 (0)
	#define PIN_1 (1)
	#define PIN_2 (2)
	#define PIN_3 (3)
	#define PIN_4 (4)
	#define PIN_5 (5)
	#define PIN_6 (6)
	#define PIN_7 (7)

	/* GPIO Port Registers redefinition */
	#define GPIO_PORTA_DATA (PORTA)
	#define GPIO_PORTA_CONTROL (DDRA)
	#define GPIO_PORTA_INPUT (PINA)

	#define GPIO_PORTB_DATA (PORTB)
	#define GPIO_PORTB_CONTROL (DDRB)
	#define GPIO_PORTB_INPUT (PINB)

	#define GPIO_PORTC_DATA (PORTC)
	#define GPIO_PORTC_CONTROL (DDRC)
	#define GPIO_PORTC_INPUT (PINC)

	#define GPIO_PORTD_DATA (PORTD)
	#define GPIO_PORTD_CONTROL (DDRD)
	#define GPIO_PORTD_INPUT (PIND)

	//#define GPIO_PORTE_DATA (PORTE)
	//#define GPIO_PORTE_CONTROL (DDRE)
	//#define GPIO_PORTE_INPUT (PINE)

	/* Directions for GPIOS */
	#define INPUT 0
	#define OUTPUT 1

	/* Values of OUTPUT */
	#define GPIO_HIGH 1
	#define GPIO_LOW 0

	/* Macros for pin */
	#define PIN_WRITE(reg, pin, data) reg = (reg & (~(1 << pin))) | (data << pin)
	#define GET_PIN(reg, index) ((reg >> index) & 0x01)
	#define TOG_PIN(reg, pin) reg ^= 1 << pin

	/* Macros for port */
	#define INIT_PORT(CONTROL, DIRECTION) CONTROL = DIRECTION? ~GPIO_LOW : GPIO_LOW
	#define WRITE_PORT(PORT, DATA) PORT = DATA
	#define PORT_MASK(reg, val) reg |= val
	#define READ_PORT(PORT) PORT

	/* Lower Nibble 0-3 */
	#define GET_LOWER_NIBBLE(reg) (reg & 0x0f)
	#define LOWER_NIBBLE_HIGH(reg) reg = ((reg & 0xf0) | 0x0f)
	#define LOWER_NIBBLE_VALUE(reg, data) reg = (reg & 0xf0) | (data & 0x0f)

	/* Higher Nibble 4-7 */
	#define GET_HIGHER_NIBBLE(reg) (reg & 0xf0)
	#define HIGHER_NIBBLE_HIGH(reg) reg = ((reg & 0x0f) | 0xf0)
	#define HIGHER_NIBBLE_VALUE(reg, data) reg = (reg & 0x0f) | ((data << 4) & 0xf0)

	/* Other peripherals */

	// FOR EXAMPLE #define GLOBAL_INTERRUPT_ENABLE (SREG |= 1 << 7)
	/** ADC***/
	#define ADC_MULTIPLEXER ADMUX
	#define	ADC_CONTROL ADCSRA
	
	#define ADC_REFERENCE0 REFS0
	#define ADC_REFERENCE1 REFS1

	#define ADC_ENABLE_BIT ADEN
	#define ADC_START_BIT ADSC
	#define ADC_PRESCALER0 ADPS0
	#define ADC_PRESCALER1 ADPS1
	#define ADC_PRESCALER2 ADPS2
	
	/*** external interrupts***/
	#define	GENERAL_INTERRUPT		GICR
	#define	INT0_ENABLE_BIT			PIN_6
	#define	INT1_ENABLE_BIT			PIN_7
	#define	INT2_ENABLE_BIT			PIN_5

	#define MICRO_CONTROL			MCUCR
	#define INTERRUPT_SENSE00		ISC00
	#define INTERRUPT_SENSE01		ISC01
	#define INTERRUPT_SENSE10		ISC10
	#define INTERRUPT_SENSE11		ISC11
	
	#define MICRO_CONTROL_STATUS MCUCSR
	#define INTERRUPT_SENSE2 ISC2
	
	/*** TIMERS preipherals ***/	
	/*****TIMER0*******/
	#define		TIMER_CONTROL_0			TCCR0
	#define		TIMER_REGISTER_0		TCNT0
	#define		TIMER_OUTPUT_COMPARE_0	OCR0	
	#define		TIMER_INTERRUPT_MASK	TIMSK
	#define		TIMER_INTERRUPT_OVF_0	TOIE0
	#define		TIMER_INTERRUPT_COMP_0	OCIE0
	
	/* Data types */
	typedef unsigned char		uint8;  // 0 .. 255
	typedef signed char			sint8;  // -128 .. 127
	typedef unsigned short		uint16; // 0 .. 65535
	typedef signed short		sint16; // -32768 .. 32767
	typedef unsigned long		uint32; // 0 .. 4294967295
	typedef signed long			sint32; // -2147483648 .. 2147483647
	typedef unsigned long long	uint64; // 0 .. 18446744073709551615
	typedef signed long long	sint64;
	typedef float				float32;
	typedef double				float64;

	/* Boolean Data Type */
	typedef unsigned char bool;

	/* Boolean Values */
	#ifndef FALSE
		#define FALSE (0u)
	#endif

	#ifndef TRUE
		#define TRUE (1u)
	#endif
	
	#if defined(ATmega32)
		#define DISABLE_JTAG MCUCSR |= 1 << JTD, MCUCSR |= 1 << JTD
	#endif
#endif /* MICRO_H_ */