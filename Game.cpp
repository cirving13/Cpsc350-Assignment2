#include "Game.h"

Game::Game()
{
  char board[10][10];
  char tempboard[10][10];
}
Game::Game(int rowInput, int columnInput)
{
  char board[rowInput][columnInput];
  char tempboard[rowInput][columnInput];
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
bool isSameGen(char** array1, char** array2){

}
