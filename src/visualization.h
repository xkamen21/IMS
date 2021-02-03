/*
*   @title: IMS - Simulation project - Spreading COVID-19
*   @author: Daniel Kamenicky, xkamen21
*   @author: Ondrej Kondek, xkonde04
*   @file: visualization.h
*/
#ifndef VIS_MODULE
#define VIS_MODULE

#include <cstddef>
#include <ncurses.h>
#include <unistd.h>

#define ROWS 21
#define COLS 80
#define CLASSSIZE 33

// color type
#define DEFAULT 0
#define HEALTHY 1
#define INFECTED 2
#define RECOVERED 3

struct Person{
    bool infected = false;
    bool recovered = false;
    int days_infected = 0;
    int days_to_recover = 0;
    bool recovering_at_home = false;
};

struct Statistics{
    int infected = 0;
    int recovered = 0;
    int healthy = 0;
};

bool main_page();


int menu_number_of_infected();


int menu_leaving_class();


int menu_hours_per_day();


double menu_vent_rate();


double menu_mask_eff();


void print_simulation(Person person[CLASSSIZE], int days);


void simulation_success();


void show_stats(Statistics stats[30]);


int type_of_color(int index, Person person[CLASSSIZE]);


void print_border();
#endif
