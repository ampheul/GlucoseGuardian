# Author:	Thomas Vandeven
# Date:		November 15th 2018

ODIR = bin
SDIR = source
# output for shared binaries (Position independent code for shared libraries)
SHARED_ODIR = $(ODIR)/shared
TEST_SDIR = tests
TEST_ODIR = $(TEST_SDIR)/bin
# Directory for shared libraries
LIBRARY_SDIR = $(SDIR)/lib
LIBRARY_ODIR = $(ODIR)/lib
CFLAGS = -iquote headerFiles
CC = g++
#TEST_PREREQS = $(patsubst $(TEST_SDIR)/%.cpp, $(TEST_ODIR)/%.o, $(shell find $(TEST_SDIR) -name "$()*.cpp"))
RULES_DIR = makeRules
RULEFILES := $(patsubst $(SDIR)/%.cpp, $(RULES_DIR)/%.mk, $(shell find $(SDIR) -name "*.cpp"))
percent := %

# make all the rule files 
rules: $(RULEFILES)
$(RULES_DIR)/%.mk: $(dir $(RULES_DIR)/%.mk) $(SDIR)/%.cpp
	g++ $(CFLAGS) -MM $(SDIR)/$*.cpp -MT $(ODIR)/$*.o > $@

.SECONDEXPANSION:
$(TEST_ODIR)/%.o: $$(wordlist 2,1000, \
		$$(shell $$(CC) $$(CFLAGS) -MM (TEST_SDIR)/$$*.cpp ))
#	$(CC) -c $(CFLAGS) $^ -o $@
	echo $^
$(SHARED_ODIR)/%.o:	$(SDIR)/%.cpp
	$(CC) -c $(CFLAGS) -fPIC $^ -o $@

#rules: $(patsubst $(SDIR)/%.cpp, $(RULESDIR)/%.mk, $(shell find $(SDIR) -name "*.cpp" -print0))

directorys: $(shell find . -name "*.cpp")
	echo "asdf"

meta:
	echo $(MAKEFILE_LIST)
tests: $(LIBRARY_ODIR)/libTest.so $(TEST_PREREQS)


# rule to make a directory ending in "/"
%/:
	mkdir -p $@
.PHONY: ./



.SECONDEXPANSION:
$(LIBRARY_ODIR)/lib%.so: $$(LIBRARY_ODIR)/
$(LIBRARY_ODIR)/lib%.so: $$(patsubst $$(SDIR)/$$(percent).cpp, $$(SHARED_ODIR)/$$(percent).o, \
		$$(shell find $$(SDIR)/$$* -name "*.cpp" -print) )
	echo $@ $^
#	$(CC) $(CFLAGS) -c $^ -o $@


clean: cleanDocs
#%.mk:

cleanDocs:
	rm -rf docs/latex docs/html


#include $(shell find $(MAKERULES) -name "*.mk" -print0)