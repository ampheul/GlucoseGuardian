#ifndef FMAN_H
#define FMAN_H

#include "PatientInfo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Contact.h"
#include "DeviceRecord.h"
#include "HormoneDose.h"
#include "MedicationRecord.h"
#include "MonitorRecord.h"

class FileManager
{
    private:
        PatientInfo *user;
        ifstream inFile;
        ofstream outFile;
    public:
        FileManager(PatientInfo *);
        ~FileManager();
        bool checkForPatientFile();
        void readFromFile();
        void writeToFile();
};

#endif
