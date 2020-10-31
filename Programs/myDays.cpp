//Objective: To calculate how many days old I will be by the due date of this assignment.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: Clang (Xcode)
//Editor: TextEdit (Mac)

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

int main() {

  //Data
  int years = 18; //The number of years in which I've lived, including my birth year and the current year
  int leapYears = 4; //The number of leap years in my life
  int daysBeforeBorn = 361; //The number of days in my birth year before I was born, including my day of birth
  int daysRemaining = 190; //The number of days remaining in the current year after the due date for this lab, excluding that date
  string dateOfBirth = "Thursday, December 27th, 2001"; //My date of birth
  string dueDate = "Sunday, June 24th, 2018"; //Assignment due date
  int days; //My calculated age in days

  //Introduction
  cout << "Objective: This program will calculate how many days old I will be by the due date off this assignment.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: TextEdit\n"; 
  cout << "Compiler(s) used: Clang\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Set the value days to 0
  days = 0;

  //Add to "days" the result of this multiplication: 365 times the number of years in which you've lived
  days = years * 365;

  //Add "leapYears" to "days"
  days = days + leapYears;

  //Subtract from "days" the number of days in your birth year before you were born
  days = days - daysBeforeBorn;

  //Subtract from "days" the number of days remaining in the current year after the due date
  days = days - daysRemaining;

  //Output the value of "dateOfBirth" with an appropriate label
  cout << "DOB: " << dateOfBirth << endl;

  //Output the value of "dueDate" with an appropriate label
  cout << "Due: " << dueDate << endl;

  //Output the value of "days" with an appropriate label
  cout << "Age: " << days << " days" << endl;

}



