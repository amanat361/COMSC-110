//Objective: Template for C++ programs and to test code
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <deque>
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
}; // Student

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //user introduction
void outputStudents(deque<Student>& student);

//Main program
int main()
{

  //Data
  string objective = "Template for C++ programs and to test code"; //Program objective
  int i; //loop index
  ifstream fin;  //input file
  deque<Student> student; // create an empty list

  //User introduction
  introduction(objective);

  //Open file for input
  fin.open("students.txt");
  if (!fin.good()) throw "I/O error";
 
  //Read and save the records
  while (fin.good())
  {
    Student aStudent;
    getline(fin, aStudent.name);

    fin >> aStudent.id;
    fin.ignore(1000, 10);
 
    fin >> aStudent.gpa;
    fin.ignore(1000, 10);
 
    fin.ignore(1000, 10); // skip the separator line

    student.push_back(aStudent);
  } // while
  fin.close();
 
  outputStudents(student);

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
 
void outputStudents(deque<Student>& student)
{
  int i; //loop index
  for (i = 0; i < student.size(); i++)
  {
    cout << "Name = " << left << setw(30) << student[i].name;
    cout.fill('0'); 
    cout << " ID = " << right << setw(7) << student[i].id
      << ", gpa = " << student[i].gpa << endl;
    cout.fill(' '); 
  } // for
} // outputStudents