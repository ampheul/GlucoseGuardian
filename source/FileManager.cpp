#include "FileManager.h"

FileManager::FileManager(PatientInfo *patient)
{
    user = patient;
}

bool FileManager::checkForPatientFile()
{
    inFile.open("patient.txt");
    if(inFile.is_open())
    {
        inFile.close();
        return true;
    }
    return false;
}

void FileManager::readFromFile()
{
    inFile.open("patient.txt");
	std::string name, sex, email, emailPassword, emergName, emergEmail;
    double weight, height;
    int age;
	inFile >> name >> weight >> height >> age  >> sex >> email >> emailPassword >> emergName >> emergEmail;
    user->setName(name);
    user->setWeight(weight);
    user->setHei(height);
    user->setAge(age);
    user->setSex(sex);
    user->setEmail(email);
    user->setEmailPassword(emailPassword);
	Contact *emergencyContact = new Contact(emergName, emergEmail);
    user->setEmergencyContact(emergencyContact);
	
    std::string input, toEnum, delmiiter = ",";
    time_t time;
    size_t pos;
    double amount;
    HormoneDose *dose;

	getline(inFile, input);
	while(getline(inFile, input) && input != "-----")
	{
		pos = input.find(delimiter);
		time = (time_t)stol(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
		GlucoseReading *tempGlucose = new GlucoseReading(stod(input));
		MonitorRecord *tempMonitor = new MonitorRecord(time, *tempGlucose);
		user->getMonitorRecords()->push_back(*tempMonitor);
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
		user->getMedicationRecords()->push_back(*temp);
		delete dose;
		delete temp;
	}
    inFile.close();
}

void FileManager::writeToFile()
{
	outFile.open("patient.txt", ios::trunc);
	outFile << user->getName() << std::endl;
	outFile << user->getWeight() << std::endl;
	outFile << user->getHeight() << std::endl;
	outFile << user->getAge() << std::endl;
	outFile << user->getSex() << std::endl;
	outFile << user->getEmail() << std::endl;
	outFile << user->getEmailPassword() << std::endl;
    outfile << user->getEmergencyContact()->getName() << std::endl;
    outfile << user->getEmergencyContact()->getEmail() << std::endl; 

	for(vector<MonitorRecord>::iterator it = user->getMonitorRecords()->begin(); it != user->getMonitorRecords->end(); ++it)
	{
		outFile << it->getRecordTime() << ",";
		outFile << it->getReading().getAmount() << endl;
	}
	outFile << "-----" << endl;
	for(vector<MedicationRecord>::iterator it = user->getMedicationRecords->begin(); it != user->getMedicationRecords->end(); ++it)
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
		outFile << it->getHormoneDose().getHormoneAmount() << std::endl;
	}
	outFile.close();
}
