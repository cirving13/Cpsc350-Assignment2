#include "board.h"

Board::board()
{
  board = new char[10][10];
}
Board::board(int rows, int colums)
{
  board = new char[rows][colums];
}
Board::~board()
{
  delete board;
}

void Board::createBoard(int rows, int columns)
{
  char** board = new char*[rows];
  for(int i = 0; i < rows; ++i)
    board[i] = new int[colums];
}
void Board::push(char val, int rowLocation, int columnLocation)
{
  board[rowLocation][columnLocation] = val;
}
char Board::peek(int rowLocation, int columnLocation)
{
  return board[rowLocation][columnLocation];
}
