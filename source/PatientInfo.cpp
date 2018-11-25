using "PatientInfo.h"

PatientInfo::Patient() {
	SetupPatientInfo();
}

PatientInfo::~Patient() {
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

double PatientInfo::getAge() {
	return this->age;
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

vector<DeviceRecord> PatientInfo::getRecordEntries() {
	return recordEntryList;
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

	// Set up emergency contact
	cout << "What is the name of your emergency contact?";
	string emergContactName;
	cin >> emergContactName;

	Contact emergContact(emergContactName);
}

bool PatientInfo::verifyPassword(string givenPassword) {
	return this->password == givenPassword;
}
};

#endif