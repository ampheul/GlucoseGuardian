#ifndef INSULINPUMP_H
#define INSULINPUMP_H


#include "Subscriber.h"
#include "Publisher.h"
#include "HormoneDose.h"
#include "MedicationRecord.h"

class InsulinPump : Subscriber<HormoneDose>, Publisher<MedicationRecord>
{
    public:
        void applyDose(const HormoneDose dose);
};

#endif
