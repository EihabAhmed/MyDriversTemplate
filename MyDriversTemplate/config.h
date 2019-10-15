#ifndef CONFIG_H_
	#define CONFIG_H_

	//#define Eta32Mini
	#define Proteus
	//#define ATmega32
	
	#ifndef F_CPU
		#if defined(Eta32Mini)
			#define F_CPU 16000000UL //16MHz Clock frequency
		#elif defined(Proteus)
			#define F_CPU 1000000UL //1MHz Clock frequency
		#elif defined(ATmega32)
			#define F_CPU 1000000UL //1MHz Clock frequency
		#endif
	#endif

	#include <avr/io.h>
	#include <avr/interrupt.h>
	#include <util/delay.h>

#endif /* CONFIG_H_ */