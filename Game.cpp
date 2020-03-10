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
  Board *b = new Board();
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
// void Game::randBoard(float val)
// {
//   for(int i = 0; i < playRows; ++i)
//   {
//     for(int j = 0; j < playColumns; ++j)
//     {
//       board[i][j] = '-';
//     }
//   }
//   char board[playRows][playColumns];
//   int randNum = playColumns*playRows*val;
//   for(int i = 0; i < randNum; ++i)
//   {
//     int v1 = rand() % playRows;
//     int v2 = rand() % playColumns;
//     board[v1][v2] = 'X';
//     cout << board[v1][v2];
//   }
// }

Board* Game::nextGen(Board *a,int x,int y){
  char** arr = a->boardP;
  Board *b = new Board();
  b->createBoard(x,y);
  for(int i = 0; i< x; ++i ){
    for(int j = 0; j < y; ++j){
      int neighbors = 0;
      if(arr[i+1][j-1] == 'X'){
        neighbors++;
      }
      else if(arr[i+1][j] == 'X'){
        neighbors++;
      }
      else if(arr[i+1][j+1] == 'X'){
        neighbors++;
      }
      else if(arr[i][j-1] == 'X'){
        neighbors++;
      }
      else if(arr[i][j+1] == 'X'){
        neighbors++;
      }
      else if(arr[i-1][j-1] == 'X'){
        neighbors++;
      }
      else if(arr[i-1][j] == 'X'){
        neighbors++;
      }
      else if(arr[i-1][j+1] == 'X'){
        neighbors++;
      }
      if(neighbors < 2){
        b->push('-',i,j);
      }
      else if(neighbors == 2){
        b->push(arr[i][j],i,j);
      }
      else if(neighbors == 3){
        b->push('X',i,j);
      }
      else if(neighbors > 3){
        b->push('-',i,j);
      }
    }
  }
  // arr = b->boardP;
  a = b;
  delete b;
  return a;
}
