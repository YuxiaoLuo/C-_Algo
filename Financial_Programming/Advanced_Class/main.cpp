/* Yuxiao Luo
 * Main CPP file for equation, level, and game
 * May 2016
 */
#include<iostream>
#include"equation.h"
#include"game.h"
using namespace std;

main(){  
   const int lower[4] = {0,0, 10, -25}; 
   const int upper[4] = {10, 25, 25, 25};
   Game levelgame( lower, upper);
   levelgame.play();
}
