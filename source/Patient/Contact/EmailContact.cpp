#include <iostream>
#include "ContactType.h"
using namespace std;

class EmailContact : ContactType {
private:
	string email;

public:
	void Notify() {
		cout << "Emergency Contact! This is an email saying your patient requires your help!";
	}

	string getEmail() {
		return email;
	}

	void setEmail(string givenEmail) {
		email = givenEmail;
	}
};