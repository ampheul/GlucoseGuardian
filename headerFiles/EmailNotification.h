/*
	@author Veronica Witzig
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
#include "PatientInfo.h"

class EmailNotification
{
public:	
	EmailNotification(PatientInfo *patientInfo);
	~EmailNotification();
	void sendUnauthorizedAccessEmail();
	void sendHypoglycemicEventEmail();
	void sendEmergencyContactEmail();
	void sendMedicalRequestEmail();

private:
	const std::string UNAUTHORIZED_ACCESS_EMAIL_TEMPLATE = "unauthorized_email.txt";		//! email template for an unauthorized access
	const std::string HYPOGLYCEMIC_EVENT_EMAIL_TEMPLATE = "hypoglycemic_email.txt";			//! email template for a hypoglycemic event
	const std::string EMERGENCY_CONTACT_EMAIL_TEMPLATE = "emergency_email.txt";				//! email template for sending to an emergency contact
	const std::string REQUEST_MEDICAL_RECORDS_EMAIL_TEMPLATE = "request_records_email.txt";	//! email template for when a request for the patient's records has been made

	std::string senderEmail;
	std::string emailPassword;
	std::string recipientEmail;

	void SendEmail(std::string senderEmail, std::string recipientEmail, std::string emailPassword, std::string emailTemplate);
};

#endif
