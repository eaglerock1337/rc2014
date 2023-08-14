#include <assert.h>
#include "cheat.h"
#include "../player.h"

/***************************************
* TMSim - Player unit tests
***************************************/

CHEAT_TEST(test_roll_stat,
    for(int i = 1; i <= 5; i++) {
        int roll = roll_stat(i);
        assert(roll > (6-i));
        assert(roll < 4 + (6-i));
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
