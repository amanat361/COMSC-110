//Objective: To use a subprogram that asks the questions returns a boolean value.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //to use console input and output functionality
#include <string> //to use the string data type to input user's answer
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //user introduction
void instructions(); //user intstuctions
bool question1(int ans); //question 1 check
bool question2(char ans); //question 2 check
bool question3(string ans); //question 3 check

//Main program
int main()
{

  //Data
  string objective = "To use a subprogram that asks the questions returns a boolean value."; //Program objective
  int answer1; //the user's answer to the first question
  char answer2; //the user's answer to the second question
  string answer3; //the user's answer to the third question
  bool correct; //if the use is correct or not
  int score = 0; //the amount of questions the user got correct

  //Output user introduction and instructions
  introduction(objective); //User introduction
  instructions(); //User instructions

  //Question 1
  cout << "1. How many bits in a byte? ";
  cin >> answer1;
  cin.ignore(1000, 10);
  if (question1(answer1) == true)
  {
    cout << answer1 << " is the correct answer!" << endl;
    score = score + 1;
  }
  else
  {
    cout << "Sorry, " << answer1 << " is not the correct answer." << endl;
  }

  //Output score
  cout << "You got " << score << " correct out of 3." << endl;

  //Question 2
  cout << "2. What is machine language: a) binary b) decimal c) hexidecimal? ";
  cin >> answer2;
  cin.ignore(1000, 10);
  if (question2(answer2) == true)
  {
    cout << answer2 << " is the correct answer!" << endl;
    score = score + 1;
  }
  else
  {
    cout << "Sorry, " << answer2 << " is not the correct answer." << endl;
  }

  //Output score
  cout << "You got " << score << " correct out of 3." << endl;

  //Question 3
  cout << "3. What was the original name of the Internet? (lowercase answer please): ";
  cin >> answer3;
  cin.ignore(1000, 10);
  if (question3(answer3) == true)
  {
    cout << answer3 << " is the correct answer!" << endl;
    score = score + 1;
  }
  else
  {
    cout << "Sorry, " << answer3 << " is not the correct answer." << endl;
  }

  //Output score
  cout << "You got " << score << " correct out of 3." << endl;

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

void instructions()
{
  //DATA
  //NONE

  //Output user instructions
  cout << "Answer the questions as best as you can. You will be given a score out of 3" << endl << "Good luck!!!" << endl;
  
} //Instructions

bool question1(int ans)
{
  //Question
  //How many bits are there in a byte?

  //DATA
  int correctAnswer = 8; //correct answer to question one
  int answer = ans; //the user's answer
  bool correct; //if the user is right or wrong

  if (answer == correctAnswer)
  {
    correct = true;
  }
  else
  {
    correct = false;
  }
  return correct;
}

bool question2(char ans)
{
  //Question
  //"What is machine language: a) binary b) decimal c) hexidecimal? "

  //DATA
  char correctAnswer = 'a'; //correct answer to question one
  char answer = tolower(ans); //the user's answer
  bool correct; //if the user is right or wrong

  if (answer == correctAnswer)
  {
    correct = true;
  }
  else
  {
    correct = false;
  }
  return correct;
}

bool question3(string ans)
{
  //Question
  //"What was the original name of the Internet? "

  //DATA
  string correctAnswer = "arpanet"; //correct answer to question one
  string answer = ans; //the user's answer
  bool correct; //if the user is right or wrong

  if (answer == correctAnswer)
  {
    correct = true;
  }
  else
  {
    correct = false;
  }
  return correct;
}