/*!
	Group: 22
	Purpose: Header file for the Guest Account class
*/

#ifndef GUEST_ACCOUNT_H
#define GUEST_ACCOUNT_H

#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "AccountType.h"

class GuestAccount : public AccountType
{	
public:	
	void printOptions();
};

#endif
