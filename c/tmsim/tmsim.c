#include "player.h"
#include "tdos.h"
#include "tm.h"

/**********************************************************
* TMSim - a nominally fun time-travelling simulator
*         by Peter Marks
*
* nominal: (adj) existing in name only.
*
* Version History
* 0.0.1 - 8/13/23 - Initial version
**********************************************************/

int main (void) {
    uint8_t difficulty = 5;
    struct player me;
    struct time_machine tm;
    initialize_player(difficulty, &me);
    initialize_tm(difficulty, &tm);
    boot(&tm);
    tdos_command_loop(&tm, &me);
    return 0;
}