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



// void Game::writeConsole()
// {
//
//   //insert live or die method thing(nextGen)
//   Board *x = new Board(playRows, PlayerColumns);
//   while(true)
//   {
//     x = nextGen(board, playRows, PlayerColumns);
//     cout << i << endl;
//     ++i;
//     for(int i = 0; i < playRows; ++i)
//     {
//       for(int j = 0; j < playColumns; ++j)
//       {
//         cout << x[i][j];
//       }
//       cout << endl;
//     }
//     if(i == 10)
//       break;
//   }
// }

// void Game::writeConsoleEnter()
// {
//   int num = 0;
//   Board *x = new Board(playRows, PlayerColumns);
//   while(true)
//   {
//     cout << num << endl;
//     ++num;
//     x = nextGen(board, playRows, PlayerColumns);
//     for(int i = 0; i < playRows; ++i)
//     {
//       for(int j = 0; j < playColumns; ++j)
//       {
//         cout << board[i][j];
//       }
//       cout << endl;
//     }
//     cout << "Press enter to continue" << endl;
//     cin.ignore();
//     if(num == 10)
//       break;
//   }
// }

Board* Game::nextGen(Board *a,int x,int y){
  char** arr = a->boardP;
  Board *b = new Board();
  b->createBoard(x,y);
  for(int i = 0; i < x; ++i ){
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
//sample for the donut mode
Board* Game::nextGenDon(Board *a,int x,int y){
  int z = x+2;
  int v = y+2;
  char** arr = a->boardP;
  Board *upd = new Board();
  Board *old = new Board();
  old->createBoard(x,y);
  upd->createBoard(z,v);
  char** arl = upd->boardP; //this is the pointer for the new board

  for(int i = 0; i < x; ++i){   //this will add everthing that's in the old board to the new board
    for(int j = 0; j < y; ++j){
      upd->push(arr[i][j],i+1,j+1); //upb now points to the same exact contents as the input board
    }
  }

  if(arl[1][1] == 'X'){// top left                     //these series of if statements takes care of the corner cells
    upd->push('X', 1, 0);
    upd->push('X', 0, 0);
    upd->push('X', 0, 1);
  }
  else if(arl[1][y] == 'X'){ //top right
    upd->push('X', 0, y);
    upd->push('X', 1, v-1);
    upd->push('X', 0, v-1);
  }
  else if(arl[x][y]){ //bottom right
    upd->push('X', x, v-1);
    upd->push('X', z-1, v-1);
    upd->push('X', z-1, y);
  }
  else if(arl[x][1]){//bottom left
    upd->push('X', 3, 0);
    upd->push('X', z-1, 0);
    upd->push('X', z-1, 1);
  }

  for(int i = 1; i <= y; ++i){//takes care of row 1 mid top
    if(arl[1][i] == 'X'){
      arl[0][i] == 'X';
    }
  }
  for(int i = 1; i <= y; ++i){// takes care of bottom row down
    if(arl[x][i] == 'X'){
      arl[z-1][i] == 'X';
    }
  }
  for(int i = 1; i <= x; ++i){ //takes care of left row vertical
    if(arl[i][1] == 'X'){
      arl[i][0] == 'X';
    }
  }
  for(int i = 1; i <= x; ++i){ //takes care of right row vertical
    if(arl[i][y] == 'X'){
      arl[i][v-1] == 'X';
    }
  }


  for(int i = 0; i< x; ++i ){ //this decides whether a cell would live or die
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
        upd->push('-',i,j);
      }
      else if(neighbors == 2){
        upd->push(arr[i][j],i,j);
      }
      else if(neighbors == 3){
        upd->push('X',i,j);
      }
      else if(neighbors > 3){
        upd->push('-',i,j);
      }
    }
  }
  for(int i = 1; i<= x; ++i ){ //this copies the contents of the updated board back to the old board
    for(int j = 1; j <= y; ++j){
      if(arl[i][j] == 'X'){
        old->push('X',i-1,j-1);
      }
      else if(arl[i][j] =='-'){
        old->push('-',i-1,j-1);
      }
    }
  }
  a = old; //a now equals the old board
  delete upd;
  delete old;
  return a;
}
