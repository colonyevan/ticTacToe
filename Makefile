# Makefile
# Build rules for propBet

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = --std=c++11 -Wall -Werror -pedantic -g

main.exe: Main.cpp Board.cpp AI.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test: Board_tests.exe /
		AI_tests.exe

		./Board_tests.exe
		./AI_tests.exe

Board_tests.exe: 

# Disable built-in Makefile rules
.SUFFIXES:

# these targets do not create any files
.PHONY: clean
clean:
	rm -rvf *.exe *.out.txt *.out.ppm *.dSYM *.stackdump