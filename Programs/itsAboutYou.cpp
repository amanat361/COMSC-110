//Objective: template for C++ programs and to test code
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

  // code block to read an int value from the keyboard
  int num1;
  cout << "Enter the first number please: "; cin >> num1;

  // code block to read an int value from the keyboard
  int num2;
  cout << "Enter the second number please: "; cin >> num2;

  int num3 = num1 + num2;

  while(true) {
  cout << "Your sum is: " << num3 << ".";
  }

}//main