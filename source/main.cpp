#include "main.h"

using namespace std;

void MedicalHistory()
{
	ReportMaker maker = new ReportMaker();
	maker.makeReport();
}

void CurrentGlucose()
{
	MedicationCalculator calc = artificialPancreas->calculator;

	double glucoseReading = calc.gluRead;
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

void MenuSwitch(int option)
{
	cout << "---------" << endl;
	switch (option)
	{
	case 1:
		exit(0);
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

int main(int argc, char **argv) 
{
	ArtificialPancreas artificialPancreas = new ArtificialPancreas();
	Account account = new Account();
	Menu menu = new Menu(account);
	bool running = true;
	
	while(running)
	{
		menu.PrintMenu();		
		int optionToRetrieve = menu.getMenuSelection();
	}
	
	return 0;
}
