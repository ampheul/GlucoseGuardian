#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "PatientInfo.h"
#include "Contact.h"
#include "DeviceRecord.h"
#include "HormoneDose.h"
#include "MedicationRecord.h"
#include "MonitorRecord.h"

class FileManager
{
    public:
        FileManager(const PatientInfo*);
        ~FileManager();
        bool checkForPatientFile();
        void readFromFile();
        void writeToFile();
    private:
        const PatientInfo *user;
        ifstream inFile;
        ofstream outFile;
};

#endif
