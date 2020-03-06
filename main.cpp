#include "Game.h"
// do you want to use a file??
// gimme that file
// how big is your Game
// rows?
// colums?
// what game mode do you want to play? (classic, donut or mirror)
//
// char myArray = new Array[rows][colums];

int main(int argc, char** argv)
{

  Game *g = new Game();
  string fileInput;
  cout << "enter filename" << endl;
  cin >> fileInput;
  g->readFile(fileInput);

  delete g;
  return 0;
}
