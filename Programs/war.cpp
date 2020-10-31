//Objective: Play the card game war between human and computer.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //to use console input and output
#include <string> //to use the string data type
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
  string objective = "Play the card game war between human and computer."; //Program objective
  int computerNumber; //a random integer between 2-14 representing the computer's card number
  int computerSuitNumber; //a random integer between 0-3 that represents the computer's suit
  string computerSuitName; //a suit either spades diamonds hearts or clubs
  int userNumber; //a random integer between 2-14 representing the user's card number
  int userSuitNumber; //a random integer between 0-3 that represents the user's suit
  string userSuitName; //a suit either spades diamonds hearts or clubs
  string winner; //the winning message
  string computerCard; //the computer's card as a string
  string userCard; //the user's card as a string
  char continueGame = 'y'; //sentinel value to determine if the user wants to continue or not

  //User introduction
  introduction(objective);

  //Loop as long as the user wants to continue, or if it's a tie
  while (continueGame == 'y')
  {

  //generate a random number from 2-14 to represent a card for the computer
  computerNumber = (rand() % 11) + 2;

  //generate a random number from 0-3 to represent a card's suit for the computer
  computerSuitNumber = (rand() % 4);

  //convert computerSuitNumber to computerSuitName
  if (computerSuitNumber == 0)
  {
    computerSuitName = "spades";
  }
  else if (computerSuitNumber == 1)
  {
    computerSuitName = "diamonds";
  }
  else if (computerSuitNumber == 2)
  {
    computerSuitName = "hearts";
  }
  else if (computerSuitNumber == 3)
  {
    computerSuitName = "clubs";
  }

  //generate a random number from 2-14 to represent a card for the user
  userNumber = (rand() % 11) + 2;

  //generate a random number from 0-3 to represent a card's suit for the user
  userSuitNumber = (rand() % 4);

  //convert userSuitNumber to userSuitName
  if (userSuitNumber == 0)
  {
    userSuitName = "spades";
  }
  else if (userSuitNumber == 1)
  {
    userSuitName = "diamonds";
  }
  else if (userSuitNumber == 2)
  {
    userSuitName = "hearts";
  }
  else if (userSuitNumber == 3)
  {
    userSuitName = "clubs";
  }

  //Determine the winner
  if (computerNumber == userNumber)
  {
    winner = "It's a tie!";
  }
  else if (computerNumber > userNumber)
  {
    winner = "Computer has won!";
  }
  else if (computerNumber < userNumber)
  {
    winner = "User has won!";
  }

  //Convert user card number from int to string
  if (!(computerNumber >= 2 && computerNumber <= 10))
  {
    if (computerNumber == 11)
    {
      computerCard = "Jack";
    }
    else if (computerNumber == 12)
    {
      computerCard = "Queen";
    }
    else if (computerNumber == 13)
    {
      computerCard = "King";
    }
    else if (computerNumber == 14)
    {
      computerCard = "Ace";
    }
  }

  //Convert user card number from int to string
  if (!(userNumber >= 2 && userNumber <= 10))
  {
    if (userNumber == 11)
    {
      userCard = "Jack";
    }
    else if (userNumber == 12)
    {
      userCard = "Queen";
    }
    else if (userNumber == 13)
    {
      userCard = "King";
    }
    else if (userNumber == 14)
    {
      userCard = "Ace";
    }
  }

  //Output the card values and the winner
  cout << "Computer's card is a " << computerCard;
  if (computerNumber >= 2 && computerNumber <= 10) cout << computerNumber;
  else if (computerNumber >= 2 && computerNumber <= 10) cout << computerCard;
  cout << " of " << computerSuitName << endl;
  cout << "User's card is a " << userCard;
  if (userNumber >= 2 && userNumber <= 10) cout << userNumber;
  else if (userNumber >= 2 && userNumber <= 10) cout << userCard;
  cout << " of " << userSuitName << endl;
  cout << winner << endl;

  //Continue or end loop
  if (winner == "It's a tie!")
  {
    continueGame = 'y';
  } //if
  else
  {
    cout << "Would you like to continue? [y/n]: ";
    cin >> continueGame;
    cin.ignore(1000, 10);
  } //else
  } //while

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