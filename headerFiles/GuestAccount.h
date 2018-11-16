/*!
	Group: 22
	Purpose: Header file for the Guest Account class
*/

#ifndef GUEST_ACCOUNT_HEADER
#define GUEST_ACCOUNT_HEADER

#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "AccountType.h"

class GuestAccount : AccountType
{	
public:	
	void PrintOptions();
};

#endif
