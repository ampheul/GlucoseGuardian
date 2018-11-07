#ifndef MONITORRECORD_H
#define MONITORRECORD_H

#include "DeviceRecord.h"
#include "GlucoseReading.h"

class MonitorRecord : DeviceRecord
{
    public:
        MonitorRecord(std::time_t time, GlucoseReading reading);
        GlucoseReading getReading() const;
    private:
        const GlucoseReading reading;
};

#endif
