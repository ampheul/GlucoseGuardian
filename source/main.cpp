#include <iostream>
#include "Account.h"

using namespace std;
private:

string accountType;

bool Login()
{
	string password;
	cout << "Please enter a password: " << endl;
	getline(cin, password);
	Account account = Account (password);
	string type = account.GetAccountType();
	
	if (type == GUEST){
		accountType = "GUEST";
	}
	else if (type == PATIENT){
		accountType = "PATIENT";
	}

	type == PATIENT || type == GUEST ? true : false;
}

int main() 
{
	if(!Login())
	{
		cout << "Log in failed" << endl;
	}
	
	if (accountType.equals("GUEST")) {
		cout << "What would you like to access?";
		cout << "1 - Medical History";
		cout << "2 - Glucose Level";
		string option;
		getline(cin, option);
		if (option.equals("1")) {
			patient.getRecordEntries();
		}
		else {
			
		}
	}


	// prompt user to input patient data
	Patient patient = new Patient();

	return 0;
}
