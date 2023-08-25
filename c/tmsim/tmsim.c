#include "player.h"
#include "tdos.h"
#include "tm.h"

/**********************************************************
* TMSim - a nominally fun time-travelling simulator
*         version 0.0.3 by Peter Marks
*
* nominal: (adj) existing in name only.
*
**********************************************************/

int main (void) {
    uint8_t difficulty = 5;
    struct player me;
    struct time_machine tm;
    initialize_player(difficulty, &me);
    initialize_tm(difficulty, &tm);
    cold_boot(&tm);
    tdos_command_loop(&tm, &me);
    return 0;
}