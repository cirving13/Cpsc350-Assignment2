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


// }
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
// Board* Game::nextGen(Board *a,int x,int y){
//   char** arr = a->boardP;
//   Board *b = new Board();
//   b->createBoard(x,y);
//   for(int i = 0; i< x; ++i ){
//     for(int j = 0; j < y; ++j){
//       int neighbors = 0;
//       if(arr[i+1][j-1] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i+1][j] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i+1][j+1] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i][j-1] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i][j+1] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i-1][j-1] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i-1][j] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i-1][j+1] == 'X'){
//         neighbors++;
//       }
//       if(neighbors < 2){
//         b->push('-',i,j);
//       }
//       else if(neighbors == 2){
//         b->push(arr[i][j],i,j);
//       }
//       else if(neighbors == 3){
//         b->push('X',i,j);
//       }
//       else if(neighbors > 3){
//         b->push('-',i,j);
//       }
//     }
//   }
//   a = b;
//   delete b;
//   return a;
// }
// //sample for the donut mode
// Board* Game::nextGenDon(Board *a,int x,int y){
//   int z = x+2;
//   int v = y+2;
//   char** arr = a->boardP;
//   Board *old = new Board();
//   Board *upd = new Board();
//   old->createBoard(x,y);
//   upd->createBoard(z,v);
//   char** arl = upd->boardP; //this is the pointer for the new board
//
//   for(int i = 0; i< x; ++i){   //this will add everthing that's in the old board to the new board
//     for(int j = 0; j < y; ++j){
//       upb->push(arr[i][j],i+1,j+1);
//     }
//   }
//
//   if(arl[1][1] == 'X'){// top left                     //these series of if statements takes care of the corner cells
//     upb->push('X', 1, v-1);
//     upb->push('X', z-1, 1);
//   }
//   else if(arl[1][y] == 'X'){ //top right
//     upb->push('X', 1, 0);
//     upb->push('X', z-1, v-1);
//   }
//   else if(arl[x][y]){ //bottom right
//     upb->push('X', 0, y);
//     upb->push('X', x, 0);
//   }
//   else if(arl[x][1]){//bottom left
//     upb->push('X', 0, 1);
//     upb->push('X', x, v-1);
//   }
//
//   for(int i = 1; i <= x; ++i){ //this loop takes care of all the other barriers
//     for(int j = 1; j <= y; ++j){
//       if(arl[i][j] == 'X'){
//
//       }
//     }
//   }
//
//
//   for(int i = 0; i< x; ++i ){
//     for(int j = 0; j < y; ++j){
//       int neighbors = 0;
//       if(arr[i+1][j-1] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i+1][j] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i+1][j+1] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i][j-1] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i][j+1] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i-1][j-1] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i-1][j] == 'X'){
//         neighbors++;
//       }
//       else if(arr[i-1][j+1] == 'X'){
//         neighbors++;
//       }
//       if(neighbors < 2){
//         b->push('-',i,j);
//       }
//       else if(neighbors == 2){
//         b->push(arr[i][j],i,j);
//       }
//       else if(neighbors == 3){
//         b->push('X',i,j);
//       }
//       else if(neighbors > 3){
//         b->push('-',i,j);
//       }
//     }
//   }
//   a = b;
//   delete b;
//   return a;
// }
