#include "Board.h"

Board::Board()
{

}
Board::~Board()
{
  delete nextp;
  delete currentp;
}

void Board::createBoard(int rows, int columns) //creates board
{
  currentp = new char*[rows];
  for(int i = 0; i < rows; ++i)
  {
    currentp[i] = new char[columns];
    for(int j = 0; j < columns; ++j)
    {
      currentp[i][j]='-';
    }
  }
  nextp = new char*[rows];
  for(int i = 0; i < rows; ++i)
  {
    nextp[i] = new char[columns];
    for(int j = 0; j < columns; ++j)
    {
      nextp[i][j]='-';
    }
  }
}
string Board::returnBoard() //outputs board
{
  string output;
  for(int i = 0;i < rows;i++)
  {
    for(int j = 0;j < columns;j++)
    {
      output = output + currentp[i][j];
    }
    output+="\n";
  }
  return output;
}
string Board::outRandBoard(int r, int c) //outputs rand board, ignore
{
  string output;
  for(int i = 0;i < r;i++)
  {
    for(int j = 0;j < c;j++)
    {
      output = output + currentp[i][j];
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
      currentp[i][j] = c;
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
void Board::randBoard(int r, int c, float val) //creates random board
{
  setColumns(c);
  setRows(r);
  createBoard(r,c);
  for(int i = 0; i < r; ++i)
  {
    for(int j = 0; j < c; ++j)
    {
      currentp[i][j] = '-';
    }
  }
  int randNum = c*r*val;
  for(int i = 0; i < randNum; ++i)
  {
    int v1 = rand() % r;
    int v2 = rand() % c;
    currentp[v1][v2] = 'X';
  }
  cout << outRandBoard(r,c);
}
int Board::getColumns(){
  return columns;
}
int Board::getRows(){   // accessors and modifiers for the private variables
  return rows;
}
void Board::setRows(int r)
{
  rows = r;
}
void Board::setColumns(int c)
{
  columns = c;
}
