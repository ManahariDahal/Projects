/***********************************************************************
A C++ madlib program that reads a .txt file and asks the user to enter
the words and displays a madlib story.
************************************************************************/


#include <iostream>
#include <fstream>

using namespace std;


/*
 * A function that asks the user to input the filename and stores it.
*/
void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   cin.ignore();
}



/*
 * A function that takes the input of any word in the array
 * replacing the old c-string with user input.
*/
void askQuestion(char arrayWord[])
{

   if ((arrayWord[0] != ':') || !(isalpha(arrayWord[1])))
   {
      return;
   }

   cout << "\t";

   cout << (char) toupper(arrayWord[1]);

   for (int i = 2; arrayWord[i] != '\0'; i++)
   {
      // Replacing underscore with a space
      if (arrayWord[i] == '_')
      {
         cout << " ";
      }


      /* Converting all other letters except for the first word
       * to small letters
      */
      else
      {
         cout << (char) tolower(arrayWord[i]);
      }
   }

   cout << ": ";
   cin.getline(arrayWord, 32);
}



/*
 * A function that reads the file and the contents are copied
 * in the 2-d array story.
 */
int readFile(char fileName[], char story[][32])
{

   getFileName(fileName);

   ifstream fin;
   fin.open(fileName);

   // Handling the file error
   if (fin.fail())
   {
      cout << "Error reading file";
      return 0;
   }

   int wordLength;
   for (wordLength = 0; fin >> story[wordLength]; wordLength++)
   {

      /* If the first letter is ':' the array looks the end of the word,
       * stores it and prompts the user to enter the value associated with
       * that word
      */
      if (story[wordLength][0] == ':')
      {
         askQuestion(story[wordLength]);
      }
   }

   fin.close();
   return wordLength;
}


/*
 * A function that checks if the punctuation is separated
 * by a space or a newline
*/
void printWordOrPunc(char arrayWord[])
{
    if (arrayWord[1] == '!')
    {
      arrayWord[0] = '\n';
      arrayWord[1] = '\0';
    }

    else if (arrayWord[1] == '.')
    {
      arrayWord[0] = '.';
      arrayWord[1] = '\0';
    }

    else if (arrayWord[1] == ',')
    {
      arrayWord[0] = ',';
      arrayWord[1] = '\0';
    }

}



/*
 * A function that translates what the symbols mean and displays the story.
* It also evaluates when a space should be printed before each word
* or punctuation, the first word in the story never needs a space before,
   * so it prints first, then tests each word after it.
*/
void displayStory(char story[][32], int wordLength)
{
   cout << endl;
   cout << story[0];
   int i;

   for (i = 1; i < wordLength; i++)
   {

      if (story[i][0] == ':')
      {
         // The punctuation is handled accordingly to the above conditions
         printWordOrPunc(story[i]);
      }


      if ((story[i][1] == '<') && (story[i - 1][0] != '\n'))
      {
         cout << " \""; // printing a space before
      }

      else if ((story[i][0] == '.') || (story[i][0] == ','))
      {
         cout << story[i]; // storing to the array
      }

      else if (story[i][1] == '<')
      {
         cout << "\""; // printing a single quotation at the back
      }

      else if (story[i][0] == '\n')
      {
         cout << story[i];
      }

      else if (story[i][1] == '>')
      {
         cout << '"'; // printing a single quotation
      }

      else if ((story[i - 1][0] == '\n') || (story[i - 1][1] == '<'))
      {
         cout << story[i];
      }

      else
      {
         cout << " " << story[i];
      }
   }

   cout << endl;

}



/*
 * A main function initializes the filename and creates a 2-d array
 * named 'story' and it calls all the other functions and displays it
 */
int main()
{
   char fileName[256];
   char story [256][32];
   int wordLength;

   bool playagain = true;
   char letter;


   /*
    * It asks the user whether they want to play the game again. If the user
    * enters 'y', they can play the game again, if the user enters 'n', the
    * program ends with a "thank you" message
    */
   while (playagain)
   {
      wordLength = readFile(fileName, story);
      displayStory(story, wordLength);

      cout << "Do you want to play again (y/n)? ";
      cin >> letter;

      if (letter != 'y')
      {
         playagain = false;
         cout << "Thank you for playing." << endl;
      }

      else if (letter == 'y')
      {
         playagain = true;
      }
   }


   return 0;
}
