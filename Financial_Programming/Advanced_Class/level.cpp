/* Yuxiao Luo
 * Level cpp file: levels of the game 
 * May 2016
 */
#include<iostream>
#include"level.h"
#include<ctime> // for time seed
#include<cstdlib> // for random number generator
using namespace std;

Level::Level(){} // default constructor 

Level::Level(int level, int lowerbound, int upperbound){ // default constructor with input
   srand(time(0));
   curlevel = level;
   lower = lowerbound;
   upper = upperbound;
   for( int i = 0; i < 4; i++){
      correct[i] = 0;
      total[i] = 0;
   }
}

Equation Level::geEQ(){ // method for randomly generating an equation
   const int shift = lower;
   const int scale = upper - lower;
   int op1, op2, opgenerate;
   char op;
   const char operators[] = {'+', '-', '*', '/'};
   op1 = shift + rand()%scale;
   op2 = shift + rand()%scale;
   opgenerate = rand()%4;
   op = operators[opgenerate];
   return(Equation(op1, op, op2));   
}

bool Level::search(const Equation &eq){ // method for searching the same equation
   bool judge = false;
   for(Earray::iterator i = eqs.begin(); i != eqs.end(); i ++){
      if(*i == eq){
         judge = true;
         break;
      }
   }     
   return(judge);
}   

void Level::play(){ // play the game
   int rowNum =0, answer; // declare number of correct answer & user's answer
   cout << "Welcome to LEVEL " << curlevel << ", enjoy the game!!" << endl;
   
   while(rowNum < goal){
      Equation newEQ;
      do{
         newEQ = geEQ(); 
      }while(search(newEQ)||!newEQ.okay());
      eqs.push_back(newEQ); // adds a new element at the end of the vector after its current last element
      total[newEQ.opNum()-1] += 1;
      
      // show equation and collect user's answers
      cout << "The randomly generated equation is "  << newEQ << endl; 
      cout << "Enter the answer of the equation: "; 
      cin >> answer;
      if( answer == (int)newEQ.calculate()){
         cout << "Bravo, it's the right answer!!" << endl;
         rowNum ++;
         correct[newEQ.opNum()-1] ++;
      }
      else{
         cout << "Your answer is incorrect." << endl;
         cout << "The answer is supposed to be " << (int)newEQ.calculate() << endl;
         rowNum = 0;
      }
      if( rowNum < goal -1)
         cout << "Okay, next equation~" << endl;
   } // end while
}

void Level::statistics(){ // method for compute and output the statistics
   double st;
   if( total[3] > 0){
      st = correct[3] / total[3] * 100;
      cout << st << "% of division equations are correct" << endl;
   }
   if( total[2] > 0){
      st = correct[2] / total[2] * 100;
      cout << st << "% of multiplication equations are correct" << endl; 
   }
   if( total[1] > 0){
      st = correct[1] / total[1] * 100;
      cout << st << "% of subtraction equations are correct" << endl;
   }
   if( total[0] > 0){
      st = correct[0] / total[0] * 100;
      cout << st << "% of addition equations are correct" << endl;
   }
}
