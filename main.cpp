#include "Board.h"

int main(int argc, char** argv)
{
  Board* b = new Board();
  b->randBoard(10,10,0.4);
  while(b->isStable() != true){
    b->classic();
  }


  // Board* b = new Board();
  // int decision;
  // int k;
  // string fileInput;
  // char mode;
  // cout << "welcome to the game of life!" << endl;
  // cout << "if you would like to provide a file for the game, press 1. if not, press 0:" << endl; //asks the user if they would like to provide a file or not
  // cin >> decision;
  // if(decision == 1){ //if the user decides to provide a file
  //   cout << "enter filename" << endl;
  //   cin >> fileInput;
  //   b->readFile(fileInput);
  // }
  // else if(decision == 0){ //if the user decides not to provide a file
  //   int r;
  //   int c;
  //   float val;
  //
  //   cout << "file not provided" << endl; //this loop asks the user for the number of rows and columns for the board
  //   cout << "Enter the number of rows for the board:" << endl;
  //   cin >> r;
  //   cout << "Enter the number of columns for the board:" << endl;
  //   cin >> c;
  //   cout << "What density would you like the world to be? (value between 0 and 1) " << endl;
  //   cin >> val;
  //   b->setRows(r);     //getters and setters are used to store the variables
  //   b->setColumns(c);
  //   b->randBoard(r, c, val);
  // }
  // cout << "what kind of boundary mode would you like to run in?" << endl;
  // cout << "enter c for classic mode, d for donut mode, or m for mirror mode" << endl;
  // cin >> mode;
  // if(mode == 'c' || 'C'){  //if the mode is classic
  //   int add;
  //   cout << "Classic mode has been selected" << endl;
  //   cout << endl;
  //   cout << "press one of the numbers to continue"
  //   cout << "1. Add a brief pause between generations" << endl;
  //   cout << "2. Press enter to display the next generation" << endl;
  //   cout << "3. Output the results to a file." << endl;
  //   cin >> add;
  // }
  // else if(mode == 'd' || 'D'){  //if the mode is donut
  //   cout << "Donut mode has been selected" << endl;
  // }
  // else if (mode == 'm' || 'M'){ //if the mode is mirror
  //   cout << "Mirror mode has been selected" << endl;
  // }
  // else{
  //   exit(1);
  // }
  //
  //
  // delete b;
  return 0;

}
