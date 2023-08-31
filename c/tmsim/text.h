#ifndef TEXT_H_
#define TEXT_H_

#include <stdint.h>

/***************************************
* TMSim - Text management header file
*
* This module currently supports the
* RC2014 and modern systems, but can
* be expanded to support more systems
* and features (such as RTC support).
***************************************/

// text delay mappings
#define MAIN_MENU   0
#define SLOW_NARR   1
#define NORM_NARR   2
#define FAST_NARR   3
#define SLOW_TDOS   4
#define NORM_TDOS   5
#define FAST_TDOS   6
#define ENDING      7

// delay array mappings (matching above)
static const uint16_t delays[8] = {
    144, 
    640, 
    256, 
    160,
    512, 
    256, 
    192, 
    1024
};

// delay loop constant
#ifdef RC
#define DELAYLOOP   16
#else
#define DELAYLOOP   65535
#endif
// TODO: sync the delay loop to 1ms and add RTC delay support,
//       then integrate both into a single delay function

// print buffer shared by all modules
#define PRINT_BUF   64
static char print_buffer[PRINT_BUF];    // reasonable width?
static char* print = print_buffer;      // 64-char print buffer

// print the provided game text at the provided speed
void tmprint(char*, uint8_t);

// delay loop for computers without a rtc
void delay(uint16_t);

// print a line of the provided chracter to the specified width
void lineprint(char, uint8_t);

// get a single-character response from the player
int get_response(void);

#endif
