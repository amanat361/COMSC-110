//Objective: find maximum score, minimum score, average score, and number of scores greater than average of all the scores from input file
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //To use file input
#include <iostream> //To use console input and output
#include <string> //To use the string data type
using namespace std;

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

  //Data
  string objective = "find maximum score, minimum score, average score, and number of scores greater than average of all the scores from input file"; //Program objective
  string fileName; //input file name
  string line; //a line from the input file
  double averageScore; //calculated average of all the scores in the input file
  int count; //number of scores in the input file
  int totalScores; //sum of all the scores in the input file
  int maxScore; //highest score of all the scores in the input file
  int minScore; //lowest score of all the scores in the input file
  int nGreater; //number of scores greater than the average score
  int i; //indice for traversing each element in the array
  int* scores = new int[count]; //holds all the scores read from the input file, each score is betwen 0-100
  ifstream fin; //input file variable

  //User introduction
  introduction(objective);

  //get input filename from user
  cout << "What is the input file name? ";
  cin >> fileName;
  cin.ignore(1000, 10);

  //determine how many scores are in the input file for storing the values
  count = 0;
  fin.open(fileName.c_str());
  if (!fin.good())
  {
    return 0;
  } //if file is not good, end program
  while (getline(fin, line))
  {
    count = count + 1;
  } //while
  fin.close();

  //create dynamic array
  if (count == 0)
  {
    cout << "Sorry, the file is empty." << endl;
    return 0;
  }

  //input values from input file
  fin.open(fileName.c_str());
  for (i = 0; i <= count; i = i + 1)
  {
    fin >> scores[i];
  }

  //calculate the average score
  totalScores = 0;
  maxScore = scores[0];
  minScore = scores[0];
  for (i = 0; i < count; i = i + 1)
  {
    //calculate max score
    if (maxScore < scores[i])
    {
      maxScore = scores[i];
    }
    //calculate min score
    if (minScore > scores[i])
    {
      minScore = scores[i];
    }
    totalScores = totalScores + scores[i];
  }
  averageScore = totalScores / count;

  //calculate the number of scores greater than the average
  nGreater = 0;
  for (i = 0; i <= count; i = i + 1)
  {
    if (scores[i] > averageScore)
    {
      nGreater = nGreater + 1;
    }
  }

  //output results
  cout << "The scores from the file " << fileName << " are: " << endl;
  for (i = 0; i < count; i = i + 1)
  {
    cout << scores[i] << endl;
  }
  cout << "The average of " << count << " scores is: " << averageScore << endl;
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