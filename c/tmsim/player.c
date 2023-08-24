#include <stdint.h>
#include <stdlib.h>

#include "player.h"

/***************************************
* TMSim - Player module
***************************************/

uint8_t roll_stat(uint8_t difficulty) {
    return rand() % 5 + (6 - difficulty);
}

void roll_stats(uint8_t difficulty, struct player* p) {
    p->stats[WISDOM] = 6 - difficulty;
    p->stats[LUCK] = 1 + 2 * difficulty;
    // random numbers for all other stats
    for (uint8_t i = 1; i < 5; i++) {
        p->stats[i] = roll_stat(difficulty);
    }
}

void initialize_player(uint8_t difficulty, struct player* p) {
    roll_stats(difficulty, p);
    p->experience = 0;
    p->level = 1;
    p->aggro = 0;
    p->difficulty = difficulty;
}

