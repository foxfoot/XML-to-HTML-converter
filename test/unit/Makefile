SOURCE = testSuite.cpp testCD.cpp testCDCatalog.cpp ../../src/CD.cpp ../../src/CDCatalog.cpp ../../src/lib/pugixml.cpp

OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

INC =
CFLAGS = -fPIC -Wall -std=c++17 $(INC)
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS =

RM = rm -rf

.PHONY: clean

all : testSuite

testSuite: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	$(RM) *.o ../../src/*.o ../../src/lib/*.o testSuite