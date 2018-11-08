#include <stdio.h>
#include <string>
#include <sstream>

#include "../../header files/Account/Account.h"

using namespace std;

int main()
{
	string password;
	cout << "Please enter a password: " << endl;
	getline(cin, password);

	Account account = Account(password);

	return 0;
}

bool TestPass_CorrectPassword()
{
	string password = "password";
	Account account = Account(password);
	string type = account.GetType();
	type == PATIENT ? true : false;
};

bool TestFail_IncorrectPassword()
{
	string password = "not the password";
	Account account = Account(password);
	string type = account.GetType();
	type == UNKNOWN ? true : false;
}
