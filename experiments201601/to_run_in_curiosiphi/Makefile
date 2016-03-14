
# Project name
EXEC=POSL

# Compiler
CXX=mpic++.mpich2
IDIR=src/main src/benchmarks src/benchmarks/cost_strategy src/benchmarks/relative_cost_strategy src/benchmarks/show_strategy src/computation src/connections src/data src/data/dStrategy src/expressions src/modules src/modules/strategy src/operators src/operators/strategy src/packing src/packing/factory src/packing/packers src/solver src/solver/strategy src/testers src/tools
IDIRFLAG=$(foreach idir, $(IDIR), -I$(idir))
CXXFLAGS=-std=c++0x -Ofast -W -Wall -Wextra -pedantic -Wno-sign-compare -Wno-unused-parameter $(IDIRFLAG)

# Linker
LINKER=mpic++.mpich2 -o
LFLAGS=$(IDIRFLAG)

# Directories
SRCDIR=src/main src/benchmarks src/benchmarks/cost_strategy src/benchmarks/relative_cost_strategy src/benchmarks/show_strategy src/computation src/connections src/data src/data/dStrategy src/expressions src/modules src/modules/strategy src/operators src/operators/strategy src/packing src/packing/factory src/packing/packers src/solver src/solver/strategy src/testers src/tools
OBJDIR=obj
BINDIR=bin

# Files
SOURCES=$(foreach sdir, $(SRCDIR), $(wildcard $(sdir)/*.cpp))
OBJECTS=$(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SOURCES)))

# For rm
SOURCESTILDE=$(foreach sdir, $(SRCDIR), $(wildcard $(sdir)/*.cpp~))
INCLUDESTILDE=$(foreach idir, $(IDIR), $(wildcard $(idir)/*.hpp~))

vpath %.cpp $(SRCDIR)

# Reminder, 'cause it is easy to forget makefile's fucked-up syntax...
# $@ is what triggered the rule, ie the target before :
# $^ is the whole dependencies list, ie everything after :
# $< is the first item in the dependencies list

# Rules
all: CXXFLAGS += -DNDEBUG
all: $(BINDIR)/$(EXEC)

debug: CXXFLAGS += -g
debug: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $^

$(OBJDIR)/%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all debug clean 

clean:
	rm -fr core *~ $(OBJECTS) $(BINDIR)/$(EXEC) $(SOURCESTILDE) $(INCLUDESTILDE)

