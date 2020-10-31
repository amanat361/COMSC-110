//Objective: A utility for copying emails from one file to another
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //to use file input and output
#include <iostream> //to use console input and output
#include <string> //to use the string data type
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
  string objective = "A utility for copying emails from one file to another"; //Program objective
  string dFileName = "fileContainingEmails.txt"; //the default file name
  string iFileName; //the input filename inputted by the user if not default
  string oFileName; //the output filename inputted by the user if not default
  string enterToContinue; //for the user to push enter to continue after confirming the filenames
  bool enterKey = false; //see if the user just pushes the enter key
  bool inputValid = true; //see if the user inputted a valid input file name
  bool outputValid = true; //see if the user inputted a valid output file name

  //User introduction
  introduction(objective);

  //Prompt user for input filename
  cout << "Enter input filename [default: " << dFileName << "]: ";
  getline(cin, iFileName);

  //Check if filename is valid
  //Check if filename is between 0 and 5 characters
  if (iFileName.length() > 0 && iFileName.length() < 5)
  {
    inputValid = false;
  }
  //Check if filename is just the enter key
  else if (iFileName.length() == 0)
  {
    enterKey = true;
  }
  //Check if filename starts with a space
  else if (iFileName[0] == ' ')
  {
    inputValid = false;
  }
  //Check if filename ends with ".txt"
  else if (!(iFileName[iFileName.length() - 1] == 't' && iFileName[iFileName.length() - 2] == 'x' && iFileName[iFileName.length() - 3] == 't' && iFileName[iFileName.length() - 4] == '.'))
  {
    inputValid = false;
  }

  //If enter key is true, iFilename = dFilename and dFilename = "copyPasteMyEmails.txt"
  if (enterKey)
  {
    iFileName = dFileName;
    dFileName = "copyPasteMyEmails.txt";
  }
  //If enter key is not pressed, input file name remains the same and default file = input file
  else
  {
    dFileName = iFileName;
  }

  //Set enterKey to false
  enterKey = false;

  //Prompt user for output filename
  cout << "Enter output filename [default: " << dFileName << "]: ";
  getline(cin, oFileName);

  //Check if filename is valid
  //Check if filename is between 0 and 5 characters
  if (oFileName.length() > 0 && oFileName.length() < 5)
  {
    outputValid = false;
  }
  //Check if filename is just the enter key
  else if (oFileName.length() == 0)
  {
    enterKey = true;
  }
  //Check if filename starts with a space
  else if (oFileName[0] == ' ')
  {
    outputValid = false;
  }
  //Check if filename ends with ".txt"
  else if (!(oFileName[oFileName.length() - 1] == 't' && oFileName[oFileName.length() - 2] == 'x' && oFileName[oFileName.length() - 3] == 't' && oFileName[oFileName.length() - 4] == '.'))
  {
    outputValid = false;
  }

  //If enter key is true, oFilename = dFilename
  if (enterKey)
  {
    //If input file is invalid and output file = input file (pushed enter for default) then output file is also invalid
    if (!(inputValid))
    {
      outputValid = false;
    }
    oFileName = dFileName;
  }

  //Output label for input file name, and iFileName
  cout << "Input file: " << iFileName << endl;
  //Output error message if input is not valid
  if (!(inputValid)) cout << "Filename is invalid." << endl;
  //Output label for output file name, and oFileName
  cout << "Output file: " << oFileName << endl;
  if (!(outputValid)) cout << "Filename is invalid." << endl;

  //Ask user to press enter to continue
  cout << endl << "Press enter to continue...";
  getline(cin, enterToContinue);

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