#include <iostream>
#include "Contact.h"

using namespace std;

Contact::Contact(string name) {
	Contact::name = name;
}

string getName() {
	return Contact::name;
}

void setName(string name) {
	Contact::name = name;
}