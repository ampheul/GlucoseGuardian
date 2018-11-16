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

#include "MedicationCalculator.h"
#include "HormoneDose.h"

using namespace std;


bool TestPass_Exercise(string exerciseLevel)
{
	// Creates time of sleep
	string sleepTime = "12:12:12";
    struct tm tm;
    strptime(sleepTime.c_str(), "%H:%M:%S", &tm);
	
	MedicationCalculator calc (39, 100, 10, tm, exerciseLevel, 0, "Basal");
	HormoneDose hormone = calc.computeDosage();
	double amount = hormone.getHormoneAmount();
	
	if(amount == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void TestSetup()
{
	vector<string> exerciseLevel = {"Low", "Medium", "High", "None"};
	bool result;
	
	for (auto& level : exerciseLevel)
	{
		result = TestPass_Exercise(level);
		if (!result)
		{
			cout << "Test failed on exercise level: " << level << endl;
		}
	}
}

int main()
{
	TestSetup();
}
