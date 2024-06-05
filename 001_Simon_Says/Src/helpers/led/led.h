#ifndef HELPERS_LED_LED_H_
#define HELPERS_LED_LED_H_

#include <stdint.h>
#include "../../structs/GPIOx_ODREG.h"
#include "../delay/delay.h"
#include "../../enums/delays.h"

// circle animation (5 times for intro, 3 for correct answer...)
// flashing animation (option for delay speed, 5 times for selecting a difficulty level, 3 for incorrect answer)
void circle(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS delay);
void flash(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS delay);
void persist(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS delay);

void display(
	GPIOx_ODREG volatile *const pGPIODODReg,
	DELAYS delay,
	uint8_t count,
	void animation(GPIOx_ODREG volatile *const pGPIODODReg, DELAYS delay)
);

#endif
