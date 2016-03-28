/*----------------------------------------------
 --
 --   Basic functions of the program
 --
 -----------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "resource.h"



/*   Clear Screen   */
void clearScreen()
{
   system("cls");
}

/*  Animation  */
void anim(unsigned int i) {
  char a[]={'-','/','|','\\'};
  int j;
  printf("\t\t\t\t");
  for (j=0;j<i;++j) {
   printf("%c\b",a[j%sizeof(a)]);
   fflush(stdout);
   usleep(125000);
  }
  return;
}

/*   Options screen   */
int optionsScreen(int diff)
{
  clearScreen();
  printf("\n\t   ---OPTIONS---");
  printf("\n");
  printf("\n\t");
  Sleep(1000);
  printf("Difficulty is now set to ");

  //switch statement to read value 'diff' and printing difficulty
  switch (diff) {
    case 1:
    printf("EASY");
    break;
    case 2:
    printf("MEDIUM (default)");
    break;
    case 3:
    printf("HARD");
    break;
  }

  int opts1;
  printf("\n\t");
  Sleep(2000);
  printf("Here you can change level of difficulty:");
  printf("\n\t  1- Easy");
  printf("\n\t  2- Medium (default)");
  printf("\n\t  3- Hard");
  printf("\n");
  printf("\n\t  4- Go back to main menu");
  printf("\n\n\t");
  Sleep(1000);
  printf("Select: ");
  scanf(" %d",&opts1);

  while( opts1 > 4 || opts1 < 1 )
  {
    printf("\t");
    Sleep(1000);
    printf("Option '%d' not recognised, try again: ",opts1);
    scanf(" %d",&opts1);
  }

  if( opts1 >= 1 && opts1 <= 3 )
  {
    printf("\n\tThe difficulty was set to ");
    switch (opts1)
    {
      case 1:
      diff=1;
      printf("Easy");
      break;

      case 2:
      diff=2;
      printf("Medium");
      break;

      case 3:
      diff=3;
      printf("Hard");
      break;
    }
  }

  if(opts1 == 4)
  {
    printf("\n\n\tThe difficulty was not changed");
  }

  printf("\n\t");
  Sleep(2000);
  system("PAUSE");
  return diff;
}

/* PERCENTAGES FOR WEATHERS
 *
 * diff=1
 * hot=30
 * sunny=50
 * cloudy=10
 * stormy=10
 *
 * diff=2
 * hot=20
 * sunny=50
 * cloudy=15
 * stormy=15
 *
 * diff=3
 * hot=10
 * sunny=40
 * cloudy=25
 * stormy=25
 *                             */
/* Weather */
int weather(int diff)
{
    srand(time(NULL)); //random feed
    //clearScreen();
    int whr; // the active weather variable
    int whrrand;
    whrrand = ( rand() % 100 ); // the random weather variable
    //printf(" %d",whrrand); //DEBUG

    int hot, sunny, cloudy, stormy;

    if(diff==1) {
      hot=30;
      sunny=50;
      cloudy=10;
      stormy=10;
    }
    else if(diff==2) {
      hot=20;
      sunny=50;
      cloudy=15;
      stormy=15;
    }
    else if(diff==3) {
      hot=10;
      sunny=40;
      cloudy=25;
      stormy=25;
    }

   if ( whrrand > 0 && whrrand <= hot )
   {   whr=1;  }
   else if( whrrand > hot && whrrand <= (sunny+hot) )
   {   whr=2;  }
   else if( whrrand > (sunny+hot) && whrrand <= (cloudy+sunny+hot) )
   {   whr=3;  }
   else if( whrrand > (cloudy+sunny+hot) && whrrand <= (cloudy+sunny+hot+stormy) )
   {   whr=4;  }

    //printing the weather set
    printf("\n\n\tThe forecast for today is...");
    printf("\n\n");
    anim(10);
    switch(whr) {
      case 1:
        printf("\n\n\tToday will be such a hot day, your teeth will");
        printf("\n\tprobably melt. You should go get a cold drink!");
	     break;
      case 2:
        printf("\n\n\tSeems like the sun is shining today. It is neither");
        printf("\n\ttoo hot nor too cold. Perfect time to play with your kite!");
	     break;
      case 3:
        printf("\n\n\tClouds are gathering up high. Maybe it will rain soon?");
        printf("\n\tGo get your yellow umbrella. You know, just in case.");
	     break;
      case 4:
        printf("\n\n\tBeware! A storm is coming!");
        printf("\n\tHold your fedora tight!");
	     break;
    }

    printf("\n\n\t");
    Sleep(3000);
    system("PAUSE");
    return whr;

}

/*  Help Screen   */
void helpScreen()
{
  clearScreen();
  printf("\n\t   ---HELP SCREEN---   \n");
  printf("\n\tThis is the help screen of the game LEMONADE STAND,");
  printf("\n\tdesigned by Apple sometime in the late 70s,");
  printf("\n\trewritten as a C terminal game.");
  printf("\n");
  Sleep(3000);
  printf("\n\tThe main objective on this game is to earn");
  printf("\n\tas much money as possible. You will do so by");
  printf("\n\tthe means of an efficient management of your");
  printf("\n\tsummertime lemonade stand. Your mum gave you 50c");
  printf("\n\tso you can start the business. Depending on the");
  printf("\n\tweather announced for the day, you must decide ");
  printf("\n\thow many glasses of lemonade to make for the batch,");
  printf("\n\thow much you will ask for each glass, and how many");
  printf("\n\tsignals you will use to advertise your business.");
  printf("\n\tThe key to maintain a steady profit is to keep an eye");
  printf("\n\ton competency's prices, as they will affect directly");
  printf("\n\tyour sales. And do not forget that nobody wants an");
  printf("\n\tice-cold drink on an ice cold day!");
  printf("\n\n\t");
  Sleep(5000);
  system("PAUSE");
  return;
}

/* Slls algorithm  */
int cslls(int numg, int prcg, int nums, int diff, int whr, int prcc)
{

  srand(time(NULL));
  int slls=0, x, a;
  if (diff==1) {
    a=numg*0.4;
    x=( rand() % a );

    slls += ( (prcc/prcg)*numg*0.4 );
    slls += x;
    slls += nums*numg*0.15;
    slls += (1/whr)*numg*0.2;
  }
  else if(diff==2) {
    a=numg*0.5;
    x=( rand() % a );

    slls += ( (prcc/prcg)*numg*0.3 );
    slls += x;
    slls += nums*numg*0.1;
    slls += (1/whr)*numg*0.15;
  }
  else if(diff==3) {
    a=numg*0.6;
    x=( rand() % a );

    slls += ( (prcc/prcg)*numg*0.2 );
    slls += x;
    slls += nums*numg*0.05;
    slls += (1/whr)*numg*0.1;
  }
  if (slls > numg) {
    slls = numg;
  }
  if (numg > 30) {
    a=(numg-30);
    x=( rand() % a );
    slls -= x*0.7;
  }

  return slls;
}

/* Gameplay  */
int gameplay(int diff, int whr)
{
    /*----------------------------------------
    --   numg: # glasses made for the batch
    --   nums: # signals used that day
    --   prcg: # price set by glass that day
    --   cstg: cost per glass
    --   totalp: partial (daily) score
    --   csts: price per signal
    --   prcc: price of competence
    ------------------------------------------*/
    int numg, nums, prcg, cstg, totalp, slls, csts, prcc, x, y;
    char slct;

    switch(diff) {
      case 1:
	     cstg=5;
	     csts=30;
	     prcc=20;
	     break;
      case 2:
	     cstg=7;
	     csts=40;
	     prcc=15;
	     break;
      case 3:
	     cstg=9;
	     csts=50;
	     prcc=12;
	     break;
    }

    clearScreen();
    printf("\n\n\t  Manage your stand for today!");
    printf("\n\n\t");
    Sleep(1000);
    printf("Remember:\n\t");
    Sleep(750);
    printf("Cost per glass: %ic\n\t", cstg);
    Sleep(750);
    printf("Cost per signal: %ic\n\t",csts);
    Sleep(750);
    printf("Average competence price per glass: %ic\n\t", prcc);
    Sleep(750);
    printf("Weather: ");
    Sleep(750);
    switch(whr) {
      case 1:
	     printf("hot");
	     break;
      case 2:
	     printf("sunny");
	     break;
      case 3:
        printf("cloudy");
	     break;
      case 4:
	     printf("stormy");
	     break;
    }

    printf("\n\n\t");
    Sleep(2000);
    do {
      x=0;
      printf("How many signals will you use? ");
      scanf(" %i", &nums);
      while(nums<0 || nums>1000){
         Sleep(500);
        printf("\tSorry, incorrect value entered (%i). Try again: ",nums);
        scanf(" %i", &nums);
      }

      printf("\n\t");
      Sleep(500);
      printf("How many glasses of lemonade will you make? ");
      scanf(" %i", &numg);
      while(numg<0 || numg>1000){
        Sleep(500);
        printf("\tSorry, incorrect value entered (%i). Try again: ", numg);
        scanf(" %i", &numg);
      }

      printf("\n\t");
      Sleep(500);
      printf("How many cents per glass will you ask? ");
      scanf(" %i", &prcg);
      while(prcg<0 || prcg>1000){
        Sleep(500);
        printf("\tSorry, incorrect value entered (%i). Try again: ", prcg);
        scanf(" %i", &prcg);
      }

      printf("\n\n\t");
      Sleep(2000);
      printf("Are these values right? (Y/N) ");

      do {
        scanf(" %c", &slct);
        y=1;
        switch (slct){
            case 'Y':
            case 'y':
             printf("\t");
             Sleep(750);
             printf("OK");
	          x=0;
	          y=1;
              break;

            case 'N':
	        case 'n':
              printf("\t");
              x=1;
	          y=1;
	          system("PAUSE");
              break;

	        default:
             printf("\t");
	          Sleep(500);
             printf("Option not recognised. Try again... ");
	          y=0;
	          break;
        }
      }while(y==0);
    }while(x==1);

    printf("\n\t");
    Sleep(750);
    system("PAUSE");

    clearScreen();
    printf("\n");
    printf("\n\t");
    Sleep(500);
    printf("The sells for today were...");
    printf("\n\n");
    anim(10);

    //computing sells
    slls = cslls(numg, prcg, nums, diff, whr, prcc);
    totalp = ( (slls*prcg) - ((numg*cstg) + (nums*csts)) );

    printf("\n");
    printf("\n");
    printf("\n\tYou sold %i glasses.\n\t",slls);
    Sleep(500);
    if(totalp < 0) {
	  printf("You lost %uc today...",totalp); }
    else {
      printf("You won %ic today!",totalp); }
    printf("\n\n\t");
    Sleep(1000);
    system("PAUSE");
    return totalp;
}
