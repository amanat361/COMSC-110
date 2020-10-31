//Objective: Digital clock that updates every second
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#ifdef _WIN32 
#include <windows.h> 
#else 
#include <unistd.h> 
#endif
#include <iostream>
#include <iomanip>
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
  //NONE

  //Introduction
  cout << "Objective: Digital clock that updates every second.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  cout << "CTRL-C to exit...\n"; 
  cout.fill('0'); 
  
  for (int hr = 0; hr < 24; hr++) 
  { 
    for (int min = 0; min < 60; min++) 
    { 
      for (int sec = 0; sec < 60; sec++) 
      { 
        cout << setw(2) << hr << ':'; 
        cout << setw(2) << min << ':'; 
        cout << setw(2) << sec << ' '; 
        cout.flush(); 
  
        //Calculate time and update every second
        #ifdef _WIN32 
        Sleep(1000); // one thousand milliseconds
        #else 
        sleep(1); // one second 
        #endif 

        //Output time
        cout << '\r'; // CR 

      } //for
    } //for
  } //for

}//main