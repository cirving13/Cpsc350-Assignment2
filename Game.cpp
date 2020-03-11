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
  a = b;
  delete b;
  return a;
}
