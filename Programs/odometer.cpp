//Objective: Odometer that counts in miles and increments in tens
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
  cout << "Objective: Odometer that counts in miles and increments in tens.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  cout << "CTRL-C to exit...\n"; 
  cout.fill('0'); 

  for (int mileTenThousand = 0; mileTenThousand < 10; mileTenThousand++) 
  {
    for (int mileThousand = 0; mileThousand < 10; mileThousand++) 
    {
      for (int mileHundred = 0; mileHundred < 10; mileHundred++) 
      {
        for (int mileTen = 0; mileTen < 10; mileTen++) 
        {
          for (int mile = 0; mile < 10; mile++) 
          {
            for (int mileTenth = 0; mileTenth < 10; mileTenth++) 
            {
              cout << setw(1) << '|' << mileTenThousand << '|';
              cout << setw(1) << mileThousand << '|';
              cout << setw(1) << mileHundred << '|';
              cout << setw(1) << mileTen << '|';
              cout << setw(1) << mile << "|.";
              cout << setw(1) << mileTenth << '|';
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
      } //for
    } //for
  } //for
}//main