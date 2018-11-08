/*!
	Group: 22
	Purpose: Represents the type of person that is logged in. Depending on the account type, 
			 may have restricted capability.
*/

#include "../../header files/Account/Account.h"

using namespace std;

/*!
	Name: Account
	Description: constructor
	@param string password - password that will be used to verify the identity of the user.
*/
Account::Account(const string& password)
{
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
		cout << "The Password you have entered has been set." << endl;
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
	if (accountType == PATIENT) 
	{
		cout << "Patient user verified, please choose an option: " << endl;
	}
	else if (accountType == GUEST)
	{
		cout << "Guest user verified, please choose an option: " << endl;
	}
	else
	{
		cout << "Stranger danger, you're not supposed to be here." << endl;
	}
};

/*!
	Name: GetAccountType
	Description: returns the type of the account
	@return	the account type
*/
string Account::GetAccountType() 
{
	return accountType;
};

/*!
	Name: VerifyPassword
	Description: verifies the password to a stored hash, sets the account type as either PATIENT, GUEST, or UNKNOWN
	@param ifstream& hashStream - stream for getting the hash
	@param string password - the password to verify
*/
void Account::VerifyPassword(ifstream& hashStream, string password)
{
	size_t toCompare = Account::HashPassword(password);

	// retrieve the locally stored hash value and compare to the new hased value
	string hashLine;
	size_t hash;

	if (hashStream.is_open())
	{
		hashStream >> hash;
	}

	if (hash == toCompare)
	{
		cout << "patient signed in" << endl;
		accountType = PATIENT;
	}
	else if (hash == 123)
	{
		cout << "guest signed in" << endl;
		accountType = GUEST;
	}
	else
	{
		cout << "unknown attempt to sign in" << endl;
		accountType = UNKNOWN;
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
	if (mkdir("accountInfo", 0777) != 0)
	{
		cout << "failed to make directory" << endl;
	}
	else
	{
		size_t hash = Account::HashPassword(password);
		ofstream accountInfo(ACCOUNT_INFO);
		accountInfo << hash << endl;

		accountInfo.close();
	}
};
