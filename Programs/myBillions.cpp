//Objective: To calculate and output the number of weeks that it will take to reach a total of one billion dollars or greater.
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
bool billion(double dollars, int week, double bank); //function that calculates the number of weeks it will take to reach $1B

//Main program
int main()
{

  //Data
  string objective = "To calculate the number of weeks it will take to reach one billion dollars."; //Program objective
  double allowance = 0.05; //number of cents recieved each week
  int week = 0; //number of weeks passed
  double piggyBank = 0; //total number of cents saved up

  //User Introduction
  introduction(objective); //User introduction

  //Run program
  billion(allowance, week, piggyBank);

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

bool billion(double dollars, int week, double bank)
{
  //DATA
  //cents, week, and bank are all passed from main
  int weeksToThousand = 0; //number of weeks it takes to become a thousandaire
  int weeksToMillion = 0; //number of weeks it takes to become a millionare
  int weeksToBillion = 0; //number of weeks it takes to become a billionare

  //Loop until bank reaches $1B
  do
  {
    //Calculations
    week = week + 1;
    bank = bank + dollars;
    dollars = dollars * 2;

    //If bank is $1B
    if (bank >= 1000000000)
    {
      weeksToBillion = week;
      break;
    }

    //If bank is $1M
    else if (bank >= 1000000)
    {
      weeksToMillion = week;
    }

    //If bank is $1,000
    else if (bank >= 1000)
    {
      weeksToThousand = week;
    }
  } while (bank < 100000000000); //keep going until bank reaches $1B

  //Output results
  cout << "In " << weeksToThousand << " weeks, I will be a thousandaire!" << endl;
  cout << "In " << weeksToMillion << " weeks, I will be a millionare!"<< endl;
  cout << "In " << weeksToBillion << " weeks, I will be a billionare!"<< endl;

  return true;
}