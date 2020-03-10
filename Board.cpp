#include "Board.h"

Board::Board()
{

}
Board::~Board()
{
  delete boardP;
}

void Board::createBoard(int rows, int columns)
{
  boardP = new char*[rows];
  for(int i = 0; i < rows; ++i){
    boardP[i] = new char[columns];
    for(int j = 0; j < columns; ++j){
      boardP[i][j]='-';
    }
  }
}
void Board::push(char val, int rowLocation, int columnLocation)
{
  boardP[rowLocation][columnLocation] = val;
}
char Board::peek(int rowLocation, int columnLocation)
{
  return boardP[rowLocation][columnLocation];
}
string Board::returnBoard(){
  string output;
  for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
      output = output + boardP[i][j];
    }
    output+="\n";
  }
  return output;
}
void Board::readFile(string input) //opens and reads a file, finding basic information about the file
{
  ifstream inFile;
  inFile.open(input);
  char c;
  inFile >> c;
  rows = (int) c - 48;
  inFile >> c;
  columns = (int) c - 48;
  if (!inFile)
  {
    cout << "Unable to open file " + input << endl;
    exit(1);
  }
  int charCount = 0;
  int i = 0;
  int j = 0;
  // string line;

  boardP = new char*[rows];
  for (int i = 0; i < rows+1; ++i)  //This method gives me a null pointer method and prints a bunch of shit
  {
    boardP[i] = new char[columns];
    getline(inFile,line);
    j = 0;
    for (char c: line)
    {
      cout << c;
      boardP[i][j]=c;
      ++j;
    }
    cout << endl;
  }
  // while (!inFile.eof()){ //this method gives me a segmentation fault and makes me want to fucking die
  //   inFile >> noskipws >> c;
  //   if(c == 'X' || c == '-'){
  //     // cout << c;
  //     boardP[i][j]=c;
  //     ++j;
  //   }
  //   else if(c == '\n'){
  //     boardP[i] = new char[columns];
  //     cout << endl;
  //     ++i;
  //     j = 0;
  //   }
  // }
  inFile.close();
}
