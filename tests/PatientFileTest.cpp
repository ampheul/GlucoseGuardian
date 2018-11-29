#include "PatientInfo.h"

int main()
{
    PatientInfo *p = new PatientInfo();
    p->getMonitorRecords()->push_back(MonitorRecord(std::time(NULL), GlucoseReading(15.0)));
    p->getMedicationRecords()->push_back(MedicationRecord(std::time(NULL), HormoneDose(BASAL_INSULIN, 5)));
    delete p;

    return 0;
}
