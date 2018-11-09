#include "Test.h"

class TestTest : public Test
{
    public:
        TestResult runTest()
        {
            return TestResult(TestValue::Success, "First test!");
        }
};

int main(int arc, char **argv)
{
    TestTest tt = TestTest();
    tt.setName("The Test of Test");
    return 0;
}
