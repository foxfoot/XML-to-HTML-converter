# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -DDEBUG

SRC = src/main.cpp src/lib/pugixml.cpp src/CDCatalog.cpp src/CD.cpp
OBJ = $(SRC:.cpp = .o)
MAIN = xml2html

all: $(MAIN)

$(MAIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJ)

clean:
	$(RM) *.o *~ $(MAIN)