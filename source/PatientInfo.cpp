/**
*	\author Naeem Budwhani and Graeme Brabers
*	\brief Contains statistics about the patient and his/her emergency contact information
*/

#include "PatientInfo.h"

/// implicit constructor
PatientInfo::PatientInfo()
{
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

/// constructor, expects patient info data
PatientInfo::PatientInfo(
	string name,
	int age,
	string sex,
	double weight,
	double height,
	string email
	):
	name(name),
	age(age),
	sex(sex),
	weight(weight),
	height(height),
	email(email)
{
	this->monitorRecords = new vector<MonitorRecord>;
	this->medicationRecords = new vector<MedicationRecord>;
}

/// destructor
PatientInfo::~PatientInfo()
{
	writeToFile();
}

/// gets the patient info weight
double PatientInfo::getWeight()
{
	return weight;
}

/// sets the patient info weight
void PatientInfo::setWeight(double Weight)
{
	this->weight = weight;
}

/// gets the patient info height
double PatientInfo::getHeight()
{
	return height;
}

/// sets the patient info height
void PatientInfo::setHeight(double height)
{
	this->height = height;
}

/// gets the patient info age
int PatientInfo::getAge()
{
	return age;
}

/// sets the patient info age
void PatientInfo::setAge(double age)
{
	this->age = age;
}

/// gets the patient info sex
string PatientInfo::getSex()
{
	return sex;
}

/// sets the patient info sex
void PatientInfo::setSex(string sex)
{
	this->sex = sex;
}

/// gets the patient info carb intake
double PatientInfo::getCarbs()
{
	return carbs;
}

/// sets the patient info carb intake
void PatientInfo::setCarbs(double carbs)
{
	this->carbs = carbs;
}

/// gets the patient info exercise
string PatientInfo::getExercise()
{
	return exercise;
}

/// sets the patient info exercise
void PatientInfo::setExercise(string exercise)
{
	this->exercise = exercise;
}

/// gets the patient info sleep
int PatientInfo::getSleep()
{
	return sleep;
}

/// sets the patient info sleep
void PatientInfo::setSleep(int sleep)
{
	this->sleep = sleep;
}

/// gets the emergency contact of the patient
Contact* PatientInfo::getEmergencyContact()
{
	return emergencyContact;
}

/// sets the emergency contact of the patient
void PatientInfo::setEmergencyContact(Contact* contact)
{
	this->emergencyContact = contact;
}

/// gets the patient info name
std::string PatientInfo::getName()
{
	return this->name;
}

/// gets the patient info email
string PatientInfo::getEmail() {
	return this->email;
}

/// sets the patient info email
void PatientInfo::setEmail(std::string email)
{
	this->email = email;
}

/// gets the patient info email password
string PatientInfo::getEmailPassword() {
	return this->emailPassword;
}

/// sets the patient info email password
void PatientInfo::setEmailPassword(std::string emailPassword)
{
	this->emailPassword = emailPassword;
}

/// gets the monitor records
vector<MonitorRecord> * PatientInfo::getMonitorRecords()
{
	return monitorRecords;
}

/// gets the medication records
vector<MedicationRecord> * PatientInfo::getMedicationRecords()
{
	return medicationRecords;
}

/// fetches th patient info stored in patient.txt
void PatientInfo::SetupPatientInfo()
{
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

/// reads the patient info file
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

/// writes to the patient info file
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
