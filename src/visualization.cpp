/*
*   @title: IMS - Simulation project - Spreading COVID-19
*   @author: Daniel Kamenicky, xkamen21
*   @author: Ondrej Kondek, xkonde04
*   @file: visualization.cpp
*/

#include "visualization.h"

bool main_page(){
    bool run = true;
    int c;

    while(run){

        mvprintw(2, 21, "                _     _       _  ___  ");
        mvprintw(3, 21, "  ___ _____   _(_) __| |     / |/ _ \\ ");
        mvprintw(4, 21, " / __/ _ \\ \\ / / |/ _` |_____| | (_) |");
        mvprintw(5, 21, "| (_| (_) \\ V /| | (_| |_____| |\\__, |");
        mvprintw(6, 21, " \\___\\___/ \\_/ |_|\\__,_|     |_|  /_/ ");
        mvaddch(8,21, ACS_ULCORNER);
        for (size_t i = 22; i < 58; i++) {
            mvaddch(10,i, ACS_HLINE);
            mvaddch(8,i, ACS_HLINE);
        }
        mvaddch(8,58, ACS_URCORNER);
        mvaddch(9,21, ACS_VLINE);
        mvaddch(9,58, ACS_VLINE);
        mvaddch(10,21, ACS_LLCORNER);
        mvaddch(10,58, ACS_LRCORNER);
        mvprintw(9, 25, "spreading around the classroom");

        //esc button
        mvaddch(15,16, ACS_ULCORNER);
        mvaddch(15,20, ACS_URCORNER);
        mvaddch(17,16, ACS_LLCORNER);
        mvaddch(17,20, ACS_LRCORNER);
        for (size_t i = 17; i < 20; i++) {
            mvaddch(15,i, ACS_HLINE);
            mvaddch(17,i, ACS_HLINE);
        }
        for (size_t i = 16; i < 17; i++) {
            mvaddch(i,16, ACS_VLINE);
            mvaddch(i,20, ACS_VLINE);
        }
        mvprintw(16, 17, "esc");

        //enter button
        mvaddch(14,58, ACS_ULCORNER);
        mvaddch(14,65, ACS_URCORNER);
        mvaddch(16,58, ACS_LLCORNER);
        mvaddch(16,61, ACS_URCORNER);
        mvaddch(18,61, ACS_LLCORNER);
        mvaddch(18,65, ACS_LRCORNER);

        for (size_t i = 59; i < 65; i++) {
            mvaddch(14,i, ACS_HLINE);
        }
        for (size_t i = 59; i < 61; i++) {
            mvaddch(16,i, ACS_HLINE);
        }
        for (size_t i = 62; i < 65; i++) {
            mvaddch(18,i, ACS_HLINE);
        }
        for (size_t i = 15; i < 16; i++) {
            mvaddch(i,58, ACS_VLINE);
        }
        for (size_t i = 15; i < 18; i++) {
            mvaddch(i,65, ACS_VLINE);
        }
        mvaddch(17,61, ACS_VLINE);

        mvprintw(15, 59, "enter");

        mvprintw(23,0,"By: Ondrej Kondek & Daniel Kamenicky");

        print_border();

        switch (c = wgetch(stdscr)) {
            case 10:
                clear();
                run=false;
                break;
            case 27:
                clear();
                return true;
            default:
                mvprintw(21,14,"Choose between 'enter' for continue and 'esc' for quit");
                refresh();
                break;
        }
    }
    return false;
}

int menu_number_of_infected(){
    bool run = true;
    int number = 0;
    int c;
    while(run){
        mvprintw(2, 27, " __  __ _____ _   _ _   _ ");
        mvprintw(3, 27, "|  \\/  | ____| \\ | | | | |");
        mvprintw(4, 27, "| |\\/| |  _| |  \\| | | | |");
        mvprintw(5, 27, "| |  | | |___| |\\  | |_| |");
        mvprintw(6, 27, "|_|  |_|_____|_| \\_|\\___/ ");

        //esc button
        mvaddch(1,1, ACS_ULCORNER);
        mvaddch(1,5, ACS_URCORNER);
        mvaddch(3,1, ACS_LLCORNER);
        mvaddch(3,5, ACS_LRCORNER);
        for (size_t i = 2; i < 5; i++) {
            mvaddch(1,i, ACS_HLINE);
            mvaddch(3,i, ACS_HLINE);
        }
        for (size_t i = 2; i < 3; i++) {
            mvaddch(i,1, ACS_VLINE);
            mvaddch(i,5, ACS_VLINE);
        }
        mvprintw(2, 2, "esc");

        mvprintw(9, 20, "Set number of infected persons in the classroom:");
        mvprintw(11, 26, "Write number between <1, 33>");
        mvprintw(13, 38, "%d", number);

        if(number>100){
            mvprintw(13, 38, "0  ");
            mvprintw(21,18,"  Your number is over 100, write it again.  ");
            number = 0;
            refresh();
        }

        print_border();

        switch (c = wgetch(stdscr)) {
            case 10:
                if(number<1 || number>33){
                    mvprintw(13, 38, "0  ");
                    mvprintw(21,18,"You have to wirte the number between <1, 33>");
                    number = 0;
                    refresh();
                }
                else{
                    run=false;
                    clear();
                    return number;
                }
                break;
            case 48:
                number = number*10+0;
                break;
            case 49:
                number = number*10+1;
                break;
            case 50:
                number = number*10+2;
                break;
            case 51:
                number = number*10+3;
                break;
            case 52:
                number = number*10+4;
                break;
            case 53:
                number = number*10+5;
                break;
            case 54:
                number = number*10+6;
                break;
            case 55:
                number = number*10+7;
                break;
            case 56:
                number = number*10+8;
                break;
            case 57:
                number = number*10+9;
                break;
            case 27:
                clear();
                return -1;
            default:
                mvprintw(21,18,"        Use numbers to write a number       ");
                refresh();
                break;
        }
    }
    return -1;
}

int menu_leaving_class(){
    bool run = true;
    int c;
    while(run){

        mvprintw(2, 27, " __  __ _____ _   _ _   _ ");
        mvprintw(3, 27, "|  \\/  | ____| \\ | | | | |");
        mvprintw(4, 27, "| |\\/| |  _| |  \\| | | | |");
        mvprintw(5, 27, "| |  | | |___| |\\  | |_| |");
        mvprintw(6, 27, "|_|  |_|_____|_| \\_|\\___/ ");

        //esc button
        mvaddch(1,1, ACS_ULCORNER);
        mvaddch(1,5, ACS_URCORNER);
        mvaddch(3,1, ACS_LLCORNER);
        mvaddch(3,5, ACS_LRCORNER);
        for (size_t i = 2; i < 5; i++) {
            mvaddch(1,i, ACS_HLINE);
            mvaddch(3,i, ACS_HLINE);
        }
        for (size_t i = 2; i < 3; i++) {
            mvaddch(i,1, ACS_VLINE);
            mvaddch(i,5, ACS_VLINE);
        }
        mvprintw(2, 2, "esc");

        mvprintw(10, 13, "Choose if student leaves the class after getting infected:");
        mvprintw(14, 28, "1. Yes");
        mvprintw(14, 47, "2. No");

        print_border();

        switch (c = wgetch(stdscr)) {
            case 49:
                run=false;
                attron(COLOR_PAIR(99));
                mvprintw(14, 28, "1. Yes");
                attroff(COLOR_PAIR(99));
                refresh();
                usleep(300000);
                clear();
                return 0;
            case 50:
                run=false;
                attron(COLOR_PAIR(99));
                mvprintw(14, 47, "2. No");
                attroff(COLOR_PAIR(99));
                refresh();
                usleep(300000);
                clear();
                return 1;
            case 27:
                clear();
                return -1;
            default:
                mvprintw(21,14,"Press 1 or 2 to choose parameter or 'esc' for quit");
                refresh();
                break;
        }
    }
    return -1;
}

int menu_hours_per_day(){
    bool run = true;
    int number = 0;
    int c;
    while(run){
        mvprintw(2, 27, " __  __ _____ _   _ _   _ ");
        mvprintw(3, 27, "|  \\/  | ____| \\ | | | | |");
        mvprintw(4, 27, "| |\\/| |  _| |  \\| | | | |");
        mvprintw(5, 27, "| |  | | |___| |\\  | |_| |");
        mvprintw(6, 27, "|_|  |_|_____|_| \\_|\\___/ ");

        //esc button
        mvaddch(1,1, ACS_ULCORNER);
        mvaddch(1,5, ACS_URCORNER);
        mvaddch(3,1, ACS_LLCORNER);
        mvaddch(3,5, ACS_LRCORNER);
        for (size_t i = 2; i < 5; i++) {
            mvaddch(1,i, ACS_HLINE);
            mvaddch(3,i, ACS_HLINE);
        }
        for (size_t i = 2; i < 3; i++) {
            mvaddch(i,1, ACS_VLINE);
            mvaddch(i,5, ACS_VLINE);
        }
        mvprintw(2, 2, "esc");

        mvprintw(9, 14, "Choose number of hours spent in classrooms per day:");
        mvprintw(11, 26, "Write number between <1, 9>");
        mvprintw(13, 38, "%d", number);

        if(number>9){
            mvprintw(13, 38, "0  ");
            mvprintw(21,18,"   Your number is over 9, write it again.   ");
            number = 0;
            refresh();
        }

        print_border();

        switch (c = wgetch(stdscr)) {
            case 10:
                if(number<1 || number>33){
                    mvprintw(13, 38, "0  ");
                    mvprintw(21,18,"You have to wirte the number between <1, 33>");
                    number = 0;
                    refresh();
                }
                else{
                    run=false;
                    clear();
                    return number;
                }
                break;
            case 48:
                number = number*10+0;
                break;
            case 49:
                number = number*10+1;
                break;
            case 50:
                number = number*10+2;
                break;
            case 51:
                number = number*10+3;
                break;
            case 52:
                number = number*10+4;
                break;
            case 53:
                number = number*10+5;
                break;
            case 54:
                number = number*10+6;
                break;
            case 55:
                number = number*10+7;
                break;
            case 56:
                number = number*10+8;
                break;
            case 57:
                number = number*10+9;
                break;
            case 27:
                clear();
                return -1;
            default:
                mvprintw(21,18,"        Use numbers to write a number       ");
                refresh();
                break;
        }
    }
    return -1;
}

double menu_vent_rate(){
    bool run = true;
    int c;
    while(run){

        mvprintw(2, 27, " __  __ _____ _   _ _   _ ");
        mvprintw(3, 27, "|  \\/  | ____| \\ | | | | |");
        mvprintw(4, 27, "| |\\/| |  _| |  \\| | | | |");
        mvprintw(5, 27, "| |  | | |___| |\\  | |_| |");
        mvprintw(6, 27, "|_|  |_|_____|_| \\_|\\___/ ");

        //esc button
        mvaddch(1,1, ACS_ULCORNER);
        mvaddch(1,5, ACS_URCORNER);
        mvaddch(3,1, ACS_LLCORNER);
        mvaddch(3,5, ACS_LRCORNER);
        for (size_t i = 2; i < 5; i++) {
            mvaddch(1,i, ACS_HLINE);
            mvaddch(3,i, ACS_HLINE);
        }
        for (size_t i = 2; i < 3; i++) {
            mvaddch(i,1, ACS_VLINE);
            mvaddch(i,5, ACS_VLINE);
        }
        mvprintw(2, 2, "esc");

        mvprintw(10, 22, "Set type of ventilation in the class:");
        mvprintw(12, 25, "1. No external ventilation");
        mvprintw(14, 25, "2. Advanced ventilation");
        mvprintw(16, 25, "3. Open Air");

        print_border();

        switch (c = wgetch(stdscr)) {
            case 49:
                run=false;
                attron(COLOR_PAIR(99));
                mvprintw(12, 25, "1. No external ventilation");
                attroff(COLOR_PAIR(99));
                refresh();
                usleep(300000);
                clear();
                return 0.35;
            case 50:
                run=false;
                attron(COLOR_PAIR(99));
                mvprintw(14, 25, "2. Advanced ventilation");
                attroff(COLOR_PAIR(99));
                refresh();
                usleep(300000);
                clear();
                return 2;
            case 51:
                run=false;
                attron(COLOR_PAIR(99));
                mvprintw(16, 25, "3. Open Air");
                attroff(COLOR_PAIR(99));
                refresh();
                usleep(300000);
                clear();
                return 9;
            case 27:
                clear();
                return -1;
            default:
                mvprintw(21,14,"Press 1 or 2 or 3 to choose parametr or 'esc' for quit");
                refresh();
                break;
        }
    }
    return -1;
}

double menu_mask_eff(){
    bool run = true;
    int c;
    while(run){

        mvprintw(2, 27, " __  __ _____ _   _ _   _ ");
        mvprintw(3, 27, "|  \\/  | ____| \\ | | | | |");
        mvprintw(4, 27, "| |\\/| |  _| |  \\| | | | |");
        mvprintw(5, 27, "| |  | | |___| |\\  | |_| |");
        mvprintw(6, 27, "|_|  |_|_____|_| \\_|\\___/ ");

        //esc button
        mvaddch(1,1, ACS_ULCORNER);
        mvaddch(1,5, ACS_URCORNER);
        mvaddch(3,1, ACS_LLCORNER);
        mvaddch(3,5, ACS_LRCORNER);
        for (size_t i = 2; i < 5; i++) {
            mvaddch(1,i, ACS_HLINE);
            mvaddch(3,i, ACS_HLINE);
        }
        for (size_t i = 2; i < 3; i++) {
            mvaddch(i,1, ACS_VLINE);
            mvaddch(i,5, ACS_VLINE);
        }
        mvprintw(2, 2, "esc");

        mvprintw(10, 30, "Set type of Mask:");
        mvprintw(12, 33, "1. Without Mask");
        mvprintw(14, 33, "2. Cloth Mask");
        mvprintw(16, 33, "3. Respirator");

        print_border();

        switch (c = wgetch(stdscr)) {
            case 49:
                run=false;
                attron(COLOR_PAIR(99));
                mvprintw(12, 33, "1. Without Mask");
                attroff(COLOR_PAIR(99));
                refresh();
                usleep(300000);
                clear();
                return 0;
            case 50:
                run=false;
                attron(COLOR_PAIR(99));
                mvprintw(14, 33, "2. Cloth Mask");
                attroff(COLOR_PAIR(99));
                refresh();
                usleep(300000);
                clear();
                return 0.7;
            case 51:
                run=false;
                attron(COLOR_PAIR(99));
                mvprintw(16, 33, "3. Respirator");
                attroff(COLOR_PAIR(99));
                refresh();
                usleep(300000);
                clear();
                return 0.95;
            case 27:
                clear();
                return -1;
            default:
                mvprintw(21,14,"Press 1 or 2 or 3 to choose parametr or 'esc' for quit");
                refresh();
                break;
        }
    }
    return -1;
}

void print_simulation(Person person[CLASSSIZE], int days){
    int index_of_student;

    start_color();
    use_default_colors();
    init_pair(DEFAULT, COLOR_WHITE, -1);
    init_pair(HEALTHY, COLOR_GREEN, -1);
    init_pair(INFECTED, COLOR_RED, -1);
    init_pair(RECOVERED, COLOR_BLUE, -1);

    clear();
    index_of_student = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if((j%20 == 0 && i%4 == 0 && i<16) || (j%60 == 0 && i%4 == 0 && j!=0 && i<20)){
                mvaddch(i,j, ACS_ULCORNER);
                j++;
                int tmp = j;
                for (; j < tmp+13; j++) {
                    mvaddch(i,j, ACS_HLINE);
                }
                mvaddch(i,j, ACS_URCORNER);
            }
            else if(j%20 == 0 && i%4 == 1 && i<16){
                mvaddch(i,j, ACS_VLINE);
                j++;
                int tmp = j;
                if(!person[index_of_student].recovering_at_home){
                    attron(COLOR_PAIR(type_of_color(index_of_student, person)));
                    for (; j < tmp+6; j++) {
                        if(j%20==2)
                            mvaddch(i,j, ACS_ULCORNER);
                        if(j%20==3)
                            mvaddch(i,j, ACS_HLINE);
                        if(j%20==4){
                            mvaddch(i,j, ACS_URCORNER);
                            attroff(COLOR_PAIR(type_of_color(index_of_student, person)));
                            index_of_student++;
                        }
                    }
                }
                else{
                    index_of_student++;
                    j=j+6;
                }
                if(!person[index_of_student].recovering_at_home){
                    attron(COLOR_PAIR(type_of_color(index_of_student, person)));
                    for (; j < tmp+13; j++) {
                        if(j%20==10)
                            mvaddch(i,j, ACS_ULCORNER);
                        if(j%20==11)
                            mvaddch(i,j, ACS_HLINE);
                        if(j%20==12){
                            mvaddch(i,j, ACS_URCORNER);
                            attroff(COLOR_PAIR(type_of_color(index_of_student, person)));
                            index_of_student++;
                        }
                    }
                }
                else{
                    index_of_student++;
                    j=j+7;
                }
                mvaddch(i,j, ACS_VLINE);
            }
            else if(j%20 == 0 && i%4 == 2 && i<16){
                if(index_of_student%8==0) index_of_student-=8;
                mvaddch(i,j, ACS_VLINE);
                j++;
                int tmp = j;
                if(!person[index_of_student].recovering_at_home){
                    attron(COLOR_PAIR(type_of_color(index_of_student, person)));
                    for (; j < tmp+6; j++) {
                        if(j%20==2)
                            mvaddch(i,j, ACS_LLCORNER);
                        if(j%20==3)
                            mvaddch(i,j, ACS_HLINE);
                        if(j%20==4){
                            mvaddch(i,j, ACS_LRCORNER);
                            attroff(COLOR_PAIR(type_of_color(index_of_student, person)));
                            index_of_student++;
                        }
                    }
                }
                else{
                    index_of_student++;
                    j=j+6;
                }
                if(!person[index_of_student].recovering_at_home){
                    attron(COLOR_PAIR(type_of_color(index_of_student, person)));
                    for (; j < tmp+13; j++) {
                        if(j%20==10)
                            mvaddch(i,j, ACS_LLCORNER);
                        if(j%20==11)
                            mvaddch(i,j, ACS_HLINE);
                        if(j%20==12){
                            mvaddch(i,j, ACS_LRCORNER);
                            attroff(COLOR_PAIR(type_of_color(index_of_student, person)));
                            index_of_student++;
                        }
                    }
                }
                else{
                    index_of_student++;
                    j=j+7;
                }
                mvaddch(i,j, ACS_VLINE);
            }
            else if((j%20 == 0 && i%4 == 3 && i<16) || (j%60 == 0 && i%4 == 3 && j!=0 && i<20)){
                mvaddch(i,j, ACS_LLCORNER);
                j++;
                int tmp = j;
                for (; j < tmp+13; j++) {
                    mvaddch(i,j, ACS_HLINE);
                }
                mvaddch(i,j, ACS_LRCORNER);
            }
            else if(j%60 == 0 && i%4 == 1 && j!=0 && i<20){
                mvaddch(i,j, ACS_VLINE);
                j++;
                int tmp = j;
                attron(COLOR_PAIR(type_of_color(index_of_student, person)));
                for (; j < tmp+13; j++) {
                    if(j%60==6)
                        mvaddch(i,j, ACS_ULCORNER);
                    if(j%60==7)
                        mvaddch(i,j, ACS_HLINE);
                    if(j%60==8){
                        mvaddch(i,j, ACS_URCORNER);
                    }
                }
                attroff(COLOR_PAIR(type_of_color(index_of_student, person)));
                mvaddch(i,j, ACS_VLINE);
            }
            else if(j%60 == 0 && i%4 == 2 && j!=0 && i<20){
                mvaddch(i,j, ACS_VLINE);
                j++;
                int tmp = j;
                attron(COLOR_PAIR(type_of_color(index_of_student, person)));
                for (; j < tmp+13; j++) {
                    if(j%60==6)
                        mvaddch(i,j, ACS_LLCORNER);
                    if(j%60==7)
                        mvaddch(i,j, ACS_HLINE);
                    if(j%60==8){
                        mvaddch(i,j, ACS_LRCORNER);
                    }
                }
                attroff(COLOR_PAIR(type_of_color(index_of_student, person)));
                mvaddch(i,j, ACS_VLINE);
            }
        }
    }

    mvprintw(ROWS, 2, "Days: %d", days);
    mvprintw(ROWS+1, 2, "Press 'esc' to quit or 's' to skip.");
    attron(COLOR_PAIR(HEALTHY));
    mvprintw(ROWS+1, 49, "HEALTHY");
    attroff(COLOR_PAIR(HEALTHY));
    attron(COLOR_PAIR(INFECTED));
    mvprintw(ROWS+1, 58, "INFECTED");
    attroff(COLOR_PAIR(INFECTED));
    attron(COLOR_PAIR(RECOVERED));
    mvprintw(ROWS+1, 68, "RECOVERED");
    attroff(COLOR_PAIR(RECOVERED));

    print_border();

    refresh();
}

void show_stats(Statistics stats[30]){
    clear();
    refresh();
    nodelay(stdscr, FALSE);
    bool run = true;
    int c;

    start_color();
    use_default_colors();
    init_pair(HEALTHY, COLOR_GREEN, -1);
    init_pair(INFECTED, COLOR_RED, -1);
    init_pair(RECOVERED, COLOR_BLUE, -1);

    while(run){

        mvprintw(0, 20, " ____  _        _   _     _   _          ");
        mvprintw(1, 20, "/ ___|| |_ __ _| |_(_)___| |_(_) ___ ___ ");
        mvprintw(2, 20, "\\___ \\| __/ _` | __| / __| __| |/ __/ __|");
        mvprintw(3, 20, " ___) | || (_| | |_| \\__ \\ |_| | (__\\__ \\");
        mvprintw(4, 20, "|____/ \\__\\__,_|\\__|_|___/\\__|_|\\___|___/");

        //esc button
        mvaddch(1,1, ACS_ULCORNER);
        mvaddch(1,5, ACS_URCORNER);
        mvaddch(3,1, ACS_LLCORNER);
        mvaddch(3,5, ACS_LRCORNER);
        for (size_t i = 2; i < 5; i++) {
            mvaddch(1,i, ACS_HLINE);
            mvaddch(3,i, ACS_HLINE);
        }
        for (size_t i = 2; i < 3; i++) {
            mvaddch(i,1, ACS_VLINE);
            mvaddch(i,5, ACS_VLINE);
        }
        mvprintw(2, 2, "esc");

        mvprintw(6, 2, "DAY   HEALTHY   INFECTED   RECOVERED    DAY   HEALTHY   INFECTED   RECOVERED");
        for (size_t i = 6; i < 23; i++) {
            if(i==7){
                mvaddch(i, 6, ACS_PLUS);
                mvaddch(i, 16, ACS_PLUS);
                mvaddch(i, 27, ACS_PLUS);
                mvaddch(i, 39, ACS_PLUS);
                mvaddch(i, 40, ACS_PLUS);
                mvaddch(i, 46, ACS_PLUS);
                mvaddch(i, 56, ACS_PLUS);
                mvaddch(i, 67, ACS_PLUS);
            }
            else{
                mvaddch(i, 6, ACS_VLINE);
                mvaddch(i, 16, ACS_VLINE);
                mvaddch(i, 27, ACS_VLINE);
                mvaddch(i, 39, ACS_VLINE);
                mvaddch(i, 40, ACS_VLINE);
                mvaddch(i, 46, ACS_VLINE);
                mvaddch(i, 56, ACS_VLINE);
                mvaddch(i, 67, ACS_VLINE);
            }
        }
        for (size_t i = 2; i < 79; i++) {
            if(i!=6 && i!=16 && i!=27 && i!=39 && i!=40 && i!=46 && i!=56 && i!=67){
                mvaddch(7, i, ACS_HLINE);
                mvaddch(7, i, ACS_HLINE);
                mvaddch(7, i, ACS_HLINE);
                mvaddch(7, i, ACS_HLINE);
                mvaddch(7, i, ACS_HLINE);
                mvaddch(7, i, ACS_HLINE);
                mvaddch(7, i, ACS_HLINE);
                mvaddch(7, i, ACS_HLINE);
            }
        }
        for (size_t i = 1; i < 16; i++) {
            mvaddch(i+7, 2, (i/10)+48);
            mvaddch(i+7, 3, (i%10)+48);
            mvaddch(i+7, 4, '.');
            mvaddch(i+7, 42, ((i+15)/10)+48);
            mvaddch(i+7, 43, ((i+15)%10)+48);
            mvaddch(i+7, 44, '.');
        }
        for (size_t i = 0; i < 15; i++) {
            mvaddch(i+8, 11, (stats[i].healthy/10)+48);
            mvaddch(i+8, 12, (stats[i].healthy%10)+48);
            mvaddch(i+8, 51, (stats[i+15].healthy/10)+48);
            mvaddch(i+8, 52, (stats[i+15].healthy%10)+48);

            mvaddch(i+8, 21, (stats[i].infected/10)+48);
            mvaddch(i+8, 22, (stats[i].infected%10)+48);
            mvaddch(i+8, 61, (stats[i+15].infected/10)+48);
            mvaddch(i+8, 62, (stats[i+15].infected%10)+48);

            mvaddch(i+8, 33, (stats[i].recovered/10)+48);
            mvaddch(i+8, 34, (stats[i].recovered%10)+48);
            mvaddch(i+8, 73, (stats[i+15].recovered/10)+48);
            mvaddch(i+8, 74, (stats[i+15].recovered%10)+48);
        }

        print_border();

        switch (c = wgetch(stdscr)) {
            case 10:
                clear();
                return;
            case 27:
                clear();
                return;
            default:
                mvprintw(23, 2, "Press 'enter' or 'esc' for finish the simulation");
                refresh();
                break;
        }
    }

}

void simulation_success(){
    mvprintw(ROWS, 2, "        ");
    mvprintw(ROWS+1, 2, "                                    ");
    mvprintw(18, 15, "Simulation:");
    attron(COLOR_PAIR(HEALTHY));
    mvprintw(18, 27, "SUCCESSFUL");
    attroff(COLOR_PAIR(HEALTHY));
    mvprintw(20, 8, "Continue to stats by pressing 'enter'");
}

int type_of_color(int index, Person person[CLASSSIZE]){
    if(person[index].infected){
        return INFECTED;
    }
    else{
        return (person[index].recovered)?RECOVERED:HEALTHY;
    }
}

void print_border(){
    for (size_t i = 0; i < 81; i++) {
        mvaddch(24, i, ACS_HLINE);
    }
    for (size_t i = 0; i < 24; i++) {
        mvaddch(i, 81, ACS_VLINE);
    }
    mvaddch(24,81, ACS_LRCORNER);
}
