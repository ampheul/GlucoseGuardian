/*!
	Group: 22
	Purpose: Represents a guest user. Guest users have limited capabilities/access. 
*/

#include "GuestAccount.h"

using namespace std;


void GuestAccount::printOptions()
{
	cout << "Guest user verified, please choose an option: " << endl;
	cout << "1 - Medical History";
	string option;
	getline(cin, option);
}

