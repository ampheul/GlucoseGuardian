/*!
	Purpose: Header file for the Contact.cpp file
*/

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

using namespace std;

class Contact 
{
public:
	string name;
	string email;

	Contact(string name, string email);
	~Contact();

	string getName();
	string getEmail();
};

#endif
