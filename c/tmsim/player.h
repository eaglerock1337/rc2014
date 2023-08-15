#include <stdio.h>
#include <stdint.h>

/***************************************
* TMSim - Player header file
***************************************/
struct player {
    // player stats
    uint8_t intelligence;
    uint8_t wisdom;
    uint8_t engineering;
    uint8_t dexterity;
    uint8_t disguise;
    uint8_t luck;

    // player progress
    uint8_t experience;
    uint8_t level;    
    uint8_t aggro;
};

// rolls a single stat based on a 1-5 difficulty
uint8_t roll_stat(uint8_t);

// roll a player's stats based on a 1-5 difficulty
void roll_stats(uint8_t, struct player*);

// get a player struct with initialized stats
struct player get_player(uint8_t);