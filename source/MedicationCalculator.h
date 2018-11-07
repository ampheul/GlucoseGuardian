/*
Author: Claire Dong
Date: Nov 5th, 2018
Description: header file for MedicationCalculator class
*/

#ifndef MEDICATIONCALCULATOR_H
#define MEDICATIONCALCULATOR_H
#include <iostream>
#include <sys/types.h>
#include <sstream>
#include <string.h>
#include <math.h>
#include <ctime>
#include <iomanip>
#include "HormoneDose.h"

// ??
// #include "Patient.h"
// #include "MonitorRecord.h"
// #include "Context.h"
// #include "HormoneDose.h"



class MedicationCalculator{
    
    public:
        //Constructor
        MedicationCalculator(double glu, double weight, int age, struct tm sleep, std::string ex, double carb);

        //Destructor
        ~MedicationCalculator();

       HormoneDose computeDosage();

    private:

        //Variables
        double gluRead;
        double weight;
        int age;
        struct tm sleepStruct;
        std::string exLevel;
        double carbGrams;
        double TDD;

        void validateReading();
        double getGlucagon();
        double getHourBasal();
        double getBolus();
        double calcSleep(double basal);
        double calcEx(double basal);
        double calcMeal();
        double calcCorrection();

        double getTDD();
        int findCurrentHour();
};

#endif