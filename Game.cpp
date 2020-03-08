#include "Game.h"

Game::Game()
{
  char board[10][10];
}
Game::Game(int rowInput, int columnInput)
{
  char board[rowInput][columnInput];
}
Game::~Game()
{
  cout << "Closing Game" << endl;
}
void Game::readFile(string input) //opens and reads a file, finding basic information about the file
{

  playRows = -3; //set at -3 because the file reader will calculate the size of the board on its own, at each \n it adds a play row and the first two rows of the file are the dimensions so this avoids it. Also the extra line at the end of the file will error everything
  ifstream inFile;
  inFile.open(input);
  char c;
  if (!inFile)
  {
    cout << "Unable to open file " + input << endl;
    exit(1);
  }
  int charCount = 0;
  while (!inFile.eof())
  {
    inFile >> noskipws >> c;
    if(c=='X' || c=='-')
    {
      cout << c;
      ++charCount;
    }
    if(c == '\n')
    {
      cout << c;
      ++playRows;
    }
  }
  playColumns = charCount/playRows;
  cout << playRows << endl;
  cout << playColumns << endl;
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
