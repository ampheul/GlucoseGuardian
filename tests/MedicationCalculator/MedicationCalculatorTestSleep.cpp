/*
Author: Claire Dong
Date: Nov 5th, 2018
Description: tests medication calculator 
*/

#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <sstream>

#include "main.h"
using namespace std;

// Please test this at 10pm at night. 
// Insulin dosages are calculated based on the current time relative to when the user goes to bed.

void TestSleep()
{	

	// Case that the person goes to sleep at noon (10pm currently would be awake time)
	string sleepTime1 = "12:12:12";
    struct tm tm1;
    strptime(sleepTime1.c_str(), "%H:%M:%S", &tm1);

    // Case that the person goes to sleep at 9pm (10pm currently would be sleep time)
   	string sleepTime2 = "21:10:12";
    struct tm tm2;
    strptime(sleepTime2.c_str(), "%H:%M:%S", &tm2);
	
	MedicationCalculator calcDay (20, 100, 20, tm1, "None", 10, "Basal");
	MedicationCalculator calcNight (20, 100, 20, tm2, "None", 10, "Basal");
	
	HormoneDose dayDosage = calcDay.computeDosage();
	HormoneDose nightDosage = calcNight.computeDosage();
	
	double dayHormone = dayDosage.getHormoneAmount();
	double nightHormone = nightDosage.getHormoneAmount();
		
	if (dayHormone == nightHormone)
	{
		cout << "Test Failed. The dosage should be different" << endl;
	}
}

int main()
{
	TestSleep();
}
