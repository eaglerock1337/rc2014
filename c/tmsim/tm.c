#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "tm.h"

/***************************************
* TMSim - Time machine module
***************************************/

/* Rolls a part status with a 25% variance
*    Difficulty is on a 1-5 sliding scale:
*    Difficulty 1 = 0-25% per part
*    Difficulty 5 = 40-65% per part
*/
uint8_t roll_part(uint8_t difficulty) {
    uint8_t rando = rand() % 25;
    return rando + (difficulty - 1) * 10;
};

void roll_parts(uint8_t difficulty, struct time_machine_parts* parts) {
    for (int i = 0; i < 6; i++) {
        parts->exterior[i].wear = roll_part(difficulty);
        parts->exterior[i].tear = roll_part(difficulty);
        parts->interior[i].wear = roll_part(difficulty);
        parts->interior[i].tear = roll_part(difficulty);
        parts->computer[i].wear = roll_part(difficulty);
        parts->computer[i].tear = roll_part(difficulty);
    }
};

struct time_machine get_time_machine(uint8_t difficulty) {
    struct time_machine tm;

    roll_parts(difficulty, &tm.parts);
    tm.ext_power = 1;   // all on
    tm.int_power = 1;   // all on
    tm.energy = rand() % 250 + difficulty * 1000 - 250;

    return tm;
};

// get bitwise power status of an exterior part by ID
bool exterior_power(uint8_t part, uint8_t byte) {
    switch (part) {
    case AIRLOCK:   return byte & AIRLOCK_ON;   break;
    case SHIELD:    return byte & SHIELD_ON;    break;
    case HOVER:     return byte & HOVER_ON;     break;
    case TESLA:     return byte & TESLA_ON;     break;
    case FUSION:    return byte & FUSION_ON;    break;
    case STEAM:     return byte & STEAM_ON;     break;
    case IS_READY:  return byte & ALL_READY;    break;
    case PC_CHECK:  return byte & PC_READY;     break;
    default:        return 0;   // do error stuff later
    }
};

// get bitwise power status of an interior part by ID
bool interior_power(uint8_t part, uint8_t byte) {
    switch (part) {
    case RC2014:    return byte & RC2014;       break;
    case POWER:     return byte & SHIELD_ON;    break;
    case SUPPORT:   return byte & HOVER_ON;     break;
    case CIRCUITS:  return byte & TESLA_ON;     break;
    case SENSORS:   return byte & FUSION_ON;    break;
    case CONSOLE:   return byte & STEAM_ON;     break;
    case IS_READY:  return byte & ALL_READY;    break;
    case PC_CHECK:  return byte & PC_READY;     break;
    default:        return 0;   // do error stuff later
    }
};

char* get_exterior_part(uint8_t part) {
    switch (part) {
    case 0:     return "Time Machine Airlock";  break;
    case 1:     return "Insibility Shield";     break;
    case 2:     return "Hover Propulsion";      break;
    case 3:     return "Tesla Charging Coil";   break;
    case 4:     return "Mr Fusion Reactor";     break;
    case 5:     return "Steam Charging Unit";   break;
    default:    return "Something went wrong";
    }
}

char* get_interior_part(uint8_t part) {
    switch (part) {
    case 0:     return "Main Energy Cells";     break;
    case 1:     return "Power Distrib. Unit";   break;
    case 2:     return "Life Support System";   break;
    case 3:     return "Time Travel Circuits";  break;
    case 4:     return "Threat Sensor System";  break;
    case 5:     return "Time Machine Console";  break;
    default:    return "Something went wrong";
    }
}

char* get_computer_part(uint8_t part) {
    switch (part) {
    case 0:     return "System Backplane";      break;
    case 1:     return "Dual System Clock";     break;
    case 2:     return "Z80 Processor Board";   break;
    case 3:     return "RAM/ROM Memory Unit";   break;
    case 4:     return "Dual Serial I/O";       break;
    case 5:     return "TM Hardware Bridge";    break;
    default:    return "Something went wrong";
    }
}

void set_bits(uint8_t* byte, uint8_t mask) {
    *byte = *byte | mask;
}

void unset_bits(uint8_t* byte, uint8_t mask) {
    *byte = *byte & ~mask;
}

void refresh_power_data(struct time_machine* tm) {
    // bitwise check if lower 6 exterior power bits are set
    if (tm->ext_power & (ALL_READY - 1) == ALL_READY - 1) {
        set_bits(&tm->ext_power, ALL_READY);
    } else {
        unset_bits(&tm->ext_power, ALL_READY);
    }
    // bitwise check if lower 6 interior power bits ar set
    if (tm->int_power & (ALL_READY - 1) == ALL_READY - 1) {
        set_bits(&tm->int_power, ALL_READY);
    } else {
        unset_bits(&tm->int_power, ALL_READY);
    }
}

struct time_machine_part* get_part(uint8_t id, uint8_t type, struct time_machine* tm) {
    struct time_machine_part* part;

    switch (type) {
    case EXTERIOR:  part = &tm->parts.exterior[id];     break;
    case INTERIOR:  part = &tm->parts.interior[id];     break;
    case COMPUTER:  part = &tm->parts.computer[id];     break;
    default:    printf("Something went wrong in get_part()\n");
    };
    return part;
}

void power_part(uint8_t id, uint8_t type, struct time_machine* tm) {
    switch (type) {
    case EXTERIOR:  set_bits(tm->ext_power, id);
    case INTERIOR:  set_bits(tm->int_power, id);
    case COMPUTER:  tm->computer = ON;
    default:    printf("Something went wrong in set_part()\n");
    };
}

void unpower_part(uint8_t id, uint8_t type, struct time_machine* tm) {
    switch (type) {
    case EXTERIOR:  unset_bits(tm->ext_power, id);
    case INTERIOR:  unset_bits(tm->int_power, id);
    case COMPUTER:  tm->computer = OFF;
    default:    printf("Something went wrong in unset_part()\n");    
    }
}

uint8_t get_condition(struct time_machine_part* part) {
    return (part->wear + part-> tear * 2) / 3;
}

void wear_part(struct time_machine_part* part) {
    part->wear += rand() % 5;
    tear_part(part);
}

void tear_part(struct time_machine_part* part) {
    part->tear += rand() % (5 * (part->wear / 20));
}

bool turn_on_part(uint8_t id, uint8_t type, struct time_machine* tm) {
    struct time_machine_part* part = get_part(id, type, tm);
    uint8_t cond = get_condition(part);
    uint8_t chance = 9/10 * cond + 5;
    if (rand() % 100 < chance) {
        set_part(id, type);
        return true;
    } else {
        return false;
    }
}
