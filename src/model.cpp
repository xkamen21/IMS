/*
*   @title: IMS - Simulation project - Spreading COVID-19
*   @author: Daniel Kamenicky, xkamen21
*   @author: Ondrej Kondek, xkonde04
*   @file: model.cpp
*/

#include "model.h"

Input_params params;

Person person[CLASSSIZE];
Statistics stats[30];
bool leaving_class = false;


int main(void) {
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    menu();
    endwin();

    return 0;
}

void menu(){
    double Vent_Rate;
    double Mask_eff;
    int Infected;
    int Hours;

    start_color();
    use_default_colors();
    init_pair(99, COLOR_GREEN, -1);

///////////////////////////////// COVID19 //////////////////////////////////////
    if(main_page()){
        return;
    }

///////////////////////////////// Infected /////////////////////////////////////
    Infected = menu_number_of_infected();
    if(Infected == -1){
        return;
    }

///////////////////////////////// Leaving class ////////////////////////////////
    int result = menu_leaving_class();
    if(result == -1){
        return;
    }
    else if(result == 1){
        leaving_class = false;
    }
    else{
        leaving_class = true;
    }


///////////////////////////////// Hours ////////////////////////////////////////
    Hours = menu_hours_per_day();
    if(Hours == -1){
        return;
    }

///////////////////////////////// Vent_Rate ////////////////////////////////////
    Vent_Rate = menu_vent_rate();
    if(Vent_Rate == -1){
        return;
    }

///////////////////////////////// Mask_eff /////////////////////////////////////
    Mask_eff = menu_mask_eff();
    if(Mask_eff == -1){
        return;
    }
////////////////////////////////////////////////////////////////////////////////

    nodelay(stdscr, TRUE);
    if(start_simulation(Vent_Rate, Mask_eff, Infected, Hours)){
        show_stats(stats);
    }
}

bool start_simulation(double Vent_Rate, double Mask_eff, int Infected, int Hours){
    bool skip = false;
    int days = 1;
    int c;

    params.hours = Hours;
    params.room_area = 60;
    params.room_height = 3;
    params.room_vent_rate = Vent_Rate;
    params.mask_eff = Mask_eff;
    params.person_infected = true;

    class_init(Infected);

    double ind_p_of_student_infection = individual_p_of_infection(params);
    params.person_infected = false;
    double ind_p_of_profesor_infection = individual_p_of_infection(params);

    while(days != 31){
        c = wgetch(stdscr);
        if(c==27) return false;
        if(c==115) skip = true;
        if(!skip || days == 30) print_simulation(person, days);
        spreading(ind_p_of_student_infection, ind_p_of_profesor_infection, days-1);
        if(!skip) usleep(500000);
        days++;
    }

    simulation_success();

    bool run = true;
    while (run) {
        switch (c = wgetch(stdscr)) {
            case 10:
                run = false;
                break;
            case 27:
                clear();
                return false;
            default:
                refresh();
                break;
        }
    }
    clear();
    return true;
}

void spreading(double s_infection, double p_infection, int day){
    int infected_count = 0;
    int recovered_count = 0;
    int recovering_at_home_count = 0;
    bool profesor_infected = false;
    for (size_t i = 0; i < CLASSSIZE; i++) {
        if(person[i].infected) {
            infected_count++;
            if(i==CLASSSIZE-1){
                profesor_infected = true;
            }
        }
        if(person[i].recovering_at_home) recovering_at_home_count++;
        if(person[i].recovered) recovered_count++;
    }
    for (size_t i = 0; i < CLASSSIZE; i++) {
        if(person[i].infected){
            if(person[i].days_infected == person[i].days_to_recover){
                person[i].infected = false;
                person[i].recovering_at_home = false;
                person[i].recovered = true;
            }
            else{
                if(person[i].days_infected == 2 && leaving_class){
                    if(i == CLASSSIZE-1){
                        person[i].infected = false;
                        person[i].days_infected = 0;
                        person[i].days_to_recover = 0;
                    }
                    else{
                        person[i].recovering_at_home = true;
                    }
                }
                person[i].days_infected++;
            }
        }
        else if(!person[i].recovered){
            if(profesor_infected){
                infected_count--;
                if((double)(rand()%100) <= ((s_infection*(infected_count-recovering_at_home_count))+p_infection)){
                    person[i].infected = true;
                    person[i].days_infected++;
                }
            }else{
                if((double)(rand()%100) < (s_infection*(infected_count-recovering_at_home_count))){
                    person[i].infected = true;
                    person[i].days_infected++;
                }
            }
        }
    }
    stats[day].infected = infected_count;
    stats[day].recovered = recovered_count;
    stats[day].healthy = 33-infected_count-recovered_count;
}

void class_init(int infected_count){
    //init stats
    for (size_t i = 0; i < 30; i++) {
        stats[i].infected = 0;
        stats[i].recovered = 0;
        stats[i].healthy = 0;
    }

    //init person
    srand((unsigned int)time(NULL));
    int infected_index;
    for (int i = 0; i < CLASSSIZE; i++) {
        person[i].infected = false;
        person[i].recovered = false;
        person[i].days_infected = 0;
        person[i].days_to_recover = (rand()%8)+8;
        person[i].recovering_at_home = false;
    }
    for (int i = 0; i < infected_count; i++) {
        infected_index = (rand()%CLASSSIZE);
        if(person[infected_index].infected){
            i--;
            continue;
        }
        else{
            person[infected_index].infected = true;
        }
    }
}
