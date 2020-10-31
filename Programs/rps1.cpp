//Objective: A 2-player human-v-computer Rock, Paper, Scissors game.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //To use console input and output functionality
using namespace std;
#include <cctype> // To convert the user input into upercase (toupper)
#include <cstdlib> // To generate a random number for the computer
#include <ctime> // To generate a random number for the computer

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//Main program
int main()
{
  srand(time(0)); rand(); //needed for random number funtions

  //Data
  char userPlay; //user's choice either R, P, S, or Q
  char computerPlay; //randomly generated num 0-2 converted to R, P, or S
  int userScore = 0; //a counter for each time the user wins
  int computerScore = 0; //a counter for each time the computer wins

  //Introduction
  cout << "Objective: Battle out a 2-player human-v-computer Rock, Paper, Scissors game.\n";
  cout << "Programmer: Samin Amanat\n";
  cout << "Editor(s) used: Notepad\n";
  cout << "Compiler(s) used: TDM MinGW\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Instructions
  cout << "Welcome to the game of Rock, Paper, Scissors." << endl;
  cout << "You will be asked to choose either R=rock or P=paper or S=scissors, and the computer will do the same." << endl;
  cout << "The winner is determined by:" << endl;
  cout << "Rock wins against Scissors" << endl;
  cout << "Scissors wins against Paper" << endl;
  cout << "Paper wins against Rock" << endl;
  cout << "The game winner is the player with the most scores." << endl;
  cout << "The best player is the player with the highest overall score." << endl;
  cout << "Visit www.worldrps.com for more information." << endl << endl;

  //The game will replay until the human player decides to quit
  do {
    //The prompt will repeat until the human input is valid
    do {
      //Output prompt for userPlay and input userPlay
      cout << "Choose: [R=rock, P=paper, S=scissors, or Q=quit]: ";
      cin >> userPlay;
      cin.ignore(1000, 10);
      userPlay = toupper(userPlay); //if they put a lowercase character, it makes it uppercase (r - R)

      //Check if input is valid, either R, P, S, or Q
      if (!(userPlay == 'R' || userPlay == 'P' || userPlay == 'S' || userPlay == 'Q'))
      {
        cout << "Please only input a single character, R, P, S, or Q." << endl;
      }
    } while (!(userPlay == 'R' || userPlay == 'P' || userPlay == 'S' || userPlay == 'Q')); //loop until input is valid

    //Quit program before anything else if user enters 'Q'
    if (userPlay == 'Q')
    {
      cout << "Thanks for playing!" << endl;
      break; //Break from the loop
    }

    //Get computerPlay
    computerPlay = (rand() % 3); //makes a random number between 0-2
  
    //Convert computerPlay
    if (computerPlay == 0)
    {
    computerPlay = 'R';
    }
    else if (computerPlay == 1)
    {
      computerPlay = 'P';
    }
    else if (computerPlay == 2)
    {
      computerPlay = 'S';
    }

    //Determine winner

    //Tie
    if (userPlay == computerPlay)
    {
      cout << "Computer: " << computerPlay << ", Human: " << userPlay;
      cout << ", you tied! (ties do not effect score)" << endl;
      cout << "Computer wins: " << computerScore << " Human wins: " << userScore << endl;
    }
    //Player chooses rock
    else if (userPlay == 'R')
    {
      //Player chooses rock and computer chooses paper
      if (computerPlay == 'P')
      {
        cout << "Computer: " << computerPlay << ", Human: " << userPlay;
        cout << ", you lost!" << endl;
        computerScore = computerScore + 1;
        cout << "Computer wins: " << computerScore << " Human wins: " << userScore << endl;
      }
      //Player chooses rock and computer chooses scissors
      else if (computerPlay == 'S')
      {
        cout << "Computer: " << computerPlay << ", Human: " << userPlay;
        cout << ", you won!" << endl;
        userScore = userScore + 1;
        cout << "Computer wins: " << computerScore << " Human wins: " << userScore << endl;
      }
    }
    //Player chooses paper
    else if (userPlay == 'P')
    {
      //Player chooses paper and computer chooses rock
      if (computerPlay == 'R')
      {
        cout << "Computer: " << computerPlay << ", Human: " << userPlay;
        cout << ", you won!" << endl;
        userScore = userScore + 1;
        cout << "Computer wins: " << computerScore << " Human wins: " << userScore << endl;
      }
      //Player chooses paper and computer chooses scissors
      else if (computerPlay == 'S')
      {
        cout << "Computer: " << computerPlay << ", Human: " << userPlay;
        cout << ", you lost!" << endl;
        computerScore = computerScore + 1;
        cout << "Computer wins: " << computerScore << " Human wins: " << userScore << endl;
      }
    }
    //Player chooses scissors
    else if (userPlay == 'S')
    {
      //Player chooses scissors and computer chooses rock
      if (computerPlay == 'R')
      {
        cout << "Computer: " << computerPlay << ", Human: " << userPlay;
        cout << ", you lost!" << endl;
        computerScore = computerScore + 1;
        cout << "Computer wins: " << computerScore << " Human wins: " << userScore << endl;
      }
      //Player chooses scissors and computer chooses paper
      else if (computerPlay == 'P')
      {
        cout << "Computer: " << computerPlay << ", Human: " << userPlay;
        cout << ", you won!" << endl;
        userScore = userScore + 1;
        cout << "Computer wins: " << computerScore << " Human wins: " << userScore << endl;
      }
    }
    //Line spacing between matches
    cout << endl;
  } while (!(userPlay == 'Q')); //The game will replay until the human player decides to quit
}//main