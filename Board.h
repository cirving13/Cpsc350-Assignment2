// # Cpsc350-Assignment2
// Cameron Irving
// 2326756
// cirving@chapman.edu
// Kenneth Cho
// 2325383
// kecho@chapman.edu
// cpsc350-1
//This is a header file for the board class

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

class Board  //class for Board Object
{
private:
  int rows;  //private variables rows and columns
  int columns;

public:
  Board();
  ~Board();

  char** currentp;  //pointers for the current 2darray and the next generation 2d array
  char** nextp;

  void createBoard(int rows, int column); //creates a board
  string returnBoard();                   //prints out the board
  bool isStable();                        //checks if the board is stable
  void readFile(string fileIn);           //reads file and creates board of given specifics
  void randBoard(int r, int c, float val);//creates a board with a random distribution using the numbers inputted by the user
  string outRandBoard(int r, int c);      //
  void writeConsoleEnter(int decision);   //writes to console for each enter
  void writeConsole(int decision);        //writes to console with brief pauses in between generations
  void writeFile(string input, int decision);// writes the results to a file

  void setRows(int h);                        //getters and setters for the rows and columns
  void setColumns(int m);
  int getRows();
  int getColumns();


  bool isEmpty();             //boolean that returns true if is empty
  void WriteArt(string input);//prints out the ASCII art in art.txt to console

  void classic();             //runs classic mode
  void mirror();              //runs mirror mode
  void donut();               //runs donut mode
  int cornerTL(int x,int y);  //checks the neighbors for the corner cells
  int cornerTR(int x,int y);
  int cornerBL(int x,int y);
  int cornerBR(int x,int y);
  int sideT(int x,int y);     //checks the neigbors for the side cells
  int sideB(int x,int y);
  int sideR(int x,int y);
  int sideL(int x,int y);
  int middle(int x,int y);    //checks the neighbors for the middle cells
  void logic(int neighbors, int x, int y);  //determines whether a cell would live or die


};
