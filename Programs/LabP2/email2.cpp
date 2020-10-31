//Objective: A utility for copying emails from one file to another
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //to use file input (this program doesn't use file output yet)
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
void introduction(string obj); //user introduction and instructions
string getFileName(string dFileName, string inputOrOutput); //input validation function
void processLine(string line); //process lines in input file

//Main program
int main()
{
  //Data
  string objective = "A utility for copying emails from one file to another"; //Program objective
  string dFileName = "fileContainingEmails.txt"; //the default filename
  string iFileName; //the input filename inputted by the user if not default
  string oFileName; //the output filename inputted by the user if not default
  string confirmation; //for the user press enter to continue
  string text; //a line to be read from the input file
  ifstream fin; //input file variable

  //User introduction and instructions
  introduction(objective);

  //Get input filename
  iFileName = getFileName(dFileName, "input");

  //If enter key is true, iFilename = dFilename and dFilename = "copyPasteMyEmails.txt"
  if (iFileName.length() == 0)
  {
    iFileName = dFileName;
    dFileName = "copyPasteMyEmails.txt";
  } //if
  else
  {
    dFileName = iFileName;
  } //else

  //Get output filename
  oFileName = getFileName(dFileName, "output");

  //If enter key is true, iFilename = dFilename and dFilename = "copyPasteMyEmails.txt"
  if (oFileName.length() == 0)
  {
    oFileName = dFileName;
  } //if

  //Output confirmation message
  cout << endl << "File name confirmation:" << endl;
  //Output label for input file name, and iFileName
  cout << "Input file: " << iFileName << endl;
  //Output label for output file name, and oFileName
  cout << "Output file: " << oFileName << endl;

  //Ask user to press enter to continue as the program waits
  cout << endl << "Press enter to continue with the program...";
  getline(cin, confirmation);

  //Open file for input
  fin.open(iFileName.c_str());
  //Check if file is good
  if (!fin.good()) throw "I/O error";

  //Process each line in the input file
  while (fin.good())
  {
    //Get the text from the input file
    getline (fin, text);
    //Process line
    processLine(text);
  } //while

  //Close input file
  fin.close();

}//main

//Introduction and instrcutions
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

  //Output user intructions
  cout << "This program will output a line in a file based on the amount of @ symbols it contains." << endl;
  cout << "You must have some text files already created for this program to work." << endl;
  cout << "This program does not require any output files." << endl;
  cout << "You must input a valid filename that ends in .txt and the program will let you know if your file is invalid." << endl << endl;

} //Introduction and instrcutions

//Get file name from user function
string getFileName(string dFileName, string inputOrOutput)
{
  //DATA
  int c; //loop index
  bool inputValid = true; //whether the input is valid or not
  string fileName; //the valid file name passed to main
  string defaultFile = dFileName; //the default file name passed from main
  string inOrOut = inputOrOutput; //whether this is for the input or output file

  //Loop until valid input filename
  do
  {
    //Reset input valid to true
    inputValid = true;

    //Prompt user for filename
    cout << "Enter " << inOrOut << " filename [enter for default: " << dFileName << "]: ";
    getline(cin, fileName);

    //Check if filename is 0 characters for default file
    if (fileName.length() == 0)
    {
      inputValid = true;
    }

    //Check if filename is between 0 and 5 characters
    else if (fileName.length() > 0 && fileName.length() < 5)
    {
      inputValid = false;
      cout << "This filename is invalid because it is too short. Perhaps you forgot the file extention." << endl << endl;
    } //if

    //Check if filename starts with a space
    else if (fileName[0] == ' ')
    {
      inputValid = false;
      cout << "This filename is invalid because it starts with a space." << endl << endl;
    } //else if

    //Check if filename starts with a period
    else if (fileName[0] == '.')
    {
      inputValid = false;
      cout << "This filename is invalid because it starts with a period." << endl << endl;
    } //else if

    //Check if filename ends with ".txt"
    else if (!(fileName[fileName.length() - 1] == 't' && fileName[fileName.length() - 2] == 'x' && fileName[fileName.length() - 3] == 't' && fileName[fileName.length() - 4] == '.'))
    {
      inputValid = false;
      cout << "This filename is invalid because it does not end with \".txt\"" << endl << endl;
    } //else if

    //Check if filename has special characters
    for (c = 0; c < fileName.length(); c = c + 1)
    {
      if (fileName[c] == '\"' || fileName[c] == '*' || fileName[c] == ':' || fileName[c] == '<' || fileName[c] == '>' || fileName[c] == '?' || fileName[c] == '/' || fileName[c] == '|')
      {
        inputValid = false;
        cout << "This filename is invalid because it contains a special character \" * : < > ? / or |" << endl << endl;
      } //if
    } //for
  } while (!(inputValid)); //while

  //Return fileName back to main
  cout << endl;
  return fileName;
}

//Process lines in the file
void processLine(string line)
{
  //DATA
  //line passed from main
  int c; //loop index

  //For every @ in the line, output the line
  for (c = 0; c < line.length(); c = c + 1)
  {
    if (line[c] == '@')
    {
      cout << line << endl;
    } //if
  } //for
} //processLine