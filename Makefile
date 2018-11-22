# Author:	Thomas Vandeven
# Date:		November 15th 2018

ODIR := bin
SDIR := source

SOURCES := $(shell find $(SDIR) -type f -name "*.cpp" -print)
OBJECTS := $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SOURCES))

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td


# output for shared binaries (Position independent code for shared libraries)
SHARED_ODIR := $(ODIR)/shared
TEST_SDIR := tests
TEST_ODIR := $(TEST_SDIR)/bin
# Directory for shared libraries

LIBRARY_SDIR := $(SDIR)/lib
LIBRARY_ODIR := $(ODIR)/lib
CFLAGS = -iquote headerFiles #-L $(LIBRARY_ODIR)
CC = g++
#TEST_PREREQS = $(patsubst $(TEST_SDIR)/%.cpp, $(TEST_ODIR)/%.o, $(shell find $(TEST_SDIR) -name "$()*.cpp"))
RULES_DIR := makeRules
RULEFILES := $(patsubst $(SDIR)/%.cpp, $(RULES_DIR)/%.mk, $(SOURCES))

percent := %


DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$@.Td
DEPDIR := .dependencies
$(shell mkdir -p $(DEPDIR) >/dev/null)

COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) -c $^ -o $@
POSTCOMPILE = mv -f $(DEPDIR)/$@.Td $(DEPDIR)/$@.d && touch $@


all: directories $(OBJECTS)

# rule to make a directory ending in "/"
%/ %/./ %/.//: $(dir %)/
	mkdir -p $@
.PHONY: ./ .//

$(ODIR)/main.o:
$(ODIR)/main.o: $(OBJECTS)
	$(COMPILE) $(OBJECTS)
	$(POSTCOMPILE)

$(SHARED_ODIR)/%.o: CFLAGS+=-fPIC
$(SHARED_ODIR)/%.o:	$(SDIR)/%.cpp
	$(COMPILE)
	$(POSTCOMPILE)

$(ODIR)/%.o:
$(ODIR)/%.o: $(SDIR)/%.cpp
	$(COMPILE)
	$(POSTCOMPILE)

directories: $(DEPDIR) $(dir $(OBJECTS)) $(patsubst %, $(DEPDIR)/%, $(dir $(OBJECTS)))

libs: $(LIBRARY_ODIR)/libTest.so

.SECONDEXPANSION:
$(LIBRARY_ODIR)/lib%.so: directories
$(LIBRARY_ODIR)/lib%.so: $$(wildcard $$(SHARED_ODIR)/$$*/*.o )
	echo $(wildcard $(SHARED_ODIR)/$*/*.o)
	$(CC) $(CFLAGS) -shared -c $(wildcard $(SHARED_ODIR)/$*/*.o) -o $@

.PHONY: clean
clean: cleanDocs

.PHONY: cleanDocs
cleanDocs:
	rm -rf docs/latex docs/html $(RULES_DIR) \
		$(ODIR) $(SHARED_ODIR) $(LIBRARY_ODIR) $(DEPDIR)


 include $(shell find $(DEPDIR) -type f -name "*.d" -print0)