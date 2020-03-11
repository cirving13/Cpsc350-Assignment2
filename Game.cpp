#include "Game.h"

Game::Game()
{

}
Game::~Game()
{
  cout << "Closing Game" << endl;
}
// void Game::writeConsole()
// {
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
// void Game::logic(int neighbors, int rows, int columns)
// {
//   if (neighbors < 2)
//     nextp[rows][columns] = '-';
//   if (neighbors == 2)
//     nextp[rows][columns] = '-';
//   if (neighbors == 3)
//     nextp[rows][columns] = currentp[rows][columns];
//   if (neighbors > 3)
//     nextp[rows][columns] = '-';
// }
// Board* Game::classic(Board *a){ //method to loop through a board and output the new board
//   int rows = a->getRows();
//   int columns = a->getColumns();
//   int neighbors;
//
//   for (int i = 0; i < rows; ++i)
//   {
//     for (int j = 0; j < columns; ++j)
//     {
//       if (i == 0 && j == 0)
//       {
//         neighbors = cornerTL(i,j);
//         logic(neighbors, i, j);
//       }
//       else if (i == 0 && j == columns - 1)
//       {
//         neighbors = cornerTR(i,j);
//         logic(neighbors, i, j);
//       }
//       else if (i == rows - 1 && j == 0)
//       {
//         neighbors = cornerBL(i,j);
//         logic(neighbors, i, j);
//       }
//       else if (i == rows - 1 && j == columns - 1)
//       {
//         neighbors = cornerBR(i,j);
//         logic(neighbors, i, j);
//       }
//       else if (i == 0 && j != 0 && j != columns - 1)
//       {
//         neighbors = sideT(i,j);
//         logic(neighbors, i, j);
//       }
//       else if (i == rows - 1 && j != 0 && j != columns - 1 )
//       {
//         neighbors = sideB(i,j);
//         logic(neighbors, i, j);
//       }
//       else if (j == 0 && i != 0 && i != rows - 1)
//       {
//         neighbors = sideL(i,j);
//         logic(neighbors, i, j);
//       }
//       else if (j == columns - 1 && i != 0 && i != rows - 1)
//       {
//         neighbors = sideR(i,j);
//         logic(neighbors, i, j);
//       }
//       else
//       {
//         neighbors = middle(i,j);
//         logic(neighbors, i, j);
//       }
//     }
//   }
//   return a;
// }
// int Game::cornerTL(int rows, int columns)
// {
//   int neighbors = 0;
//   if(currentp[rows][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   return neighbors;
// }
//
// int Game::cornerTR(int rows, int columns)
// {
//   int neighbors = 0;
//   if(currentp[rows+1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   return neighbors;
// }
//
// int Game::cornerBL(int rows, int columns)
// {
//   int neighbors = 0;
//   if(currentp[rows][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows-1][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows-1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   return neighbors;
// }
//
// int Game::cornerBR(int rows, int columns)
// {
//   int neighbors = 0;
//   if(currentp[rows-1][columns] == 'X')
//   {
//      neighbors++;
//   }
//   if(currentp[rows-1][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   return neighbors;
// }
//
// int Game::sideT(int rows, int columns)
// {
//   int neighbors = 0;
//   if(currentp[rows][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   return neighbors;
// }
//
// int Game::sideR(int rows, int columns)
// {
//   int neighbors = 0;
//   if(currentp[rows-1][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows-1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   return neighbors;
// }
//
// int Game::sideB(int rows, int columns)
// {
//   int neighbors = 0;
//   if(currentp[rows][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows-1][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows-1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows-1][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   return neighbors;
// }
//
// int Game::sideL(int rows, int columns)
// {
//   int neighbors = 0;
//   if(currentp[rows-1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows-1][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   return neighbors;
// }
//
// int Game::middle(int rows, int columns)
// {
//   int neighbors = 0;
//   if(currentp[rows][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows-1][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows-1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows-1][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns-1] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns] == 'X')
//   {
//     neighbors++;
//   }
//   if(currentp[rows+1][columns+1] == 'X')
//   {
//     neighbors++;
//   }
//   return neighbors;
// }
//sample for the donut mode, not ready for testing
// Board* Game::nextGenDon(Board *a,int x,int y){
//   int z = x+2;
//   int v = y+2;
//   char** arr = a->boardP;
//   Board *upd = new Board();
//   Board *old = new Board();
//   old->createBoard(x,y);
//   upd->createBoard(z,v);
//   char** arl = upd->boardP; //this is the pointer for the new board
//
//   for(int i = 0; i < x; ++i){   //this will add everthing that's in the old board to the new board
//     for(int j = 0; j < y; ++j){
//       upb->push(arr[i][j],i+1,j+1); //upb now points to the same exact contents as the input board
//     }
//   }
//
//   if(arl[1][1] == 'X'){// top left                     //these series of if statements takes care of the corner cells
//     upb->push('X', 1, 0);
//     upb->push('X', 0, 0);
//     upb->push('X', 0, 1);
//   }
//   else if(arl[1][y] == 'X'){ //top right
//     upb->push('X', 0, y);
//     upb->push('X', 1, v-1);
//     upb->push('X', 0, v-1);
//   }
//   else if(arl[x][y]){ //bottom right
//     upb->push('X', x, v-1);
//     upb->push('X', z-1, v-1);
//     upb->push('X', z-1, y);
//   }
//   else if(arl[x][1]){//bottom left
//     upb->push('X', 3, 0);
//     upb->push('X', z-1, 0);
//     upb->push('X', z-1, 1);
//   }
//
// for(int i = 1; i <= y; ++i){//takes care of row 1 mid top
//   if(arl[1][i] == 'X'){
//     arl[0][i] == 'X';
//   }
// }
// for(int i = 1; i <= y; ++i){// takes care of bottom row down
//   if(arl[x][i] == 'X'){
//     arl[z-1][i] == 'X';
//   }
// }
// for(int i = 1; i <= x; ++i){ //takes care of left row vertical
//   if(arl[i][1] == 'X'){
//     arl[i][0] == 'X';
//   }
// }
// for(int i = 1; i <= x; ++i){ //takes care of right row vertical
//   if(arl[i][y] == 'X'){
//     arl[i][v-1] == 'X';
//   }
// }
//
//
//   for(int i = 0; i< x; ++i ){ //this decides whether a cell would live or die
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
//         upb->push('-',i,j);
//       }
//       else if(neighbors == 2){
//         upb->push(arr[i][j],i,j);
//       }
//       else if(neighbors == 3){
//         upb->push('X',i,j);
//       }
//       else if(neighbors > 3){
//         b->push('-',i,j);
//       }
//     }
//   }
//   for(int i = 1; i<= x; ++i ){ //this copies the contents of the updated board back to the old board
//     for(int j = 1; j <= y; ++j){
//       if(arl[i][j] == 'X'){
//         old->push('X',i-1,j-1);
//       }
//       else if(arl[i][j] =='-'){
//         old->push('-',i-1,j-1);
//       }
//     }
//   }
//   a = old; //a now equals the old board
//   delete upb;
//   delete old;
//   return a;
// }
