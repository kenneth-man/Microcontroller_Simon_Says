#include "led.h"

void orange(
	GPIOx_ODREG volatile *const pGPIODODReg,
	DELAYS d
){
	pGPIODODReg->ODR13 = 1;
	delay(MEDIUM);
	pGPIODODReg->ODR13 = 0;
}

void green(
	GPIOx_ODREG volatile *const pGPIODODReg,
	DELAYS d
){
	pGPIODODReg->ODR12 = 1;
	delay(d);
	pGPIODODReg->ODR12 = 0;
}

void blue(
	GPIOx_ODREG volatile *const pGPIODODReg,
	DELAYS d
){
	pGPIODODReg->ODR15 = 1;
	delay(d);
	pGPIODODReg->ODR15 = 0;
}

void red(
	GPIOx_ODREG volatile *const pGPIODODReg,
	DELAYS d
){
	pGPIODODReg->ODR14 = 1;
	delay(d);
	pGPIODODReg->ODR14 = 0;
}
