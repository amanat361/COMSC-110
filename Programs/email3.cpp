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
string getFileName(string dFileName, string fileType); //input validation function
void readFile (string iFileName); //reads input file until EOF and outputs valid email addresses and number of valid email addresses
int processLine(string line); //process lines in input file and returns the number of valid emails
bool isValidEmailCharacter(char c); //process characters from line

//Main program
int main()
{
  //Data
  string objective = "A utility for copying emails from one file to another"; //Program objective
  string dFileName = "fileContainingEmails.txt"; //the default filename
  string iFileName; //the input filename inputted by the user if not default
  string oFileName; //the output filename inputted by the user if not default
  string confirmation; //for the user press enter to continue

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
  //Else - default file (dFileName) = iFileName
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
  cout << "File name confirmation:" << endl;
  //Output label for input file name, and iFileName
  cout << "Input file: " << iFileName << endl;
  //Output label for output file name, and oFileName
  cout << "Output file: " << oFileName << endl;

  //Ask user to press enter to continue as the program waits
  cout << endl << "Press enter to continue with the program...";
  getline(cin, confirmation);
  cout << endl;

  //Get data from input file
  readFile(iFileName);

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
  cout << "This program will output all emails in a file." << endl;
  cout << "You must have some text files already created for this program to work." << endl;
  cout << "This version of the program does not require any output files." << endl;
  cout << "You must input a valid filename that ends in .txt and the program will let you know if your file is invalid." << endl << endl;

} //Introduction and instrcutions

//Get file name from user function
string getFileName(string dFileName, string fileType)
{
  //DATA
  int c; //loop index
  bool inputValid = true; //whether the input is valid or not
  string fileName; //the valid file name passed to main
  string defaultFile = dFileName; //the default file name passed from main
  string inOrOut = fileType; //whether this is for the input or output file

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
  } while (!inputValid); //while input is not valid

  //Return fileName back to main
  cout << endl;
  return fileName;
}

void readFile(string iFileName)
{
  //DATA
  //iFileName passed from main
  int nEmails = 0; //number of valid emails in the whole file
  string lineFromFile; //a line to be read from the input file
  ifstream fin; //input file variable

  //Open file for input
  fin.open(iFileName.c_str());
  //Check if file is good
  if (!fin.good()) throw "I/O error";

  //Process each line in the input file
  while (fin.good())
  {
    //Get the text from the input file
    getline (fin, lineFromFile);
    //Process line
    nEmails = nEmails + processLine(lineFromFile);
  } //while

  //Close input file
  fin.close();

  //Output number of valid emails in file
  cout << endl << endl << "Number of valid email addresses: " << nEmails << endl;

}

//Process lines in the file
int processLine(string line)
{
  //DATA
  //line passed from readLine
  int c; //loop index
  int s; //loop index
  int e; //loop index
  int nEmails = 0; //number of valid emails in the line
  int dotPos; //position of dot in email
  string anEmail; //valid email address
  bool hasDot; //If there is a period in the line

  //For every @ in the line, output the line
  for (c = 0; c < line.length(); c = c + 1)
  {
    if (line[c] == '@')
    {
      //DATA
      s = c - 1;
      e = c + 1;
      hasDot = false;

      //Find beginning of string with s
      //Break loop when invalid email character is met
      for (s; s >= 0; s = s - 1)
      {
        if(!isValidEmailCharacter(line[s]))
        {
          break;
        } //if
      } //for

      //This lines up s with c after the s loop has completed
      s = s + 1;

      //Find end of string with e
      //Get valid characters from email to output
      for (e; e < line.length(); e = e + 1)
      {
        //If email character is not valid
        if (!isValidEmailCharacter(line[e]))
        {
          break;
        } //if

        //Check if email contains dot
        if (line[e] == '.')
        {
          dotPos = e;
          hasDot = true;
        } //if
      } //for

      //Check if dot is at least one character after email and output email
      if (hasDot && dotPos > (c + 1) && s < c && e > c)
      {
        cout << line.substr(s,e-s) << "; ";
        nEmails = nEmails + 1;
      }
    } //if
  } //for

  //Return number of valid emails to readFile
  return nEmails;

} //processLine

//Is valid email character
bool isValidEmailCharacter(char c)
{
  //DATA
  //c passed from main as character

  //Character IS a valid email character
  if((c >='A' && c <= 'Z') || (c >='a' && c <='z') || (c >='0' && c <='9') || c=='.' || c=='-' || c=='+')
  {
    return true;
  }

  //Character is not a valid email character
  return false;
}