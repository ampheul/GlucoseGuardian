/**
*	\author Veronica Witzig
*	Responsible for sending email notifications to gmail accounts
*/

#include "EmailNotification.h"

using namespace std;

/**
*	\name EmailNotification
*	constructor
*/
EmailNotification::EmailNotification(PatientInfo *patientInfo)
{
	Contact* emergContact = patientInfo->getEmergencyContact();
	senderEmail = patientInfo->getEmail();
	emailPassword = patientInfo->getEmailPassword();
	recipientEmail = emergContact->getEmail();
	
	/// curl needs the direct path for the email template, grab it now
	// ... using commands that work on the pi.
	// hint the working directory is usually just group22
	currentWorkingDirectory = "";
};

/**
*	\name ~EmailNotification
*	destructor
*/
EmailNotification::~EmailNotification() {};

/**
*	\name sendHypoglycemicEventEmail
*	sends an email from the patient's email to themself to warn the patient that a hypoglycemic event may occur,
*	assumes the sender has a gmail account
*/
void EmailNotification::sendHypoglycemicEventEmail()
{
	EmailNotification::sendEmail(senderEmail, senderEmail, emailPassword, UNAUTHORIZED_ACCESS_EMAIL_TEMPLATE);
};

/**
*	\name sendUnauthorizedAccessEmail
*	sends an email from the patient's email to themself to warn the patient that an unauthorized user has 
*	attempted to log into their account, assumes the sender has a gmail account
*/
void EmailNotification::sendUnauthorizedAccessEmail()
{
	EmailNotification::sendEmail(senderEmail, recipientEmail, emailPassword, HYPOGLYCEMIC_EVENT_EMAIL_TEMPLATE);
};

/**
*	\name sendEmergencyContactEmail
*	sends an email from the patient's email to their emergency contact to notify the guardiam that a 
*	hypoglycemic event has occured, assumes the sender has a gmail account
*/
void EmailNotification::sendEmergencyContactEmail()
{
	EmailNotification::sendEmail(senderEmail, recipientEmail, emailPassword, EMERGENCY_CONTACT_EMAIL_TEMPLATE);
};

/**
*	\name sendEmergencyContactEmail
*	sends an email from the patient's email to their own email to notify them that a guardiam has
*	requested to see their medical records
*/
void EmailNotification::sendMedicalRequestEmail()
{
	EmailNotification::sendEmail(senderEmail, recipientEmail, emailPassword, REQUEST_MEDICAL_RECORDS_EMAIL_TEMPLATE);
};

/**
*	\name SendEmail
*	sends an email from the sender's address to the recipient's address, assumes the sender has a gmail account
*	\param string senderEmail - sender's email address
*	\param string recipientEmail - recipient's email address
*	\param string emailPassword - password for the email account
*/
void EmailNotification::sendEmail(string senderEmail, string recipientEmail, string emailPassword, string emailTemplate)
{
	/// curl needs a direct path to point to the email template
	emailTemplate = emailTemplate + currentWorkingDirectory;
	
	cout << "Sending email to: " << recipientEmail << endl;
	string command = "curl --url \'smtps://smtp.gmail.com:465\' --ssl-reqd --mail-from \'" + senderEmail + "\' --mail-rcpt \'" + recipientEmail + "\' --upload-file" + emailTemplate + "--user \'" + senderEmail + ":" + emailPassword + "\'";
	
	/// system() expects a const char[]*
	const char* commandToChar = command.c_str();
	system(commandToChar);
	cout << "Email sent" << endl;
};
