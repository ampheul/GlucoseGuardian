#ifndef REPORTMAKER_H
#define REPORTMAKER_H

#include "GraphMaker.h"
#include "PatientInfo.h"

/** Makes Reports

afsadsafds
*/
class ReportMaker
{
    public:
        void makeReport();
    private:
        GraphMaker graphMaker;
        PatientInfo patient;
};

#endif