/*
	Group: 22
	Purpose: Header file for the EmailNotification class
*/

#ifndef EMAIL_NOTIFICATION_HEADER
#define EMAIL_NOTIFICATION_HEADER

#include <string>
#include <iostream>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include "EmailNotification.h"

class EmailNotification
{	
public:	
	EmailNotification(PatientInfo patientInfo);
	~EmailNotification();
	const std::string EMAIL_COMMAND = "curl --url \'smtps://smtp.gmail.com:465\' --ssl-reqd --mail-from \'noah123body@gmail.com\' --mail-rcpt \'receiver@gmail.com\' --upload-file email.txt --user \'noah123body@gmail.com:pass123word\'";

private:
	std::string senderEmail = patientInfo.getEmail();
	std::string emailPassword = patientInfo.getEmailPassword();
	std::string recipientEmail = emergContact.getEmail();

	const std::string EMAIL_TEMPLATE = "email.txt";							//! email template file when sending emails

	void SendEmail(std::string senderEmail, std::string recipientEmail, std::string emailPassword);
};

#endif
