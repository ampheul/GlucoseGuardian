/*
	Group: 22
	Purpose: Header file for the Account class
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

class Account
{	
public:	
	Account();
	~Account();
	void accountOptions();
	std::string GetAccountType();

private:
	const std::string PATIENT_ACCOUNT = "Patient";							//! represents account type of Patient
	const std::string GUEST_ACCOUNT = "Guest";								//! represents account type of Guest
	const std::string UNKNOWN_ACCOUNT = "Unknown";							//! represents account type of Unknown
	
	const std::string ACCOUNT_INFO_PATH = "/accountInfo/accountInfo.txt"; 	//! path to directory for storing accountInfo.txt
	const std::string ACCOUNT_INFO = "accountInfo.txt";						//! file name for storing account information

	std::string accountType;												//! the type of the account
	DIR *accountDir;														//! pointer to accountInfo directory

	void VerifyPassword(std::ifstream& hashStream, std::string password);
	std::size_t HashPassword(std::string password);
	void InitializeAccount(std::string password);
};

#endif
