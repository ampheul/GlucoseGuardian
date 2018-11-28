/*!
	@author Graeme Brabers
	Responsible for managing patient info and determining insulin administration for the patient
*/

#include "ArtificialPancreas.h"

/*!
	@name ArtificialPancreas
	@purpose constructor
*/
ArtificialPancreas::ArtificialPancreas()
{
    user = new PatientInfo();
    output = new LaptopOutput("127.0.0.1", 3307);
    //email = new EmailNotification(user);
}

/*!
	@name ~ArtificialPancreas
	@purpose destructor
*/
ArtificialPancreas::~ArtificialPancreas()
{
    delete user;
    delete output;
}

/*!
	@name setPatient
	@purpose sets user
	@param *newPatient - patient info to set
*/
void ArtificialPancreas::setPatient(PatientInfo *newPatient)
{
    user = newPatient;
}

/*!
	@name getPatientInfo
	@purpose gets the patient info
	@return the patient info
*/
PatientInfo * ArtificialPancreas::getPatientInfo()
{
    return user;
}

/*!
	@name calculateMedication
	@purpose calculates the medication needed for the patient based on their glucose reading
	@param reading - the glucose reading
*/
void ArtificialPancreas::calculateMedication(const double reading)
{
    if(reading > 1.7 && reading < 40)
    {
        //user->getRecordEntries.push_back(new MonitorRecord(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()), reading));        
        if(reading < 2.8)
        {
            //email->sendHypoglycemicEventEmail();
        }
        calculator = new MedicationCalculator(reading, user, "Basal");
        dose = calculator->computeDosage();
        
        //user->getRecordEntries.push_back(new MedicationRecord(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()), dose));
        output->sendInstruction(dose);
        delete dose;
        delete calculator;
    }
    else
    {
        std::cout << "Error: invalid glucose measurement submitted" << std::endl;
    }
}

/*!
	@name manuallyAdministerInsulin
	@purpose administers the amount of insulin to the patient
	@param insulinAmount - the insulin amount to administer
*/
void ArtificialPancreas::manuallyAdministerInsulin(const double insulinAmount)
{
	dose = new HormoneDose(BOLUS_INSULIN, insulinAmount);
	output->sendInstruction(dose);
    delete dose;
}

*MedicationCalculator ArtificialPancreas::getCalculator()
{
	return calculator
}
