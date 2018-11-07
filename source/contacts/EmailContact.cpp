#include <iostream>
using namespace std;

public class EmailContact implements ContactType{
private:
	string email;

public:
	void Notify() {
		printf("Emergency Contact! This is an email saying your patient requires your help!");
	}

	string getEmail() {
		return email;
	}

	void setEmail(string givenEmail) {
		email = givenEmail;
	}
};