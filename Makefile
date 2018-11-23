# Author:	Thomas Vandeven
# Date:		November 15th 2018
HEADER := headerFiles 
ODIR := bin
STATIC_ODIR := $(ODIR)/static
SDIR := source

TEST_SDIR := tests
TEST_ODIR := bin/tests

SOURCES := $(shell find $(SDIR) -type f -name "*.cpp" -print)
OBJECTS := $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SOURCES))

TEST_SOURCES := $(shell find $(TEST_SDIR) -type f -name "*.cpp" -print)
TEST_OBJECTS := $(patsubst $(TEST_SDIR)/%.cpp, $(TEST_ODIR)/%.o, $(TEST_SOURCES))

SHARED_ODIR := $(ODIR)/shared

LIBRARY_SDIR := $(SDIR)/lib
LIBRARY_ODIR := lib/bin
INCLUDE := lib/include

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$@.Td
CFLAGS = -iquote $(HEADER) -iquote $(INCLUDE) -iquote . -L $(LIBRARY_ODIR) -Wall
CC = g++

DEPDIR := .dependencies
$(shell mkdir -p $(DEPDIR) >/dev/null)

COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) $^ -o $@
POSTCOMPILE = mv -f $(DEPDIR)/$@.Td $(DEPDIR)/$@.d && touch $@
ARCHIVE = ar rcs $@ $^

DIRECTORIES := $(DEPDIR)/ $(dir $(OBJECTS)) $(patsubst %, $(DEPDIR)/%, $(dir $(OBJECTS) $(TEST_OBJECTS))) $(LIBRARY_ODIR)/ \
	$(dir $(TEST_OBJECTS)) $(INCLUDE)/

help:
	@less help.txt

all: directories objects libs tests
directories: $(DIRECTORIES)
objects: $(OBJECTS)
libs: $(LIBRARY_ODIR)/libPancreas.a
tests: $(TEST_OBJECTS)
.PHONY: directories objects libs tests

# rule to make a directory ending in "/"
%/ %/./ %/.//: $(dir %)/
	@mkdir -p $@
.PHONY: ./ .//

MAINOBJECTS := $(filter-out $(ODIR)/main.o, $(OBJECTS))
$(ODIR)/main.o: $(INCLUDE)/libPancreas.h $(LIBRARY_ODIR)/libPancreas.a
$(ODIR)/main.o: $(SDIR)/main.cpp 
	@echo remaking main.o
	$(COMPILE)
	$(POSTCOMPILE)

$(LIBRARY_ODIR)/libPancreas.a: $(MAINOBJECTS) $(INCLUDE)/libPancreas.h
	@$(ARCHIVE)

HEADERFILES := $(shell find $(HEADER) -maxdepth 1 -type f -name "*.h")
$(INCLUDE)/libPancreas.h: $(filter-out $(INCLUDE)/libPancreas.h, $(HEADERFILES))
	@echo remaking libPancreas.h $^
	@echo \#ifndef LIBPANCREAS_H\\n\#define LIBPANCREAS_H\\n > $@;\
	for f in $^; \
	do echo \#include \"$$(basename $$f)\" >> $@; done; \
	echo "\n#endif\n" >> $@ && touch $@
.PHONY: $(HEADER)

$(ODIR)/%.o:
$(ODIR)/%.o: $(SDIR)/%.cpp
	@$(COMPILE) -c
	@$(POSTCOMPILE)

$(TEST_ODIR)/%.o:
$(TEST_ODIR)/%.o: $(TEST_SDIR)/%.cpp $(HEADER)/main.h $(LIBRARY_ODIR)/libPancreas.a 
	@$(COMPILE)
	@$(POSTCOMPILE)


.PHONY: clean
clean: cleanDocs

.PHONY: cleanDocs
cleanDocs:
	@rm -rf docs/latex docs/html $(RULES_DIR) \
		$(ODIR) $(SHARED_ODIR) $(LIBRARY_ODIR) $(DEPDIR)


 include $(shell find $(DEPDIR) -type f -name "*.d" -print0)