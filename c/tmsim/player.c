#include <stdio.h>
#include <stdint.h>

/***************************************
*
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

