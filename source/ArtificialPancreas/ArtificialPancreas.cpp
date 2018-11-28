#include "ArtificialPancreas.h"

ArtificialPancreas::ArtificialPancreas()
{
    user = new PatientInfo();
    output = new LaptopOutput("127.0.0.1", 3307);
    //email = new EmailNotification(user);
}

ArtificialPancreas::~ArtificialPancreas()
{
    delete user;
    delete output;
}

void ArtificialPancreas::setPatient(PatientInfo *newPatient)
{
    user = newPatient;
}

PatientInfo * ArtificialPancreas::getPatientInfo()
{
    return user;
}

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

void ArtificialPancreas::manuallyAdministerInsulin(const double insulinAmount)
{
	dose = new HormoneDose(BOLUS_INSULIN, insulinAmount);
	output->sendInstruction(dose);
    delete dose;
}
