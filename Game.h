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
    char board[10][10];
    char tempboard[10][10];

  public:
    Game();
    Game(int rowInput, int columnInput);
    ~Game();
    void readFile(string fileIn); //reads file and creates board of given specifics
    //void writeFile(string fileOut); //outputs the game to a file, given filename
    //void writeConsoleEnter(); //writes to console but doesnt continue game until user presses enter
    //void writeConsole(); //writes to console with small pauses
    int getRows(); //accessors and modifiers for the private variables in the class
    void setRows(int row);
    int getColumns();
    void setColumns(int column);
    bool isSameGen(char** array1, char** array2); //a boolean function that compares the current generation with its next
    void consoleOut(); //a function that prints out the results to the console
    void boardCopy(); // a function that copies the original array to the next generation array
    // isAlive();
  };
