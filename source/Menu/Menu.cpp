/*!
	@author Veronica Witzig
	Purpose: Responsible for displaying the UI menu
*/

#include "Menu.h"

using namespace std;

/*!
	Name: Menu
	Description: builds the menu items available for the user based on their account type
*/
Menu::Menu(Account *account)
{
	accountType = account->getAccountType();
	
	if (accountType == Account::PATIENT_ACCOUNT)
	{
		cout << "Patient user verified, please choose an option: " << endl;
		menuItems = new vector<string>(){
			"1 - Exit Program"
			"2 - Medical History",
			"3 - Check Current Glucose Level",
			"4 - Manual Glucose Entry",
			"5 - Manual Insulin Administration"				
		}
	}
	else if (accountType == Account::GUEST_ACCOUNT)
	{
		cout << "Guest user verified, please choose an option: " << endl;
		menuItems = new vector<string>(){
			"1 - Exit Program"
			"2 - Medical History",
		}
	}
	else if (accountType == Account::UNKNOWN_ACCOUNT)
	{
		cout << "Get out." << endl;
	}
};

/*!
	Name: ~Menu
	Description: destructor
*/
Menu::~Menu() {};

/*!
	Name: PrintMenu
	Description: prints the UI menu to the terminal for the user
*/
void Menu::printMenu()
{
	for (const auto& item : menuItems)
	{
		cout << item << endl;
	}
};

/*!
	Name: GetMenuSelection
	Description: retrieves the option that the user has selected from the available menu items
*/
int Menu::getMenuSelection()
{
	bool validSelection = false;
	string userInput;
	int optionInt = 0;
	
	while(!validSelection)
	{
		userInput = "";
		optionInt = 0;
		
		cout << "Please select a corresponding number from the above selection: " << endl;
		getline(cin, userInput);
		validSelection = validateSelection(userInput);
		
		stringstream(userInput) >> optionInt;		
	}
	
	return optionInt;
};

/*!
	Name: ValidateSelection
	Description: verfies that the user entered value is valid
*/
bool Menu::validateSelection(string userInput)
{
	string userInput;
	getline(cin, userInput);
	
	// ensure the input is an int
	int asInt = 0;
	stringstream(userInput) >> asInt;
	if(asInt > 4 || asInt < 1)
	{
		cout << userInput + " is not a valid selection, please try again." << endl;
		return false;
	}
	
	// ensure the user is not trying to select an option they should not be able to
	if (accountType != Account::PATIENT_ACCOUNT && asInt > 2)
	{
		cout << asInt + " is not a valid selection, please try again." << endl;
		return false;
	}
	
	return true;
};
