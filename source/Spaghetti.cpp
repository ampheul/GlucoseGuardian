#include "Spaghetti.h"

PatientInfo* Spaghetti::makePatient()
{
    std::string name = "Tortellini Linguini";
    std::string sex = "sphaghettini";
    int age = 41;
    double weight = 741;
    double height = 167;
    std::string email = "pastafarianPrincess@ragu.fart";

    PatientInfo* patient = new PatientInfo(name, age, sex, weight, height, email);

    std::vector<MonitorRecord> *records = patient->getMonitorRecords();
    
    std::ifstream dataStream("base/patientData/glucose23340.dat");
    std::cerr << "here" << std::endl;
    std::time_t timeSetting = std::time(NULL) -24*60*60;
    
    while (!dataStream.eof())
    {
        double hour = 0;
        double glucose = 0;
        dataStream >> hour >> glucose;
        
        std::time_t time = (std::time_t)(timeSetting + hour*60*60);

        records->push_back(MonitorRecord(time, glucose));
            std::cerr << "here" << std::endl;

    }

    return patient;
}