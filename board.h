#include <iostream>

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
};
