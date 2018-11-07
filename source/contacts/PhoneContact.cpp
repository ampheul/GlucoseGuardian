#include <iostream>
using namespace std;

public class PhoneContact implements ContactType{
private:
	int phoneNumber;

public:
	void Notify() {
		printf("Emergency Contact! Your patient requires help!");
		// Go back to this later
	}

	int getPhoneNumber() {
		return phoneNumber;
	}

	void setPhoneNumber(int number) {
		phoneNumber = number;
	}
};