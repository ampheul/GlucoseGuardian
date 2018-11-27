/*!
	@author Veronica Witzig
	Purpose: Responsible for executing requests made by the user
*/

#include "UserInputExecutor.h"

using namespace std;

/*!
	@name userInputExecutor
	Description: constructor
	@param artificialPancreas - the pancreas for sending manually entered glucose and insulin to
*/
UserInputExecutor::userInputExecutor(ArtificialPancreas artificialPancreas)
{
	this->artificialPancreas = artificialPancreas;
};

/*!
	@name ~UserInputExecutor
	Description: destructor
*/
UserInputExecutor::~userInputExecutor() {};

/*!
	@name quitProgram
	Description: closes the artificialPancreas program
*/
UserInputExecutor::quitProgram()
{
	ReportMaker maker = new ReportMaker();
	maker.makeReport();
}

/*!
	@name medicalHistory
	Description: displays a graph of the patient's medical history
*/
UserInputExecutor::medicalHistory()
{
	ReportMaker maker = new ReportMaker();
	maker.makeReport();
}

/*!
	@name currentGlucose
	Description: queries the patient's glucose monitor to report their current glucose level
*/
UserInputExecutor::currentGlucose()
{
	MedicationCalculator calc = artificialPancreas.calculator;

	double glucoseReading = calc.GetGlucoseReading();
	auto glucoseToPrint = to_string(glucoseReading);
	
	cout << "Your current glucose reading is : " + glucoseToPrint + "mg/dL";
}

/*!
	@name manualGlucoseEntry
	Description: queries the user for a glucose entry and then sends the value to the artificial pancreas
*/
UserInputExecutor::manualGlucoseEntry()
{
	bool validEntry = false;
	int glucoseEntry = 0;

	while(!validEntry) 
	{
		glucoseEntry = 0;

		cout << "Please enter the glucose reading: " << endl;

		// ensure the user input is a valid entry
		cin >> glucoseEntry;
		if (glucoseEntry < 40 && glucoseEntry > 1.7)
		{
			validEntry = true;
		}
		else
		{
			auto glucoseToPrint = to_string(glucoseEntry);
			cout << glucoseToPrint + " is not a valid glucose reading, please try again." << endl;
		}
	}
	
	artificialPancreas.manuallyEnterGlucose(glucoseEntry);
}

/*!
	@name manualInsulinAdministration
	Description: queries the user for a insulin amount to be administered
*/
UserInputExecutor::manualInsulinAdministration()
{
	bool validEntry = false;
	string userInput;
	int glucoseEntry = 0;

	while(!validEntry) 
	{
		glucoseEntry = 0;
		userInput = "";

		cout << "Please enter the insulin to be administered: " << endl;
		getline(cin, userInput);

		// ensure the user input is a valid entry
		stringstream(userInput) >> glucoseEntry;
		if (glucoseEntry < 0 && glucoseEntry > artificialPancreas.getPatientInfo.getWeight() / 4)
		{
			validEntry = true;
		}
		else
		{
			auto glucoseToPrint = to_string(glucoseEntry);
			cout << glucoseToPrint + " is not a valid glucose reading, please try again." << endl;
		}
	}
	
	artificialPancreas.manuallyAdministerInsulin(insulinEntry);
}

/*!
	@name updateCarbsExerciseSleep
	Description: updates the patient's expected consumed carbs, exercise level, and sleep
*/
UserInputExecutor::updateCarbsExerciseSleep()
{
	cout << "Updating carbohydrates, exercise level, and sleep time" << endl;
	
	PatientInfo patientInfo = artificialPancreas.getPatientInfo();
	
	UserInputExecutor::updatePatientInfoCarbs(patientInfo);
	UserInputExecutor::updatePatientInfoExercise(patientInfo);
	UserInputExecutor::updatePatientInfoSleep(patientInfo);
	
	cout << "Update completed." << endl;
}

/*!
	@name updatePatientInfoCarbs
	Description: updates the patient's consumed carbs
	@param patientInfo - the info to update
*/
UserInputExecutor::updatePatientInfoCarbs(PatientInfo patientInfo)
{
	bool validEntry = false;
	double carbs = 0;
	
	while(!validEntry) 
	{
		carbs = 0;
		userInput = "";

		cout << "Please enter the number of carbs you expect to consume: " << endl;

		// ensure the user input is an int or double and is within the allowable range
		cin >> carbs;
		if (!cin.fail() && (carbs > UserInputExecutor::MINIMUM_CARBS || carbs < UserInputExecutor::MAXIMUM_CARBS))
		{
			validEntry = true;
		}
		else
		{
			cout << "Not a valid carb entry, please try again." << endl;
		}
	}
	
	patientInfo.setCarbs(carbs);
}

/*!
	@name updatePatientInfoExercise
	Description: updates the patient's expected exercise level
	@param patientInfo - the info to update
*/
UserInputExecutor::updatePatientInfoExercise(PatientInfo patientInfo)
{
	bool validEntry = false;
	string exercise;
	int optionInt;
	
	while(!validEntry) 
	{
		exercise = "";
		userInput = "";
		optionInt = 0;

		cout << "Please select the corresponding number for the amount of exercise you expect to achieve: " << endl;
		cout << "1 - None 	- no activity" << endl;
		cout << "2 - Low 	- 1 to 20 minutes of activity" << endl;
		cout << "3 - Medium - 20 to 30 minutes of activity" << endl;
		cout << "4 - High 	- 40 or more minutes of activity" << endl;

		// ensure the user input is an int
		cin >> optionInt;
		if (!cin.fail())
		{			
			switch (optionInt)
			{
			case 1:
				exercise = "None";
				validEntry = true;
				break;
			case 2:
				exercise = "Low";
				validEntry = true;
				break;
			case 3:
				exercise = "High";
				validEntry = true;
				break;
			case 4:
				exercise = "Medium";
				validEntry = true;
				break;
			default:
				cout << "That was not a valid option, please only enter a single int value." << endl;
			}
		}
		else
		{
			cout << "Not a valid entry, please try again." << endl;
		}
	}
	
	patientInfo.setExercise(exercise);
}

/*!
	@name updatePatientInfoSleep
	Description: updates the patient's expected hours of sleep
	@param patientInfo - the info to update
*/
UserInputExecutor::updatePatientInfoSleep(PatientInfo patientInfo)
{
	bool validEntry = false;
	int sleepHours;
	
	while(!validEntry) 
	{
		sleepHours = 0;

		cout << "Please enter your hours of expected sleep between 0 to 24 hours: " << endl;

		// ensure the user input is a valid entry
		cin >> sleepHours;
		if (!cin.fail() || sleepHours > 24 || sleepHours < 0)
		{			
			validEntry = true;
		}
		else
		{
			cout << "Not a valid entry, please try again." << endl;
		}
	}

	patientInfo.setSleep(sleepHours);
}

/*!
	@name menuSwitch
	Description: determines which UI menu should be presented to the user depending on the menu item they selected
	@param option - represents the menu item selected by the user
*/
UserInputExecutor::menuSwitch(int option)
{
	cout << "---------" << endl;
	switch (option)
	{
	case 1:
		UserInputExecutor::quitProgram();
		break;
	case 2:
		UserInputExecutor::medicalHistory();
		break;
	case 3:
		UserInputExecutor::currentGlucose();
		break;
	case 4:
		UserInputExecutor::manualGlucoseEntry();
		break;
	case 5:
		UserInputExecutor::manualInsulinAdministration();
		break;
	case 6:
		UserInputExecutor::updateCarbsExerciseSleep();
		break;
	default:
		cout << "Not a valid selection, please try again." << endl;
	}
	cout << "---------\n" << endl;
}
