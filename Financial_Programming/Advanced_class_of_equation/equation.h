/* Yuxiao Luo
 * Equation Class -- Header File
 * Apr 2016
 */
#ifndef equation_h
#define equation_h

#include<iostream>
using namespace std;

class Equation{
	
   friend ostream & operator<< (ostream &, Equation &); // operator overloaded for coutcommand to be used on an equation
   friend istream & operator>> (istream &, Equation &); // operator overloaded for cin command to be used on an equation
   public:
      Equation(); //dafault constructor 
      Equation(int, char, int); // constructor to initialize the equation from the arguments passed 
      void input(); // a method to randomly generate the equation 
      void output(); // a method to display the equation 
      float calculate(); // a method to calculate the equation 
      bool equality( Equation e ); // a method for equality of  two equations
      bool inequality(Equation e); // a method for inequality of two equations   
      bool operator==(Equation); // operator overloaded for equality of two equations
      bool operator!=(Equation); // operator overloaded for inequality of two equations 
      bool okay(); // method to judge correct equation
      int opNum(); // method to transfer the operator to number
   private:
      // variables declaration
      int op1, op2;
      char op;
      float result; 
};

#endif
