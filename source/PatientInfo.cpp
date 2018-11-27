#include "PatientInfo.h"

PatientInfo::PatientInfo() {
	iofile.open("patient.txt", ios::in);
	if(!iofile.is_open)
	{
		SetupPatientInfo();
	}
	else
	{
		readFromFile();
		iofile.close();
	}
}

PatientInfo::~PatientInfo()
{
	iofile.open("patient.txt", ios::out);
	writeToFile();
}

double PatientInfo::getWeight() {
	return weight;
}

void PatientInfo::setWeight(double Weight) {
	this->weight = weight;
}

double PatientInfo::getHeight() {
	return height;
}

void PatientInfo::setHeight(double height) {
	this->height = height;
}

int PatientInfo::getAge() {
	return age;
}

void PatientInfo::setAge(double age) {
	this->age = age;
}

string PatientInfo::getSex() {
	return sex;
}

void PatientInfo::setSex(string sex) {
	this->sex = sex;
}

vector<MedicationRecord> PatientInfo::getMedicationRecords() {
	return medicationRecords;
}

vector<MonitorRecord> PatientInfo::getMonitorRecords() {
	return monitorRecords;
}

vector<Contact> PatientInfo::getEmergencyContacts() {
	return emergencyContacts;
}

string PatientInfo::getPassword() {
	return password;
}

void PatientInfo::setPassword(string password) {
	this->password = password;
}

void PatientInfo::SetupPatientInfo() {
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

	cout << "What is your email?";
	cin >> email;

	cout << "What is your email password?";
	cin >> emailPassword;

	// Set up emergency contact
	cout << "What is the name of your emergency contact?";
	string emergContactName;
	string emergContactEmail;
	cin >> emergContactName;
	 
	cout << "What is the email of your emergency contact?";
	cin >> emergContactEmail;

	Contact emergContact(emergContactName, emergContactEmail);
}

bool PatientInfo::verifyPassword(string givenPassword) {
	return this->password == givenPassword;
}

void PatientInfo::readFromFile()
{
	iofile.open("patient.txt", ios::in);
	iofile >> weight >> height >> age >> bmi >> sex >> email >> emailPassword;
	delimiter = ",";
	while(getline(iofile, input) && input != "-----")
	{
		pos = input.find(delimiter);
		time = (time_t)stol(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
		tmpReading = new GlucoseReading(stod(input));
		tmpMonitor = new MonitorRecord(time, *tmpReading);
		monitorRecords.push_back(*tmpMonitor);
	}
	while(getline(iofile, input) && input != "-----")
	{
		pos = input.find(delimiter);
		time = (time_t)stol(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
		pos = input.find(delimiter);
		toEnum = input.substr(0, pos);
		input.erase(0, pos + delimiter.length());
		amount = stod(input);
		if(toEnum == "Bolus Insulin")
		{
			dose = new HormoneDose(BOLUS_INSULIN, amount);
		}
		else if(toEnum == "Basal Insulin")
		{
			dose = new HormoneDose(BASAL_INSULIN, amount);
		}
		else if(toEnum == "Glucacon")
		{
			dose = new HormoneDose(GLUCAGON, amount);
		}
		tmpRecord = new MedicationRecord(time, *dose);
		medicationRecords.push_back(*tmpRecord);
	}
}

void PatientInfo::writeToFile()
{
	iofile.open("patient.txt", ios::out);
	iofile << weight << endl;
	iofile << height << endl;
	iofile << age << endl;
	iofile << bmi << endl;
	iofile << sex << endl;
	iofile << email << endl;
	iofile << emailPassword << endl;
	iofile << "-----" << endl;
	for(vector<MonitorRecord>::iterator it = monitorRecords.begin(); it != monitorRecords.end(); ++it)
	{
		iofile << it->getRecordTime() << ",";
		iofile << it->getReading().getAmount() << endl;
	}
	iofile << "-----" << endl;
	for(vector<MedicationRecord>::iterator it = medicationRecords.begin(); it != medicationRecords.end(); ++it)
	{
		iofile << it->getRecordTime() << ",";
		switch(it->getHormoneDose().getHormoneType())
		{
			case BOLUS_INSULIN:
				iofile << "Bolus Insulin,";
				break;
			case BASAL_INSULIN:
				iofile << "Basal Insulin,";
				break;
			case GLUCAGON:
				iofile << "Glucagon,";
				break;
		}
		iofile << it->getHormoneDose().getHormoneAmount() << endl;
	}
	iofile.close();
}
