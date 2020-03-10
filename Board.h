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

  char** boardP;

  void createBoard(int rows, int column);
  void push(char val, int rowLocation, int columnLocation);
  char peek(int rowLocation, int columnLocation);
  string returnBoard();
  void readFile(string fileIn); //reads file and creates board of given specifics
  void randBoard(int r, int c, float val);


};
