// Importing library stream
#include <iostream>
using namespace std;


/*
* A function that returns the number of letters in a string
*/
void countLetters(char letter, string text)
{
  int count = 0;
  for (int i = 0; i < text.length(); i++)
  {
    if (text[i] == letter)
      count++;
  }
  cout << "Number of " << "'" << letter << "'" << "s: " << count << endl;

}


/*
* A main function that prompts the user for a line of input, calls
* countLetters function, and displays the number of letters
*/
int main()
{
  char letter;
  char text[256];

  cout << "Enter a letter: ";
  cin >> letter;

  cout << "Enter text: ";
  cin.ignore();
  cin.getline(text, 256);


  countLetters(letter, text);

  return 0;
}
