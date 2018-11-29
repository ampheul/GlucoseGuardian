#include "PatientInfo.h"
#include "FileManager.h"

int main()
{
    PatientInfo *p = new PatientInfo();
    FileManager *fm = new FileManager();
    p->getMonitorRecords()->push_back(MonitorRecord(std::time(NULL), GlucoseReading(15.0)));
    p->getMedicationRecords()->push_back(MedicationRecord(std::time(NULL), HormoneDose(BASAL_INSULIN, 5)));
    fm->writeToFile(p);
    delete p;

    return 0;
}
