//Objective: A factorial program that uses iteration
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
int factorial(int n); //factorial function
void introduction(string obj); //user introduction

//Main program
int main()
{

  //Data
  int number; //the number inputted by the user to get a factorial from
  string objective = "A factorial program that uses iteration"; //Program objective

  //User introduction
  introduction(objective);

  //Prompt for number until user inputs a valid number above or equal to zero
  while (true)
  {
    //Prompt for number
    cout << "Input a number to get a factorial for (must be > or = to 0): ";
    cin >> number;
    cin.ignore(1000, 10);

    //Check if number is greater than or equal to zero
    if (number < 0)
    {
      cout << "Your number must be greater than or equal to zero." << endl;
    }
    else
    {
      break;
    } //while
  }

  //Output factorial answer from function with number passed through
  cout << "The factorial of !" << number << " is " << factorial(number) << endl;

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

int factorial (int n)
{
  //DATA
  int c; //loop index
  int answer = 1; //answer

  //Loop through every number between 1 and number
  for (c = 1; c <= n; c = c + 1)
  {
    if (n == 0)
    {
      return answer;
    }
    else
    {
      answer = answer * c;
    }
  } //for

  //Return the answer back to main
  return answer;
}