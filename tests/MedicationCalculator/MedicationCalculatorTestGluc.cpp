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
#include <vector>


#include "main.h"
using namespace std;

bool TestPass_Meal(int meal)
{
	// Creates time of sleep
	string sleepTime = "12:12:12";
    struct tm tm;
    strptime(sleepTime.c_str(), "%H:%M:%S", &tm);
	
	MedicationCalculator calc (39, 10, 10, tm, "Low", meal, "Basal");
	
	HormoneDose hormone = calc.computeDosage();

	if (hormone.getHormoneAmount() > 0){
		return true;
	}
	
	return false;
}
	

bool TestPass_Hormone(int glucoseLevel)
{
	// Creates time of sleep
	string sleepTime = "12:12:12";
    struct tm tm;
    strptime(sleepTime.c_str(), "%H:%M:%S", &tm);
	
	MedicationCalculator calc (glucoseLevel, 10, 10, tm, "Low", 100000, "Basal");
	
	HormoneDose hormone = calc.computeDosage();

	if (hormone.getHormoneAmount() > 0){
		return true;
	}

	return false;
}

void TestSetupSuccess()
{
	vector<double> glucoseLevels = {3.9, 5.6, 6.9};
	bool result;
	
	for (auto& level : glucoseLevels)
	{
		result = TestPass_Hormone(level);
		if (!result)
		{
			cout << "Test failed on glucose level: " << level << endl;
		}
	}
}

void TestSetupFail()
{
	vector<double> glucoseLevels = {1.6, 41};
	bool result;
	
	for (auto& level : glucoseLevels)
	{
		result = TestPass_Hormone(level);
		if (result)
		{
			cout << "Test failed on glucose level: " << level << endl;
		}
	}
}




int main(){

	TestSetupSuccess();
	TestSetupFail();
}
