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

Board* Game::nextGen(Board *a,int x,int y){
  char** arr = a->boardP;
  Board *b = new Board();
  b->createBoard(x,y);
  for(int i = 4; i < x; ++i){
    cout << i;
    for(int j = 0; j < y; ++j){
      int neighbors = 0;
      cout << j << endl;
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
        cout << "hi";
      }
      else if(arr[i-1][j-1] == 'X'){
        neighbors++;
        cout << "hii";
      }
      else if(arr[i-1][j] == 'X'){
        neighbors++;
        cout << "hiii";

      }
      else if(arr[i-1][j+1] == 'X'){
        neighbors++;
      }
      else {

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
