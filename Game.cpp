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
<<<<<<< HEAD
  cout << playRows << endl;
  cout << playColumns << endl;

=======
  cout << board[2][2] << endl;
>>>>>>> 1595a22f40cbd03b4a7611ae2670779c45878679
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
  char board[playRows][playColumns];
  int randNum = playColumns*playRows*val;
  for(int i = 0; i < randNum; ++i)
  {
    int v1 = rand() % playRows;
    int v2 = rand() % playColumns;
    board[v1][v2] = 'X';
    cout << "Kachigga my" << endl;
  }
}
