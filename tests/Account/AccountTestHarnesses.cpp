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
	return account.getAccountType() == account.PATIENT_ACCOUNT;
};

bool PatientTestFail_IncorrectPassword()
{
	const string password = "not the password";
	Account account = Account();
	return account.getAccountType() == account.UNKNOWN_ACCOUNT;
}

bool GuestTestPass_CorrectPassword()
{
	const string password = "guest password";
	Account account = Account();
	return account.getAccountType() == account.GUEST_ACCOUNT;
};

bool GuestTestFail_IncorrectPassword()
{
	const string password = "not the guest password";
	Account account = Account();
	return account.getAccountType() == account.UNKNOWN_ACCOUNT;
}
