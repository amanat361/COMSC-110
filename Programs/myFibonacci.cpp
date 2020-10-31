//Objective: Calculate a value in the "Fibonacci number" series
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
void introduction(string obj); //user introduction
int fibonacci(int n); //fibonacci sequence function

//Main program
int main()
{

  //Data
  string objective = "Calculate a value in the \"Fibonacci number\" series"; //Program objective
  int number; //the index that the user is inputting
  int i; //loop index

  //User introduction
  introduction(objective);

  //Prompt user for index
  cout << "What is the fibonacci index [0 or greater]: ";
  cin >> number;
  cin.ignore(1000, 10);

  //Run fibonacci sequence and output each number
  for (i = 0; number >= i; i++)
  {
    cout << fibonacci(i) << " ";
  }

  //Output the last number in the sequence
  cout << endl << "The Fibonacci number at index " << number << " is " << fibonacci(number) << endl;

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

//Fibonacci sequence
int fibonacci(int n)
{
  //If the number is 1 or 0, just output the nubmer
  if (n == 1 || n == 0)
  {
    return(n);
  }
  //Take the number and sum the values of the two numbers that precede it
  else
  {
    //Return value to main
    return(fibonacci(n-1)+fibonacci(n-2));
  }
}