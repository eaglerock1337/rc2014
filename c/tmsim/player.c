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
    p->intelligence = roll_stat(difficulty);
    p->wisdom = roll_stat(difficulty);
    p->engineering = roll_stat(difficulty);
    p->dexterity = roll_stat(difficulty);
    p->disguise = roll_stat(difficulty);
    p->luck = roll_stat(difficulty);
}

struct player get_player(uint8_t difficulty) {
    struct player new;
    roll_stats(difficulty, &new);

    new.experience = 0;
    new.level = 1;
    new.aggro = 0;

    return new;
}

