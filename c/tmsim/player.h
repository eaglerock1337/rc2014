#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdint.h>

/***************************************
* TMSim - Player header file
***************************************/

// stats array mappings
#define WISDOM          0
#define INTELLIGENCE    1
#define ENGINEERING     2
#define DEXTERITY       3
#define DISGUISE        4
#define LUCK            5

struct player {
    // player stats
    uint8_t stats[6];

    // player progress
    uint8_t experience;
    uint8_t level;    

    // player threat
    uint8_t difficulty;
    uint8_t aggro;
};

// rolls a single stat based on a 1-5 difficulty
uint8_t roll_stat(uint8_t);

// roll a player's stats based on a 1-5 difficulty
void roll_stats(uint8_t, struct player*);

// initialize the player struct based on given difficulty
void initialize_player(uint8_t, struct player*);

#endif

/* Idea TODOs:
*   TODO: add routines for specific wisdom point checkpoints
*   TODO: add routines for other points as well (e.g. engineering)
*   TODO: in events.h, make sure to add routines for one-time
*           events inside every-time events
*/