#ifndef REPORTMAKER_H
#define REPORTMAKER_H

#include "GraphMaker.h"
#include "Testable.h"
#include "Patient.h"

/** Makes Reports

afsadsafds
*/
class ReportMaker : Testable
{
    public:
        static void testHarness();
        void makeReport();
    private:
        GraphMaker graphMaker;
        Patient patient;
}

#endif