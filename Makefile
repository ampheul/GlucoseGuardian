TEST = false

CFLAGS = -iquote source
CC = g++

TestTest: Test.o

Test.o: TestResult.o
	$(CC) -o source/Test.cpp TestResult.o
TestResult.o:
	$(CC) -c source/TestResult.cpp

clean: cleanDocs

%:

cleanDocs:
	rm -rf docs/latex docs/html