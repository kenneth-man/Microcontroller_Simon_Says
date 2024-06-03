#include <stdint.h>
#include "macros.h"
#include "structs/GPIOx_IDREG.h"
#include "structs/GPIOx_ODREG.h"
#include "structs/GPIOx_MODEREG.h"
#include "structs/GPIOx_PUPDREG.h"
#include "structs/RCC_AHB1ENREG.h"
#include "helpers/outputTitle/outputTitle.h"
#include "helpers/gpio/gpio.h"
#include "helpers/led/led.h" // TODO testing - to remove
#include "enums/delays.h" // TODO testing - to remove

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	RCC_AHB1ENREG volatile *const pRCCAHB1ENREG = (RCC_AHB1ENREG*)(RCC_AHB1ENREG_ADDR);
	GPIOx_MODEREG volatile *const pGPIODModeReg = (GPIOx_MODEREG*)(GPIOD_MODEREG_ADDR);
	GPIOx_PUPDREG volatile *const pGPIODPUPDReg = (GPIOx_PUPDREG*)(GPIOD_PUPDREG_ADDR);
	//GPIOx_IDREG volatile *const pGPIODIDReg = (GPIOx_IDREG*)(GPIOD_IDREG_ADDR);
	GPIOx_ODREG volatile *const pGPIODODReg = (GPIOx_ODREG*)(GPIOD_ODREG_ADDR);

	outputTitle();
	initGPIO(pRCCAHB1ENREG, pGPIODModeReg, pGPIODPUPDReg);

	// TODO testing - to removed
	orange(pGPIODODReg, MEDIUM);
	green(pGPIODODReg, MEDIUM);
	blue(pGPIODODReg, MEDIUM);
	red(pGPIODODReg, MEDIUM);

	orange(pGPIODODReg, MEDIUM);
	green(pGPIODODReg, MEDIUM);
	blue(pGPIODODReg, MEDIUM);
	red(pGPIODODReg, MEDIUM);

	orange(pGPIODODReg, MEDIUM);
	green(pGPIODODReg, MEDIUM);
	blue(pGPIODODReg, MEDIUM);
	red(pGPIODODReg, MEDIUM);

	pGPIODODReg->ODR13 = 0;
	pGPIODODReg->ODR12 = 0;
	pGPIODODReg->ODR15 = 0;
	pGPIODODReg->ODR14 = 0;

	while(1) {

	}
}
