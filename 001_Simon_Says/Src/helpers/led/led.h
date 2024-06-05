#ifndef HELPERS_LED_LED_H_
#define HELPERS_LED_LED_H_

#include <stdint.h>
#include "../../structs/GPIOx_ODREG.h"
#include "../delay/delay.h"
#include "../../enums/delays.h"

void orange(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);
void green(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);
void blue(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);
void red(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);

// circle animation (5 times for intro, 3 for correct answer...)
// flashing animation (option for delay speed, 5 times for selecting a difficulty level, 3 for incorrect answer)
void circle(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);
void flash(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);
void persist(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS d);

void display(
	GPIOx_ODREG volatile *const pGPIODODReg,
	DELAYS delay,
	uint8_t count,
	void animation(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS delay)
);

#endif
