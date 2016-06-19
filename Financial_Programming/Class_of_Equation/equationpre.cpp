/* Yuxiao Luo
 * Equation Pre CPP file: define constructor and function in class
 * Apr 2016
 */
#include"equation.h"
#include<iostream>
using namespace std;

Equation::Equation(){
   op1 = 8;
   op = '*';
   op2 = 2;
   calculate();
}

Equation::Equation(int op1 ,char op, int op2){
   Equation::op1 = op1;
   Equation::op2 = op2;
   Equation::op = op;
   calculate();
}
   
void Equation::input(){
   cout << "Please enter two numbers: ";
   cin >> op1 >> op2;
   do{
   cout << "Please enter one operator: ";
   cin >> op; 
   }while( op != '+' && op != '-' && op != '*' && op != '/');
}

void Equation::output(){
   result = calculate();
   cout << op1 << " " << op << " " << op2 << " " << "=" << " " << result << endl;
}

float Equation::calculate(){

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

bool Equation::compare(Equation e){
   bool equal;
   if( e.op1 == op1 && e.op2 == op2 && e.op == op)
      equal = true;  
   else 
      equal = false;
   return(equal);
}

bool Equation::operator==(Equation eq){
   return compare(eq);
}

ostream& operator<< ( ostream &os, Equation &eq){
   eq.result = eq.calculate();
   os << eq.op1 << eq.op << eq.op2 << "=" << eq.result << endl;
   return(os);
}

istream& operator>> (istream &is, Equation &eq){
   cout << "Please enter two numbers for the equation: ";
   cin >> eq.op1 >> eq.op2;
   do{
      cout << "Please enter the operator: ";
      is >> eq.op;
   }while(eq.op != '+' && eq.op != '-' && eq.op != '*' && eq.op != '/' );
   return(is);
}
