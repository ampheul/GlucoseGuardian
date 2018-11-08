#include "Test.h"

TestResult Test::runTest()
{
    return TestResult(TestValue::Failure, "Unimplemented");
}

TestResult Test::runAndPrint( std::string name)
{
    TestResult tr = runTest();
    
    std::cout << "Running Test: " << this->name << std::endl;
    std::cout << tr.toString() << std::endl;

    return tr;
}