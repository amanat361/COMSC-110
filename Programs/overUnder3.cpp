//Objective: Guess a random number between 1-100
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
void introduction(string obj); //user introduction

//Main program
int main()
{
  srand(time(0)); //To use the random number function

  //Data
  int number = 1 + rand() % 100; //randomly generated number
  const int MAX_GUESSES = 100; //list capacity
  int nGuesses = 0; //initially empty list
  int userGuess[MAX_GUESSES]; //the array that holds the user's guesses
  int temp; //temporary value that holds the user's guess
  int i; //for duplicate loop indexing
  bool inputValid = true;
  string objective = "Guess a random number between 1-100"; //Program objective

  //User introduction
  introduction(objective);

  //Output intro message (different from introduction)
  cout << "I'm thinking of a whole number from 1 to 100." << endl;

  //Start a while-true loop for the user to guess multiple times
  while (true)
  {
    //Set input valid to true
    inputValid = true;

    //Prompt user for their guess
    cout << "What is your guess [1-100]? ";
    cin >> temp;

    //Check if guess is NOT between 1 and 100 and not a repeat
    if (!(temp >= 1 && temp <= 100))
    {
      cout << "I really want a number between 1 and 100." << endl;
      inputValid = false;
    } //if

    //Check if user's guess has already been guessed
    for (i = 0; i < nGuesses; i = i + 1)
    {
      if (temp == userGuess[i])
      {
        cout << "You've already guessed " << userGuess[i] << endl;
        inputValid = false;
      }
    }

    //Add value to list if guess is valid
    if (inputValid && nGuesses < MAX_GUESSES)
    {
      userGuess[nGuesses++] = temp;
    }

    //Check if user guessed the number correctly, or guess is too high/low
    if (inputValid)
    {
      //If the user guess is correct
      if (userGuess[i] == number)
      {
        cout << "You guessed it!" << endl;
        break;
      } //if
      //If the user guess is incorrect
      //See if user guess is too high
      else if (userGuess[i] > number)
      {
        cout << "That's too high. Try again..." << endl;
      } //else if high
      //See if user guess it too low
      else if (userGuess[i] < number)
      {
        cout << "That's too low. Try again..." << endl;
      } //else if low
    } //if inputValid
  } //while true
}//main

void introduction(string obj)
{
  //DATA
  //obj is the program objective passed from main

  //Output user introduction
  cout << "Objective: " << obj << endl;
  cout << "Programmer: Samin Amanat\n";
  cout << "Editor(s) used: Notepad\n";
  cout << "Compiler(s) used: TDM MinGW\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
} //Introduction