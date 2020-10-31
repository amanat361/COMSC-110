//Objective: To calculate the area of a circle's radius
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;
#include <cmath>

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
  double r;
  double area;
  double pi = 4 * atan(1.0); // 4 times the angle whose tangent is 1

  //Introduction
  cout << "Objective: This program will serve to calculate the area of a circle's radius.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Ask user to enter a circle's radius
  cout << "Enter the radius of a circle: ";
  cin >> r;

  //Calculate the area with Pi(r)^2
  area = pi * r * r;

  //Output the area to the user
  cout << "The area is " << area << endl;

}//main