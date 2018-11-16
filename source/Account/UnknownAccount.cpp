/*!
	Group: 22
	Purpose: Represents an unknown user. Unknown users have no capabilities/access.
*/

#include "UnknownAccount.h"

using namespace std;

public class UnknownAccount : AccountType
{
	public void PrintOptions()
	{
		cout << "Stranger danger, you're not supposed to be here." << endl;
	}
}
