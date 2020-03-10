#include "Board.h"

Board::Board()
{

}
Board::~Board()
{
  delete boardP;
}

void Board::createBoard(int rows, int columns)
{
  char** b = new char*[rows];
  for(int i = 0; i < rows; ++i)
    b[i] = new char[columns];
}
void Board::push(char val, int rowLocation, int columnLocation)
{
  boardP[rowLocation][columnLocation] = val;
}
char Board::peek(int rowLocation, int columnLocation)
{
  return boardP[rowLocation][columnLocation];
}
string Board::returnBoard(){
  string output = "";
  for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
      output = output + boardP[i][j];
    }
    output+="\n";
  }
  return output;
}
