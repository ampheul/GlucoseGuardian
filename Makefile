
SDIR = "source"
ODIR = "bin"
test: TestTest.cpp Test.o
	g++ -o $(ODIR)/TestTest TestTest.cpp $(ODIR)/Test.o

$(ODIR)/Test.o:
	g++ $(SDIR)/Test.cpp -c $(ODIR)/Test.o
$(ODIR)/Test.o
clean: cleanDocs

cleanDocs:
	rm -rf docs/latex docs/html