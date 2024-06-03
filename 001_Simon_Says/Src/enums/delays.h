#ifndef ENUMS_DELAYS_H_
#define ENUMS_DELAYS_H_

/*
	Processor running with 16Mhz of internal RC oscillator
	Assuming 1 assembly instruction takes 1 clock cycle

	1 instruction = approx 0.0625 microseconds
	7 instructions = approx 0.5 microseconds

	0.5 microseconds = approx 1 iteration of for loop
	1000 microseconds = approx 1 millisecond (2000 for loop iterations)

	150 milliseconds = approx 150 * 2000 = 300000

*/

typedef enum {
	SMALL = 150000,
	MEDIUM = 300000,
	LARGE = 600000,
	EXTRA_LARGE = 2000000
} DELAYS;

#endif
