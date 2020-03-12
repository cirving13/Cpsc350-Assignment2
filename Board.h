#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Board
{
private:
  int rows;
  int columns;

public:
  Board();
  ~Board();

  char** currentp;
  char** nextp;

  void createBoard(int rows, int column);
  string returnBoard();
  void readFile(string fileIn); //reads file and creates board of given specifics
  void randBoard(int r, int c, float val);
  string outRandBoard(int r, int c);
  int getRows(); //accessors and modifiers for the private variables in the class
  int getColumns();
  void setRows(int r);
  void setColumns(int c);


};
