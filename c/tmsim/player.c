#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "player.h"
#include "sim.h"

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
    // player progress
    p->exp = 0;
    p->level = 1;
    p->score = 0;
    // player threat
    p->difficulty = difficulty;
    p->aggro = 0;
    // player state
    p->view = VIEW_CONSOLE;         // set to console view
    p->new_view = true;
    p->paused = true;
}

