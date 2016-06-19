/* Yuxiao Luo
 * yluo52@fordham.edu / rollrainshell@gmail.com
 * game CPP file based on Game class header file
 * May 2016
 */
#include<iostream>
#include<memory.h> // header defines general utilities to manage dynamic memory
#include"game.h"
using namespace std;

Game::Game(){}; // default constructor 

Game::Game( const int min[], const int max[]){ // default constructor with input
   end = false;
   current = 0;
   for( int i = 0; i < levelTop; i ++){
      gameList[i] = Level( i+1, min[i], max[i]);
   }
}

int Game::menu(){ // method of menu
   int choose; // declare variable to choose
   cout << "1.Continue at the current level." << endl;

   if( current < levelTop -1)
   cout << "2.Go to the next level." << endl;

   cout << "3.Display summary statistics for the current level." << endl;
   cout << "4.Quit" << endl;   
   cout << "Please enter the number of choice: ";
   cin >> choose;
   cout << "\n";
   while( choose < 1 || choose > 4 || (current == levelTop -1 && choose == 2)){
      cout << "The number of choice could only be 1, 2, 3 or 4. Please enter one: ";
      cin >> choose;
   }
   return(choose);
}

void Game::userInput( int a){ // method for compare user's input
   switch(a){
      case 1:
   	 break;
      case 2:
         current ++;
         break;
      case 3: 
         gameList[current].statistics();
         userInput(menu());
         break;
      case 4:
         end = true;
         break;
   }
}

void Game::play(){
   int choose;
   do{
      gameList[current].play();
      choose = menu();
      userInput(choose);	
   }while(!end);
   cout << "Let's take a look at the statistics." << endl;
   for( int i =0; i <= current; i++){
      cout << "Level " << i+1 << " --> " << endl;
      gameList[i].statistics();
   }
   cout << "You are awesome!" << endl;
   cout << "This is the end of the game. See you next time. :)" << endl;
}
