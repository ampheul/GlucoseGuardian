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
	

void TestMeal()
{
	double neg = 1;
	double small = 25;
	double medium = 50;
	double large = 70;

	string sleepTime = "12:12:12";
    struct tm tm;
    strptime(sleepTime.c_str(), "%H:%M:%S", &tm);
	
	MedicationCalculator calcNeg (8, 100, 20, tm, "None", neg, "Bolus");
	MedicationCalculator calcSmall (8, 100, 20, tm, "None", small, "Bolus");
	MedicationCalculator calcMedium (8, 100, 20, tm, "None", medium, "Bolus");
	MedicationCalculator calcLarge (8, 100, 20, tm, "None", large, "Bolus");

	
	HormoneDose negDosage = calcNeg.computeDosage();
	HormoneDose smallDosage = calcSmall.computeDosage();
	HormoneDose mediumDosage = calcMedium.computeDosage();
	HormoneDose largeDosage = calcLarge.computeDosage();

	double negHormone = negDosage.getHormoneAmount();
	double smallHormone = smallDosage.getHormoneAmount();
	double mediumHormone = mediumDosage.getHormoneAmount();
	double largeHormone = largeDosage.getHormoneAmount();	
	
	if (negHormone == smallHormone || negHormone == mediumHormone || negHormone == largeHormone)
	{
		cout << "Test Failed. The dosage should be different" << endl;
	}

}


int main(){

	TestMeal();
}
