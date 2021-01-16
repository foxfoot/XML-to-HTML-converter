SOURCE = src/main.cpp src/lib/pugixml.cpp src/CDCatalog.cpp src/CD.cpp

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

# Declare the targets as PHONY. "make" command will not check for any produced file. 
.PHONY: clean test

MAIN = xml2html

all: $(MAIN)

$(MAIN): $(OBJS)
	$(GCC) $(CFLAGS) -o $(MAIN) $(OBJS)

test:
	make -C test/unit/

clean:
	$(RM) *.o src/*.o src/lib/*.o $(MAIN) test/unit/*.o

help:
	@echo "make       - build the executable file xml2html"
	@echo "make test  - build the unit test executable file testSuite"
	@echo "make clean - remove .o, executable file xml2html and test executable file testSuite"
