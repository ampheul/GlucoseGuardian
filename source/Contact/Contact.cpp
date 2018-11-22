#include <iostream>
#include "Contact.h"

using namespace std;

Contact::Contact(string name) {
	Contact::name = name;
}

string Contact::getName() {
	return this->name;
}

void Contact::setName(string name) {
	this->name = name;
}