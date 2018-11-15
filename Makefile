TEST = false

CFLAGS = -iquote headerFiles
CC = g++

%:
	echo "asdfasdf"
%Q:
	echo $@

TestTest: Test.o

Test.o: TestResult.o
	$(CC) -o source/Test.cpp TestResult.o
TestResult.o:
	$(CC) -c $(CFLAGS) source/TestResult.cpp

clean: cleanDocs


cleanDocs:
	rm -rf docs/latex docs/html