/* Yuxiao Luo
 * game header file 
 * May 2016
 */
#ifndef game_h
#define game_h

#include"level.h"
#include<iostream>

const int levelTop = 4;

class Game{

   public:
      Game();
      Game( const int min[], const int max[]); // default constructor
      void play(); // play the game
      int menu(); // menu function 
      void userInput( int a); // compare the input and result

   private:
      Level gameList[levelTop]; // level array
      bool end; // logical variable for ending the game
      int current; // number of current level 
};

#endif
