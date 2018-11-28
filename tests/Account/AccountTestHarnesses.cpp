#include <stdio.h>
#include <string>
#include <sstream>

#include "main.h"

using namespace std;

int main()
{
	string password;
	cout << "Please enter a password: " << endl;
	getline(cin, password);

	Account account = Account();

	return 0;
}

bool PatientTestPass_CorrectPassword()
{
	const string password = "patient password";
	Account account = Account();
	string type = account.getAccountType();
	type == account.PATIENT_ACCOUNT ? true : false;
};

bool PatientTestFail_IncorrectPassword()
{
	const string password = "not the password";
	Account account = Account();
	string type = account.getAccountType();
	type == account.UNKNOWN ? true : false;
	return type;
}

bool GuestTestPass_CorrectPassword()
{
	const string password = "guest password";
	Account account = Account(password);
	string type = account.getAccountType();
	type == account.GUEST_ACCOUNT ? true : false;
	return type;
};

bool GuestTestFail_IncorrectPassword()
{
	const string password = "not the guest password";
	Account account = Account();
	string type = account.getAccountType();
	type == account.UNKNOWN_ACCOUNT ? true : false;
	return type;
}
