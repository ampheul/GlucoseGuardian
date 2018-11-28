/*!
	Group: 22
	Purpose: Contains statistics about the patient and his/her emergency contact information
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
	/*!
		@name PatientInfo
		Description: constructor
	*/

	PatientInfo();
	PatientInfo(
		std::string name,
		int age,
		std::string sex,
		double weight,
		double height,
		std::string email
		);
	~PatientInfo();
	
	/*!
	@name getWeight
	Description: gets the patient's weight
    */
	double getWeight();

	/*!
	@name setWeight
	Description: sets the patient's weight
	@param Weight - patient's weight to set
    */
	void setWeight(double weight);
	
	/*!
	@name getHeight
	Description: gets the patient's height
    */
	double getHeight();

	/*!
	@name setHeight
	Description: sets the patient's height
	@param height - patient's height to set
	*/
	void setHeight(double height);
	
	/*!
	@name getAge
	Description: gets the patient's age
    */
	int getAge();

	/*!
	@name setAge
	Description: sets the patient's age
	@param Weight - patient's age to set
	*/
	void setAge(double age);
	
	/*!
	@name getEmail
	Description: gets the patient's email
    */
	std::string getEmail();

	/*!
	@name setEmail
	Description: sets the patient's email
	@param email - patient's email to set
	*/
	void setEmail(std::string email);
	
	/*!
	@name getEmailPassword
	Description: gets the patient's email's password
    */
	std::string getEmailPassword();

	/*!
	@name setEmailPassword
	Description: sets the patient's email password for the purpose of 
	sending emails.
	@param password - patient's email to set
	*/
	void setEmailPassword(std::string password);

	/*!
	@name getSex
	Description: gets the patient's sex as a string
    */
	string getSex();

	/*!
	@name setSex
	Description: sets the patient's sex
	@param sex - patient's sex to set
	*/
	void setSex(string sex);
	
	/*!
	@name getCarbs
	Description: gets the grams of carbs the patient has eaten in his/her last meal
    */
	double getCarbs();

	/*!
	@name setCarbs
	Description: sets the patient's carbs
	@param carbs - patient's email to set
	*/
	void setCarbs(double carbs);
	
	/*!
	@name getExercise
	Description: gets the patient's exercise (low, medium, or high)
    */
	string getExercise();

	/*!
	@name setExercise
	Description: sets the patient's exercise (low, medium or high)
	@param exercise - patient's exercise to set
	*/
	void setExercise(string exercise);
	
	/*!
	@name getSleep
	Description: gets the patient's sleep in hours
    */
	int getSleep();

	/*!
	@name setSleep
	Description: sets the patient's sleep in hours
	@param sleep - patient's sleep to set
	*/
	void setSleep(int sleep);

	/*!
	@name getEmergencyContact
	Description: gets the patient's emergency contact as a Contact type
    */
	Contact* getEmergencyContact();

	/*!
	@name setEmergencyContact
	Description: sets the patient's emergency contact
	@param contact - patient's contact set
	*/
	void setEmergencyContact(Contact* contact);
	
	/*!
	@name getMonitorRecords
	Description: gets the patient's monitor records
    */
	vector<MonitorRecord> *getMonitorRecords();

	/*!
	@name getMedicationRecords
	Description: gets the patient's administered medication records
    */
	vector<MedicationRecord> getMedicationRecords();
	
	/*!
	@name SetupPatientInfo
	Description: prompts user for all required bio-statistics
    */
	void SetupPatientInfo();

	/*!
	@name readFromFile
	Description: deserializes patient.txt data obtained from previous artificial
	pancreas sessions and stores it in the current session
    */
	void readFromFile();

	/*!
	@name writeToFile
	Description: serializes the monitor and medication records into the patient.txt file
    */
	void writeToFile();

	/*!
	@name getName
	Description: gets the patient's name
    */
	std::string getName();
	
private:
	/// patient's weight
	double weight;

	/// patient's height
	double height;

	/// patient's bmi
	double bmi;

	/// patient's carbs
	double carbs;

	/// patient's hormone dose
	double amount;
	
	/// patient's age
	int age;

	/// patient's sleep
	int sleep;
	
	/// patient's sex
	string sex;

	/// patient's email
	string email;

	/// patient's email password
	string emailPassword;

	/// patient's exercise
	string exercise;

	/// patient's name
	string name;

	/// monitor records for the patient
	vector<MonitorRecord> *monitorRecords;

	/// medication records for the patient
	vector<MedicationRecord> *medicationRecords;

	/// patient's emergency contact
	Contact* emergencyContact;


	fstream iofile;
	string input, delimiter;
	time_t time;
	size_t pos;

	HormoneDose *dose;
	hormoneType type;

	string toEnum;
	
	/// glucose reading
	GlucoseReading *tmpReading;

	/// contains dose information for the patient
	MonitorRecord *tmpMonitor;

	/// medication record for the patient
	MedicationRecord *tmpRecord;
};

#endif
