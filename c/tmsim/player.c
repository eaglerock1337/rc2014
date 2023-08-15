#include <stdio.h>
#include <stdint.h>

#include "player.h"

/***************************************
* TMSim - Player module
***************************************/

uint8_t roll_stat(uint8_t difficulty) {
    return rand() % 5 + (6 - difficulty);
}

void roll_stats(uint8_t difficulty, struct player* p) {
    for(uint8_t i = 0; i < 6; i++) {
        p->stats[i] = roll_stat(difficulty);
    }
}

struct player get_player(uint8_t difficulty) {
    struct player new;

    for(uint8_t i = 0; i < 6; i++) {
        new.stats[i] = roll_stat(difficulty);
    }

    new.experience = 0;
    new.level = 1;
    new.aggro = 0;
    new.difficulty = difficulty;

    return new;
}

