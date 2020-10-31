//Objective: Convert Fahrenheit Input Into Celcius Output
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
//NONE

//main program
int main()
{

  //Data
  double c; // degrees Celsius
  double f; // degrees Fahrenheit

  //Introduction
  cout << "Objective: This program will convert fahrenheit input into celcius output.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Ask user to enter Fahrenheit
  cout << "Enter the temperature in degrees Fahrenheit: ";
  cin >> f;

  //Convert Temperature
  c = 5 * (f - 32) / 9;

  //Output results
  cout << endl << "That's " << c << " degrees Celsius!" << endl;

}//main