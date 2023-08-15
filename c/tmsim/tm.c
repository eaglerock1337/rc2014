#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "tm.h"

/***************************************
* TMSim - Time machine module
***************************************/

/* Rolls a part status with a 25% variance
*    Difficulty is on a 1-5 sliding scale:
*    Difficulty 1 = 75-100% per part
*    Difficulty 5 = 25-50% per part
*/
uint8_t roll_part(uint8_t difficulty) {
    uint8_t rando = rand() % 25;
    return rando + (6 - difficulty) * 15 + 31;
};

void roll_parts(uint8_t difficulty, struct time_machine_parts* parts) {
    for(int i = 0; i < 6; i++) {
        parts->exterior[i] = roll_part(difficulty);
        parts->interior[i] = roll_part(difficulty);
        parts->computer[i] = roll_part(difficulty);
    }
};

struct time_machine get_time_machine(uint8_t difficulty) {
    struct time_machine time;

    // stuff goes here.

    return time;
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
    case EXTERIOR:  return byte & EXT_READY;    break;
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
    case INTERIOR:  return byte & EXT_READY;    break;
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

void refresh_data(struct time_machine* tm) {
    // this doesn't work yet...bitwise or doesn't unset a set bit
    bool is_ready = (tm->ext_power & (EXT_READY - 1) == EXT_READY - 1);
    uint8_t set_byte = is_ready ? EXT_READY : 0;
    tm->ext_power = tm->ext_power | set_byte;
    is_ready = (tm->int_power & (INT_READY - 1) == INT_READY - 1);
    set_byte = is_ready ? INT_READY : 0;
    tm->int_power = tm->int_power | set_byte;
}