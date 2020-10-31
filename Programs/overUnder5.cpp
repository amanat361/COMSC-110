//Objective: Guess a random number between 1-100
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <deque> //to use queues with recently inputted data
#include <iostream> //To use console input and output
using namespace std;
#include <cstdlib> //To use the random number function
#include <ctime> //To use the random number function

//Programmer defined data types
struct Guess
{
  int userGuess; //a user's guess
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
  int temp; //temporary variable to compare values
  int c; //loop index for ammount of times user has guessed
  bool inputValid = true; //input validation flag (true/false)
  deque<Guess> listOfGuesses; //the list of guesses the user gives to be remembered
  Guess guess; //guess given by the user

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
    cin.ignore(1000, 10);

    //Check if number has already been guessed
    for (c = 0; c < listOfGuesses.size(); c = c + 1)
    {
      if (temp == listOfGuesses[c].userGuess)
      {
        cout << "Sorry, " << listOfGuesses[c].userGuess << " has already been guessed." << endl;
        inputValid = false;
      } //if
    } //for

    //Check if guess is NOT between 1 and 100 and not a repeat
    if (!(temp >= 1 && temp <= 100))
    {
      cout << "I really want a number between 1 and 100." << endl;
      inputValid = false;
    } //if

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
        guess.userGuess = temp;
        listOfGuesses.push_back(guess);
      } //else if high
      //See if user guess it too low
      else if (temp < number)
      {
        cout << "That's too low. Try again..." << endl;
        guess.userGuess = temp;
        listOfGuesses.push_back(guess);
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