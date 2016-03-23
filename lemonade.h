/*-------------------------------------------------------------------------------------------------
--
--   LEMONADE STAND HEADER FILE
--
---------------------------------------------------------------------------------------------------*/

// Function to clear screen
#ifdef CLEAR_SCREEN
#define CLEAR_SCREEN
int clearScreen();
#endif

#ifdef MAIN_MENU
#define MAIN_MENU
int mainMenu(int diff);
#endif

#ifdef OPTIONS_SCREEN
#define OPTIONS_SCREEN
int optionsScreen(int diff);
#endif

#ifdef WEATHER
#define WEATHER
int weather(int diff);
#endif

#ifdef HELP_SCREEN
#define HELP_SCREEN
void helpScreen();
#endif

#ifdef CALCULATE_SLLS
#define CALCULATE_SLLS
int cslls(int numg, int prcg, int nums, int diff, int whr, int prcc);
#endif

#ifdef GAMEPLAY
#define GAMEPLAY
int gameplay(int diff, int whr);
#endif

