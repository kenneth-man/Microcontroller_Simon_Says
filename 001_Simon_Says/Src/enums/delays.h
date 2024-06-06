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
	// 0.075 seconds
	// used for looping over this enum because each value has a difference of 150000 from prev/next
	SPEED_DIFF = 150000,
	SPEED2 = 300000, // 0.15 seconds
	SPEED3 = 450000, // 0.225 seconds
	SPEED4 = 600000, // 0.3 seconds
	SPEED5 = 750000, // 0.375 seconds
	SPEED6 = 900000, // 0.45 seconds
	SPEED7 = 1050000, // 0.525 seconds
	SPEED8 = 1200000, // 0.6 seconds
	SPEED9 = 1350000, // 0.675 seconds
	SPEED10 = 1500000, // 0.75 seconds
	SPEED_MAX = 1650000 // 0.825 seconds
} DELAYS;

#endif
