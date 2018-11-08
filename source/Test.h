#ifndef TESTABLE_H
#define TESTABLE_H

#include "TestResult.h"
#include <iostream>
#include <string>
/** Test Harness

afsadsafds
*/
class Test 
{
    public:
        TestResult runTest();
        TestResult runAndPrint();
        std::string getName();
    private:
        std::string name;
};


#endif
