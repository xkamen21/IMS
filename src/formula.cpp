/*
*   @title: IMS - Simulation project - Spreading COVID-19
*   @author: Daniel Kamenicky, xkamen21
*   @author: Ondrej Kondek, xkonde04
*   @file: formula.cpp
*/

#include "formula.h"

double infection_probability(){
    return (1.0 - pow(10.0, log10(0.5) / D50));
}

double rna_content_in_aerosol(){
    return (RESP_RNA_CONC * (PI/6.0) * pow(MEAN_AERO_DIAM / 10000.0 , 3));
}

double aerosol_emission(bool person_infected){
    double ratio = STUDENT_INFECT_RATIO;
    if (person_infected == false){
        ratio = TEACHER_INFECT_RATIO;
    }
    return ((BREATH * (1 - ratio) + SPEAK * ratio) * 1000 * RESP_RATE * 60.0);
}

double aerosol_concentration(int room_area, int room_height, bool person_infected){
    double aero_emission = aerosol_emission(person_infected);
    return (aero_emission/(room_area * room_height * 1000.0));
}

double rna_content_aerosol_concetration(double aero_concentration){
    double rna_cont = rna_content_in_aerosol();
    return (rna_cont * aero_concentration);
}

double rna_dosis(double rna_cont_aero_conc){
    return (RESP_RATE * 60 * rna_cont_aero_conc * DEPOSITION);
}

double hour_dosis(double rna_dos, double room_vent, double mask_eff){
    return (rna_dos / (room_vent + 1 / VIRUS_LIFETIME) * (1 - mask_eff));
}

double individual_p_of_infection(Input_params params){

    double infection_p = infection_probability();
    double aero_conc = aerosol_concentration(params.room_area, params.room_height, params.person_infected);
    double rna_cont_aero_conc = rna_content_aerosol_concetration(aero_conc);
    double rna_dos = rna_dosis(rna_cont_aero_conc);
    double dosis = hour_dosis(rna_dos, params.room_vent_rate, params.mask_eff);
    double ind_p_of_infection = (1 - pow(1 - infection_p, dosis*2*params.hours)) * 100;

    return ind_p_of_infection;
}
