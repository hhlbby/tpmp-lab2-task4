#ifndef BUILDINGS_H
#define BUILDINGS_H

#define MAX_ADDRESS_LEN 100
#define MAX_TYPE_LEN 50
#define CAPITAL_REPAIR_PERIOD 25

typedef struct {
    char address[MAX_ADDRESS_LEN];
    char type[MAX_TYPE_LEN];
    int floors;
    int apartments;
    int service_life;
    int years_to_repair;
} Building;


void create_initial_file(const char *filename);
void view_file(const char *filename);
