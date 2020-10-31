//Objective: To calculate the change due from a text file input.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
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
void introduction(string obj); //user introduction

//Main program
int main()
{

  //Data
  string objective = "To calculate the change due from a text file input."; //Program objective
  ifstream fin; //To input data from a text document
  int amountOwed; //amount owed to be inputted by the user in change.txt
  int cashPaid; //amount paid to be inputted by the user in change.txt
  int totalChangeDue; //the amount of change that is owed
  int changeDue; //a variable version of totalChangeDue
  int thousand100; //number of $100000 bills
  int thousand10; //number of $10000 bills
  int thousand5; //number of $5000 bills
  int thousand; //number of $1000 bills
  int hundred5; //number of $500 bills
  int hundred; //number of $100 bills
  int fifty; //number of $50 bills
  int twenty; //number of $20 bills
  int ten; //number of $10 bills
  int five; //number of $5 bills
  int two; //number of $2 bills
  int one; //number of $1 bills
  string ready; //if the user is ready to continue

  //Output user introduction and instructions
  introduction(objective); //User introduction and instrucions

  //Output that the program will wait for them to make the file
  cout << "Push the enter key when the file is ready...";
  getline(cin, ready);

  //Open file and see if it is valid
  fin.open("change.txt");
  if (!fin.good()) throw "I/O error";

  //Take values given by the user and assign to amountOwed and cashPaid
  fin >> amountOwed;
  fin.ignore(1000, 10);
  fin >> cashPaid;
  fin.ignore(1000, 10);

  //Calculate change due
  totalChangeDue = cashPaid - amountOwed;
  changeDue = totalChangeDue;

  //Calculate how the change should be paid out
  thousand100 = changeDue / 100000; //number of $100,000 bills
  changeDue = changeDue % 100000; //remainder from $100,000
  thousand10 = changeDue / 10000; //number of $10,000 bills
  changeDue = changeDue % 10000; //remainder from $10,000
  thousand5 = changeDue / 5000; //number of $5,000 bills
  changeDue = changeDue % 5000; //remainder from $5,000
  thousand = changeDue / 1000; //number of $1,000 bills
  changeDue = changeDue % 1000; //remainder from $1,000
  hundred5 = changeDue / 500; //number of $500 bills
  changeDue = changeDue % 500; //remainder from $500
  hundred = changeDue / 100; //number of $100 bills
  changeDue = changeDue % 100; //remainder from $100
  fifty = changeDue / 50; //number of $50 bills
  changeDue = changeDue % 50; //remainder from $50
  twenty = changeDue / 20; //number of $20 bills
  changeDue = changeDue % 20; //remainder from $20
  ten = changeDue / 10; //number of $10 bills
  changeDue = changeDue % 10; //remainder from $10
  five = changeDue / 5; //number of $5 bills
  changeDue = changeDue % 5; //remainder from $5
  two = changeDue / 2; //number of $2 bills
  changeDue = changeDue % 2; //remainder from $2
  one = changeDue;

  //Output the inputted values
  cout << "The amount owed is: " << amountOwed << endl;
  cout << "The cash paid is: " << cashPaid << endl;
  cout << "The change due is: " << totalChangeDue << endl << endl;
  cout << "It will be paid out in: " << endl;

  //Output only the values greater than zero
  if (thousand100 > 0)
  {
    cout << "This many $100,000 bills: " << thousand100 << endl;
  }
  if (thousand10 > 0)
  {
    cout << "This many $10,000 bills: " << thousand10 << endl;
  }
  if (thousand5 > 0)
  {
    cout << "This many $5,000 bills: " << thousand5 << endl;
  }
  if (thousand > 0)
  {
    cout << "This many $1,000 bills: " << thousand << endl;
  }
  if (hundred5 > 0)
  {
    cout << "This many $500 bills: " << hundred5 << endl;
  }
  if (hundred > 0)
  {
    cout << "This many $100 bills: " << hundred << endl;
  }
  if (fifty > 0)
  {
    cout << "This many $50 bills: " << fifty << endl;
  }
  if (twenty > 0)
  {
    cout << "This many $20 bills: " << twenty << endl;
  }
  if (ten > 0)
  {
    cout << "This many $10 bills: " << ten << endl;
  }
  if (five > 0)
  {
    cout << "This many $5 bills: " << five << endl;
  }
  if (two > 0)
  {
    cout << "This many $2 bills: " << two << endl;
  }
  if (one > 0)
  {
    cout << "This many $1 bills: " << one << endl;
  }

  //Close file
  fin.close();

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

  //Output suer instructions
  cout << "You will be asked to input values into a file.";
  cout << "The file must be named exactly as \"change.txt\"." << endl;
  cout << "Put two values on two lines";
  cout << ", amount owed on line one, and change due on line two" << endl;
  cout << "Do not put any symbols such as $ or ,";
  cout << "because the program only needs the number." << endl << endl;
} //Introduction