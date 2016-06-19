/* Yuxiao Luo
 * Date header file
 * May 3rd, 2016 changed
 */
#ifndef Date.h
#define Date.h

#include<iostream>
using namespace std;

class Date{
   public:
      Date();
      void input();

      void display();
    
      int difference( const Date &d);

      bool equality( Date &d);   

   private:
      int month, day, years;

};

#endif
