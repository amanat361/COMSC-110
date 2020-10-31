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
struct Guess
{
  int userGuess; //a user's guess
  Guess* next; //the link
};

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
  string objective = "Guess a random number between 1-100"; //Program objective
  int number = 1 + rand() % 100; //randomly generated number
  bool inputValid = true; //input validation flag (true/false)
  int temp; //temporary variable to compare values
  int nGuess = 0; //initially empty list
  int count = 0; //a count that is used to see how many times an input is in the list (duplicates)
  Guess* p; //a linked list that is used to check for duplicates
  Guess* start = 0; //create an empty linked list

  //User introduction
  introduction(objective);

  //Output intro message (different from introduction)
  cout << "I'm thinking of a whole number from 1 to 100." << endl;

  //Start a while-true loop for the user to guess multiple times
  while (true)
  {
    //Make a new guess each time the loop repeats
    Guess* aGuess = new Guess;

    //Set input valid to true
    inputValid = true;

    //Prompt user for their guess
    cout << "What is your guess [1-100]? ";
    cin >> aGuess->userGuess;
    cin.ignore(1000, 10);

    //Add node to list
    aGuess->next = start;
    start = aGuess;

    //Check if guess is NOT between 1 and 100 and not a repeat
    if (!(aGuess->userGuess >= 1 && aGuess->userGuess <= 100))
    {
      cout << "I really want a number between 1 and 100." << endl;
      inputValid = false;
    } //if

    //Check if user's guess has already been guessed
    for (p = start; p; p = p->next)
    {
      if (aGuess->userGuess == p->userGuess && inputValid)
      {
        count = count + 1;
        if (count > 1)
        {
          cout << "You've already guessed " << aGuess->userGuess << endl;
          inputValid = false;
        } //if
      } //if
    } //for

    //If the input is valid, set temp to the user's guess for comparison
    if (inputValid)
    {
      temp = aGuess->userGuess;
    }

    //Check if user guessed the number correctly, or guess is too high/low
    if (inputValid)
    {
      //If the user guess is correct
      if (temp == number)
      {
        cout << "You guessed it!" << endl;
        break;
      } //if
      //If the user guess is incorrect
      //See if user guess is too high
      else if (temp > number)
      {
        cout << "That's too high. Try again..." << endl;
      } //else if high
      //See if user guess it too low
      else if (temp < number)
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