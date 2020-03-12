#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

class Board
{
private:
  int rows;
  int columns;
  int equalCount = 0;

public:
  Board();
  ~Board();

  char** currentp;
  char** nextp;

  void createBoard(int rows, int column);
  string returnBoard();
  bool isStable();
  void readFile(string fileIn); //reads file and creates board of given specifics
  void randBoard(int r, int c, float val);
  string outRandBoard(int r, int c);
  void writeConsoleEnter(int decision);
  void writeConsole(int decision);
  void writeFile(string input, int decision);
  bool isEmpty();

  void classic();
  void mirror();
  void donut();
  int cornerTL(int x,int y);
  int cornerTR(int x,int y);
  int cornerBL(int x,int y);
  int cornerBR(int x,int y);
  int sideT(int x,int y);
  int sideB(int x,int y);
  int sideR(int x,int y);
  int sideL(int x,int y);
  int middle(int x,int y);
  void logic(int neighbors, int x, int y);


};
