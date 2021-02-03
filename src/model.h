/*
*   @title: IMS - Simulation project - Spreading COVID-19
*   @author: Daniel Kamenicky, xkamen21
*   @author: Ondrej Kondek, xkonde04
*   @file: model.h
*/

#ifndef MOD_MODULE
#define MOD_MODULE

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <cstddef>
#include "formula.h"
#include "visualization.h"
/*
 * Prints menu and select params for simulation.
 */
void menu();

/*
 * Simulation.
 */
bool start_simulation(double Vent_Rate, double Mask_eff, int Infected, int Hours);

/*
 * Calculates how many students are infected, healthy or recovered.
 */
void spreading(double s_infection,double p_infection, int day);

/*
 * Inicialization of structures.
 */
void class_init(int infected_count);
#endif
