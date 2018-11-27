#ifndef PATIENTINFO_H
#define PATIENTINFO_H

#include <iostream>
#include <fstream>
#include "DeviceRecord.h"
#include "Contact.h"
#include "MonitorRecord.h"
#include "MedicationRecord.h"
#include "HormoneDose.h"
using namespace std;

class PatientInfo {
private:
	double weight;
	double height;
	int age;
	double bmi;
	double carbs;
	string exercise;
	struct tm sleep;
	string sex;
	string email;
	string emailPassword;
	vector<MonitorRecord> monitorRecords;
	vector<MedicationRecord> medicationRecords;
	vector<Contact> emergencyContacts;
	string password;
	fstream iofile;
	string input, delimiter;
	time_t time;
	size_t pos;
	HormoneDose *dose;
	string toEnum;
	hormoneType type;
	double amount;
	GlucoseReading *tmpReading;
	MonitorRecord *tmpMonitor;	
	MedicationRecord *tmpRecord;

public:
	PatientInfo();

	~PatientInfo();

	double getWeight();

	void setWeight(double weight);

	double getHeight();

	void setHeight(double height);

	int getAge();

	void setAge(double age);

	string getSex();

	double getCarbs();

	void setCarbs(double carbs);

	string getExercise();

	void setExercise(string exercise);

	struct tm getSleep();

	void setSleep(struct tm sleep);

	void setSex(string sex);

	vector<MonitorRecord> getMonitorRecords();

	vector<MedicationRecord> getMedicationRecords();

	vector<Contact> getEmergencyContacts();

	string getPassword();

	void setPassword(string password);

	void SetupPatientInfo();

	bool verifyPassword(string givenPassword);

	void readFromFile();

	void writeToFile();
};

#endif
