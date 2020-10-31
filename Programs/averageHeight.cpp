//Objective: Find the average height of everyone in the room.
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
//NONE

//main program
int main()
{

  //Data
  double height; //each person's height in inches (21.5 inches - 99 inches are valid values)
  int count = 0; //number of people in the room
  double sum = 0; //sum of all heights
  int averageHeight; //average height of all the people in the room
  int feet; //when converting average height to feet, this holds the whole number of feet
  int inches; //when converting average height to feet, this holds the remainder of inches
  char peopleLeft; //either Y or N to see if any people are left in the room

  //Introduction
  cout << "Objective: This program will serve as a template for all programs\n written in this course.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "Instructions: Please answer the prompts about each person's height." << endl << endl;

  //Start loop asking for people's height, do until there are no more people
  do
  {
    //Ask again if value is not between 21.5 inches and 99 inches
    do
    {
      //Ask for people's height
      cout << "What is a height in inches [21.5 - 99]: ";
      cin >> height;
      cin.ignore(1000, 10);

      //Error message
      if (!(height >= 21.5 && height <= 99))
      {
        cout << "That is an invalid height. Height must be in inches and between 21.5 inches and 99 inches." << endl;
      }
    } while (!(height >= 21.5 && height <= 99)); //Input validation

    //Add height to sum
    sum = sum + height;

    //Add one to count
    count = count + 1;

    //Ask of there are any people left in the room
    cout << "Are there more people to count? [Y/N]: ";
    cin >> peopleLeft;
    cin.ignore(1000, 10);

  } while (peopleLeft == 'Y' || peopleLeft == 'y'); //loop as long as there are people left in room

  //Calculate average height of all the people
  averageHeight = sum / count;

  //Convert average height to feet
  feet = averageHeight / 12;
  inches = averageHeight % 12;

  //Output the average height
  cout << "The average height is " << feet << "'" << inches << "\"" << endl;

}//main