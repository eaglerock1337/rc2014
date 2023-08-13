#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/***************************************
* TMSim - Time machine module
***************************************/

#define OFF     0
#define ON      1
#define FAULT   2

struct time_machine_parts {
    uint8_t airlock;
    uint8_t invis_shield;
    uint8_t hover_prop;
    uint8_t tesla_coil;
    uint8_t mr_fusion;
    uint8_t generator;

    uint8_t energy_cells;
    uint8_t power_dist;
    uint8_t life_support;
    uint8_t time_circuits;
    uint8_t sensor_system;
    uint8_t system_console;

    uint8_t motherboard;
    uint8_t processor;
    uint8_t memory;
    uint8_t storage;
    uint8_t power_supply;
    uint8_t tm_interface;
};

struct time_machine_status {
    uint8_t airlock;
    uint8_t invis_shield;
    uint8_t hover_prop;
    uint8_t tesla_coil;
    uint8_t mr_fusion;
    uint8_t generator;

    uint8_t energy_cells;
    uint8_t power_dist;
    uint8_t life_support;
    uint8_t time_circuits;
    uint8_t sensor_system;
    uint8_t system_console;

    uint8_t computer;
};

struct time_machine {
    struct time_machine_parts parts;
    struct time_machine_status status;

    uint32_t energy;
};
