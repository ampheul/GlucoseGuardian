/*!
	Group: 22
	Purpose: Represents a patient user. Patient users have full capabilities/access.
*/

#include "PatientAccount.h"

using namespace std;

public class PatientAccount : AccountType
{
	public void PrintOptions()
	{
		cout << "Patient user verified, please choose an option: " << endl;
		cout << "1 - Medical History";
		cout << "2 - Check Current Glucose Level";
		cout << "3 - Manual Glucose Entry";
		cout << "4 - Manual Insulin Administration";
		string option;
		getline(cin, option);
	}
}
