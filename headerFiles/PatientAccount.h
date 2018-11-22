/*
	Group: 22
	Purpose: Header file for the Patient Account class
*/

#ifndef PATIENT_ACCOUNT_HEADER
#define PATIENT_ACCOUNT_HEADER

#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "AccountType.h"

class PatientAccount : public AccountType
{	
public:	
	void printOptions();
};

#endif
