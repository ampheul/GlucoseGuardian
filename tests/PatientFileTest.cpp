#include "PatientInfo.h"
#include "FileManager.h"

int main()
{
    PatientInfo *p;
    FileManager *fm = new FileManager();
    if(fm->checkForPatientFile())
    {
        try
        {
        p = fm->readFromFile();
        p->getMonitorRecords()->push_back(MonitorRecord(std::time(NULL), GlucoseReading(17.0)));
        p->getMedicationRecords()->push_back(MedicationRecord(std::time(NULL), HormoneDose(BASAL_INSULIN, 17)));
        }
        catch(std::bad_alloc &ba)
        {
            std::cout << "1" << std::endl;
        }
    }
    else
    {
        try
        {
            p = new PatientInfo();
        }
        catch(std::bad_alloc &ba)
        {
            std::cout << "2" << std::endl;
        }
        
    }
    fm->writeToFile(p);
    delete p;

    return 0;
}
