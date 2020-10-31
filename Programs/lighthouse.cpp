//Objective: To determine how far away a boat can see a lighthouse at sea.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip> //To use setprecision formatting
#include <iostream> //To use console input and output
using namespace std;
#include <cmath> //To use the square root function

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
  double height; //height of the lighthouse
  double miles; //the distance in miles

  //Introduction
  cout << "Objective: To determine how far away a boat can see a lighthouse at sea.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "Instructions: Input the height of the lighthouse when prompted please." << endl << endl;

  //Prompt the user to enter the height of the lighthouse
  cout << "Please enter the height of the lighthouse, in feet, with any number of decimal digits (for example, 100 or 55.5): ";
  cin >> height;
  cin.ignore(1000, 10);

  //Calculate the distance in miles
  miles = sqrt(0.8*height);

  //Output the answer with a label w/ input and out
  cout.setf(ios::fixed);
  cout << setprecision(0) << endl << "A " << height << " foot tall lighthouse can be seen from " << miles << " miles away." << endl;

}//main