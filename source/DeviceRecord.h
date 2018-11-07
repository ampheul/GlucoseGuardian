#ifndef DEVICERECORD_H
#define DEVICERECORD_H

#include <ctime>

class DeviceRecord
{
    public:
        DeviceRecord(std::time_t time);
        std::time_t getRecordTime() const;
    private:
        const std::time_t recordTime;
};

#endif
