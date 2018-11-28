/**
*	\author Veronica Witzig
*	Header file for the Account class
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

class Account
{	
public:	
	/// constructor
	Account();
	
	/// desrtuctor
	~Account();
	
	/// returns the type of the account, either "Patient", "Guest", or "Unknown"
	std::string getAccountType();
	/// represents account type of Patient
	const std::string PATIENT_ACCOUNT = "Patient";

	/// represents account type of Guest
	const std::string GUEST_ACCOUNT = "Guest";

	/// represents account type of Unknown
	const std::string UNKNOWN_ACCOUNT = "Unknown";

	/// path to directory for storing accountInfo.txt
	const std::string ACCOUNT_INFO_PATH = "/accountInfo/accountInfo.txt";

	/// file name for storing account information
	const std::string ACCOUNT_INFO = "accountInfo.txt";	

private:
						

	/// the type of the account
	std::string accountType;

	/// confirms if the password matches the locally stored hashed password
	void verifyPassword(std::ifstream& hashStream, std::string password);

	/// returns the hash of a password
	std::size_t hashPassword(std::string password);
	
	/// prompts the user to set a password and guest password
	void initializeAccount(std::string password);
};

#endif
