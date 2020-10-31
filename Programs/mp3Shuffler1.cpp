//Objective: Read all song titles from a text file, and randomly select and output titles in a loop until the user wishes to stop
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
#include <cstdlib> //To use the random number function
#include <ctime> //To use the random number function

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
  srand(time(0)); //To use the random number function

  //Data
  string objective = "Read all song titles from a text file, and randomly select and output titles in a loop until the user wishes to stop"; //Program objective
  string fileName; //the name of the input file
  int number; //randomly generated number between 1-200
  int nSongs = 0; //initially empty list
  const int MAX_SONGS = 200; //list capacity
  string songList[MAX_SONGS]; //the array that holds the user's songs
  string temp; //temporary value that holds the song name
  char playSong; //y/n if the user wants to play the next song
  bool inputValid = true; //input validation parameter
  ifstream fin; //input file variable

  //User introduction
  introduction(objective);

  //Prompt for filename
  cout << "What is the name of the file with the list of songs: ";
  getline(cin, fileName);

  //Open file for input
  fin.open(fileName.c_str());
  if (!fin.good()) throw "I/O error";

  //Read through lines in the file
  while (fin.good())
  {
    //Reset value of input valid
    inputValid = true;

    //Get line in the file
    getline (fin, temp);

    //Check if line is blank
    if (temp.length() <= 0)
    {
      inputValid = false;
    } //if

    //Add value of song to list of songs if input is valid
    if (inputValid && nSongs < MAX_SONGS)
    {
      songList[nSongs++] = temp;
    } //if
  } //while

  //Play a random song in the array if the user wants to
  do
  {
    //See if the user wants to play a song
    cout << "Play a song? [Y/N]: ";
    cin >> playSong;
    cin.ignore(1000, 10);
    playSong = tolower(playSong);

    //Play song if yes
    if (playSong == 'y')
    {
      number = rand() % nSongs;
      cout << songList[number] << endl;
    } //if
  } while (playSong == 'y'); //while
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

  //Output user instructions
  cout << "Please create a text file with 200 songs listed on separate lines." << endl;
} //Introduction