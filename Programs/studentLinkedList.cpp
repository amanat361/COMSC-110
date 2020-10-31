//Objective: Table of student data
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//Programmer defined data types
struct Student
{
  string name;
  int id;
  float gpa;
  Student* next; // the next-link
}; // Student

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
  ifstream fin;
  int count = 0;
  Student* start = 0;
  Student* p;
  string objective = "Template for C++ programs and to test code"; //Program objective

  //User introduction
  introduction(objective);

  //Open a file for input
  fin.open("students.txt");
  if (!fin.good()) throw "I/O error";

  //Read and save the records
  while (fin.good())
  {
    // Step 1, create a node
    Student* aStudent = new Student;

    // Step 2, read its data fields
    getline (fin, aStudent->name);

    fin >> aStudent->id;
    fin.ignore(1000, 10);
 
    fin >> aStudent->gpa;
    fin.ignore(1000, 10);
 
    fin.ignore(1000, 10); // skip the separator line

    // Step 3, add new node to the list
    aStudent->next = start;
    start = aStudent;

    count = count + 1;
  }

  //Close file for input
  fin.close(); 

  //Output number of students
  cout << "The number of students is: " << count << endl << endl;

  //Traverse the list and output
  for (p = start; p; p = p->next)
  {
    cout << "Name = " << left << setw(30) << p->name;
    cout.fill('0'); 
    cout << " ID = " << right << setw(7) << p->id
      << ", gpa = " << p->gpa << endl;
    cout.fill(' '); 
  }

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