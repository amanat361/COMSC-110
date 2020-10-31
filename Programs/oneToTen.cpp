//Objective: Guess a number between 1 and 10.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //To use console input and output
using namespace std;
#include <cstdlib> //To use the random number function
#include <ctime> //To use the random number function

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
  srand(time(0)); //To use the random number function

  //Data
  int number = 1 + rand() % 10; //randomly generated number
  int userGuess; //user inputed guess

  //Introduction
  cout << "Objective: Guess a number between 1 and 10.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "Instructions: Answer the prompts please." << endl << endl;

  //Output intro message (different from introduction)
  cout << "I'm thinking of a number from 1 to 10." << endl;

  //Start a while-true loop for the user to guess multiple times
  while (true)
  {
    //Prompt user for their guess
    cout << "What is your guess [1-10]? ";
    cin >> userGuess;

    //Check if guess is NOT between 1 and 10
    if (!(userGuess >= 1 && userGuess <= 10))
    {
      cout << "I really want a number between 1 and 10." << endl;
    } //if
    //If the user guess is between 1 and 10
    else
    {
      //If the user guess is correct
      if (userGuess == number)
      {
        cout << "You guessed it!" << endl;
        break;
      } //if
      //If the user guess is incorrect
      else
      {
        cout << "Try again..." << endl;
      } //else
    } //else
  } //while true
}//main