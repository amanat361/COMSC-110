//Objective: Template for C++ programs and to test code
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
void introduction(string obj); //user introduction and instructions

//Main program
int main()
{
  //Data
  string objective = "Template for C++ programs and to test code"; //Program objective
  int size; //the number of vlaues to be inputted
  int* Scores = new int[size]; //dynamically defined for SIZE number of values
  int min; //minimum value of inputed values
  int max; //maximum value of inputed values
  int sum = 0; //sum from all the inputed values
  double average; //average value of inputed values
  int nGradeA = 0; //number of scores that are A grade
  int temp; //used for temporarily storing one of the values in the array in the swapping process to sort
  int i; //loop index for sorting
  int j; //loop index for sorting

  //User introduction and instructions
  introduction(objective);

  //Output prompt for number of scores
  cout << "How many scores? ";
  cin >> size;
  cin.ignore(1000, 10);

  //Input values for the array and sum them together
  for (i = 0; i < size; i = i + 1)
  {
    cout << "Enter a score: ";
    cin >> Scores[i];
    cin.ignore(1000, 10);
    //Input validation
    if (Scores[i] < 0 || Scores[i] > 100)
    {
      cout << "Invalid value." << endl;
      i = i - 1;
    }
    sum = sum + Scores[i];
  }

  //Calculate average
  if (size > 0)
  {
    average = sum / size;
  }
  else
  {
    average = sum;
  }

  //Calculate minimum and maximum scores
  min = Scores[0];
  for (i = 0; i < size; i = i + 1)
  {
    if (min > Scores[i])
    {
      min = Scores[i];
    }
  }
  max = Scores[0];
  for (i = 0; i < size; i = i + 1)
  {
    if (max < Scores[i])
    {
      max = Scores[i];
    }
  }

  //Sort loops
  for (i = 0; i < size; i = i + 1)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (Scores[i] > Scores[j])
      {
        //Swap code
        temp = Scores[i];
        Scores[i] = Scores[j];
        Scores[j] = temp;
      } //if
    } //for j
  } //for i

  //Output results
  cout << "Sorted: ";
  for (i = 0; i < size; i = i + 1)
  {
    cout << Scores[i] << " ";
  }
  cout << endl;
  cout << "Minimum: " << min << endl;
  cout << "Maximum: " << max << endl;
  cout << "Average: " << average << endl;
  cout << "A Grades: " << nGradeA << endl;

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

  cout << "Please answer the prompts as they show up with appropriate values." << endl;
  cout << "You will be asked to enter multiple scores." << endl << endl;
} //Introduction and instructions