#include "MedicationCalculator.h"
#include "PatientInfo.h"
#include "InsulinPump.h"
#include "LaptopOutput.h"
#include "HormoneDose.h"

class ArtificialPancreas
{
    private:
        PatientInfo *user;
        MedicationCalculator *calculator;
        InsulinPump *output;
        HormoneDose *dose;
    public:
        ArtificialPancreas();
        ~ArtificialPancreas();
        void setPatient(const PatientInfo *);
        PatientInfo getPatientInfo() const;
        void calculateMedication(const double);
		void manuallyEnterGlucose(const double);
		void manuallyAdministerInsulin(const double);
};
