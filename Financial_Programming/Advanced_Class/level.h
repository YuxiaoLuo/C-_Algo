/********************************
 * Yuxiao Luo
 * yluo52@fordham.edu / rollrainshell@gmail.com
 * Level games class header file
 * May 2016
 ********************************/
#ifndef level_h
#define level_h

#include<vector> // define vector container class
#include"equation.h"
#include<iostream>
using namespace std;

const int goal = 2; // number of right answers to display menu for each row

class Level{
   private:
      typedef vector<Equation> Earray; // define the array class
      Earray eqs;
      int curlevel; // current level
      int lower, upper; // lower bound and upper bound
      double correct[4]; // correct answers for operators in equation list
      double total[4]; // total number of operators in equation list
      // generate equation & search for equal equations in equation list
      Equation geEQ();
      bool search( const Equation&);

   public:
      Level();      
      Level(int level, int lowerbound, int upperbound);
      
      void play(); // play the game
      void statistics(); // statistics summary
};

#endif
