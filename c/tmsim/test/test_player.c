#include <assert.h>
#include <stdint.h>
#include "cheat.h"
#include "../player.h"

/***************************************
* TMSim - Player unit tests
***************************************/

CHEAT_TEST(test_roll_stat,
    for(uint8_t i = 1; i <= 5; i++) {
        uint8_t roll = roll_stat(i);
        assert(roll > (6-i));
        assert(roll < 4 + (6-i));
    }
);

CHEAT_TEST(test_roll_stats,
    for(uint8_t i = 1; i <= 5; i++) {
        struct player play = get_player(i);
        roll_stats(i, &play);
        assert(play.intelligence > (6-i));
        assert(play.intelligence < 4 + (6-i));
        assert(play.wisdom > (6-i));
        assert(play.wisdom < 4 + (6-i));
        assert(play.engineering > (6-i));
        assert(play.engineering < 4 + (6-i));
        assert(play.dexterity > (6-i));
        assert(play.dexterity < 4 + (6-i));
        assert(play.disguise > (6-i));
        assert(play.disguise < 4 + (6-i));
        assert(play.luck > (6-i));
        assert(play.luck < 4 + (6-i));    
    }
);

CHEAT_TEST(test_get_player,
    struct player play = get_player(3);
    assert(play.intelligence > 0);
    assert(play.wisdom < 10);
    assert(play.engineering > 0);
    assert(play.dexterity < 10);
    assert(play.disguise > 0);
    assert(play.luck < 10);
    assert(play.experience = 0);
    assert(play.level = 1);
    assert(play.aggro = 0);
);
