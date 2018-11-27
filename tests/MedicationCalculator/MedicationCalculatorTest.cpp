/*
Author: Claire Dong
Date: Nov 5th, 2018
Description: tests medication calculator 
*/

// Change to makefiles
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <sstream>

#include "libPancreas.h"
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

	cout << "Please enter an hour of sleep in military time(hour) or -1 for hour if not specified: ";
	getline(cin, sleepTime);
	getline(cin, sleepTime,'\n');

	cout << "Please enter an exercise level (Low/Medium/High/None): ";
	getline(cin, exerciseLevel);

	cout << "Please enter if a 'Basal' or 'Bolus' insulin dose is needed: ";
	getline(cin, basalOrBolus);

    /* Make medication calculator
       Parameters are: (double glucoseReading, double weight, double age, double sleepTime, string exerciseLevel, double carbInGrams);
     */
     MedicationCalculator calc (glucose, weight, age, sleepTime, exerciseLevel, carbs, basalOrBolus);

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
