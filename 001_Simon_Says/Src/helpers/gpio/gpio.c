#include "gpio.h"

void initGPIO(
	RCC_AHB1ENREG volatile *const pRCCAHB1ENREG,
	GPIOx_MODEREG volatile *const pGPIODModeReg,
	GPIOx_PUPDREG volatile *const pGPIODPUPDReg
) {
	// enable clock (RCC peripheral) for GPIOD peripheral (port D)
	pRCCAHB1ENREG->gpioDEN = 1;

	// set the keypad columns pin mode to input mode
	pGPIODModeReg->modeR8 = 0;
	pGPIODModeReg->modeR9 = 0;
	pGPIODModeReg->modeR10 = 0;
	pGPIODModeReg->modeR11 = 0;

	// enable internal pull-up resistors for keypad column pins
	pGPIODPUPDReg->PUPDR8 = 1;
	pGPIODPUPDReg->PUPDR9 = 1;
	pGPIODPUPDReg->PUPDR10 = 1;
	pGPIODPUPDReg->PUPDR11 = 1;

	// set the keypad rows pin mode to output mode
	pGPIODModeReg->modeR0 = 1;
	pGPIODModeReg->modeR1 = 1;
	pGPIODModeReg->modeR2 = 1;
	pGPIODModeReg->modeR3 = 1;

	// set LEDs mode (PD12-15) to ouput mode
	pGPIODModeReg->modeR12 = 1;
	pGPIODModeReg->modeR13 = 1;
	pGPIODModeReg->modeR14 = 1;
	pGPIODModeReg->modeR15 = 1;
}

//char* recieveInput() {
//
//}
