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

void TestAge()
{	
	double prePubescent = 7;
	double postPubescent = 40;

	string sleepTime = "12:12:12";
    struct tm tm;
    strptime(sleepTime.c_str(), "%H:%M:%S", &tm);
	
	MedicationCalculator calcPre (8, 100, prePubescent, tm, "None", 10, "Bolus");
	MedicationCalculator calcPost (8, 100, postPubescent, tm, "None", 10, "Bolus");
	
	HormoneDose preDosage = calcPre.computeDosage();
	HormoneDose postDosage = calcPost.computeDosage();
	
	double preHormone = preDosage.getHormoneAmount();
	double postHormone = postDosage.getHormoneAmount();
		
	if (preHormone == postHormone)
	{
		cout << "Test Failed. The dosage should be different" << endl;
	}
}

int main()
{
	TestAge();
}
