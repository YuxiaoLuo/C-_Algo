/* Yuxiao Luo
 * euqation.cpp
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
   cout << "Please enter one number, one operator and the second number: " << endl;
   cin >> op1 >> op >> op2; 
}

void Equation::output(){
   cout << op1 << " " << op << " " << op2 << " " << "=" << " " << result << endl;
}

float Equation::calculate(){
   if(op == '+')
      result = op1 + op2;
   else if( op == '-')
      result = op1 - op2;
   else if( op == '*')
      result = op1 * op2;
   else if( op == '/')
      result = op1 / op2;
   else 
      cout << "The operator you entered is not valid." << endl;
   return(result);
}

main(){
   Equation eq;
   Equation eq2(7, '*', 3); 
   Equation eq3;
   eq.input();
   eq.calculate();
   eq.output();
   eq2.output();
   eq3.output();
}
