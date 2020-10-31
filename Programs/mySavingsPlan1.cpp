//Objective: To calculate how much money to save every month for number of years before retirement and how much money would you have when you retire.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
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
  int deposit = 100; //how much money you will add to your savings account each month
  double interestRate = 0.075; //annual interest rate you can expect
  int years = 10; //how many more years until you retire
  double amountSaved; //how much money you have when you retire
  int time = 0; //number of months in years

  //Introduction
  cout << "Objective: This program calculate how much money to save every month for number of years before retirement and how much money would you have when you retire.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //interest rate = interest rate / 12
  interestRate = interestRate / 12;

  //Add to time the result of "years" * 12;
  time = years * 12;

  //Use interest formula to calculate amount saved
  amountSaved = deposit * ((pow(1 + interestRate, time) - 1) / interestRate);

  //Format the amountSaved to 2 decimal points
  cout.setf(ios::fixed|ios::showpoint);

  //Output result
  //Output label1 + Output years + Output label2
  cout << "In " << years << " years at ";
  //Setprecision to 1 decimal point, convert interest rate to percentage (times 100), multiply by 12, and output interest rate
  cout << setprecision(1) << ((interestRate * 100) * 12);
  //Output label3 + Output deposit + Output label4
  cout << "%, $" << deposit << " deposited per month will grow to $";
  //Output amountSaved formatted to 2 digits past the decimal point
  cout << setprecision(2) << amountSaved << "." << endl;

}//main