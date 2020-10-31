//Objective: Template for C++ programs and to test code
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> //To use console input and output
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
  string objective = "Template for C++ programs and to test code"; //Program objective
  int Numbers[4]; //stores 4 input values from the user
  double average = 0; //calculated average of 4 values input
  int nGreater = 0; //calculated number of input values that are greater than the calculated average
  int sum = 0; //sum of input values
  int count = 0; //count input values
  int i = 0; //loop iteration index

  //User introduction and instructions
  introduction(objective);

  //Loop for 4 inputs
  for (i = 0; i <=3; i = i + 1)
  {
  //Input 4 numbers
  cout << "Please enter a number [0-100]: ";
  cin >> Numbers[count];
  cin.ignore(1000, 10);
  //Input validation
  if (Numbers[count] < 0 || Numbers[count] > 100)
  {
    cout << "Please only enter a values 1-100." << endl;
    i = i - 1;
    count = count - 1;
  } //if
  sum = sum + Numbers[count];
  count = count + 1;
  } //for

  //Calculate average
  if (count > 0)
  {
    average = double(sum) / double(count);
  }
  else
  {
    average = sum;
  }

  //Loop for 4 values
  for (i = 0; i <= 3; i = i + 1)
  {
    if (average < Numbers[i])
    {
      nGreater = nGreater + 1;
    } //if
  }

  //Output results
  cout << "The average of ";
  cout << count;
  cout << " numbers is ";
  cout << average;
  cout << ". ";
  cout << nGreater;
  cout << " numbers are greater than the average." << endl;

}//main

void introduction(string obj)
{
  //DATA
  //obj is the program objective passed from main

  //Output user introduction and instructions
  cout << "Objective: " << obj << endl;
  cout << "Programmer: Samin Amanat\n";
  cout << "Editor(s) used: Notepad\n";
  cout << "Compiler(s) used: TDM MinGW\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "You will be asked to enter 4 numbers to get the average of and how many of those numbers are above the average." << endl;
  cout << "Please follow and respond to the prompts as asked." << endl;
} //Introduction and instructions