//Objective: 4 function calculator that takes two numbers and an operator as input and gives the result
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//Libraries
#include <iostream>
#include <string>
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
  double firstNumber; //the user's first number
  double secondNumber; //the user's second number
  double answer; //the result of the equation
  int mathOperator; //a number that represents the operator
  string operatorText; //to output the result with the operator
  char loopProgram; //either Y or N to continue loop or not

  //Introduction
  cout << "Objective: 4 function calculator that takes two numbers and an operator as input and gives the result.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "Instructions: Please follow the prompts." << endl << endl;

  do //loop as long as user chooses "Y" to continue
  {

  //Get the two numbers from user
  cout << "Please enter first number: ";
  cin >> firstNumber;
  cin.ignore(1000, 10);
  cout << "Please enter second number: ";
  cin >> secondNumber;
  cin.ignore(1000, 10);

  //Repeat asking for operator if value is incorrect
  do
  {
    //Get the operator from user
    cout << "Please enter operator [1= addition  2= subtraction  3= multiplcation  4= division]: ";
    cin >> mathOperator;
    cin.ignore(1000, 10);

    //Error message if operator is not between 1 and 4
    if (!(mathOperator >= 1 && mathOperator <= 4))
    {
      cout << "That was not a number 1-4" << endl;
    }
  } while (!(mathOperator >= 1 && mathOperator <= 4)); //do-while operator is not 1-4

  //Calculations

  //Addition
  if (mathOperator == 1)
  {
    answer = firstNumber + secondNumber;
    operatorText = "+";
  }

  //Subtraction
  else if (mathOperator == 2)
  {
    answer = firstNumber - secondNumber;
    operatorText = "-";
  }

  //Multiplication
  else if (mathOperator == 3)
  {
    answer = firstNumber * secondNumber;
    operatorText = "*";
  }

  //Division
  else if (mathOperator == 4)
  {
    answer = firstNumber / secondNumber;
    operatorText = "/";
  }

  //Output result
  cout << firstNumber << " " << operatorText << " " << secondNumber << " = " << answer << endl;

  //See if user would like to go again
  cout << "Another calculation [Y=yes or N=no]: ";
  cin >> loopProgram;
  cin.ignore(1000, 10);

  } while (loopProgram == 'Y' || loopProgram == 'y'); //do as long as user chooses Y (or y) to continue

}//main