#ifndef GLUCOSEMONITOR_H
#define GLUCOSEMONITOR_H

#include "MonitorRecord.h"
#include "Publisher.h"

class GlucoseMonitor : Publisher<MonitorRecord>
{
    public:
        void start();
    private:
        virtual void background() = 0;
};

#endif