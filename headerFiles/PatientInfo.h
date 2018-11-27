#ifndef PATIENTINFO_H
#define PATIENTINFO_H

#include <iostream>
#include "DeviceRecord.h"
#include "Contact.h"
#include "MonitorRecord.h"
#include "MedicationRecord.h"
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
	vector<MonitorRecord> monitorRecords;
	vector<MedicationRecord> medicationRecords;
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

	vector<MonitorRecord> getMonitorRecords();

	vector<MedicationRecord> getMedicationRecords();

	vector<Contact> getEmergencyContacts();

	string getPassword();

	void setPassword(string password);

	void SetupPatientInfo();

	bool verifyPassword(string givenPassword);
};

#endif
