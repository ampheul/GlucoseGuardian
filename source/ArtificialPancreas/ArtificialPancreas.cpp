#include "ArtificialPancreas.h"

ArtificialPancreas::ArtificialPancreas()
{
    //TODO: Need final implementation of patient file to construct patient and submit data to medicationcalculator
    user = new Patient();
    output = new LaptopOutput("127.0.0.1", 3307);

}

ArtificialPancreas::~ArtificialPancreas()
{
    delete user;
    delete output;
}

void ArtificialPancreas::setPatient(const Patient *newPatient)
{
    //Need final implementation of patient to complete;
    user = newPatient();
}

Patient ArtificialPancreas::getPatient() const
{
    return user;
}

void ArtificialPancreas::calculateMedication(const double reading)
{
    //Need final patient implementation to complete
    //Update patient record with glucose measurement
    calculator = new MedicationCalculator(amount, user, , , , );
    dose = calculator->computeDosage();
    //Update patient record with hormonedose
    output->sendInstruction(dose);
    delete dose;
    delete calculator;
}

void ArtificialPancreas::manuallyEnterGlucose(const double gluToAdmin)
{
	// calculator = new MedicationCalculator(amount, user, ...);
}

void ArtificialPancreas::manuallyAdministerInsulin(const double insulinAmount)
{
	HormoneDose dose = new HormoneDose(BOLUS_INSULIN, insulinAmount);
	output->sendInstruction(dose);
}
