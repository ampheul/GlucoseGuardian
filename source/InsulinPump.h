#ifndef INSULINPUMP_H
#define INSULINPUMP_H


#include "Subscriber.h"
#include "Publisher.h"
#include "HormoneDose.h"
#include "MedicationRecord.h"

// Insulin pump will receive HormoneDoses from the artificial pancreas
// Insulin pump may publish Medication Records after administering.

class InsulinPump : Subscriber<HormoneDose>, Publisher<MedicationRecord>
{
    public:
        void applyDose(const HormoneDose dose);
};

#endif
