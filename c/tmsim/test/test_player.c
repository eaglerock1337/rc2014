#include <assert.h>
#include <stdint.h>
#include "cheat.h"
#include "../player.h"

/***************************************
* TMSim - Player unit tests
***************************************/

CHEAT_TEST(test_roll_stat,
    for (uint8_t i = 1; i <= 5; i++) {
        uint8_t roll = roll_stat(i);
        assert(roll > (6-i));
        assert(roll < 4 + (6-i));
    }
);

CHEAT_TEST(test_roll_stats,
    for (int i = 1; i <= 5; i++) {
        struct player play;
        roll_stats(i, &play);
        for(int j = 0; j < 6; j++) {
           assert(play.stats[j] > (6-i));
           assert(play.stats[j] < 4 + (6-i));
        }
    }
);

CHEAT_TEST(test_get_player,
    for (int i = 1; i <= 5; i++) {
        struct player play = get_player(i);
        for(int j = 0; j < 6; i++) {
           assert(play.stats[j] > (6-i));
           assert(play.stats[j] < 4 + (6-i));
        }
        assert(play.experience = 0);
        assert(play.level = 1);
        assert(play.aggro = 0);
        assert(play.difficulty = i);
    }
);
