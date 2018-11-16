TEST = false
TSDIR = tests
ODIR = bin
ODIR_SHARED = $(ODIR)/shared
CFLAGS = -iquote headerFiles
CC = g++
TEST_PREREQS = $(patsubst %.cpp, %.o, $(wildcard $(TSDIR)/* ))

none:
	echo $(TEST)

tests/%.o:
	g++ -c $(ODIR)/$(patsubst tests/%, )

$(ODIR)/shared/%.o: CFLAGS += -fPIC

	
$(ODIR)/Test.o: 
	g++ $(CFLAGS) -fPIC -o $(ODIR)/Test.o $(SDIR)/Test/Test.cpp

tests: Test.o TestResult.o 

libTest: Test.o TestResult.o
	g++ -c -shared 

clean: cleanDocs

cleanDocs:
	rm -rf docs/latex docs/html