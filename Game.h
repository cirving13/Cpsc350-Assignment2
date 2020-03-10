#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "Board.h"

using namespace std;

class Game
  {
  private:
    int playRows;
    int playColumns;

  public:
    Game();
    Game(int rowInput, int columnInput);
    ~Game();

    int getRows(); //accessors and modifiers for the private variables in the class
    void setRows(int row);
    int getColumns();
    void setColumns(int column);
    Board* nextGen(Board *a,int x,int y);
    Board* nextGenDon(Board *a,int x,int y);
  };
