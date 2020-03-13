# Cpsc350-Assignment2
Cameron Irving
2326756
cirving@chapman.edu
Kenneth Cho
2325383
kecho@chapman.edu
cpsc350-1

Files that are submitted:
Board.cpp
Board.h
main.cpp
Makefile
output.txt
sample.txt
This README file
art.txt

references

basic idea
https://codereview.stackexchange.com/questions/47167/conways-game-of-life-in-c
sleep function
https://www.poftut.com/what-is-sleep-function-and-how-to-use-it-in-c-program/

Our solution:
we have created a Board object that has private variables of rows and columns and method and two pointers each for the current 2d array and the next gen 2d array
and the other methods needed for the game. for each mode, to avoid segmentation faults, we have created methods that count the neighbors of cells depending
on where on the board it exists. for example, if the game is in classic mode, and a cell that's being read through the for loop is a corner cell, it doesn't try to read cells
that are out of their bounds but detects only the cells around it depending on which corner it exists in. same thing is done for cells that are right by the barriers
and cells that are in the middle. Other modes detect cells that are around it, and depending on where they are, adds an additional number of neighbors due to reflection
or folding. The process of the game and the results can be seen by the user on the console or in a file if the user decides to output to it. If the current generation and the next generation
are the same, the game halts. If it falls into an infinite loop, it keeps on going.
