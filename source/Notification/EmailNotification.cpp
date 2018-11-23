/*!
	@author Veronica Witzig
	Purpose: Responsible for sending email notifications to gmail accounts
*/

#include "EmailNotification.h"

using namespace std;

/*!
	Name: EmailNotification
	Description: constructor
*/
EmailNotification::EmailNotification(PatientInfo patientInfo)
{
	EmergencyContact emergContact = patientInfo.getEmergencyContact();
	senderEmail = patientInfo.getEmail();
	emailPassword = patientInfo.getEmailPassword();
	recipientEmail = emergContact.getEmail();
};

/*!
	Name: ~EmailNotification
	Description: destructor
*/
EmailNotification::~EmailNotification() {};

/*!
	Name: SendEmail
	Description: sends an email from the sender's addredd to the recipient's address, assumes the sender has a gmail account
	@param string senderEmail - sender's email address
	@param string recipientEmail - password for the email account
	@param string emailPassword - recpient's email address
*/
void EmailNotification::SendEmail(string senderEmail, string recipientEmail, string emailPassword)
{
<<<<<<< HEAD
	cout << "Sending email to: " << recpientEmail << endl;
	string command = "curl --url \'smtps://smtp.gmail.com:465\' --ssl-reqd --mail-from \'" + senderEmail + "\' --mail-rcpt \'" + recipientEmail + "\' --upload-file email.txt --user \'" + senderEmail + ":" + emailPassword + "\'";
	sys(command);	
=======
	cout << "Sending email";
	
	"curl --url \'smtps://smtp.gmail.com:465\' --ssl-reqd --mail-from \'noah123body@gmail.com\' --mail-rcpt \'receiver@gmail.com\' --upload-file email.txt --user \'noah123body@gmail.com:pass123word\'";
>>>>>>> 615d18b0b3b03fd2654db9ebd7646ca7652e08cd
};
