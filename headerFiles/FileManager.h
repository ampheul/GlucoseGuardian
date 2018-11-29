#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Contact.h"
#include "DeviceRecord.h"
#include "HormoneDose.h"
#include "MedicationRecord.h"
#include "MonitorRecord.h"
#include "PatientInfo.h"

class FileManager
{
    public:
        FileManager();
        ~FileManager();
        bool checkForPatientFile();
        PatientInfo * readFromFile();
        void writeToFile(PatientInfo *);
    private:
        ifstream inFile;
        ofstream outFile;
};

#endif
