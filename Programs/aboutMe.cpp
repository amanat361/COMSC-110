//Objective: To store and show information/data about me
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
#include <string>
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
  int luckyNumber = 66; //my favorite number
  double amountEarned = 1.5; //the amount of money I want to save for the rest of my life
  string movie = "The Imitation Game"; //my favorite movie
  char initial = 'S'; //my first name first initial

  //Introduction
  cout << "Objective: This program will store and show information and data about me.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Output data values about me
  cout << "My lucky number is " << luckyNumber << "." << endl;
  cout << "The amount of money I want to save for the rest of my life is about " << amountEarned << " million dollars." << endl;
  cout << "My favorite movie is " << movie << "." << endl;
  cout << "My first name initial is '" << initial << "'." << endl;

}//main