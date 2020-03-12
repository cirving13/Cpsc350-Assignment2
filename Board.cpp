#include "Board.h"

Board::Board()
{

}
Board::~Board()
{
  delete nextp;
  delete currentp;
}

void Board::createBoard(int rows, int columns) //creates board
{
  currentp = new char*[rows];
  nextp = new char*[rows];
  for(int i = 0; i < rows; ++i)
  {
    currentp[i] = new char[columns];
    nextp[i] = new char[columns];
    for(int j = 0; j < columns; ++j)
    {
      currentp[i][j]='-';
      nextp[i][j]='-';
    }
  }
}
string Board::returnBoard() //outputs board
{
  string output;
  for(int i = 0;i < rows;i++)
  {
    for(int j = 0;j < columns;j++)
    {
      output = output + currentp[i][j];
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
  string line;
  getline(inFile, line);
  rows = stoi(line);
  getline(inFile, line);
  columns = stoi(line);
  createBoard(rows,columns);
  if (!inFile)
  {
    cout << "Unable to open file " + input << endl;
    exit(1);
  }
  int i = 0;
  int j = 0;

  while (!inFile.eof())
  {
    inFile >> noskipws >> c;
    if(c == 'X' || c == '-')
    {
      currentp[i][j] = c;
      ++j;
    }
    else if(c == '\n')
    {
      ++i;
      j = 0;
    }
  }
  inFile.close();
}
void Board::writeConsole(int decision)
{
  int generation = 0;
  while(true)
  {
    cout << "generation number: " << generation << endl;
    if(decision = 1)
    {
      classic();
    }
    else if(decision = 2)
    {
      mirror();
    }
    else
    {
      donut();
    }
    cout << returnBoard() << endl;
    ++generation;
    sleep(1);
    if(isEmpty())
    {
      break;
    }
  }
}
void Board::writeConsoleEnter(int decision)
{
  int generation = 0;
  while(true)
  {
    cout << "generation number: " << generation << endl;
    if(decision = 1)
    {
      classic();
    }
    else if(decision = 2)
    {
      mirror();
    }
    else
    {
      donut();
    }
    cout << returnBoard() << endl;
    ++generation;
    cout << "press enter to loop again" << endl;
    cin.ignore();
    if(isEmpty())
    {
      break;
    }
    if(generation > 40)
    {
      cout << "stable enough" << endl;
      break;
    }
  }
}
void Board::writeFile(string input, int decision)
{
  ofstream outFile;
  outFile.open(input, ios::app);
  int generation = 0;
  while(true)
  {
    outFile << "generation number: " << generation << endl;
    if(decision = 1)
    {
      classic();
    }
    else if(decision = 2)
    {
      mirror();
    }
    else
    {
      donut();
    }
    outFile << returnBoard() << endl;
    ++generation;
    if(isEmpty())
    {
      break;
    }
    if(generation > 40)
    {
      outFile << "stable enough" << endl;
      break;
    }
  }
outFile.close();
}
void Board::randBoard(int r, int c, float val) //creates random board
{
  rows = r;
  columns = c;
  createBoard(rows,columns);
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      currentp[i][j] = '-';
    }
  }
  int randNum = c*r*val;
  for(int i = 0; i < randNum; i++)
  {
    int v1 = rand() % r;
    int v2 = rand() % c;
    currentp[v1][v2] = 'X';
  }
  cout << returnBoard() << endl;
}

void Board::logic(int neighbors, int rows, int columns) //method that determines life or death
{
  if (neighbors < 2)
    nextp[rows][columns] = '-';
  else if (neighbors == 2)
    nextp[rows][columns] = currentp[rows][columns];
  else if (neighbors == 3)
    nextp[rows][columns] = 'X';
  else if (neighbors > 3)
    nextp[rows][columns] = '-';
}

void Board::classic(){ //method to loop through a board and output the new board
  int neighbors;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (i == 0 && j == 0)
      {
        neighbors = cornerTL(i,j); //corner top left
        logic(neighbors, i, j);
      }
      else if (i == 0 && j == columns - 1)
      {
        neighbors = cornerTR(i,j);  //corner top right
        logic(neighbors, i, j);
      }
      else if (i == rows - 1 && j == 0)
      {
        neighbors = cornerBL(i,j);  //corner bottom left
        logic(neighbors, i, j);
      }
      else if (i == rows - 1 && j == columns - 1)
      {
        neighbors = cornerBR(i,j);  //corner bottom right
        logic(neighbors, i, j);
      }
      else if (i == 0 && j != 0 && j != columns - 1)
      {
        neighbors = sideT(i,j);    //side of top row
        logic(neighbors, i, j);
      }
      else if (i == rows - 1 && j != 0 && j != columns - 1 )
      {
        neighbors = sideB(i,j);   //side of bottom row
        logic(neighbors, i, j);
      }
      else if (j == 0 && i != 0 && i != rows - 1)
      {
        neighbors = sideL(i,j);  //side of left column
        logic(neighbors, i, j);
      }
      else if (j == columns - 1 && i != 0 && i != rows - 1)
      {
        neighbors = sideR(i,j);  //side of right column
        logic(neighbors, i, j);
      }
      else
      {
        neighbors = middle(i,j); //the rest that aren't next to the borders
        logic(neighbors, i, j);
      }
    }
  }
  if(isStable())
  {
    cout << "system is stable" << endl;
    exit(1);
  }
  for(int i = 0; i < rows; i++)  //these nested for loops input the resulting cels of the next input to the current input
  {
    for(int j = 0; j < columns; j++)
    {
      currentp[i][j] = nextp[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
bool Board::isEmpty()
{
  bool x = true;
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      if(currentp[i][j] == 'X')
      {
        x = false;
      }
    }
  }
  return x;
}
bool Board::isStable(){ //checks if program is stable
  int cellequalCount = 0;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      if(currentp[i][j] != nextp[i][j]){
        return false;
      }
    }
  }
  return true;
}

void Board::donut(){ //donut class
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      int neighbors = 0;
      if (i == 0 && j == 0)
      {
        if (currentp[0][columns-1] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-1][0] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-1][columns-1] == 'X')
        {
          neighbors++;
        }
        if (currentp[1][columns-1] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-1][1] == 'X')
        {
          neighbors++;
        }
        neighbors += cornerTL(i,j);
        logic(neighbors, i, j);
      }
      else if (i == 0 && j == (columns - 1))
      {
        if (currentp[0][0] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-1][columns-1] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-1][0] == 'X')
        {
          neighbors++;
        }
        if (currentp[1][0] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-1][columns-2] == 'X')
        {
          neighbors++;
        }
        neighbors += cornerTR(i,j);
        logic(neighbors, i, j);
      }
      else if (i == rows - 1 && j == 0)
      {
        if (currentp[0][0] == 'X')
        {
          neighbors++;
        }
        if (currentp[0][1] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-1][columns-1] == 'X')
        {
          neighbors++;
        }
        if (currentp[0][columns-1] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-2][columns-1] == 'X')
        {
          neighbors++;
        }
        neighbors += cornerBL(i,j);
        logic(neighbors, i, j);
      }
      else if (i == rows - 1 && j == columns - 1)
      {
        if (currentp[0][0] == 'X')
        {
          neighbors++;
        }
        if (currentp[0][columns-1] == 'X')
        {
          neighbors++;
        }
        if (currentp[0][columns-2] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-1][0] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-2][0] == 'X')
        {
          neighbors++;
        }
        neighbors += cornerBR(i,j);
        logic(neighbors, i, j);
      }
      else if (i == 0 && j != 0 && j != columns - 1)
      {
        if (currentp[rows-1][j] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-1][j+1] == 'X')
        {
          neighbors++;
        }
        if (currentp[rows-1][j-1] == 'X')
        {
          neighbors++;
        }
        neighbors += sideT(i,j);
        logic(neighbors, i, j);
      }
      else if (i == rows - 1 && j != 0 && j != columns - 1 )
      {
        if (currentp[0][j] == 'X')
        {
          neighbors++;
        }
        if (currentp[0][j+1] == 'X')
        {
          neighbors++;
        }
        if (currentp[0][j-1] == 'X')
        {
          neighbors++;
        }
        neighbors += sideB(i,j);
        logic(neighbors, i, j);
      }
      else if (j == 0 && i != 0 && i != rows - 1)
      {
        if (currentp[i-1][columns-1] == 'X')
        {
          neighbors++;
        }
        if (currentp[i][columns-1] == 'X')
        {
          neighbors++;
        }
        if (currentp[i+1][columns-1] == 'X')
        {
          neighbors++;
        }
        neighbors += sideL(i,j);
        logic(neighbors, i, j);
      }
      else if (j == columns - 1 && i != 0 && i != rows - 1)
      {
        if (currentp[i-1][0] == 'X')
        {
          neighbors++;
        }
        if (currentp[i][0] == 'X')
        {
          neighbors++;
        }
        if (currentp[i+1][0] == 'X')
        {
          neighbors++;
        }
        neighbors += sideR(i,j);
        logic(neighbors, i, j);
      }
      else
      {
        neighbors = middle(i,j);
        logic(neighbors, i, j);
      }
    }
  }
  if(isStable())
  {
    cout << "system is stable" << endl;
    exit(1);
  }
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      currentp[i][j] = nextp[i][j];
    }
    cout << endl;
  }
}
int Board::cornerTL(int rows, int columns)
{
  int neighbors = 0;
  if(currentp[rows][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns] == 'X')
  {
    neighbors++;
  }
  return neighbors;
}

int Board::cornerTR(int rows, int columns)
{
  int neighbors = 0;
  if(currentp[rows+1][columns] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows][columns-1] == 'X')
  {
    neighbors++;
  }
  return neighbors;
}

int Board::cornerBL(int rows, int columns)
{
  int neighbors = 0;
  if(currentp[rows][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows-1][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows-1][columns] == 'X')
  {
    neighbors++;
  }
  return neighbors;
}

int Board::cornerBR(int rows, int columns)
{
  int neighbors = 0;
  if(currentp[rows-1][columns] == 'X')
  {
     neighbors++;
  }
  if(currentp[rows-1][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows][columns-1] == 'X')
  {
    neighbors++;
  }
  return neighbors;
}

int Board::sideT(int rows, int columns)
{
  int neighbors = 0;
  if(currentp[rows][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns+1] == 'X')
  {
    neighbors++;
  }
  return neighbors;
}

int Board::sideR(int rows, int columns)
{
  int neighbors = 0;
  if(currentp[rows-1][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows-1][columns] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns] == 'X')
  {
    neighbors++;
  }
  return neighbors;
}

int Board::sideB(int rows, int columns)
{
  int neighbors = 0;
  if(currentp[rows][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows-1][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows-1][columns] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows-1][columns+1] == 'X')
  {
    neighbors++;
  }
  return neighbors;
}
int Board::sideL(int rows, int columns)
{
  int neighbors = 0;
  if(currentp[rows-1][columns] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows-1][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns] == 'X')
  {
    neighbors++;
  }
  return neighbors;
}

int Board::middle(int rows, int columns)
{
  int neighbors = 0;
  if(currentp[rows][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows-1][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows-1][columns] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows-1][columns+1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns-1] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns] == 'X')
  {
    neighbors++;
  }
  if(currentp[rows+1][columns+1] == 'X')
  {
    neighbors++;
  }
  return neighbors;
}

void Board::mirror(){
  int neighbors;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      if (i == 0 && j == 0)
      {
        if(currentp[i][j] == 'X'){
          if(currentp[i+1][j] == 'X' && currentp[i][j+1] == 'X'){
            neighbors = cornerTL(i,j) + 5; //corner top left
            logic(neighbors, i, j);
          }
          else if(currentp[i+1][j] == 'X' || currentp[i][j+1] == 'X'){
            neighbors = cornerTL(i,j) + 4; //corner top left
            logic(neighbors, i, j);
          }
          else{
            neighbors = cornerTL(i,j) + 3; //corner top left
            logic(neighbors, i, j);
          }
        }
        else if(currentp[i][j] == '-'){
          if(currentp[i+1][j] == 'X' && currentp[i][j+1] == 'X'){
            neighbors = cornerTL(i,j) + 2; //corner top left
            logic(neighbors, i, j);
          }
          else if(currentp[i+1][j] == 'X' || currentp[i][j+1] == 'X'){
            neighbors = cornerTL(i,j) + 1; //corner top left
            logic(neighbors, i, j);
          }
          else{
            neighbors = cornerTL(i,j); //corner top left
            logic(neighbors, i, j);
          }
        }
      }
      else if (i == 0 && j == columns - 1)//corner top Right
      {
        if(currentp[i][j] == 'X'){
          if(currentp[i][j-1] == 'X' && currentp[i+1][j] == 'X'){
            neighbors = cornerTR(i,j) + 5; //corner top right
            logic(neighbors, i, j);
          }
          else if(currentp[i][j-1] == 'X' || currentp[i+1][j] == 'X'){
            neighbors = cornerTR(i,j) + 4; //corner top right
            logic(neighbors, i, j);
          }
          else{
            neighbors = cornerTR(i,j) + 3; //corner top right
            logic(neighbors, i, j);
          }
        }
        else if(currentp[i][j] == '-'){
          if(currentp[i][j-1] == 'X' && currentp[i+1][j] == 'X'){
            neighbors = cornerTR(i,j) + 2; //corner top right
            logic(neighbors, i, j);
          }
          else if(currentp[i][j-1] == 'X' || currentp[i+1][j] == 'X'){
            neighbors = cornerTR(i,j) + 1; //corner top right
            logic(neighbors, i, j);
          }
          else{
            neighbors = cornerTR(i,j); //corner top right
            logic(neighbors, i, j);
          }
        }
      }
      else if (i == rows - 1 && j == 0) //corner bottom left
      {
        if(currentp[i][j] == 'X'){
          if(currentp[i-1][j] == 'X' && currentp[i][j+1] == 'X'){
            neighbors = cornerBL(i,j) + 5;
            logic(neighbors, i, j);
          }
          else if(currentp[i-1][j] == 'X' || currentp[i][j+1] == 'X'){
            neighbors = cornerBL(i,j) + 4;
            logic(neighbors, i, j);
          }
          else{
            neighbors = cornerBL(i,j) + 3;
            logic(neighbors, i, j);
          }
        }
        else if(currentp[i][j] == '-'){
          if(currentp[i-1][j] == 'X' && currentp[i][j+1] == 'X'){
            neighbors = cornerBL(i,j) + 2;
            logic(neighbors, i, j);
          }
          else if(currentp[i-1][j] == 'X' || currentp[i][j+1] == 'X'){
            neighbors = cornerBL(i,j) + 1;
            logic(neighbors, i, j);
          }
          else{
            neighbors = cornerBL(i,j);
            logic(neighbors, i, j);
          }
        }
      }
      else if (i == rows - 1 && j == columns - 1) //corner bottom Right
      {
        if(currentp[i][j] == 'X'){
          if(currentp[i][j-1] == 'X' && currentp[i-1][j] == 'X'){
            neighbors = cornerBR(i,j) + 5;
            logic(neighbors, i, j);
          }
          else if(currentp[i][j-1] == 'X' || currentp[i-1][j] == 'X'){
            neighbors = cornerBR(i,j) + 4;
            logic(neighbors, i, j);
          }
          else{
            neighbors = cornerBR(i,j) + 3;
            logic(neighbors, i, j);
          }
        }
        else if(currentp[i][j] == '-'){
          if(currentp[i][j-1] == 'X' && currentp[i-1][j] == 'X'){
            neighbors = cornerBR(i,j) + 2;
            logic(neighbors, i, j);
          }
          else if(currentp[i][j-1] == 'X' || currentp[i-1][j] == 'X'){
            neighbors = cornerBR(i,j) + 1;
            logic(neighbors, i, j);
          }
          else{
            neighbors = cornerBR(i,j);
            logic(neighbors, i, j);
          }
        }
      }
      else if (i == 0 && j != 0 && j != columns - 1) //sideT
      {
        if(currentp[i][j] == 'X'){
          if(currentp[i][j-1] == 'X' && currentp[i][j+1] == 'X'){
            neighbors = sideT(i,j) + 3;
            logic(neighbors, i, j);
          }
          else if(currentp[i][j-1] == 'X' || currentp[i][j+1] == 'X'){
            neighbors = sideT(i,j) + 2;
            logic(neighbors, i, j);
          }
          else{
            neighbors = sideT(i,j) + 1;
            logic(neighbors, i, j);
          }
        }
        else if(currentp[i][j] == '-'){
          if(currentp[i][j-1] == 'X' && currentp[i][j+1] == 'X'){
            neighbors = sideT(i,j) + 2;
            logic(neighbors, i, j);
          }
          else if(currentp[i][j-1] == 'X' || currentp[i][j+1] == 'X'){
            neighbors = sideT(i,j) + 1;
            logic(neighbors, i, j);
          }
          else{
            neighbors = sideT(i,j);
            logic(neighbors, i, j);
          }
        }
      }
      else if (i == rows - 1 && j != 0 && j != columns - 1 ) //sideB
      {
        if(currentp[i][j] == 'X'){
          if(currentp[i][j-1] == 'X' && currentp[i][j+1] == 'X'){
            neighbors = sideB(i,j) + 3;
            logic(neighbors, i, j);
          }
          else if(currentp[i][j-1] == 'X' || currentp[i][j+1] == 'X'){
            neighbors = sideB(i,j) + 2;
            logic(neighbors, i, j);
          }
          else{
            neighbors = sideB(i,j) + 1;
            logic(neighbors, i, j);
          }
        }
        else if(currentp[i][j] == '-'){
          if(currentp[i][j-1] == 'X' && currentp[i][j+1] == 'X'){
            neighbors = sideB(i,j) + 2;
            logic(neighbors, i, j);
          }
          else if(currentp[i][j-1] == 'X' || currentp[i][j+1] == 'X'){
            neighbors = sideB(i,j) + 1;
            logic(neighbors, i, j);
          }
          else{
            neighbors = sideB(i,j);
            logic(neighbors, i, j);
          }
        }
      }
      else if (j == 0 && i != 0 && i != rows - 1) //sideL
      {
        if(currentp[i][j] == 'X'){
          if(currentp[i+1][j] == 'X' && currentp[i-1][j] == 'X'){
            neighbors = sideL(i,j) + 3;
            logic(neighbors, i, j);
          }
          else if(currentp[i+1][j] == 'X' || currentp[i-1][j] == 'X'){
            neighbors = sideL(i,j) + 2;
            logic(neighbors, i, j);
          }
          else{
            neighbors = sideL(i,j) + 1;
            logic(neighbors, i, j);
          }
        }
        else if(currentp[i][j] == '-'){
          if(currentp[i+1][j] == 'X' && currentp[i-1][j] == 'X'){
            neighbors = sideL(i,j) + 2;
            logic(neighbors, i, j);
          }
          else if(currentp[i+1][j] == 'X' || currentp[i-1][j] == 'X'){
            neighbors = sideL(i,j) + 1;
            logic(neighbors, i, j);
          }
          else{
            neighbors = sideL(i,j);
            logic(neighbors, i, j);
          }
        }
      }
      else if (j == columns - 1 && i != 0 && i != rows - 1)//sideR
      {
        if(currentp[i][j] == 'X'){
          if(currentp[i+1][j] == 'X' && currentp[i-1][j] == 'X'){
            neighbors = sideR(i,j) + 3;
            logic(neighbors, i, j);
          }
          else if(currentp[i+1][j] == 'X' || currentp[i-1][j] == 'X'){
            neighbors = sideR(i,j) + 2;
            logic(neighbors, i, j);
          }
          else{
            neighbors = sideR(i,j) + 1;
            logic(neighbors, i, j);
          }
        }
        else if(currentp[i][j] == '-'){
          if(currentp[i+1][j] == 'X' && currentp[i-1][j] == 'X'){
            neighbors = sideR(i,j) + 2;
            logic(neighbors, i, j);
          }
          else if(currentp[i+1][j] == 'X' || currentp[i-1][j] == 'X'){
            neighbors = sideR(i,j) + 1;
            logic(neighbors, i, j);
          }
          else{
            neighbors = sideR(i,j);
            logic(neighbors, i, j);
          }
        }
      }
      else
      {
        neighbors = middle(i,j); //the rest that aren't next to the borders
        logic(neighbors, i, j);
      }
    }
  }
  if(isStable())
  {
    cout << "system is stable" << endl;
    exit(1);
  }
  for(int i = 0; i < rows; i++)  //these nested for loops input the resulting cels of the next input to the current input
  {
    for(int j = 0; j < columns; j++)
    {
      currentp[i][j] = nextp[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
