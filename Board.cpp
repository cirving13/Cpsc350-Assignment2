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
  boardP = new char*[rows];
  for(int i = 0; i < rows; ++i)
  {
    boardP[i] = new char[columns];
    for(int j = 0; j < columns; ++j)
    {
      boardP[i][j]='-';
    }

  }
}
void Board::push(char val, int rowLocation, int columnLocation)
{
  boardP[rowLocation][columnLocation] = val;
}
char Board::peek(int rowLocation, int columnLocation)
{
  return boardP[rowLocation][columnLocation];
}
string Board::returnBoard()
{
  string output;
  for(int i = 0;i < rows;i++)
  {
    for(int j = 0;j < columns;j++)
    {
      output = output + boardP[i][j];
    }
    output+="\n";
  }
  return output;
}
void Board::readFile(string input) //opens and reads a file, finding basic information about the file
{
  ifstream inFile;
  inFile.open(input);
  char c;
  string line;
  getline(inFile, line);
  rows = stoi(line);
  getline(inFile, line);
  columns = stoi(line);
  cout << rows << endl;
  cout << columns << endl;
  createBoard(rows,columns);
  if (!inFile)
  {
    cout << "Unable to open file " + input << endl;
    exit(1);
  }
  int i = 0;
  int j = 0;

  while (!inFile.eof())
  {
    inFile >> noskipws >> c;
    if(c == 'X' || c == '-')
    {
      boardP[i][j] = c;
      ++j;
    }
    else if(c == '\n')
    {
      ++i;
      j = 0;
    }
  }
  inFile.close();
}
void Board::randBoard(int r, int c, float val)
{
  createBoard(r,c);
  for(int i = 0; i < r; ++i)
  {
    for(int j = 0; j < c; ++j)
    {
      boardP[i][j] = '-';
    }
  }
  int randNum = c*r*val;
  for(int i = 0; i < randNum; ++i)
  {
    int v1 = rand() % r;
    int v2 = rand() % c;
    boardP[v1][v2] = 'X';
  }
}
