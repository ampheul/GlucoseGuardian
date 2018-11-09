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



class MedicationCalculator
{    
    public:
        MedicationCalculator(double glu, double weight, int age, struct tm sleep, std::string ex, double carb, std::string ins);
        ~MedicationCalculator();
		HormoneDose computeDosage();

    private:
        double gluRead;
        double weight;		
        double carbGrams;
        double TDD;
        int age;
        struct tm sleepStruct;
        std::string exLevel;
        std::string insType;

        void validateReading();
        double getGlucagon();
        double getHourBasal();
        double getBolus();
        double getTDD();
        double calcSleep(double basal);
        double calcEx(double basal);
        double calcMeal();
        double calcCorrection();
        int findCurrentHour();
};

#endif
