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
    
    Board* nextGen(Board *a,int x,int y);
    Board* nextGenDon(Board *a,int x,int y);
  };
