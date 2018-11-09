#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>
// #include "ContactType.h"
using namespace std;

class Contact {
public:
	string name;
	// vector<ContactType> contactOptions;
	Contact(std::string name);
	string getName();
	void setName(string name);
};

#endif