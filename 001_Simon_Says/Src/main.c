#include <stdint.h>
#include "helpers/outputDelay/outputDelay.h"
#include "enums/delays.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	while(1) {
		outputDelay("1 message", LARGE);
		outputDelay("2 message", LARGE);
		outputDelay("3 message", LARGE);
		outputDelay("4 message", EXTRA_LARGE);
		outputDelay("5 message", LARGE);
		outputDelay("6 message", LARGE);
		outputDelay("7 message", LARGE);
		outputDelay("8 message", EXTRA_LARGE);
		outputDelay("9 message", LARGE);
		outputDelay("10 message", LARGE);
	}
}
