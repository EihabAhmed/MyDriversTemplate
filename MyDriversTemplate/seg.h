#ifndef SEG_H_
	#define SEG_H_

	#include "hardware.h"
	
	typedef enum
	{
		seg_1,
		seg_2,
		seg_both,
	} seg_select;

	void seg_init();
	void seg_write(seg_select seg, uint8 value);
	void seg_update();

#endif /* SEG_H_ */