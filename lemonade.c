/*------------------------------------------------------------------
--
--      LEMONADE STAND
--
--   Rip off of the famous Apple II game.
--   Programmed in C by R
--
--  Started by 8, feb, 2016
--
--
-- DISCLAIMER: not to be distributed comercially.
-- Only for educational purposes.
-- 
-- NOTE: Linux version
--
---------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lemonade.h"

void clearScreen();
int mainMenu(int diff);
int optionsScreen(int diff);
int weather(int diff);
int helpScreen(int x);

int main()
{ 
  FILE *fp; 
  int whr; //weather
  int diff=2; //variable for difficulty initialized in medium
  int slct1; //main menu selection
  int x,y=0,i=1; //loops
  int totals=50; //total score
  char name[30];
  char c; //gameplay selection loop
  
  
    clearScreen();
    printf("\n\t   ---Welcome to LEMONADE STAND--- ");
    printf("\n\tA C version of the original game from the Apple II.");
    printf("\n\tProgrammed by R");
    printf("\n");
    printf("\n\tPlease, enter your name: ");
    scanf(" %[^\n]s", name);
    while( strlen(name) == 30) {
      printf("\tSorry, the name is too long. Try again...");
      printf("\n\tEnter your name: ");
      scanf(" %30[^\n]", name);
    }
    
    fp=fopen("scores.txt","a");
    
    int slct; //main menu selection
    
    do {
    printf("\n\t1- Start a new game");
    printf("\n\t2- HELP and how to play");
    printf("\n\t3- Options");
    do{
      printf("\n\tEnter: ");
      scanf(" %i",&slct); //menu entry selection
      switch(slct) {
          case 1:                    //GAME START
            x=0; 
	    break;
          case 2:                    //HELP SCREEN
            helpScreen(x);
    	    x=1;
	    clearScreen();
            break;
          case 3:                    //OPTIONS SCREEN
            diff=optionsScreen(diff);
	    x=1;
	    clearScreen();
            break;
	  default:
	    printf("\tOption not recognised");
	    x=2;
	    break;
       }
      }while(x==2);
    } while(x==1);
    
    clearScreen();
    printf("\n\n\t Press ENTER to start the game.\n\tEnjoy and have fun!");
    getchar();
    getchar();
    
    do{
      clearScreen();
      printf("\n\tDay %i", i);
      printf("\n\tMoney: %ic", totals);
      getchar();
      
      whr = weather(diff); //weather screen
      totals += gameplay(diff, whr);
     
      clearScreen();
      printf("\tYour total money is %i", totals);
      do {
        printf("\n\tDo you want to continue? (Y/N) ");
        scanf(" %c", &c);
        switch(c) {
	  case 'y':
	  case 'Y':
	    y=1;
	    break;
	  case 'n':
	  case 'N':
	    y=0;
	    break;
	  default:
	    printf("\tOption not recognised. Try again...");
	    y=2;
	    break;
	}
      } while (y==2);
      i+=1;
    }while(y==1);
    
    clearScreen();
    printf("\n\tYour total earnings were %i", totals);
    printf("\n\tIt will be saved to scores.txt");
    
    fprintf(fp, "\n%s --- %i", name, totals);
    fclose(fp);
    
    printf("\n\tThank you for playing!");
    printf("\n\n\n\tPress Enter to exit...\n\n");
    getchar();
    getchar();
    
    return;
}































