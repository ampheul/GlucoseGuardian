#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include "DeviceRecord.h"
#include "Patient.h"
#include "Contact.h"
using namespace std;

class Patient {
private:
	double weight;
	double height;
	double age;
	double bmi;
	string sex;
	vector<DeviceRecord> recordEntryList;
	vector<Contact> emergencyContacts;
	string password;

public:
	Patient();
	~Patient();

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
