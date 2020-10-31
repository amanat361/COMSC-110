//Objective: Depending on the capacity in gallons of the fuel tank calculate the range possible with the remaining fuel.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip> //To use the setprecision formatting statement
#include <iostream> //To use console input and output
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
  double capacity; //fuel tank capacity in gallons
  double miles; //distance of their last trip
  double gallons; //amount of fuel used on trip
  double mpg; //amount of miles that can be traveled per gallon
  double totalDistance; //range possible with the remaining fuel

  //Introduction
  cout << "Objective: Calculate the range possible with remaining fuel.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "Instructions: Please answer the following prompts." << endl << endl;

  //Get keyboard input from the user

  //Capacity
  cout << "What is the fuel tank capacity [in gallons] of your vehicle: ";
  cin >> capacity;
  cin.ignore(1000, 10);

  //Miles
  cout << "How many miles was your last trip: ";
  cin >> miles;
  cin.ignore(1000, 10);

  //Gallons
  cout << "How many gallons did you use on that trip: ";
  cin >> gallons;
  cin.ignore(1000, 10);

  //Calculate miles per gallon
  mpg = miles / gallons;

  //Calculate remaining fuel
  capacity = capacity - gallons;

  //Calculate range possible with the remaining fuel
  totalDistance = mpg * capacity;

  //Output answer with both inputs and outputs
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(1);
  cout << endl << "At " << mpg << " miles per gallon and " << capacity << " gallons left in your fuel tank, ";
  cout << "you can drive " << totalDistance << " miles on your next trip!" << endl;

}//main