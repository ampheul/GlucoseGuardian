#include <iostream>
#include "DeviceRecord.h"
#include "Patient.h"
#include "Contact.h"
using namespace std;

public static class Patient {
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
	Patient() {
		SetupPatientInfo();
	}

	double getWeight() {
		return weight;
	}

	void setWeight(double weight) {
		this.weight = weight;
	}

	double getHeight() {
		return height;
	}

	void setHeight(double height) {
		this.height = height;
	}

	double getAge() {
		return age;
	}

	void setAge(double age) {
		this.age = age;
	}

	string getSex() {
		return sex;
	}

	void setSex(string sex) {
		this.sex = sex;
	}

	vector<DeviceRecord> getRecordEntries() {
		return recordEntryList;
	}

	vector<Contact> getEmergencyContacts() {
		return emergencyContacts;
	}

	string getPassword() {
		return password;
	}

	void setPassword(string password) {
		this.password = password;
	}

	void SetupPatientInfo() {
		cout << "What is your weight?";
		cin >> weight;

		cout << "What is your height?";
		cin >> height;

		cout << "What is your age?";
		cin >> age;

		cout << "What is your sex?";
		cin >> sex;

		cout << "What would you like your password to be?";
		cin >> password;

		// Set up emergency contact
		cout << "What is the name of your emergency contact?";
		string emergContactName;
		cin >> emergContactName;

		Contact emergContact = new Contact(emergContactName);
	}

	bool verifyPassword(string givenPassword) {
		return password.equals(givenPassword);
	}
};