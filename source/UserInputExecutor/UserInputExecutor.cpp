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


