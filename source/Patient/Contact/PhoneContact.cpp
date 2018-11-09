#include <iostream>
#include "ContactType.h"
using namespace std;

class PhoneContact : ContactType{
private:
	int phoneNumber;

public:
	void Notify() {
		cout << "Emergency Contact! Your patient requires help!";
		// Go back to this later
	}

	int getPhoneNumber() {
		return phoneNumber;
	}

	void setPhoneNumber(int number) {
		phoneNumber = number;
	}
};