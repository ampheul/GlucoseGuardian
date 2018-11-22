/*!
	Group: 22
	Purpose: Represents the type of person that is logged in. Depending on the account type, 
			 may have restricted capability.
*/

#include "Account.h"

using namespace std;

/*!
	Name: Account
	Description: constructor
	@param string password - password that will be used to verify the identity of the user.
*/
Account::Account()
{
	string password;
	cout << "Please enter a password: " << endl;
	getline(cin, password);
	
	// check if accounts.txt file exists locally. If it does not, then the account needs to be initialized, else, continue the verification process.
	ifstream accountStream(ACCOUNT_INFO);
	if (accountStream.is_open())
	{
		Account::VerifyPassword(accountStream, password);
	}
	else
	{
		cout << "An account has not been initialized on this machine. Performing setup..." << endl;
		Account::InitializeAccount(password);
		cout << "The password you have entered has been set." << endl;

		cout << "Now that your account has been initialized, please re-enter your password: ";
		string newPassword;
		getline(cin, newPassword);
		Account::VerifyPassword(accountStream, newPassword);
	}
};

/*!
	Name: ~Account
	Description: destructor for the Account class
*/
Account::~Account() {};

/*!
	Name: accountOptions
	Description: options that are available to the user. Depends on the type of the user.
	@return	the hash value of the passed password
*/
void Account::AccountOptions()
{
	accountType.PrintOptions();
};

/*!
	Name: GetAccountType
	Description: returns the type of the account
	@return	the account type
*/
string Account::GetAccountType() 
{
	return this->accountType;
};

/*!
	Name: VerifyPassword
	Description: verifies the password to a stored hash, sets the account type as either PATIENT, GUEST, or UNKNOWN
	@param ifstream& hashStream - stream for getting the hash
	@param string password - the password to verify
*/
void Account::VerifyPassword(ifstream& hashStream, string password)
{
	size_t hashToCheck = Account::HashPassword(password);

	// retrieve the locally stored hash value and compare to the new hased value
	string hashLine;
	size_t patientHash;
	size_t guestHash;

	// patient hash is on first line. guest/emergency contact hash is on second line

	if (hashStream.is_open())
	{
		hashStream >> patientHash;
		hashStream >> guestHash;
	}

	if (patientHash == hashToCheck)
	{
		cout << "patient signed in" << endl;
		accountType = new PatientAccount();
	}
	else if (guestHash == hashToCheck)
	{
		cout << "guest signed in" << endl;
		accountType = new GuestAcount();
	}
	else
	{
		cout << "unknown attempt to sign in" << endl;
		accountType = new UnknownAccount();
	}
};

/*!
	Name: HashPassword
	Description: hashes the received password from the user
	@param string password - the password to hash
	@return hash value of the password
*/
size_t Account::HashPassword(string password)
{
	hash<string> hasher;
	size_t hash = hasher(password);
	return hash;
};

/*!
	Name: InitializeAccount
	Description: initializes the patient's main account by setting a password for the user.
	@param string password - the password to verify
*/
void Account::InitializeAccount(string password)
{
	cout << "Would you like to use the password you entered for the main account (Y / N): ";
	string yesOrNo = "";
	getline(cin, yesOrNo);

	if (yesOrNo == "N") {
		cout << "Please enter a password: ";
		getline(cin, password);
	}

	size_t hash = Account::HashPassword(password);
	ofstream accountInfo(ACCOUNT_INFO);
	accountInfo << hash << endl;

	cout << "For your own safety, please provide a password for an emergency guest account: ";
	string guestPassword = "";
	getline(cin, guestPassword);
	guestPassword = "\n" + guestPassword;
	hash = Account::HashPassword(guestPassword);
	accountInfo << hash << endl;
};
