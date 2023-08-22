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
    struct player me = get_player(3);
    struct time_machine tm = get_time_machine(3);
    tdos_command_loop(&tm, &me);
    return 0;
}