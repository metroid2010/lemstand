/*------------------------------------------------------------------
--
--      LEMONADE STAND
--
--   Rip off of the famous Apple II game.
--   Programmed in C by R
--
--  Started by 8, feb, 2016
--  First alpha: 22 march, 2016
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
#include <windows.h>
#include "lemstand.h"

void clearScreen();
void anim(unsigned int i);
int mainMenu(int diff);
int helpScreen();
int optionsScreen(int diff);
int weather(int diff);
int gameplay(int diff, int whr);


int main() {
  FILE *fp;
  int whr; //weather
  int diff=2; //variable for difficulty initialized in medium
  int slct1=0; //main menu selection
  int x,y=0; //loops
  int i=1; //days
  int totals=50; //total score
  char name[30];
  char c; //gameplay selection loop


    clearScreen();
    printf("loading...");
    printf("\n\n\n");
    anim(17);
    clearScreen();
    printf("\n\t   ---Welcome to LEMONADE STAND---  ");
    printf("\n\tA C version of the original game from the Apple ][.");
    printf("\n\tProgrammed by R");
    printf("\n\n\t");
    Sleep(2000);
    printf("Please, enter your name: ");
    scanf(" %[^\n]s", name);
    while( strlen(name) > 20 ) {
      printf("\tSorry, the name is too long. Try again...");
      printf("\n\tEnter your name: ");
      scanf(" %20[^\n]", name);
    }

    fp=fopen("scores.txt","a");

    do{
      printf("\n\t");
      Sleep(2000);
      printf("1- Start a new game");
      printf("\n\t2- HELP and how to play");
      printf("\n\t3- Options");
      do{
        printf("\n\t");
        Sleep(1000);
        printf("Enter: ");
        scanf(" %i",&slct1); //menu entry selection
        switch(slct1) {
            case 1:                    //GAME START
              x=0;
	            break;
            case 2:                    //HELP SCREEN
              helpScreen();
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
    }while(x==1);

    clearScreen();
    printf("\n\n\tEnjoy and have fun!");
    printf("\n\n\t");
    Sleep(3000);
    system("PAUSE");

    do{
      clearScreen();
      printf("\n\t");
      Sleep(3000);
      printf("Day %i. ", i);
      switch((i-1)%7) {
        case 0:
          printf("Monday.");
          break;
        case 1:
          printf("Tuesday.");
          break;
        case 2:
          printf("Wednesday.");
          break;
        case 3:
          printf("Tuesday.");
          break;
        case 4:
          printf("Friday.");
          break;
        case 5 :
          printf("Saturday.");
          break;
        case 6:
          printf("Sunday!");
          break;
      }
      printf("\n\t");
      Sleep(2000);
      printf("Money: %ic\n\n\t", totals);
      Sleep(1000);
      system("PAUSE");

      whr = weather(diff); //weather screen
      totals += gameplay(diff, whr);

      clearScreen();
      printf("\n\tYour total money is %ic", totals);
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
	          Sleep(500);
	         printf("\tOption not recognised. Try again...");
	         y=2;
	         break;
        }
      } while (y==2);
      i+=1;
    }while(y==1);

    clearScreen();
    printf("\n\t");
    Sleep(1000);
    printf("Your total earnings were %ic", totals);
    printf("\n\t");
    Sleep(500);
    printf("It will be saved to scores.txt");

    fprintf(fp, "\n%s --- %i", name, totals);
    fclose(fp);

    printf("\n\t");
    Sleep(1000);
    printf("Thank you for playing!");
    printf("\n\n\n\t");
    Sleep(500);
    system("PAUSE");
    return 0;
}

