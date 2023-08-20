#include <stdint.h>

#include "tm.h"
#include "player.h"

/***************************************
* TMSim - TDOS system header file
***************************************/

// the main TDOS command loop
void tdos_command_loop(struct time_machine*, struct player*);

// the TDOS boot sequence
void boot(struct time_machine*);
