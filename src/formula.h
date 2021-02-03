/*
*   @title: IMS - Simulation project - Spreading COVID-19
*   @author: Daniel Kamenicky, xkamen21
*   @author: Ondrej Kondek, xkonde04
*   @file: formula.h
*/
#ifndef FORMULA_MODULE
#define FORMULA_MODULE

#include <iostream>
#include <cmath>
using namespace std;

/***
* Models input constants according to the article
* source: https://www.medrxiv.org/content/10.1101/2020.09.22.20199489v3.full-text
***/
#define D50 316                     /**< RNA for 50% infection probability */
#define DEPOSITION 0.5              /**< deposition probability */
#define BREATH 0.06                 /**< emission breathing [cm^3] */
#define SPEAK 0.6                   /**< emission speaking [cm^3] */
#define RESP_RATE 10                /**< respiratory rate [l/min] */
#define MEAN_AERO_DIAM 5            /**< mean wet aerosol diameter [um] */
#define VIRUS_LIFETIME 1.7          /**< virus lifetime in aerosol [h] */
#define RESP_RNA_CONC 500000000     /**< respiratory fluid RNA concentration [cm^3] */
#define STUDENT_INFECT_RATIO 0.1    /**< speaking/breathing ratio - student is infectious*/
#define TEACHER_INFECT_RATIO 0.9    /**< speaking/breathing ratio - teacher is infectious*/
#define PI 3.141592

typedef struct Input_params{
    double hours;
    double room_area;
    double room_height;
    double room_vent_rate;
    double mask_eff;
    bool person_infected;           /**< True == student, False == Teacher */
} Input_params;

/* 3.7. Infective dose D50 */
double infection_probability();


double rna_content_in_aerosol();


double aerosol_emission();


double aerosol_concentration(int room_area, int room_height);


double rna_dosis();


double individual_p_of_infection(Input_params params);
#endif
