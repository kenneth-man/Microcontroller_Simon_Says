#ifndef HELPERS_OUTPUTDELAY_OUTPUTDELAY_H_
#define HELPERS_OUTPUTDELAY_OUTPUTDELAY_H_

#include "../output/output.h"
#include "../delay/delay.h"
#include "../../enums/delays.h"

void outputDelay(
	const char *message,
	const DELAYS delayType
);

#endif
