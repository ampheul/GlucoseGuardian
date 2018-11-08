#include <iostream>
#include "Account.h"

using namespace std;
/*
bool Login()
{
	string password;
	cout << "Please enter a password: " << endl;
	getline(cin, password);
	Account account = Account (password);
	string type = account.GetAccountType();
	
	type == PATIENT || type == GUEST ? true : false;
}
*/

int main() 
{
	/*
	if(!Login())
	{
		cout << "Log in failed" << endl;
	}
	*/
	
	// prompt user to input patient data
	Patient patient = new Patient();

	return 0;
}
