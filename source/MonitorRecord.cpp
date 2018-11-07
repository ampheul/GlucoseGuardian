#include "MonitorRecord.h"
MonitorRecord::MonitorRecord(
    const std::time_t time, 
    const GlucoseReading reading) 
        :   DeviceRecord(time), reading(reading)
{}

const GlucoseReading MonitorRecord::getReading() const
{
    return this->reading;
}