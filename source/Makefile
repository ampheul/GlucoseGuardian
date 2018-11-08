all: ReportMaker

ReportMaker: ReportMaker.h ReportMaker.cpp
	g++ -o ReportMaker.o reportMaker.cpp
clean:
	rm -rf latex html

tests: 

runTest: runTest.cpp runTest.h
	g++ -o runTests runTests.cpp 