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

/*
Function name: main

Description: tests medication calculator. 
Adminsters glucagon if patient is hypoglycemic. Administers basal or bolus insulin depending on what is needed.
Considers current glucose levels, patient weight, age, and exercise level into calcuations.
Patient can enter carb consumed or 0 if none. Patient can also enter sleep time or a sleep time of 11pm is assumed. 
Sleep time is compared to current time to administer insulin appropriately. 
PLEASE ASSUME INPUTS ARE IN CORRECT FORMAT AS THEY EVENTUALLY WILL BE TAKEN FROM OTHER CLASSES.


Parameters: none
*/

int main(){

	double glucose;
	double weight;
	double age;
	string sleepTime;
	string exerciseLevel;
	double carbs;
	string basalOrBolus;

	/* NOTE TO TA: 
	   Please assume inputs are in correct format. These would be checked by other classes
	*/

	cout << "Please enter a glucose level in mg/dL: ";
	cin >> glucose;
	
	cout << "Please enter a weight in lbs: ";
	cin >> weight;

	cout << "Please enter an age: ";
	cin >> age;

	cout << "Please enter intake of carbohydrates in grams or 0: ";
	cin >> carbs;

	cout << "Please enter a time of sleep in military time(hour:minute:seconds) or -1 for hour if not specified: ";
	getline(cin, sleepTime);
	getline(cin,sleepTime,'\n');

	cout << "Please enter an exercise level (Low/Medium/High/None): ";
	getline(cin, exerciseLevel);

	cout << "Please enter if a 'Basal' or 'Bolus' insulin dose is needed: ";
	getline(cin, basalOrBolus);

    // Creates time of sleep
    struct tm tm;
    strptime(sleepTime.c_str(), "%H:%M:%S", &tm);

    /* Make medication calculator
       Parameters are: (double glucoseReading, double weight, double age, double sleepTime, string exerciseLevel, double carbInGrams);
     */
     MedicationCalculator calc (glucose, weight, age, tm, exerciseLevel, carbs, basalOrBolus);

     // Compute Dosage to give
     HormoneDose hormone = calc.computeDosage();
     switch(hormone.getHormoneType()){
     	case 2:
     		cout << "----Administer glucagon----" << endl; 
     		break;
     	case 1:
     		cout << "----Administer bolus insulin----" << endl; 
     		break;
     	case 0:
     		cout << "----Administer basal insulin----" << endl; 
     		break;
     } 

     cout << "Units of hormone (100 units = 1 mL): " << hormone.getHormoneAmount() << endl;


     return 0;
}

void TestSetup()
{
	vector<double> glucoseLevels = [1.7, 3.9, 5.6, 6.9, 1.6];
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

bool TestPass_Hormone(int glucoseLevel)
{
	// Creates time of sleep
	string sleepTime = "12:12:12";
    struct tm tm;
    strptime(sleepTime.c_str(), "%H:%M:%S", &tm);
	
	MedicationCalculator calc (glucoseLevel, 100, 10, tm, "Low", 0, "Basal");
}
