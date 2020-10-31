//Objective: Enter a line of text then decode the text to the previous character in the ASCII code
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //To use file input and outputs in C++
#include <iostream> //To use console input and outputs
#include <string>  //To use the string data type
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //user introduction and instructions

//Main program
int main()
{

  //Data
  string objective = "Decode the text from secret.txt to the previous character in the ASCII code."; //Program objective
  string text; //text inputed by the user in their text file
  string inputFile = "secret.txt"; //the file that is inputted by the user
  int c; //loop index.
  ifstream fin; //input file variable

  //User introduction and instructions
  introduction(objective);

  //Open file for input
  fin.open(inputFile.c_str());
  //Check if file is good
  if (!fin.good()) throw "I/O error";

  while (fin.good())
  {
    getline (fin, text); //Get the text from the input file

    //loop for every character in the text
    for (c = 0; c < text.length(); c = c + 1)
    {
      text[c] = text[c] - 1; //Moves the ASCII code for each character up by one
    }

    //Output to console
    cout << text << endl;
  } //while

  //Close files
  fin.close();

}//main


//Introduction and instructions
void introduction(string obj)
{
  //DATA
  //obj is the program objective passed from main
  string ready; //for the user to push enter when they are ready

  //Output user introduction
  cout << "Objective: " << obj << endl;
  cout << "Programmer: Samin Amanat\n";
  cout << "Editor(s) used: Notepad\n";
  cout << "Compiler(s) used: TDM MinGW\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

} //Introduction and instructions