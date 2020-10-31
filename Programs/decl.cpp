//Objective: Prompt the user to console-input data and have the program output the data
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //Using this library mostly for cout and cin
#include <string> //Using this library for the string variable type
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{

  //Data
  int luckyNumber; //The user's favorite number
  string favoriteMovie; //The user's favorite movie
  double age; //The user's age
  char firstInitial; //The user's first name first initial

  //Introduction
  cout << "Objective: Prompt the user to console-input data and have the program output the data.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "Instructions: Answer the data prompts as specified please." << endl << endl;

  //Prompt the user for their lucky number (integer).
  cout << "What is your lucky number [whole number that can be either positive or negative]: ";
  cin >> luckyNumber;
  cin.ignore(1000, 10);

  //Prompt the user for their favorite movie (text)
  cout << "What is your favorite movie: ";
  getline(cin, favoriteMovie);

  //Prompt the user for their age (decimal)
  cout << "What is your age [decimal value, can't be negative]: ";
  cin >> age;
  cin.ignore(1000, 10);

  //Prompt the user for their first letter in their name (single character)
  cout << "What is your first initial [one character]: ";
  cin >> firstInitial;
  cin.ignore(1000, 10);

  //Output these data values in a sentence with appropriate lablels.
  cout << endl << "Thanks for inputting your data. Your lucky number is " << luckyNumber << ", your favorite movie is " << favoriteMovie << ", your age is " << age << ", and your first initial is " << firstInitial << "." << endl;

}//main