//Objective: Play a random song in a list of songs excluding the last 5 played songs
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <deque> //to use queue functions such as .pop and .push
#include <fstream> //for file input
#include <iostream> //for console input and output
#include <string> //to use the string data type
using namespace std;
#include <cctype> //to convert string to lowercase
#include <cstdlib> //To use the random number function
#include <ctime> //To use the random number function

//Programmer defined data types
struct recentFive
{
  string recentSong;
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //user introduction
bool inputValidation(string temp); //input validation

//Main program
int main()
{
  srand(time(0)); //To use the random number function

  //Data
  string objective = "Play a random song in a list of songs excluding the last 5 played songs."; //Program objective
  string fileName; //the name of the input file
  string temp; //temporary value that holds the song name
  string outputSong = ""; //what to output as the song
  int number; //randomly generated number between 1-200
  int c; //loop index
  bool inputValid = true; //input validation parameter
  bool recent = false; //was the song recently played
  bool continuePlaying = true; //continue playing the songs
  char playSong; //y/n if the user wants to play the next song
  ifstream fin; //input file variable
  //-----
  const int MAX_SONGS = 200; //maximum amount of songs that the list can have
  int nSongs = 0; //the number of songs in the list
  string listOfSongs[MAX_SONGS]; //array of songs
  //-----
  deque<recentFive> aRecentFive; //empty list of songs
  recentFive aSong; //creates a new song within the list

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
      listOfSongs[nSongs++] = temp;
    } //if
  } //while

  //Close input file
  fin.close();

  //Play a random song in the array if the user wants to that hasn't been recently played
  do
  {
    //See if the user wants to play a song
    cout << "Play a song? [Y/N]: ";
    cin >> playSong;
    cin.ignore(1000, 10);
    //Convert song to lowercase
    playSong = tolower(playSong);
    //If user chooses to play a song
    if (playSong == 'y')
    {
      //Loop as long as the user chooses to continue
      do
      {
        //Play song if yes

        //Reset continuePlaying bool
        continuePlaying = true;

        //Get random number between 1 and number of songs
        number = rand() % nSongs;

        //Change the output song to a song in listOfSongs at index of random number
        outputSong = listOfSongs[number];

        //Reset recent bool
        recent = false;

        //Traverse through list of 5 recent songs
        for (c = 0; c < aRecentFive.size(); c++)
        {
          //If the output song is in the list of recent songs, it has already been recently played
          if ((aRecentFive[c].recentSong) == outputSong)
          {
            recent = true;
          } //if
        } //for

        //If the song has not been recently played
        if (recent == false)
        {
          //Output to console the outputSong
          cout << outputSong << endl;

          //Queue outputSong to the recent 5 songs
          aSong.recentSong = outputSong;

          //Move 4 recent songs backward in the recent songs list (one will leave the list)
          if (aRecentFive.size() == 5)
          {
            //
            aRecentFive.pop_front();
          } //if

          //Take the new song and add it to the front of the queue
          aRecentFive.push_back(aSong);

        } //if
      } while (recent); //while the song hasen't been recently played
    } //if

    //If the user did not push Y or y, then don't continue the loop
    else
    {
      continuePlaying = false;
    } //else

  } while (continuePlaying); //while the user chooses to continue playing
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