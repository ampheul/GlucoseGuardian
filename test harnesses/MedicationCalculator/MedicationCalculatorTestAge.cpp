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

#include "MedicationCalculator.h"
#include "HormoneDose.h"
using namespace std;

void TestAge()
{	
	double prePubescent = 6;
	double postPubescent = 40;
	
	MedicationCalculator calcPre (39, 100, prePubescent, tm, "Low", 0, "Basal");
	MedicationCalculator calcPost (39, 100, postPubescent, tm, "Low", 0, "Basal");
	
	HormoneDose preDosage = calcPre.computeDosage();
	HormoneDose postDosage = calcPost.computeDosage();
	
	int preHormone = preDosage.getHormoneAmount();
	int postHormone = postDosage.getHormoneAmount();
		
	if (preHormone == postHormone)
	{
		cout << "Test Failed. The dosage should be different" << endl;
	}
}

int main()
{
	TestAge();
}
