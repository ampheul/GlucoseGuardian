# Author:	Thomas Vandeven
# Date:		November 15th 2018
HEADER = headerFiles
ODIR := bin
STATIC_ODIR = $(ODIR)/static
SDIR := source

TEST_SDIR := tests
TEST_ODIR := $(TEST_SDIR)/bin

SOURCES := $(shell find $(SDIR) -type f -name "*.cpp" -print)
OBJECTS := $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SOURCES))

TEST_SOURCES := $(shell find $(TESTDIR) -type f -name "*.cpp" -print)
TEST_OBJECTS := $(patsubst $(TEST_SDIR)/%.cpp, $(TEST_ODIR)/%.o, $(TESTSOURCES))

SHARED_ODIR := $(ODIR)/shared

# Directory for shared libraries

LIBRARY_SDIR := $(SDIR)/lib
LIBRARY_ODIR := $(ODIR)/lib

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
CFLAGS = -iquote headerFiles -L $(LIBRARY_ODIR) -Wall
CC = g++

RULES_DIR := makeRules
RULEFILES := $(patsubst $(SDIR)/%.cpp, $(RULES_DIR)/%.mk, $(SOURCES))

percent := %


DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$@.Td
DEPDIR := .dependencies
$(shell mkdir -p $(DEPDIR) >/dev/null)

COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) $^ -o $@
POSTCOMPILE = mv -f $(DEPDIR)/$@.Td $(DEPDIR)/$@.d && touch $@
ARCHIVE = ar rcs $@ $^

DIRECTORIES := $(DEPDIR) $(dir $(OBJECTS)) $(patsubst %, $(DEPDIR)/%, $(dir $(OBJECTS)))

all: $(DIRECTORIES) $(OBJECTS) libs
libs: $(LIBRARY_ODIR)/libPancreas.a 
.PHONY: libs

# rule to make a directory ending in "/"
%/ %/./ %/.//: $(dir %)/
	@mkdir -p $@
.PHONY: ./ .//

MAINOBJECTS := $(filter-out $(ODIR)/main.o, $(OBJECTS))
$(ODIR)/main.o: $(HEADER)/main.h $(LIBRARY_ODIR)/libPancreas.a
$(ODIR)/main.o: $(SDIR)/main.cpp 
	$(COMPILE)
	$(POSTCOMPILE)

$(LIBRARY_ODIR)/libPancreas.a: $(MAINOBJECTS)
	$(ARCHIVE)

$(HEADER)/main.h: $(HEADER)
	@echo \#ifndef MAIN_H\\n\#define MAIN_H\\n > $@;\
	for f in $(HEADER)/*; \
	do echo \#include \"$$(basename $$f)\" >> $@; done; \
	echo "\n#endif\n" >> $@ && touch $@
.PHONY: $(HEADER)

SHAREDOBJECTS = $(patsubst /)
$(ODIR)/%.o:
$(ODIR)/%.o: $(SDIR)/%.cpp
	$(COMPILE) -c
	$(POSTCOMPILE)





.PHONY: clean
clean: cleanDocs

.PHONY: cleanDocs
cleanDocs:
	rm -rf docs/latex docs/html $(RULES_DIR) \
		$(ODIR) $(SHARED_ODIR) $(LIBRARY_ODIR) $(DEPDIR)


 include $(shell find $(DEPDIR) -type f -name "*.d" -print0)