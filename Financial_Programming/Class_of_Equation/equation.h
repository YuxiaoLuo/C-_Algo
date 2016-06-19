/* Yuxiao Luo
 * Equation Class -- Header File
 * Apr 2016
 */
#ifndef equation_h
#define equation_h

#include<iostream>
using namespace std;

class Equation{
	
   friend ostream& operator<< (ostream &, Equation &);
   friend istream& operator>> (istream &, Equation &);
   public:
      Equation(); //dafault constructor 
      Equation(int, char, int); // constructor to initialize the equation from the arguments passed 
      void input(); // a method to randomly generate the equation 
      void output(); // a method to display the equation 
      float calculate(); // a method to calculate the equation 
      bool compare( Equation e );
      bool operator==(Equation);

   private:
      int op1, op2;
      char op;
      float result; 
};

#endif
