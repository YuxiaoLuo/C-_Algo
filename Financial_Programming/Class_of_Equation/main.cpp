/* Yuxiao Luo	
 * Equation cpp file
 * May 3rd, 2016
 */
#include"equation.h"
#include<iostream>

using namespace std;

main(){
   bool equal;
   Equation eq1, eq2(7, '+', 8);
 
   cin >> eq1;
	//eq1.input(); 

   cout << eq1;
   cout << eq2;
   //eq1.input();
   //eq2.output();
   
   //equal = eq1.compare( eq2); 
   if(eq1 == eq2)
      cout << "Equations are the same." << endl;
   else
      cout << "Equations are not the same" << endl; 
}
