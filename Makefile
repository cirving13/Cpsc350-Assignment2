# # Cpsc350-Assignment2
# Cameron Irving
# 2326756
# cirving@chapman.edu
# Kenneth Cho
# 2325383
# kecho@chapman.edu
# cpsc350-1

#this Makefile goes in the src directory

#change this to the correct assignment #
EXECUTABLE := game

# the source files to be built
SOURCES := *.cpp

#stuff you don't need to worry about
INCLUDES := -I ../include
EXT := exe
CC := g++

all:
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)

realclean:
	find . -type f -name "*.o" -exec rm '{}' \;
	find . -type f -name "*.exe" -exec rm '{}' \;
	find . -type f -name "*.out" -exec rm '{}' \;

# this line required by make - don't delete
