##############################################################
###################### ECSV Makefile #########################
############### Copyright (c), Evoluti, Inc. #################
##############################################################

ifeq ($(OS),Windows_NT)
	TARGET_EXT=exe
else
	TARGET_EXT=out

MAKEFLAGS = --quiet

LIBVER=0.0.1
RELEASE=1

MKDIR=mkdir -p
CLEANUP=rm -f
CHMOD=chmod
MV=mv

#### build directories

BUILDDIR=build/
BUILDOBJ=$(BUILDDIR)objects/
BUILDDPS=$(BUILDDIR)depends/

BUILDDIR_PATHS = $(BUILDDIR) $(BUILDOBJ) $(BUILDDPS)

#### source directories

SRC=src/
TEST=tests/

SOURCES = $(SRC) $(TEST)

TESTSRCS = $(wildcard $(TEST)*.cpp)

#### binaries
ALL_SRC = $(wildcard $(SRC)*.cpp)
ALL_SRC += $(wildcard $(TEST)*.cpp)

OBJ_FILES_TEMP = $(patsubst $(SRC)%.cpp,$(BUILDOBJ)%.o, $(ALL_SRC))
OBJ_FILES += $(patsubst $(TEST)%.cpp,$(BUILDOBJ)%.o, $(OBJ_FILES_TEMP))
DPS_FILES_TEMP = $(patsubst $(SRC)%.cpp,$(BUILDDPS)%.d, $(ALL_SRC))
DPS_FILES += $(patsubst $(TEST)%.cpp,$(BUILDDPS)%.d, $(DPS_FILES_TEMP))

#### Includes

PATHSI = . \
	src/ \
	src/include/ \

INCLUDES = $(patsubst %,-I%,$(PATHSI))

#### Compilation & Linking

CXX=g++
CFLAGS=-std=c++11 -Wall
EXTRA_CFLAGS=$(INCLUDES)
DBG=
DEPENDS=-MM -MG -MF

.PHONY: tests
.PHONY: clean
.PHONY: release

#### Rules

# Final Rules

tests: $(BUILDDIR_PATHS) $(BUILDDIR)par_tests.$(TARGET_EXT)

install:
	@echo "ECSV" $(LIBVER): "Not Installable"

# Linking

$(BUILDDIR)par_tests.$(TARGET_EXT): $(OBJ_FILES)
	@echo "Linking "$^"..."
	$(CXX) $(CFLAGS) $(DBG) $^ -o $@
	@echo "Finished linking "$^"."

# Compilation

$(BUILDOBJ)%.o:: $(SRC)%.cpp
	@echo "Compiling "$<"..."
	$(CXX) -c $(CFLAGS) $(CFLAGS_LIB) $(EXTRA_CFLAGS) $(DBG) $< -o $@
	@echo "Finished compiling "$<"."

$(BUILDOBJ)%.o:: $(TEST)%.cpp
	@echo "Compiling "$<"..."
	$(CXX) -c $(CFLAGS) $(EXTRA_CFLAGS) $(DBG) $< -o $@
	@echo "Finished compiling "$<"."

# Dependencies

$(BUILDDPS)%.d:: $(SRC)%.cpp
	$(CXX) $(DEPENDS) $@ $<

$(BUILDDPS)%.d:: $(TEST)%.cpp
	$(CXX) $(DEPENDS) $@ $<

$(PATHSI):
	$(MKDIR) $(PATHSI)

$(BUILDDIR_PATHS):
	$(MKDIR) $(BUILDDIR_PATHS)

clean:
	$(CLEANUP) $(BUILDDIR)*.$(TARGET_EXT)
	$(CLEANUP) $(BUILDOBJ)*.o
	$(CLEANUP) $(BUILDDPS)*.d

.PRECIOUS: $(BUILDDIR)%.$(TARGET_EXT)
.PRECIOUS: $(BUILDOBJ)%.o
.PRECIOUS: $(BUILDDPS)%.d
