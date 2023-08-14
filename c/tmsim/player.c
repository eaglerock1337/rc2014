#include <stdio.h>
#include <stdint.h>
#include "player.h"

/***************************************
* TMSim - Player module
***************************************/

int roll_stat(int difficulty) {
    return rand() % 5 + (6 - difficulty);
}

void roll_stats(int difficulty, struct player* p) {
    p->intelligence = roll_stat(difficulty);
    p->wisdom = roll_stat(difficulty);
    p->engineering = roll_stat(difficulty);
    p->dexterity = roll_stat(difficulty);
    p->disguise = roll_stat(difficulty);
    p->luck = roll_stat(difficulty);
}

struct player get_player(int difficulty) {
    struct player new;
    roll_stats(difficulty, &new);

    new.experience = 0;
    new.level = 1;
    new.aggro = 0;

    return new;
}

