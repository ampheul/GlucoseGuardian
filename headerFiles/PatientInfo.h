#ifndef PATIENTINFO_H
#define PATIENTINFO_H

#include <iostream>
#include "DeviceRecord.h"
#include "Contact.h"
using namespace std;

class PatientInfo {
private:
	double weight;
	double height;
	int age;
	double bmi;
	string sex;
	string email;
	string emailPassword;
	vector<DeviceRecord> recordEntryList;
	vector<Contact> emergencyContacts;
	string password;

public:
	PatientInfo();

	double getWeight();

	void setWeight(double weight);

	double getHeight();

	void setHeight(double height);

	double getAge() {
		return this->age;
	}

	void setAge(double age);

	string getSex();

	void setSex(string sex);

	vector<DeviceRecord> getRecordEntries();

	vector<Contact> getEmergencyContacts();

	string getPassword();

	void setPassword(string password);

	void SetupPatientInfo();

	bool verifyPassword(string givenPassword);
};

#endif
