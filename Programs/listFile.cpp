//Objective: Calculate the average, highest, lowest scores and scores greater than average, using a linked list
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
#include <iostream>
using namespace std;

//Programmer defined data types
struct Student
{
  int score; //the score of the student
  Student* next; //the link
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //user introduction

//Main program
int main()
{
  //Data
  string objective = "Calculate average, min, and max, scores and how many > average."; //Program objective
  ifstream fin; //to use file input
  int nGreater = 0; //number of scores greater than the average
  int count = 0; //the number of scores
  int scoreTotal = 0; //the sum of all of the scores
  int temp; //temporary value for inputted score
  double average; //a decimal value holding the average score
  Student* p; //a variable to traverse through the linked list
  Student* start = 0; //create an empty linked list
  int minScore = 0; //the lowest score of the list
  int maxScore = 0; //the highest score of the list

  //User introduction
  introduction(objective);

  //Open text file for input
  fin.open("scores.txt");
  if (!fin.good()) throw "I/O error";

  //Read and save the scores 
  while (fin.good()) 
  {
    //Make a new score each time the loop repeats
    Student* aScore = new Student;

    //Read a score from the file
    fin >> temp;
    fin.ignore(1000, 10);

    //Add node to list
    if (temp >= 0 && temp <= 100)
    {
      aScore->score = temp;
      aScore->next = start;
      start = aScore;
      count = count + 1;
    } //if
  } //while

  //Close input file
  fin.close();

  //Calculate the average
  for (p = start; p; p = p->next)
  {
    scoreTotal = scoreTotal + p->score;
  } //for
  average = (double)scoreTotal / count;
  
  //Count number of scores > average 
  for (p = start; p; p = p->next)
  {
    if (p->score > average) nGreater++;
  } //for

  //Calculate maximum score
  for (p = start; p; p = p->next)
  {
    if (maxScore < p->score)
    {
      maxScore = p->score;
    }
   } //for

  //Calculate minimum score
  minScore = maxScore;
  for (p = start; p; p = p->next)
  {
    //calculate min score
    if (minScore > p->score)
    {
      minScore = p->score;
    }
  }

  //Output results
  cout << "The average of " << count << " scores is: " << average << endl;
  cout << "The highest score is: " << maxScore << endl;
  cout << "The lowest score is: " << minScore << endl;
  cout << "The number of scores greater than the average is: " << nGreater << endl;

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
} //Introduction