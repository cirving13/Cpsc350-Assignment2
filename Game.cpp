#include "Game.h"

Game::Game()
{
  char board[10][10];
  char tempBoard[10][10];
}
Game::Game(int rowInput, int columnInput)
{
  char board[rowInput][columnInput];
  char tempBoard[rowInput][columnInput];
}
Game::~Game()
{
  cout << "Closing Game" << endl;
}
void Game::readFile(string input) //opens and reads a file, finding basic information about the file
{

  ifstream inFile;
  inFile.open(input);
  char c;
  inFile >> c;
  playRows = (int) c - 48;
  inFile >> c;
  playColumns = (int) c - 48;
  Board *b = new Board(playRows,playColumns);
  b->createBoard(playRows,playColumns);
  if (!inFile)
  {
    cout << "Unable to open file " + input << endl;
    exit(1);
  }
  int charCount = 0;

  char board[playRows][playColumns];
  int i = 0;
  int j = 0;
  while (!inFile.eof()){
    inFile >> noskipws >> c;
    if(c == 'X'){
      cout << c;
      board[i][j]='X';
      ++j;
    }
    else if(c == '-'){
      cout << c;
      board[i][j]='-';
      ++j;
    }
    else if(c == '\n'){
      cout << c;
      ++i;
      j = 0;
    }
  }
  cout << board[2][2] << endl;
  inFile.close();
}
int Game::getRows(){   // accessors and modifiers for the private variables
  return playRows;
}
void Game::setRows(int row){
  playRows = row;
}
int Game::getColumns(){
  return playColumns;
}
void Game::setColumns(int columns){
  playColumns = columns;
}
void Game::randBoard(float val)
{
  for(int i = 0; i < playRows; ++i)
  {
    for(int j = 0; j < playColumns; ++j)
    {
      board[i][j] = '-';
    }
  }
  char board[playRows][playColumns];
  int randNum = playColumns*playRows*val;
  for(int i = 0; i < randNum; ++i)
  {
    int v1 = rand() % playRows;
    int v2 = rand() % playColumns;
    board[v1][v2] = 'X';
    cout << board[v1][v2];
  }
  writeConsoleEnter();
}
void Game::writeFile(string input)
{
  //insert live or die method thing
  ofstream outFile;
  outFile.open(input);
  int i = 0;
  while(true)
  {
    cout << i << endl;
    ++i;
    for(int i = 0; i < playRows; ++i)
    {
      for(int j = 0; j < playColumns; ++j)
      {
        outFile << board[i][j];
      }
      outFile << endl;
    }
    if(i == 10)
      break;
  }

}
void Game::writeConsole()
{
  //insert live or die method thing
  int i = 0;
  while(true)
  {
    cout << i << endl;
    ++i;
    for(int i = 0; i < playRows; ++i)
    {
      for(int j = 0; j < playColumns; ++j)
      {
        cout << board[i][j];
      }
      cout << endl;
    }
    if(i == 10)
      break;
  }
}
void Game::writeConsoleEnter()
{
  int num = 0;
  while(true)
  {
    cout << num << endl;
    ++num;
    for(int i = 0; i < playRows; ++i)
    {
      for(int j = 0; j < playColumns; ++j)
      {
        cout << board[i][j];
      }
      cout << endl;
    }
    cout << "Press enter to continue" << endl;
    cin.ignore();
    if(num == 10)
      break;
  }
}
