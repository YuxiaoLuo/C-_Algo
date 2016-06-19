/* Date1.cpp
 * Yuxiao Luo
 * Date member-function definitions
 */

#include"Date.h"
#include<iostream>
using namespace std;

Date::Date(){}
   // any other constructor you want to write 
void Date:: input(){
   cout << "Enter month day and year: " << endl;
   cin >> month >> day >> years;
}
void Date::display(){
   cout << day << endl;
}
   
   // difference method
   // to comput the number of days between two dates 
int Date::difference( const Date &d){
   int numOfDays;
   numOfDays = day - d.day;
      return(numOfDays);
}
   // equality method
bool Date::equality( Date &d){
   bool valid;
   if( month == d.month && day == d.day && years == d.years )
      valid = true; 
   else 
      valid = false;
   return( valid );   
}
