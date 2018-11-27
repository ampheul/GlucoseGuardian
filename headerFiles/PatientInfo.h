/*
	Purpose: header file for the PatientInfo class
*/

#ifndef PATIENTINFO_H
#define PATIENTINFO_H

#include <iostream>
#include <fstream>
#include <vector>
#include "DeviceRecord.h"
#include "Contact.h"
#include "MonitorRecord.h"
#include "MedicationRecord.h"
#include "HormoneDose.h"

using namespace std;

class PatientInfo 
{
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
	void setSex(string sex);
	
	double getCarbs();
	void setCarbs(double carbs);
	
	string getExercise();
	void setExercise(string exercise);
	
	int getSleep();
	void setSleep(int sleep);

	vector<MonitorRecord> getMonitorRecords();
	vector<MedicationRecord> getMedicationRecords();
	vector<Contact> getEmergencyContacts();
	void SetupPatientInfo();
	void readFromFile();
	void writeToFile();
	std::string getName();
	
private:
	double weight;
	double height;
	double bmi;
	double carbs;
	double amount;
	
	int age;
	int sleep;
	
	string sex;
	string email;
	string emailPassword;
	string exercise;
	string name;

	vector<MonitorRecord> monitorRecords;
	vector<MedicationRecord> medicationRecords;
	vector<Contact> emergencyContacts;

	fstream iofile;
	string input, delimiter;
	time_t time;
	size_t pos;
	HormoneDose *dose;
	hormoneType type;
	string toEnum;
	
	GlucoseReading *tmpReading;
	MonitorRecord *tmpMonitor;
	MedicationRecord *tmpRecord;
};

#endif
