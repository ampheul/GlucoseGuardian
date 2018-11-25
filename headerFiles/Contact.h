#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>
// #include "ContactType.h"
using namespace std;

class Contact {
public:
	string name;
	string email;
	Contact(string name, string email);
	string getName();
	string getEmail();
};

#endif