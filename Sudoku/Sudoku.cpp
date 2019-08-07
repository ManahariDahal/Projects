/***********************************************************************
* Program:
*    Project 12, Sudoku
*    Sister Hansen, CS124
* Author:
*    Manahari Dahal
* Summary:
*    A program that allows the user to play Sudoku
*
*    Estimated:  7.0 hrs
*    Actual:     12.0 hrs
*      Working on the functions were hard. Got stuck on the editOneSquare
*      and showPossible spent at least 3 hours fixing it. I asked my
*      brother about the getPossibleValues function and I was able to
*      fix it from his suggestion.
****************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;

void getFileName(string &filename);
bool readFile(string &filename, char arrayBoard[][9]);
void boardOptions();
void display(int arrayBoard[][9]);
void interact(int arrayBoard[][9]);
void getWriteBoard(string &filename);
bool getWriteFile(string &filename, int arrayBoard[][9]);
void editOneSquare(int arrayBoard[][9]);
void getCoordinates(string &coordinates);
bool getValid(int r, int column, string &coordinates, int arrayBoard[][9]);
void getPossibleValues(int arrayBoard[][9]);
void showPossible(int r, int c, int arrayBoard[][9], int possible[]);


/****************************************************************
* A function that asks the user for the location of the
* board.
*****************************************************************/
void getFileName(string &filename)
{
  cout << "Where is your board located? ";
  cin >> filename;
  cin.ignore();
}




/****************************************************************
* A function that displays board options.
*****************************************************************/
void boardOptions()
{
  cout << "Options:" << endl;
  cout << "   ?  Show these instructions" << endl;
  cout << "   D  Display the board" << endl;
  cout << "   E  Edit one square" << endl;
  cout << "   S  Show the possible values for a square" << endl;
  cout << "   Q  Save and Quit" << endl << endl;
}


/****************************************************************
* A function that reads the files and stores the content
* in a 2-d array.
*****************************************************************/
bool readFile(string &filename, int arrayBoard[][9])
{
  ifstream fin(filename.c_str());

  if (fin.fail())
  {
    cout << "Error reading file." << endl;
    return 0;
  }


  for (int r = 0; r < 9; r++)
  {
    for (int c = 0; c < 9; c++)
    {
      fin >> arrayBoard[r][c];
    }
  }

  return true;
  fin.close();
}




/****************************************************************
* A function that writes the file that was read earlier and
* stores it for further use.
*****************************************************************/
bool getWriteFile(string &filename, int arrayBoard[][9])
{
  ofstream fout(filename.c_str());

  if (fout.fail())
  {
    return false;
  }

  for (int r = 0; r < 9; r++)
  {
    for (int c = 0; c < 9; c++)
    {
      fout << arrayBoard[r][c];

      if (c < 9 - 1)
      {
        fout << " ";
      }
    }

    if (r < 9 - 1)
    {
      fout << endl;
    }
  }

  fout.close();
  return true;
}




/****************************************************************
* A function that asks the user where they want to write
* the data to.
*****************************************************************/
void getWriteBoard(string &filename)
{
  cout << "What file would you like to write your board to: ";
  cin >> filename;
  cin.ignore();
}




/****************************************************************
* A function that displays the overall board of the game.
*****************************************************************/
void display(int arrayBoard[][9])
{
  cout << "   A B C D E F G H I" << endl;

  for (int r = 0; r < 9; r++)
  {
    cout << setw(3) << left << r + 1;

    for (int c = 0; c < 9; c++)
    {
      if ((c + 1) % 3 == 0 && (c + 1) % 9 != 0)
      {
        if (arrayBoard[r][c] == 0)
        {
          cout << " |";
        }

        else
        {
          cout << arrayBoard[r][c] << "|";
        }
      }


      else if ((c + 1) % 9 == 0)
      {
        if (arrayBoard[r][c] == 0)
        {
          cout << " \n";
        }

        else
        {
          cout << arrayBoard[r][c] << endl;
        }
      }


      else
      {
        if (arrayBoard[r][c] == 0)
        {
          cout << "  ";
        }

        else
        {
          cout << arrayBoard[r][c] << " ";
        }
      }
    }

    if ((r + 1) % 3 == 0 && (r + 1) % 9 != 0)
    {
      cout << "   -----+-----+-----\n";
    }
  }
}



/****************************************************************
* A function that asks the user to enter a certain character
* and the function will perform accordingly. It shows an error
* if the user type any other words which are not valid.
*****************************************************************/
void interact(int arrayBoard[][9])
{
  boardOptions();
  display(arrayBoard);

  cout << endl;
  char choose;


  do
  {
    cout << "> ";

    cin >> choose;

    if (choose == '?')
    {
      boardOptions();
      cout << endl;
    }

    else if (choose == 'D')
    {
      display(arrayBoard);
      cout << endl;
    }

    else if (choose == 'E')
    {
      editOneSquare(arrayBoard);
    }

    else if (choose == 'S')
    {
      getPossibleValues(arrayBoard);
    }

    else if (choose == 'Q')
    {

    }

    else
    {
      cout << "ERROR: Invalid command" << endl;
    }
  }
  while (toupper(choose) != 'Q');

}



/****************************************************************
* A function that allows the user whether the coordinate entered
* is valid or not and checks if it already has a value in it.
*****************************************************************/
bool getValid(int r, int c, string &coordinates, int arrayBoard[][9])
{
  if (arrayBoard[r][c] != 0)
  {
    cout << "ERROR: Square '" << coordinates[0] << coordinates[1]
         << "' is filled" << endl;
    return false;
  }

  return true;
}




/****************************************************************
* A function that allows the user to put a new value at any
* given coordinate which is empty in the first place.
*****************************************************************/
void editOneSquare(int arrayBoard[][9])
{
  string coordinates;
  getCoordinates(coordinates);
  int r = (int) coordinates[1] - '1';
  int c = toupper(coordinates[0]) - 'A';

  if (getValid(r, c, coordinates, arrayBoard))
  {
    cout << "What is the value at '" << coordinates[0] << coordinates[1]
         << "': ";
    cin >> arrayBoard[r][c];
  }
  cout << endl;
}


/****************************************************************
* A function that asks the user for the coordinates of the
* Sudoku and stores in a local 2-d array.
*****************************************************************/
void getCoordinates(string &coordinates)
{
  cout << "What are the coordinates of the square: ";
  cin >> coordinates[0];
  cin >> coordinates[1];
}




/****************************************************************
* A function that calculates the possible values
*****************************************************************/
void showPossible(int r, int c, int arrayBoard[][9], int possible[])
{

}

/****************************************************************
* A function that displays the coordinate's value
*****************************************************************/
void getPossibleValues(int arrayBoard[][9])
{
  string coordinates;
  getCoordinates(coordinates);

  int possible[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int r = (int) coordinates[1] - '1';
  int c = toupper(coordinates[0]) - 'A';


  showPossible(r, c, arrayBoard, possible);
  cout << "The possible values for '" << coordinates[0] << coordinates[1]
       << "' are: " << possible;

  for (int i = 0; i < 9; i++)
  {
    if (possible[i] != 0)
    {
      cout << possible[i];
    }
  }

  cout << endl;

}







/***************************************************************************
* A main function that creates an array that holds rows and columns,
* passes all the other functions and checks the condition whether the
* file was written successfully and stores it
****************************************************************************/
int main()
{

  // Declaring a file variable
  string filename;

  // Declaring an 2-d array
  int arrayBoard[9][9];

  getFileName(filename);
  readFile(filename, arrayBoard);
  interact(arrayBoard);

  getWriteBoard(filename);

  if (getWriteFile(filename, arrayBoard))
  {
    cout << "Board written successfully" << endl;
  }

  return 0;
}
