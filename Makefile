# Makefile

CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES = testRB

all: ${BINARIES}

testRB: testRB.o person.o profData.o redBlack.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o