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


/*   Clear Screen   */
void clearScreen()
{
   // printing character ANSI to clear screen
   const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
   write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
   return;
}


/*   Options screen   */
int optionsScreen(int diff)
{
  clearScreen();
  printf("\n\t   ---OPTIONS---");
  printf("\n");
  printf("\n\tDifficulty is now set to ");
  
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
  printf("\n\tHere you can change level of difficulty:");
  printf("\n\t  1- Easy");
  printf("\n\t  2- Medium (default)");
  printf("\n\t  3- Hard");
  printf("\n");
  printf("\n\t  4- Go back to main menu");
  printf("\n\t Select: ");
  scanf(" %d",&opts1);
		    
  while( opts1 > 4 && opts1 < 1 )
  {
    printf("\tOption '%d' not recognised, try again: ",opts1);
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
  
  printf("\n");
  printf("\n\tPress 'Enter' to continue... ");
  getchar();
  getchar();
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
    
    //printf("%i",whr); //DEBUG

    //printing the weather set
    printf("\n\n\tThe forecast for today is...");
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
        
    printf("\n\n\n\tPress Enter to continue... ");
    getchar();
    return whr;

}

/*  Help Screen   */
void helpScreen()
{
  clearScreen();
  printf("\n\t   ---HELP SCREEN---\n");
  printf("\n\t This is the help screen of the game LEMONADE STAND,");
  printf("\n\tdesigned by Apple sometime in the late 70s, rewritten as a terminal game");
  printf("\n\t               --//--            ");
  printf("\n\tThe main objective on this game is to earn as much money as possible.");
  printf("\n\tYou will do so by the means of an efficient management of your");
  printf("\n\tsummertime lemonade stand. Depending on the weather announced for the");
  printf("\n\tday, you must decide how many glasses of lemonade to make for the batch,");
  printf("\n\thow much you will ask for each glass, and how many signals you will use to");
  printf("\n\tadvertise your business.");
  printf("\n\tThe key to maintain a steady profit is to keep an eye on the competency's");
  printf("\n\tprices, as they will affect directly your sales. And do not forget that nobody");
  printf("\n\twants an ice cold drink on an ice cold day!");
  printf("\n\n\n\tPress ENTER to get back to main menu ");
  getchar();
  getchar();
  return;
}

/* Slls algorithm  */
int cslls(int numg, int prcg, int nums, int diff, int whr, int prcc) 
{
 
  srand(time(NULL));
  int slls=0, x, a;
  if (diff==1) {
    a=numg*0.4;
    x=( random() % a );
    
    slls += ( (prcc/prcg)*numg*0.4 );
    slls += x;
    slls += nums*numg*0.15;
    slls += (1/whr)*numg*0.2;
  }
  else if(diff==2) {
    a=numg*0.5;
    x=( random() % a );
    
    slls += ( (prcc/prcg)*numg*0.3 );
    slls += x;
    slls += nums*numg*0.1;
    slls += (1/whr)*numg*0.15;
  }
  else if(diff==3) {
    a=numg*0.6;
    x=( random() % a );
    
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
    x=( random() % a );
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
    int numg, nums, prcg, cstg, totalp, slls, csts, prcc, prcs, x, y;
    
    switch(diff) {
      case 1:
	cstg=5;
	prcs=30;
	prcc=20;
	break;
      case 2:
	cstg=7;
	prcs=40;
	prcc=15;
	break;
      case 3:
	cstg=9;
	prcs=50;
	prcc=12;
	break;
    }
    
    clearScreen();
    printf("\n\n\t  Manage your stand for today!");
    printf("\n\t");
    printf("\n\tRemember:");
    printf("\n\tCost per glass: %ic", cstg);
    printf("\n\tCost per signal: %ic",csts);
    printf("\n\tAverage competence price per glass: %ic", prcc);
    printf("\n\tWeather: ");
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
    printf("\n\n");
    
    do {
      x=0;
      printf("\n\tHow many signals will you use? ");
      scanf("%d", &nums);

      printf("\n\tHow many glasses of lemonade will you make? ");
      scanf("%d", &numg);

      printf("\n\tHow much cents per glass will you ask? ");
      scanf("%d", &prcg);
      printf("\n");
      printf("\n\tAre these values right? (Y/N)");
      
      char slct;
      
      do {
        scanf(" %c", &slct);
        y=1;
        switch (slct)
        {
            case 'Y':
            case 'y':
              printf("\tOK ");
	      x=0;
	      y=1;
              break;

            case 'N':
	    case 'n':
              printf("\tPress ENTER to set values again ");
              x=1;
	      y=1;
	      getchar();
              break;
	    default:
	      printf("\tOption not recognised. Try again... ");
	      y=0;
	      break;
        }
      }while(y==0);
      }while(x==1);
    
    
      clearScreen();
      printf("\n");
      printf("\n\tThe sells for today were...");

      //computing sells
    
      slls = cslls(numg, prcg, nums, diff, whr, prcc);
    
      totalp = ( (slls*prcg) - ((numg*cstg) + (nums*csts)) );

      printf("\n");
      printf("\n");
      printf("\n\tYou sold %i glasses.",slls);
      
      if(totalp < 0) {
	printf("\n\tYou lost %i today",totalp);
      }
      else {
        printf("\n\tYou won %i today",totalp);
      }
      getchar();
      getchar();
      return totalp;
    
}
