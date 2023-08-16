#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "cheat.h"
#include "../tm.h"

/***************************************
* TMSim - Time Machine unit tests
***************************************/

CHEAT_TEST(test_roll_part,
    for (int i = 1; i <= 5; i++) {
        int roll = roll_part(i);
        assert(roll > 25 + 10 * (6-i));
        assert(roll < 50 + 10 * (6-i));
    }
);

CHEAT_TEST(test_roll_parts,
    for (int i = 1; i <= 5; i++) {
        struct time_machine_parts parts;
        roll_parts(i, &parts);
        for(int j = 0; j < 6; j++) {
           assert(parts.exterior[j] > 25 + 10 * (6-i));
           assert(parts.exterior[j] < 50 + 10 * (6-i));
           assert(parts.interior[j] > 25 + 10 * (6-i));
           assert(parts.interior[j] < 50 + 10 * (6-i));
           assert(parts.computer[j] > 25 + 10 * (6-i));
           assert(parts.computer[j] < 50 + 10 * (6-i));
        }
    }
);

CHEAT_TEST(test_get_time_machine,
    for (int i = 1; i <= 5; i++) {
        // pass
    }
);

CHEAT_TEST(test_exterior_power,
    for (int i = 0; i <= 6; i++) {
        assert(exterior_power(i, 0xFF) == 2*i);
    }
);

CHEAT_TEST(test_interior_power,
    for (int i = 0; i <= 6; i++) {
        assert(interior_power(i, 0xFF) == 2*i);
    }
);

