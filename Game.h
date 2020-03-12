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
    ~Game();

    Board* classic(Board *a);
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
