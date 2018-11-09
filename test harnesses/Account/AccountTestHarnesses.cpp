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
	string password = "patient password";
	Account account = Account(password);
	string type = account.GetAccountType();
	type == account.PATIENT ? true : false;
};

bool TestFail_IncorrectPassword()
{
	const string password = "not the password";
	Account account = Account(password);
	string type = account.GetAccountType();
	type == account.UNKNOWN ? true : false;
}

bool TestPass_CorrectPassword()
{
	const string password = "guest password";
	Account account = Account(password);
	string type = account.GetAccountType();
	type == account.GUEST ? true : false;
};

bool TestFail_IncorrectPassword()
{
	string password = "not the guest password";
	Account account = Account(password);
	string type = account.GetAccountType();
	type == account.UNKNOWN ? true : false;
}
