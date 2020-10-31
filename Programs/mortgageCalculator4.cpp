//Objective: A 30 year fixed loan mortgage calculator
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //To output to a file
#include <iomanip> //To set precision of outputs
#include <iostream> //To use console input and output
using namespace std;
#include <cmath> //To use math functions

//Programmer defined data types
//Mortgage struct
struct mortgage
{
  int borrowed; //the amount of money borrowed
  double interestRate; //the annual interest rate
  int monthlyPayments; //the ammount of monthly payments
  double payment; //the payment
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //user introduction

//Main program
int main()
{

  //Data
  string objective = "A 30 year fixed loan mortgage calculator."; //Program objective
  int password = 1234567; //A student ID to be used as the program's password
  int passwordGuess; //What the user enters for password
  ofstream fout; //to echo the output to a file called mortgage.txt
  mortgage a; //makes a mortgage table for the user called a

  //Introduction
  introduction(objective);

  //Get password to run
  while (true)
  {
    cout << "What is the correct student ID: ";
    cin >> passwordGuess;
    cin.ignore(1000, 10);
    if (passwordGuess == password) break;
  } //while

  //Get data from user
  a.monthlyPayments = 360; //30 years with 12 months per year
  cout << "What is the ammount borrowed (whole number): ";
  cin >> a.borrowed;
  cin.ignore(1000, 10);
  cout << "What is the annual interest rate (as a percentage without the % sign): ";
  cin >> a.interestRate;
  cin.ignore(1000, 10);

  //Calculate payment
  a.interestRate = a.interestRate / 100;
  a.interestRate = a.interestRate / 12;
  a.payment = a.borrowed * ((pow(1 + a.interestRate, a.monthlyPayments) * a.interestRate) / (pow(1 + a.interestRate, a.monthlyPayments) - 1));

  //Output the mortgage payment to console
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);
  cout << "The mortgage payment is $" << a.payment;

  //Output the mortgage payment to file
  fout.open("mortgage.txt");
  fout.setf(ios::fixed|ios::showpoint);
  fout << setprecision(2);
  fout << "The mortgage payment is $" << a.payment;
  fout.close();
  
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
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "Please answer the prompts as given. Don't use any characters or symbols, only numbers and decimals." << endl << endl;
} //Introduction