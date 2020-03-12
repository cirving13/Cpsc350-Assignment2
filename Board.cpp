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
  for(int i = 0; i < rows; ++i)
  {
    currentp[i] = new char[columns];
    for(int j = 0; j < columns; ++j)
    {
      currentp[i][j]='-';
    }
  }
  nextp = new char*[rows];
  for(int i = 0; i < rows; ++i)
  {
    nextp[i] = new char[columns];
    for(int j = 0; j < columns; ++j)
    {
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
string Board::outRandBoard(int r, int c) //outputs rand board, ignore
{
  string output;
  for(int i = 0;i < r;i++)
  {
    for(int j = 0;j < c;j++)
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
void Board::randBoard(int r, int c, float val) //creates random board
{
  setColumns(c);
  setRows(r);
  createBoard(r,c);
  for(int i = 0; i < r; ++i)
  {
    for(int j = 0; j < c; ++j)
    {
      currentp[i][j] = '-';
    }
  }
  int randNum = c*r*val;
  for(int i = 0; i < randNum; ++i)
  {
    int v1 = rand() % r;
    int v2 = rand() % c;
    currentp[v1][v2] = 'X';
  }
  cout << outRandBoard(r,c);
}
int Board::getColumns(){
  return columns;
}
int Board::getRows(){   // accessors and modifiers for the private variables
  return rows;
}
void Board::setRows(int r)
{
  rows = r;
}
void Board::setColumns(int c)
{
  columns = c;
}
void Board::logic(int neighbors, int rows, int columns)
{
  if (neighbors < 2)
    nextp[rows][columns] = '-';
  else if (neighbors == 2)
    nextp[rows][columns] = '-';
  else if (neighbors == 3)
    nextp[rows][columns] = currentp[rows][columns];
  else if (neighbors > 3)
    nextp[rows][columns] = '-';
}
Board* Board::classic(Board *a){ //method to loop through a board and output the new board
  int rows = a->getRows();
  int columns = a->getColumns();
  int neighbors;

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < columns; ++j)
    {
      if (i == 0 && j == 0)
      {
        neighbors = cornerTL(i,j);
        logic(neighbors, i, j);
      }
      else if (i == 0 && j == columns - 1)
      {
        neighbors = cornerTR(i,j);
        logic(neighbors, i, j);
      }
      else if (i == rows - 1 && j == 0)
      {
        neighbors = cornerBL(i,j);
        logic(neighbors, i, j);
      }
      else if (i == rows - 1 && j == columns - 1)
      {
        neighbors = cornerBR(i,j);
        logic(neighbors, i, j);
      }
      else if (i == 0 && j != 0 && j != columns - 1)
      {
        neighbors = sideT(i,j);
        logic(neighbors, i, j);
      }
      else if (i == rows - 1 && j != 0 && j != columns - 1 )
      {
        neighbors = sideB(i,j);
        logic(neighbors, i, j);
      }
      else if (j == 0 && i != 0 && i != rows - 1)
      {
        neighbors = sideL(i,j);
        logic(neighbors, i, j);
      }
      else if (j == columns - 1 && i != 0 && i != rows - 1)
      {
        neighbors = sideR(i,j);
        logic(neighbors, i, j);
      }
      else
      {
        neighbors = middle(i,j);
        logic(neighbors, i, j);
      }
    }
  }
  for(int i = 0; i < rows; ++i)
  {
    for(int j = 0; j < columns; ++j)
    {
      currentp[i][j] = nextp[i][j];
    }
  }
  return a;
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

// void ClassicMode::NewGen()
// {
//   for(int i = 0; i < numRows; ++i)
//   {
//     for(int j = 0; j < numColumns; ++j)
//     {
//       previousMap[i][j] = currentMap[i][j];
//     }
//   }
//
//   int numAround;
//
//   for(int i = 0; i < numRows; ++i)
//   {
//     for(int j = 0; j < numColumns; ++j){
//       numAround = 0;
//       if(previousMap[i][j] == 'X'){
//         if(i == 0){
//           if(j == 0){
//             numAround = CheckCornerTL(i, j);
//           }
//           else if(j == (numColumns - 1)){
//             numAround = CheckCornerTR(i, j);
//           }
//           else
//           {
//             numAround = CheckSideT(i, j);
//           }
//         }
//         else if(i == (numRows - 1))
//         {
//           if(j == 0)
//           {
//             numAround = CheckCornerBL(i, j);
//           }
//           else if(j == (numColumns - 1))
//           {
//             numAround = CheckCornerBR(i, j);
//           }
//           else
//           {
//             numAround = CheckSideB(i, j);
//           }
//         }
//         else if(j == 0)
//         {
//           if(i != 0 && i != (numRows -1))
//           {
//             numAround = CheckSideL(i, j);
//           }
//         }
//         else if(j == (numColumns - 1))
//         {
//           if(i != 0 && i != (numRows -1))
//           {
//             numAround = CheckSideR(i, j);
//           }
//         }
//         else
//         {
//           numAround = CheckMiddle(i, j);
//         }
//
//         if(numAround <= 1)
//         {
//           currentMap[i][j] = '-';
//         }
//         else if(numAround < 3)
//         {
//
//         }
//         else if(numAround < 4)
//         {
//           currentMap[i][j] = 'X';
//         }
//         else
//         {
//           currentMap[i][j] = '-';
//         }
//       }
//     }
//   }
// }
