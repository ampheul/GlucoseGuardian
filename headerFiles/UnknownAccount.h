/*
	Group: 22
	Purpose: Header file for the Unknown Account class
*/

#ifndef UNKNOWN_ACCOUNT_HEADER
#define UNKNOWN_ACCOUNT_HEADER

#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "AccountType.h"

class UnknownAccount : public AccountType
{	
public:	
	void printOptions();
};

#endif
