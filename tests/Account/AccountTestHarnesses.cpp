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
<<<<<<< HEAD
	string type = account.getAccountType();
	type == account.PATIENT_ACCOUNT ? true : false;
=======
	return account.getAccountType() == account.PATIENT_ACCOUNT;
>>>>>>> c43104b8c06e711ac788f12d65a1d84b01252bd5
};

bool PatientTestFail_IncorrectPassword()
{
	const string password = "not the password";
	Account account = Account();
<<<<<<< HEAD
	string type = account.getAccountType();
	type == account.UNKNOWN_ACCOUNT ? true : false;
=======
	return account.getAccountType() == account.UNKNOWN_ACCOUNT;
>>>>>>> c43104b8c06e711ac788f12d65a1d84b01252bd5
}

bool GuestTestPass_CorrectPassword()
{
	const string password = "guest password";
	Account account = Account();
<<<<<<< HEAD
	string type = account.getAccountType();
	type == account.GUEST_ACCOUNT ? true : false;
=======
	return account.getAccountType() == account.GUEST_ACCOUNT;
>>>>>>> c43104b8c06e711ac788f12d65a1d84b01252bd5
};

bool GuestTestFail_IncorrectPassword()
{
	const string password = "not the guest password";
	Account account = Account();
<<<<<<< HEAD
	string type = account.getAccountType();
	return type == account.UNKNOWN_ACCOUNT ? true : false;
=======
	return account.getAccountType() == account.UNKNOWN_ACCOUNT;
>>>>>>> c43104b8c06e711ac788f12d65a1d84b01252bd5
}
