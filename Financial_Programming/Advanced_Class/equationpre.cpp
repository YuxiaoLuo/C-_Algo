/* Yuxiao Luo
 * Equation Pre CPP file: define constructor and function in class
 * Apr 2016
 */
#include"equation.h"
#include<iostream>
using namespace std;

Equation::Equation(){ // default constructor 
   op1 = 0;
   op = ' ';
   op2 = 0;
}

Equation::Equation(int op1 ,char op, int op2){ // default constructor
   Equation::op1 = op1;
   Equation::op2 = op2;
   if( op != '+' && op != '-' && op != '*' && op != '/'){
      cout << "Invalid operator for default constructor " << endl;
      do{
         cout << "Please enter one operator(only +, -, *, and /): ";
	 cin >> op; 
      }while( op != '+' && op != '-' && op != '*' && op != '/');
      Equation::op = op;
   }
   else{
      Equation::op = op;		 
   }
   if( op == '/' && op2 == 0){
      do{
         cout << "The denominator could not be 0, enter another denominator: ";
         cin >> op2;
         if( op2 != 0) 
            break;   
      }while(1);
      Equation::op2 = op2; 
   }
   calculate();
}
   
void Equation::input(){ // input method 
   cout << "Please enter two numbers: ";
   cin >> op1 >> op2;
   do{
   cout << "Please enter one operator: ";
   cin >> op; 
   }while( op != '+' && op != '-' && op != '*' && op != '/');
   if( op == '/' && op2 == 0){
      do{
         cout << "The denominator could not be 0, enter another denominator: ";
         cin >> op2;
         if( op2 != 0)
            break;
      }while(1);
   }  
}   
                            
void Equation::output(){ // output method 
   result = calculate();
   cout << op1 << op << op2 << "=" << result << endl;
} 

float Equation::calculate(){ // calculate method

   switch(op){
      case '+':
         result = op1 + op2;
         break;
      case '-':
         result = op1 - op2;
         break;
      case '*':
         result = op1 * op2;
         break;
      case '/':
         result = op1 / op2;
         break;
      default:
         cout << "The operator you entered is invalid" << endl;
         break;
   }      
   return(result);
}

bool Equation::equality(Equation e){ // equality method
   bool equal;
   if( e.op1 == op1 && e.op2 == op2 && e.op == op)
      equal = true;  
   else 
      equal = false;
   return(equal);
}

bool Equation::inequality(Equation e){ // ineuqality method
   bool inequal;
   if( e.op1 = op1 && e.op2 == op2 && e.op == op)
      inequal = false;
   else 
      inequal = true;
   return(inequal);
}

bool Equation::operator==(Equation eq){ // operator overloaded for equality of two equations
   return equality(eq);
} 

bool Equation::operator!=(Equation eq){ // operator overloaded for inequality of two equations
   return inequality(eq);
}

ostream & operator<< ( ostream &os, Equation &eq){ // operator overloaded for cout command on an equation
   eq.result = eq.calculate();
   os << eq.op1 << eq.op << eq.op2 << " ";
   return(os);
}

istream & operator>> (istream &is, Equation &eq){ // ooperator overloaded for cin command on an equation
   cout << "Please enter two numbers for the equation: ";
   is >> eq.op1 >> eq.op2;
   do{
      cout << "Please enter the operator: ";
      is >> eq.op;
   }while(eq.op != '+' && eq.op != '-' && eq.op != '*' && eq.op != '/' );
   if( eq.op == '/' && eq.op2 == 0){
      do{
         cout << "The denominator could not be 0, enter another denominator: ";
         is >> eq.op2;
         if( eq.op2 != 0)
            break;
      }while(1);
   }
   return(is);
}

bool Equation::okay(){ // method for judging the correct equation 
   bool ok;
   if(op == '/' && op2 == 0)
      ok = false;
   else
      ok = true;
   return(ok);
}

int Equation::opNum(){ // method for transferring the operator to number
   int opNum;
   if( op == '+')
      opNum = 1;
   if( op == '-')
      opNum = 2;
   if( op == '*')
      opNum = 3;
   if( op == '/')
      opNum = 4;
   return(opNum);
}
