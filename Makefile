# Makefile
# Build rules for propBet

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = --std=c++11 -Wall -Werror -pedantic -g

main.exe: Main.cpp Board.cpp AI.cpp Game.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test: Board_tests.exe \
		Game_tests.exe

	./Board_tests.exe

	./Game_tests.exe

Board_tests.exe: Board.cpp Board_test.cpp unit_test_framework.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Game_tests.exe: Game.cpp unit_test_framework.cpp Game_test.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Disable built-in Makefile rules
.SUFFIXES:

# these targets do not create any files
.PHONY: clean
clean:
	rm -rvf *.exe *.out.txt *.out.ppm *.dSYM *.stackdump