#include "PatientInfo.h"

PatientInfo::PatientInfo(
	string name,
	int age,
	string sex,
	double weight,
	double height,
	string email
	)
	:
	name(name),
	age(age),
	sex(sex),
	weight(weight),
	height(height),
	email(email)
	
{
	this->monitorRecords = new vector<MonitorRecord>();
}

PatientInfo::PatientInfo() {
	monitorRecords = new vector<MonitorRecord>;
	medicationRecords = new vector<MedicationRecord>;
	
	inFile.open("patient.txt");
	if(!inFile.is_open())
	{
		SetupPatientInfo();
	}
	else
	{
		readFromFile();
	}

	sleep = -1;
	exercise = "None";
	carbs = 0;
}

PatientInfo::~PatientInfo()
{
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

double PatientInfo::getCarbs() {
	return carbs;
}

void PatientInfo::setCarbs(double carbs) {
	this->carbs = carbs;
}

std::string PatientInfo::getName()
{
	return this->name;
}

string PatientInfo::getExercise() {
	return exercise;
}

void PatientInfo::setExercise(string exercise) {
	this->exercise = exercise;
}

int PatientInfo::getSleep() {
	return sleep;
}

void PatientInfo::setSleep(int sleep) {
	this->sleep = sleep;
}

vector<MedicationRecord> * PatientInfo::getMedicationRecords() {
	return medicationRecords;
}

vector<MonitorRecord> * PatientInfo::getMonitorRecords() {
	return monitorRecords;
}

Contact* PatientInfo::getEmergencyContact() {
	return emergencyContact;
}

void PatientInfo::setEmergencyContact(Contact* contact)
{
	this->emergencyContact = contact;
}

string PatientInfo::getEmailPassword() {
	return this->emailPassword;
}

void PatientInfo::setEmailPassword(std::string emailPassword)
{
	this->emailPassword = emailPassword;
}

string PatientInfo::getEmail() {
	return this->email;
}

void PatientInfo::setEmail(std::string email)
{
	this->email = email;
}

void PatientInfo::SetupPatientInfo() {
	cout << "What is your name?";
	cin >> name;

	cout << "What is your weight?";
	cin >> weight;

	cout << "What is your height?";
	cin >> height;

	cout << "What is your age?";
	cin >> age;

	cout << "What is your sex?";
	cin >> sex;

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

	emergencyContact = new Contact(emergContactName, emergContactEmail);

}

void PatientInfo::readFromFile()
{
	string emergName, emergEmail;
	inFile >> name >> weight >> height >> age >> bmi >> sex >> email >> emailPassword >> emergName >> emergEmail;
	emergencyContact = new Contact(emergName, emergEmail);
	delimiter = ",";
	getline(inFile, input);
	while(getline(inFile, input) && input != "-----")
	{
		pos = input.find(delimiter);
		time = (time_t)stol(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
		GlucoseReading *tempGlucose = new GlucoseReading(stod(input));
		MonitorRecord *tempMonitor = new MonitorRecord(time, *tempGlucose);
		monitorRecords->push_back(*tempMonitor);
		delete tempGlucose;
		delete tempMonitor;
	}
	while(getline(inFile, input))
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
		MedicationRecord *temp = new MedicationRecord(time, *dose);
		medicationRecords->push_back(*temp);
		delete dose;
		delete temp;
	}
}

void PatientInfo::writeToFile()
{
	outFile.open("patient.txt", ios::trunc);
	outFile << name << endl;
	outFile << weight << endl;
	outFile << height << endl;
	outFile << age << endl;
	outFile << bmi << endl;
	outFile << sex << endl;
	outFile << email << endl;
	outFile << emailPassword << endl;

	for(vector<MonitorRecord>::iterator it = monitorRecords->begin(); it != monitorRecords->end(); ++it)
	{
		outFile << it->getRecordTime() << ",";
		outFile << it->getReading().getAmount() << endl;
	}
	outFile << "-----" << endl;
	for(vector<MedicationRecord>::iterator it = medicationRecords->begin(); it != medicationRecords->end(); ++it)
	{
		outFile << it->getRecordTime() << ",";
		switch(it->getHormoneDose().getHormoneType())
		{
			case BOLUS_INSULIN:
				outFile << "Bolus Insulin,";
				break;
			case BASAL_INSULIN:
				outFile << "Basal Insulin,";
				break;
			case GLUCAGON:
				outFile << "Glucagon,";
				break;
		}
		outFile << it->getHormoneDose().getHormoneAmount() << endl;
	}
	outFile.close();
}

