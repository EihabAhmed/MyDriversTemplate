#include "interrupt.h"

void Interrupt0_handler();
void Interrupt1_handler();
void Interrupt2_handler();

void interrupt_init(interrupt_pins intrpt, trigger trig)
{
	switch (intrpt)
	{
		case Interrupt0:
			PIN_WRITE(GPIO_PORTD_CONTROL, PIN_2, INPUT);
			PIN_WRITE(GPIO_PORTD_DATA, PIN_2, GPIO_HIGH);
			PIN_WRITE(GENERAL_INTERRUPT, INT0_ENABLE_BIT, GPIO_HIGH);
			switch (trig)
			{
				case LowLevel:
					INT0_LOW_LEVEL;
					break;
				case LogicalChange:
					INT0_LOGICAL_CHANGE;
					break;
				case FallingEdge:
					INT0_FALLING_EDGE;
					break;
				case RisingEdge:
					INT0_RISING_EDGE;
					break;
			}
			break;
		case Interrupt1:
			PIN_WRITE(GPIO_PORTD_CONTROL, PIN_3, INPUT);
			PIN_WRITE(GPIO_PORTD_DATA, PIN_3, GPIO_HIGH);
			PIN_WRITE(GENERAL_INTERRUPT, INT1_ENABLE_BIT, GPIO_HIGH);
			switch (trig)
			{
				case LowLevel:
					INT1_LOW_LEVEL;
					break;
				case LogicalChange:
					INT1_LOGICAL_CHANGE;
					break;
				case FallingEdge:
					INT1_FALLING_EDGE;
					break;
				case RisingEdge:
					INT1_RISING_EDGE;
					break;
			}
			break;
		case Interrupt2:
			PIN_WRITE(GPIO_PORTB_CONTROL, PIN_2, INPUT);
			PIN_WRITE(GPIO_PORTB_DATA, PIN_2, GPIO_HIGH);
			PIN_WRITE(GENERAL_INTERRUPT, INT2_ENABLE_BIT, GPIO_HIGH);
			switch (trig)
			{
				case FallingEdge:
					INT2_FALLING_EDGE;
					break;
				case RisingEdge:
					INT2_RISING_EDGE;
					break;
				default:
					break;
			}
			break;
	}
	
	sei();
}

ISR(INT0_vect)
{
	Interrupt0_handler();
}

ISR(INT1_vect)
{
	Interrupt1_handler();
}

ISR(INT2_vect)
{
	Interrupt2_handler();
}