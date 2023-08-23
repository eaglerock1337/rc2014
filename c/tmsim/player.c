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

void initialize_player(uint8_t difficulty, struct player* play) {
    roll_stats(difficulty, play);
    play->experience = 0;
    play->level = 1;
    play->aggro = 0;
    play->difficulty = difficulty;
}

