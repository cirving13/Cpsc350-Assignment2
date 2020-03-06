#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Game
  {
  private:
    int rows;
    int columns;
    int playRows; 
    int playColumns;

    char **space;

  public:
    Game();
    Game(int rowInput, int columnInput);
    ~Game();
    void readFile(string fileIn); //reads file and creates board of given specifics
    // void writeFile(string fileOut); //outputs the game to a file, given filename
    // void writeConsoleEnter(); //writes to console but doesnt continue game until user presses enter
    // void writeConsole(); //writes to console with small pauses

  };
