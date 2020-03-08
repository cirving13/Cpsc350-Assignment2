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
  int decision;
  string fileInput;
  char mode;
  cout << "welcome to the game of life!" << endl;
  cout << "if you would like to provide a file for the game, press 1. if not, press 0:" << endl; //asks the user if they would like to provide a file or not
  cin >> decision;
  if(decision == 1){ //if the user decides to provide a file
    cout << "enter filename" << endl;
    cin >> fileInput;
    g->readFile(fileInput);
  }
  else if(decision == 0){ //if the user decides not to provide a file
    int r;
    int c;
    cout << "file not provided" << endl;                        //this loop asks the user for the number of rows and columns for the board
    cout << "Enter the number of rows for the board:" << endl;
    cin >> r;
    cout << "Enter the number of columns for the board:" << endl;
    cin >> c;
    g->setRows(r);     //getters and setters are used to store the variables
    g->setColumns(c);
  }
  cout << "what kind of boundary mode would you like to run in?" << endl;
  cout << "enter c for classic mode, d for donut mode, or m for mirror mode" << endl;
  cin >> mode;
  if(mode == 'c' || 'C'){  //if the mode is classic
    //classic mode implementations
  }
  else if(mode == 'd' || 'D'){  //if the mode is donut
    //donut mode implementations
  }
  else{ //if the mode is mirror

  }


  delete g;
  return 0;

}
