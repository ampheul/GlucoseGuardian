#include "ArtificialPancreas.h"

ArtificialPancreas::ArtificialPancreas()
{
    user = new PatientInfo();
    output = new LaptopOutput("127.0.0.1", 3307);

}

ArtificialPancreas::~ArtificialPancreas()
{
    delete user;
    delete output;
}

void ArtificialPancreas::setPatient(const PatientInfo *newPatient)
{
    user = newPatient();
}

PatientInfo ArtificialPancreas::getPatientInfo() const
{
    return user;
}

void ArtificialPancreas::calculateMedication(const double reading)
{
    user->getRecordEntries.push_back(new MonitorRecord(std::chrono::system_clock::now(), reading));
    //calculator = new MedicationCalculator(reading, user, ...);
    dose = calculator->computeDosage();
    //Update patient record with hormonedose
    user->getRecordEntries.push_back(new MedicationRecord(std::chrono::system_clock::now(), dose));
    output->sendInstruction(dose);
    delete dose;
    delete calculator;
}

//unnecessary?
void ArtificialPancreas::manuallyEnterGlucose(const double gluToAdmin)
{

	//calculator = new MedicationCalculator(reading, user, ...)
    dose = calculator->computeDosage();
    user->getRecordEntries.push_back(new MedicationRecord(std::chrono::system_clock::now(), dose));
    output->sendInstruction(dose);
    delete dose;
    delete calculator;
}

void ArtificialPancreas::manuallyAdministerInsulin(const double insulinAmount)
{
	HormoneDose dose = new HormoneDose(BOLUS_INSULIN, insulinAmount);
	output->sendInstruction(dose);
    delete dose;
}
