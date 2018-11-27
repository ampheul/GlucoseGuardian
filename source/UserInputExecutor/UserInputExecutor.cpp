/*!
	Group: 22
	Purpose: Responsible for executing the request made by the user
*/

#include "UserInputExecutor.h"

using namespace std;

void QuitProgram()
{
	ReportMaker maker = new ReportMaker();
	maker.makeReport();
}

void MedicalHistory()
{
	ReportMaker maker = new ReportMaker();
	maker.makeReport();
}

void CurrentGlucose()
{
	MedicationCalculator calc = artificialPancreas.calculator;

	double glucoseReading = calc.GetGlucoseReading();
	auto glucoseToPrint = to_string(glucoseReading);
	
	cout << "Your current glucose reading is : " + glucoseToPrint + "mg/dL";
}

void ManualGlucoseEntry()
{
	bool validEntry = false;
	string userInput;
	int glucoseEntry = 0;

	while(!validEntry) 
	{
		glucoseEntry = 0;
		userInput = "";

		cout << "Please enter the glucose reading: " << endl;
		getline(cin, userInput);

		// ensure the user input is a valid entry
		stringstream(userInput) >> glucoseEntry;
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

void ManualInsulinAdministration()
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

void UpdateCarbsExerciseSleep()
{
	cout << "Updating carbohydrates, exercise level, and sleep time" << endl;
	
	PatientInfo patientInfo = artificialPancreas.getPatientInfo();
	
	UpdatePatientInfoCarbs(patientInfo);
	UpdatePatientInfoExercise(patientInfo);
	UpdatePatientInfoSleep(patientInfo);
	
	cout << "Update completed." << endl;
}

void UpdatePatientInfoCarbohydrates(PatientInfo patientInfo)
{
	bool validEntry = false;
	string userInput;
	double carbs = 0;
	
	while(!validEntry) 
	{
		carbs = 0;
		userInput = "";

		cout << "Please enter the number of carbs you expect to consume: " << endl;
		getline(cin, userInput);

		// ensure the user input is an int or double
		cin >> carbs;
		if ((carbs > 0 || carbs < ) && !cin.fail())
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

void UpdatePatientInfoExercise(PatientInfo patientInfo)
{
	bool validEntry = false;
	string exercise;
	int optionInt;
	
	while(!validEntry) 
	{
		exercise = "";
		userInput = "";
		optionInt = 0;

		cout << "Please select the corresponding amount of exercise you expect to achieve: " << endl;
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
				exercise = "";
				break;
			case 2:
				OperatingSystemMenu();
				break;
			case 3:
				ProcessorMenu();
				break;
			case 4:
				MemoryMenu();
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

void UpdatePatientInfoSleep(PatientInfo patientInfo)
{
	
	patientInfo.setSleep();
}

void MenuSwitch(int option)
{
	cout << "---------" << endl;
	switch (option)
	{
	case 1:
		QuitProgram();
		break;
	case 2:
		MedicalHistory();
		break;
	case 3:
		CurrentGlucose();
		break;
	case 4:
		ManualGlucoseEntry();
		break;
	case 5:
		ManualInsulinAdministration();
		break;
	case 6:
		UpdateCarbsExerciseSleep();
		break;
	default:
		cout << "This shouldn't have happened." << endl;
	}
	cout << "---------\n" << endl;
}

/*!
	Name: UserInputExecutor
	Description: constructor
	@param artificialPancreas - 
*/
UserInputExecutor::UserInputExecutor(ArtificialPancreas artificialPancreas)
{
	this->artificialPancreas = artificialPancreas;
};

/*!
	Name: ~UserInputExecutor
	Description: destructor for the UserInputExecutor class
*/
UserInputExecutor::~UserInputExecutor() {};


