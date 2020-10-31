//Objective: Read names in a text file, sort them alphabetically, and output them to the screen.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //for file input
#include <iostream> //for console input and output
#include <string> //to use the string data type
using namespace std;
#include <cctype> //to convert string to lowercase

//Programmer defined data types
//Struct for Names
struct Names
{
  string name; //name from the list
};

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
  string objective = "Read names in a text file, sort them alphabetically, and output them to the screen."; //Program objective
  string fileName; //the name of the input file
  const int SIZE = 5; //size of the array
  int nNames = 0; //count how many names have been inputted
  Names listOfNames[SIZE]; //list of names within struct names
  Names aName; //a name to add to the array
  int c; //loop index outter loop
  int x; //loop index inner loop
  bool inputValid = true; //skip blank lines and duplicates in file
  ifstream fin; //input file variable

  //User introduction and instructions
  introduction(objective);

  //Ask for filename from user
  cout << "What is the name of the file that you created? ";
  cin >> fileName;
  cin.ignore(1000, 10);

  //Open file for input
  fin.open(fileName.c_str());
  if (!fin.good()) throw "I/O error";

  //Read through lines in the file
  while (fin.good())
  {
    //Reset value of input valid
    inputValid = true;

    //Get line in the file
    getline (fin, aName.name);

    //Skip blank lines
    if (aName.name.length() <= 0)
    {
      inputValid = false;
    }

    //Check if duplicate
    for (c = 0; c < nNames; c = c + 1)
    {
      for (x = 0; x < listOfNames[c].name.length(); x = x + 1)
      {
        if (tolower(aName.name[x]) == tolower(listOfNames[c].name[x]))
        {
          inputValid = false;
        }
        else
        {
          inputValid = true;
        }
      }
    }

    //Add name to array if it is not full
    if (nNames < SIZE && inputValid)
    {
     listOfNames[nNames++] = aName;
    }
  } //while

  //Close file for input
  fin.close();

  //Sort list of names in alphabetical order
  //Loop through all the names in the file starting with #1 (index 0)
  for (c = 0; c < nNames; c = c + 1)
  {
    //Loop through all the names in the file starting with #2 (index 1)
    for (x = c + 1; x < nNames; x = x + 1)
    {
      //Compare the two names
      if (tolower(listOfNames[c].name[0]) > tolower(listOfNames[x].name[0]))
      {
        //Bubble sort
        Names temp = listOfNames[c];
        listOfNames[c] = listOfNames[x];
        listOfNames[x] = temp;
      } //if
    } //for x
    //Output
    cout << listOfNames[c].name << endl;
  } //for c
}//main

void introduction(string obj)
{
  //DATA
  //obj is the program objective passed from main
  string ready; //see if the user is ready

  //Output user introduction
  cout << "Objective: " << obj << endl;
  cout << "Programmer: Samin Amanat\n";
  cout << "Editor(s) used: Notepad\n";
  cout << "Compiler(s) used: TDM MinGW\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Output user intsructions
  cout << "Since this program will sort names in a text file, you will need to create that file." << endl;
  cout << "Please create an empty text file." << endl;
  cout << "Please enter names of your friends on lines in the file." << endl;
  cout << "You may enter five names MAXIMUM. No more. Less is okay." << endl;
  cout << "Once you have created this text file filled with information, push enter to continue." << endl;
  cout << "The program will wait for you to finish and push enter...";
  getline (cin, ready);
  cout << endl;

} //Introduction and instructions