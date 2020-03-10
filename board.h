#include <iostream>

using namespace std;

class board
{
private:
  int rows;
  int colums;
  char** board;

public:
  board();
  board(int rows, int colums);
  ~board();

  void createBoard(int rows, int column);
  void push(char val, int rowLocation, int columnLocation);
  char peek(int rowLocation, int columnLocation);
}
