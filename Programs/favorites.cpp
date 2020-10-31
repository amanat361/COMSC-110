//Objective: Assume the user based on their preferences
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
#include <iostream>
using namespace std;

//Programmer defined data types
struct Favorites
{
  string movie;
  string song;
  string food;
  string sport;
  string tvShow;
  string book;
  string place;
};

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //user introduction
void outputRecord(Favorites* record, int nRecords, string* who);

//Main program
int main()
{

  //Data
  string objective = "Template for C++ programs and to test code"; //Program objective
  int i;
  int n = 12;
  int nRecords = 0;
  string whoAreYou[n];
  Favorites favorite[n];
  ifstream fin;

  //User introduction
  introduction(objective);

  fin.open("favoritesData.txt");  
  if (!fin.good()) throw "I/O error";

  while (fin.good())
  {
    Favorites aData;
    getline(fin, aData.movie);
    getline(fin, aData.song);
    getline(fin, aData.food);
    getline(fin, aData.sport);
    getline(fin, aData.tvShow);
    getline(fin, aData.book);
    getline(fin, aData.place);
    fin.ignore(1000, 10);
    nRecords++;

  if(nRecords < n)
  {
    favorite[nRecords++] = aData;
  }
      
  cout << "Who is this? " << endl;
  getline(cin, whoAreYou[nRecords]);
     
  for(int i = 0; i < nRecords; i++)
  { 
    outputRecord(favorite, nRecords, whoAreYou); 
  }
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

void outputRecord(Favorites* record, int nRecords, string* who)
{ 
  int i;
    
    cout << "Person #" << nRecords << ": " << who[i] << endl;
    cout << "Favorite movie: " << record[i].movie << endl;
    cout << "Favorite song: " << record[i].song << endl;
    cout << "Favorite food: " << record[i].food << endl;
    cout << "Favorite sport: " << record[i].sport << endl;
    cout << "Favorite TV show: " << record[i].tvShow << endl;
    cout << "Favorite book: " << record[i].book << endl;
    cout << "Favorite place: " << record[i].place << endl;
    cout << endl;
    
    i++;
}