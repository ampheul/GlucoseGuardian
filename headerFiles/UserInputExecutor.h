/*!
	@author Veronica Witzig
	Purpose: Header file for the UserInputExecutor class
*/

#ifndef USER_INPUT_EXECUTOR_H
#define USER_INPUT_EXECUTOR_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include "ArtificialPancreas.h"
#include "ReportMaker.h"

class UserInputExecutor
{	
public:	
	UserInputExecutor(ArtificialPancreas artificialPancreas);
	~UserInputExecutor();
	void MenuSwitch();
	
private:
	const int MINIMUM_CARBS = 0;				//! The minimum number of carbs allowed for user input
	const int MAXIMUM_CARBS = 1250;				//! The maximum number of carbs allowed for user input

	ArtificialPancreas artificialPancreas;
	
	void quitProgram();
	void medicalHistory();
	void currentGlucose();
	void manualGlucoseEntry();
	void manualInsulinAdministration();

	void updateCarbsExerciseSleep();
	void updatePatientInfoCarbs(PatientInfo patientInfo);
	void updatePatientInfoExercise(PatientInfo patientInfo);
	void updatePatientInfoSleep(PatientInfo patientInfo);
};

#endif
