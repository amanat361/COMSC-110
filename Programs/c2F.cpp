//Objective: Use text file inputted temperature and convert from celsius to farenheit.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
#include <iomanip>
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

//Main program
int main()
{
  //Data
  string objective = "Use text file inputted temperature and convert from celsius to farenheit."; //Program objective
  ifstream fin;
  double celsius;
  double farenheit;

  //Output user introduction and instructions
  introduction(objective); //User introduction and instructions

  //Open file and see if it is valid
  fin.open("temps.txt");
  if (!fin.good()) throw "I/O error";

  //Loop to get all values and output their counterpart (C to F)
  do
  {
    //Input value
    fin >> celsius;
    fin.ignore(1000, 10);

    //Sentinel -999
    if (celsius == -999)
    {
      break;
    }

    //Convert
    farenheit = ((9.0/5.0)*celsius) + 32;

    //Output to console
    cout.setf(ios::fixed|ios::showpoint);
    cout << celsius << " degrees celsius to farenheit is ";
    cout << setprecision(1) << farenheit << endl;
  } while(celsius != -999 || !fin.eof()); //go until input is -999 or end of file is reached

}//main

void introduction(string obj)
{
  //DATA
  //obj is the program objective passed from main
  string ready; //for the user to push enter when ready

  //Output user introduction
  cout << "Objective: " << obj << endl;
  cout << "Programmer: Samin Amanat\n";
  cout << "Editor(s) used: Notepad\n";
  cout << "Compiler(s) used: TDM MinGW\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Output user instructions
  cout << "Please make a text file called \"temps.txt\"" << endl;
  cout << "On each line in the text file, input a celsius value that you would like to convert" << endl;
  cout << "Only put numbers in the text file, no symbols or letters." << endl;
  cout << "MAKE SURE to put -999 as a value at the bottom of the file to terminate the loop!" << endl;
  cout << "The program will wait for you to create the file with valid values." << endl;
  cout << "Press the enter key when ready..." << endl;
  getline(cin, ready);

} //Introduction