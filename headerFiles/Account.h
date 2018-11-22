/*
	Group: 22
	Purpose: Header file for the Account class
*/

#ifndef ACCOUNT_HEADER
#define ACCOUNT_HEADER

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include "AccountType.h"

class Account
{	
public:	
	Account();
	~Account();
	void accountOptions();
	AccountType getAccountType();

private:
	const std::string ACCOUNT_INFO_PATH = "/accountInfo/accountInfo.txt"; 	//! path to directory for storing accountInfo.txt
	const std::string ACCOUNT_INFO = "accountInfo.txt";						//! file name for storing account information

	AccountType accountType;												//! the type of the account
	DIR *accountDir;														//! pointer to accountInfo directory

	void VerifyPassword(std::ifstream& hashStream, std::string password);
	std::size_t HashPassword(std::string password);
	void InitializeAccount(std::string password);
};

#endif
