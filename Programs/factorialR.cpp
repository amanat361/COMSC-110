//Objective: A factorial program using recursion
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
  string objective = "A factorial program using recursion"; //Program objective
  int number; //the number inputted by the user to get a factorial from

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

//Factorial function
int factorial (int n)
{
  //DATA
  int answer; //result of the factorial

  //Detecting a base case
  if (n < 2)
  {
    answer = 1;
  }
  //Answer is the number multiplied by the number below it until 1 is reached
  else
  {
    answer = n * factorial(n-1);
  }

  //Return answer back to main
  return answer;
}