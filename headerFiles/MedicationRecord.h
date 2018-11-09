#ifndef MEDICATIONRECORD_H
#define MEDICATIONRECORD_H

#include "DeviceRecord.h"
#include "HormoneDose.h"
#include "HormoneType.h"

class MedicationRecord : DeviceRecord
{
    public:
        MedicationRecord(const std::time_t time, const HormoneDose dose);
        HormoneDose getHormoneDose() const;
    private:
        const HormoneDose hormoneDose; 
};

#endif
