#ifndef TDOS_H_
#define TDOS_H_

#include <stdbool.h>
#include <stdint.h>

#include "tm.h"
#include "player.h"

/***************************************
* TMSim - TDOS system header file
***************************************/

// the main TDOS command loop
void tdos_command_loop(struct time_machine*, struct player*);

// TDOS module print routine
void printdos(char*, uint8_t);

// the TDOS boot sequence
bool boot(struct time_machine*);

#endif
