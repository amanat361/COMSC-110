//Objective: Calculate change due in a transaction using these U.S. bills - no cents: $1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills.
//Name: Samin Amanat
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <ifstream>
#include <iostream>
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
  ifstream fin;
  int amountOwed = 44999; //amount owed
  int cashPaid = 50000; //amount paid
  int totalChangeDue = cashPaid - amountOwed; //total change due
  int changeDue = totalChangeDue; //a variable change due amount
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

  //Introduction
  cout << "Objective: calculate change due in a transaction using these U.S. bills - no cents: \n$1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills.\n"; 
  cout << "Programmer: Samin Amanat\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Calculate total change due
  totalChangeDue = cashPaid - amountOwed;

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
 
  //Output calculated change due for each kind of monetary demonination
  cout << "Amount owed: $" << amountOwed << endl;
  cout << "Cash paid: $" << cashPaid << endl;
  cout << "Total change due: $" << totalChangeDue << endl << endl;
  cout << "This many $100,000 bills: " << thousand100 << endl;
  cout << "This many $10,000 bills: " << thousand10 << endl;
  cout << "This many $5,000 bills: " << thousand5 << endl;
  cout << "This many $1,000 bills: " << thousand << endl;
  cout << "This many $500 bills: " << hundred5 << endl;
  cout << "This many $100 bills: " << hundred << endl;
  cout << "This many $50 bills: " << fifty << endl;
  cout << "This many $20 bills: " << twenty << endl;
  cout << "This many $10 bills: " << ten << endl;
  cout << "This many $5 bills: " << five << endl;
  cout << "This many $2 bills: " << two << endl;
  cout << "This many $1 bills: " << one << endl;
}