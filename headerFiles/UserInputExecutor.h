/*
	Group: 22
	Purpose: Header file for the Account class
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
	ArtificialPancreas artificialPancreas;
	void QuitProgram();
	void MedicalHistory();
	void CurrentGlucose();
	void ManualGlucoseEntry();
	void ManualInsulinAdministration();
};

#endif
