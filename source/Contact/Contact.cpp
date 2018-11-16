#include <iostream>
#include "../../header files/Contacts/Contact.h"
// #include "ContactType.h"

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