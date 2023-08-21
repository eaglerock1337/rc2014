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
void printdos(char*, struct time_machine*);

// the TDOS boot sequence
bool boot(struct time_machine*);
