#include<iostream>
#include"Date.h"
using namespace std;

// main function code
int main(){
   Date d1,d2;
   d1.input();
   d2.input();
   int numDays = d1.difference(d2);
   
   cout << "The difference between ";
   d1.display(); 
   cout << "and";
   d2.display();
	   cout << "is: " <<  numDays << " days!" << endl;  
   if( d1.equality(d2) == true)
      cout << "Two dates are equal" << endl;
   if( d1.equality(d2) == false)
      cout << "Two dates are different" << endl;
}
