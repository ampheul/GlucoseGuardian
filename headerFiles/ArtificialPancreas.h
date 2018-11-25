#include "MedicationCalculator.h"
#include "Patient.h"
#include "InsulinPump.h"
#include "LaptopOutput.h"
#include "HormoneDose.h"

class ArtificialPancreas
{
    private:
        Patient *user;
        MedicationCalculator *calculator;
        InsulinPump *output;
        HormoneDose *dose;
    public:
        ArtificialPancreas();
        ~ArtificialPancreas();
        void setPatient(const Patient *);
        Patient getPatient() const;
        void calculateMedication(const double);
};