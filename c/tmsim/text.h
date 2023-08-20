#include <stdio.h>
#include <stdint.h>

/***************************************
* TMSim - Text management header file
*
* This module is specifically written
* for the RC2014, but is designed to
* be easily rewritten or expanded for
* other systems.
***************************************/

// text output mappings
#define MAIN_MENU   0
#define SLOW_NARR   1
#define NORM_NARR   2
#define FAST_NARR   3
#define SLOW_TDOS   4
#define NORM_TDOS   5
#define FAST_TDOS   6
#define ENDING      7

// the main TDOS command loop
void tmprint(char*, uint8_t);

// delay loop for computers without a rtc
void delay(uint16_t);
