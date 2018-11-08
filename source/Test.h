#ifndef TESTABLE_H
#define TESTABLE_H

#include "TestResult.h"
#include <iostream>
#include <string>
/** Test class

Test Class is meant to be subclassed where the user overrides runTest
*/
class Test 
{
    public:
        virtual TestResult runTest();
        TestResult runAndPrint();
        std::string getName();
    private:
        std::string name;
};


#endif
