//Objective: Enter a line of text then encode the text to based on the encoding array.
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
char encrypt(char text, int increment, int size); //encryption function

//Main program
int main()
{

  //Data
  string objective = "Enter a line of text then encode the text to based on the encoding array."; //Program objective
  string text; //text inputed by the user in their text file
  string inputFile; //the file that is inputted by the user
  string outputFile = "secret.txt"; //the file that the encoded text is outputted to
  int c; //loop index for going through text
  ifstream fin; //input file variable
  ofstream fout; //output file variable
  int offsetIndex; //the location in the offset array
  int counter = 0; //how far in the string the loop has gone through
  const int SIZE = 5; //size of the array
  int offset[SIZE] = {-5, 8, 12, 6, 1}; //an array of whole numbers

  //User introduction and instructions
  introduction(objective);

  //Ask user for name of input file
  cout << "What is the name of the file to be encoded? (should end with .txt): ";
  cin >> inputFile;

  //Open file for input
  fin.open(inputFile.c_str());
  //Check if file is good
  if (!fin.good()) throw "I/O error";

  //Open file for output
  fout.open(outputFile.c_str());
  //Check if file is good
  if (!fin.good()) throw "I/O error";

  while (fin.good())
  {
    offsetIndex = counter % SIZE; //see if the offset array needs to overlap
    getline (fin, text); //Get the text from the input file

    //loop for every character in the text
    for (c = 0; c < text.length(); c = c + 1)
    {
      text[c] = text[c] + offset[offsetIndex]; //moves the ASCII code of the character by the offset index
      counter = counter + 1;
      offsetIndex = counter % SIZE; //see if the offset array needs to overlap
    }

    //Output to file
    fout << text << endl;

    //Output to console
    cout << text << endl;
  } //while file has not ended

  //Close files
  fin.close();
  fout.close();

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

  //Output user instructions
  cout << "Please make a text file that you would like to be encoded." << endl;
  cout << "Put your text that you would like to be encoded inside of that file." << endl;
  cout << "The encoded file will be created as \"secret.txt\" and also outputted to the console." << endl;
  cout << "When you are done, push enter, the program will wait...";
  getline(cin, ready);

} //Introduction and instructions