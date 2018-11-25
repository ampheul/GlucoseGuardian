#include <iostream>
#include "Contact.h"

using namespace std;

string Contact::getName() {
	return this->name;
}

string Contact::getEmail() {
	return this->email;
}

Contact::Contact(string name, string email)
{
}
