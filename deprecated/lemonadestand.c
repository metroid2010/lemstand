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
-- Licensed under GNU's GLP
--
-- NOTE: Linux version
--
---------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>



/*--------------------------------------------------------------------*/
/*----------------------------
--  Function to clear the
--  screen
------------------------------*/
int clearScreen()
{  const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12); }

/*--------------------------------------------------------------------*/

char whrstring[10];
char dest[50];
int whr; // the active weather variable
char sunnystring[20] = "sunny" ;
char hotstring[20] = "hot" ;
char stormystring[20] = "stormy" ;
char cloudystring[20] = "cloudy" ;


int diff, cstg;
/*----------------------------------------
--
--  diff: difficulty
--      1- Easy
--      2-Medium
--      3-Hard
--  cstg: cost per glass made
--
------------------------------------------*/
int storm, hot, sunny, cloudy;
/*----------------------------
--  Functions for the difficulty
--  They set the percentages for
--  the weather
------------------------------*/
int setdiffeasy()
{
    storm=5;
    hot=20+storm;
    sunny=60+hot;
    cloudy=15+sunny;
    cstg=3; // 3 cents per glass
    diff=1;
}
int setdiffhard()
{
    storm=30;
    hot=10+storm;
    sunny=20+hot;
    cloudy=40+sunny;
    cstg=7; // 7 cents per glass
    diff=3;
}
int setdiffmedium()
{
    storm=10;
    hot=20+storm;
    sunny=50+hot;
    cloudy=20+sunny;
    cstg=5; // 5 cents per glass
    diff=2;
}



/*--------------------------------------------------------------------*/

int feedrdm()
{
    srand(time(NULL)); //stackoverflow folks say this is needed for the random function
}



/*--------------------------------------------------------------------
--
--  THE PROGRAM STARTS HERE
--
----------------------------------------------------------------------*/



int mainmenu ()
{

    int slct1; //main menu selection

    clearScreen();
    printf("\n\t   ---Welcome to LEMONADE STAND--- ");
    printf("\n\tA C version of the original game from the Apple II.");
    printf("\n\tProgrammed by R\n");
    printf("\n\t1- Start a new game\n\t2- HELP and how to play\n\t3- Options\n\t");
    scanf("%d",&slct1); //menu entry selection


/*-------------------------------------------------------------------------
--
--      Now, for the menu entries, with the
--  three entries: options, help, and start game.
--
--      Using int variable slct1 for the switch statement...
--
--
---------------------------------------------------------------------------*/
int opts1; // switch variable for options

    switch(slct1)
    {
/*--------------------------------------*/
        case 2: //HELP SCREEN
            clearScreen();
            printf("\n\t   ---HELP SCREEN---\n\t WIP");
            printf("\n\t This is the WIP help screen of the game LEMONADE STAND,");
            printf("\n\tdesigned by Apple sometime in the late 70s, rewritten as a C game");
            printf("\n\n\n\tPress ENTER to get back to main menu");
            getchar();
            getchar();
            mainmenu();
            break;

/*--------------------------------------*/

        case 1: //GAME START

            return 0;
            break;
/*--------------------------------------*/
        case 3: //OPTIONS SCREEN

            clearScreen();
            printf("\n\t   ---OPTIONS---");
            printf("\n\tRemember this is still a preliminary version!");
            printf("\n\t");
            printf("\n\tDifficulty is now set to ");
            //switch function to read value 'diff' and printing difficulty
            switch (diff)
            {
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


            printf("\n\t");
            printf("\n\tHere you can change level of difficulty:");
            printf("\n\t  1- Easy");
            printf("\n\t  2- Medium (default)");
            printf("\n\t  3- Hard");
            printf("\n");
            printf("\n\t  4- Go back to main menu");
            printf("\n\t Select: ");
            scanf("%d",&opts1);

            //the difficulty is set by calling the functions stated back at the start of the program
            switch (opts1)
            {
                case 1:

                setdiffeasy();
                printf("\n\n\tThe difficulty was set to Easy\n");
                break;

                case 2:

                setdiffmedium();
                printf("\n\n\tThe difficulty was set to Medium\n");
                break;

                case 3:

                setdiffhard();
                printf("\n\n\tThe difficulty was set to Hard\n");
                break;

                case 4:

                printf("\n\n\tPress Enter to go back to Main Menu...\n");
                getchar();
                getchar();
                mainmenu();
                break;

                default:
                printf("\n\n\tOption '%d' not recognised, try again\n",opts1); //STILL NO FUNCTIONAL 'TRY AGAIN'!
                return (0);
                break;
                }


        printf("\nPress 'Enter' to continue: ... \n\n");
        getchar();
        getchar();
        mainmenu();
        break;

/*--------------------------------------*/

        default:
            printf("Please, make a valid selection\n");
            getchar();
            getchar();
            mainmenu();

    }


}




/*-----------------------------------------------------------------------------
--
--          Now starts the game
--
-------------------------------------------------------------------------------*/

int gamestart() //Just prints message and redirects to function weather
{
    clearScreen();
    printf("\n\t Press ENTER to start the game.\n\tEnjoy and have fun! ");
    getchar();
    getchar();
    return 0;
}

/*-------------------------------------------------
--
--  The weather system uses a random variable,
-- whrrand, which is set each time the function
-- weather is called, and it sets the time based on
-- the percentages set with the difficulty chosen
-- The different values for whr are storm (1), hot (2),
-- sunny (3), cloudy (4)
--
---------------------------------------------------*/
int weather()
{

    clearScreen();

    int whrrand;
    whrrand = ( rand() % 100 ); // the random weather variable
    printf("%d",whrrand); //DEBUG
    printf("\n%d %d %d %d\n",storm,hot,sunny,cloudy); //DEBUG
    if ( whrrand <= storm )
    {
        whr = 1;
    }
    else if ( whrrand <= hot )
    {
        whr = 2;
    }
    else if ( whrrand <= sunny )
    {
        whr = 3;
    }
    else if ( whrrand <= cloudy )
    {
        whr = 4;
    }

    printf("%d",whr); //DEBUG

    //printing the weather set
    printf("\n\n\tThe forecast for today is...");
    if ( whr == 1 )
    {
        printf("\n\n\tBeware! A storm is coming!");
        printf("\n\tHold your fedora tight!");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
    }
    else if ( whr == 2 )
    {
        printf("\n\n\tToday will be such a hot day, your teeth will");
        printf("\n\tprobably melt. You should go get a cold drink!");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
    }
    else if ( whr == 3 )
    {
        printf("\n\n\tSeems like the sun is shining today. It is neither");
        printf("\n\ttoo hot nor too cold. Perfect time to play with your kite!");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");

    }
    else if ( whr == 4 )
    {
        printf("\n\n\tClouds are gathering up high. Maybe it will rain soon?");
        printf("\n\tGo get your yellow umbrella. You know, just in case.");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
        printf("");
    }
    printf("\n\n\n\tPress Enter to continue... ");
    getchar();


}
int assignwhr()
{
    if ( whr == 1 )
    {
        memset(dest, '\0', sizeof(dest));
        strcpy(whrstring, "stormy");
        strcpy(dest,whrstring);
    }
    else if ( whr == 2 )
    {
      memset(dest, '\0', sizeof(dest));
        strcpy(whrstring, "hot");
        strcpy(dest,whrstring);

    }
    else if ( whr == 3 )
    {
    memset(dest, '\0', sizeof(dest));
        strcpy(whrstring, "sunny");
        strcpy(dest,whrstring);

    }
    else if ( whr == 4 )
    {
  memset(dest, '\0', sizeof(dest));
        strcpy(whrstring, "cloudy");
        strcpy(dest,whrstring);
    }
    printf("%s",whrstring);
}

    //declaring variables for gameplay
    int numg, nums, prcg, totalp, totals, slls;
    totals=0;
    /*----------------------------------------
    --
    --   numg: # glasses made for the batch
    --   nums: # signals used that day
    --   prcg: # price set by glass that day
    --
    ------------------------------------------*/

int selectscreen()
{
    clearScreen();
    printf("\n\n\t  Manage your stand for today");
    printf("\n\t");
    printf("\n\tRemember the cost per glass is %d, the cost per signal %d and it is %s", cstg, 15, whrstring);
    printf("\n\t");
    printf("\n\t");
    printf("\n\tHow many signals will you use now? ");
    scanf("%d", &nums);

    printf("\n\tHow many glasses of lemonade will you make? ");
    scanf("%d", &numg);

    printf("\n\tHow much cents per glass will you ask? ");
    scanf("%d", &prcg);
    printf("\n\t");
    printf("\n\tAre these values right? (Y/N)");

    char slct2;
    scanf("%c",slct2);
    //slct2 = getchar();

    switch (slct2)
    {
        case 'A' ://|| 'y' ):
        printf("OK");
        break;

        case 'N' ://|| 'n' ):
        printf("\n\tPress ENTER to enter values again");
        getchar();
        getchar();
        selectscreen();
        break;
    }
    printf("\n\t");
    printf("\n\t");
    getchar();
    return;
}

int resultscreen()
{
    clearScreen();
    printf("\n\t");
    printf("\n\tThe sells for today were...");

    /*---------------------------------
    --
    --  Equations to compute score
    --
    -----------------------------------*/

    slls =  numg ;
    totalp = ((slls*prcg)-((numg*cstg)+(nums*15)));
    totals = totals + totalp ;

    printf("\n\t");
    printf("\n\t");
    printf("\n\tYou sold %d glasses.",slls);
    printf("\n\tYou won %d today",totalp);
    printf("\n\tYour numbers were: %d %d %d %d %d",slls,prcg,numg,cstg,nums);
    printf("\n\tYour total score is %d",totals);
    printf("\n\tIt was %s",whrstring);

    printf("\n\tGood look next time!");

    printf("\n\tPress ENTER to go to next day ");
    getchar();
    return;
}


int main() //this is called just when the program starts
{
    setdiffmedium(); //default option must be set!!!
    feedrdm(); //feeds the random stuff
    mainmenu();
    gamestart();
    for(;;)
    {
    weather(); //weather screen
    assignwhr();
    selectscreen(); // gameplay screen
    resultscreen();
    }
}

