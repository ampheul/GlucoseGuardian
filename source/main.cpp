#include <iostream>
#include "../headerFiles/Account.h"

using namespace std;

string accountType;

bool Login()
{
	string password;
	cout << "Please enter a password: " << endl;
	getline(cin, password);
	Account account = Account (password);
	string type = account.GetAccountType();
	
	if (type == account.GUEST){
		accountType = account.GUEST;
	}
	else if (type == account.PATIENT){
		accountType = account.PATIENT;
	}

	type == account.PATIENT || type == account.UNKNOWN ? true : false;
}

int main() 
{
	if(!Login())
	{
		cout << "Log in failed" << endl;
	}
	
	if (accountType == "GUEST") {
		cout << "What would you like to access?";
		cout << "1 - Medical History";
		cout << "2 - Glucose Level";
		string option;
		getline(cin, option);
		if (option == "1") {
			cout << "Patient Records Are: No Records Found";
		}
		else {
			cout << "Patient's Latest Glucose Reading is: No Records Found";
		}
	}

	// prompt user to input patient data
	// Patient patient = new Patient();

	return 0;
}
