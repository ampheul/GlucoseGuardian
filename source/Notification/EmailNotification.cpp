/*!
	@author Veronica Witzig
	Purpose: Responsible for sending email notifications
*/

#include "EmailNotification.h"

using namespace std;

/*!
	Name: EmailNotification
	Description: constructor
*/
EmailNotification::EmailNotification()
{
};

/*!
	Name: ~EmailNotification
	Description: destructor
*/
EmailNotification::~EmailNotification() {};

/*!
	Name: SendEmail
	Description: sends an email to the user's email
	@param string password - password for the email account
*/
void EmailNotification::SendEmail(string password)
{
	cout << "Sending email";
	
	"curl --url \'smtps://smtp.gmail.com:465\' --ssl-reqd --mail-from \'noah123body@gmail.com\' --mail-rcpt \'receiver@gmail.com\' --upload-file email.txt --user \'noah123body@gmail.com:pass123word\'";
};
