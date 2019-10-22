/* 
MadLib.c
By Zach Weber
Last Edited 9/8/19
Desc: First proper code written in C, user inputs words to fill out a story.
gcc -Wall -Wextra -ansi -pedantic MadLib.c -o MadLib
 */
 
  #define MAXLENGTH 64
  #include <stdio.h>
  #include <string.h>
 
  int main(void)
  {
	  /* created storage for all the words in the story */
      char adjective1[MAXLENGTH];
      char adjective2[MAXLENGTH];
      char typeOfBird[MAXLENGTH];
      char roomInAHouse[MAXLENGTH];
      char verb1[MAXLENGTH];
      char verb2[MAXLENGTH];
      char relative[MAXLENGTH];
      char noun1[MAXLENGTH];
      char liquid[MAXLENGTH];
      char verb3[MAXLENGTH];
	  char bodyPart[MAXLENGTH];
	  char noun2[MAXLENGTH];
	  char verb4[MAXLENGTH];
	  char noun3[MAXLENGTH];
      
	  /* asks user for words to enter into the variables to fill the story */
      printf("Enter an adjective: ");
      fgets(adjective1, MAXLENGTH, stdin);
	  adjective1[strlen(adjective1)-1] = 0;
	  
      printf("Enter an adjective: ");
      fgets(adjective2, MAXLENGTH, stdin);
	  adjective2[strlen(adjective2)-1] = 0;
	  
      printf("Enter a type of bird: ");
      fgets(typeOfBird, MAXLENGTH, stdin);
	  typeOfBird[strlen(typeOfBird)-1] = 0;
	  
      printf("Enter a room in a house: ");
      fgets(roomInAHouse, MAXLENGTH, stdin);
	  roomInAHouse[strlen(roomInAHouse)-1] = 0;
	  
	  printf("Enter a verb (past tense): ");
      fgets(verb1, MAXLENGTH, stdin);
	  verb1[strlen(verb1)-1] = 0;
	  
	  printf("Enter a verb: ");
      fgets(verb2, MAXLENGTH, stdin);
	  verb2[strlen(verb2)-1] = 0;
	  
	  printf("Enter a relative's name: ");
      fgets(relative, MAXLENGTH, stdin);
	  relative[strlen(relative)-1] = 0;
	  
	  printf("Enter a noun: ");
      fgets(noun1, MAXLENGTH, stdin);
	  noun1[strlen(noun1)-1] = 0;
	  
	  printf("Enter a type of liquid: ");
      fgets(liquid, MAXLENGTH, stdin);
	  liquid[strlen(liquid)-1] = 0;
	  
	  printf("Enter a verb ending in -ing: ");
      fgets(verb3, MAXLENGTH, stdin);
	  verb3[strlen(verb3)-1] = 0;
	  
	  printf("Enter a part of the body (plural): ");
      fgets(bodyPart, MAXLENGTH, stdin);
	  bodyPart[strlen(bodyPart)-1] = 0;
	  
	  printf("Enter a plural noun: ");
      fgets(noun2, MAXLENGTH, stdin);
	  noun2[strlen(noun2)-1] = 0;
	  
	  printf("Enter a verb ending in -ing: ");
      fgets(verb4, MAXLENGTH, stdin);
	  verb4[strlen(verb4)-1] = 0;
	  
	  printf("Enter a noun: ");
      fgets(noun3, MAXLENGTH, stdin);
	  noun3[strlen(noun3)-1] = 0;
      
	  /* outputs the final story with user inputs */
      printf("\nIt was a %s, cold November day.\n",adjective1);
      printf("I woke up to the %s smell of %s\n",adjective2,typeOfBird);
      printf("roasting in the %s downstairs.\n",roomInAHouse);
      printf("I %s down the stairs to see if I\n",verb1);
      printf("could help %s the dinner. My mom said,\n",verb2);
      printf("\"See if %s needs a fresh %s.\" So I\n",relative,noun1);
      printf("carried a tray of glasses full of %s\n",liquid);
      printf("into the %s room. When I got there, I\n",verb3);
	  printf("couldn't believe my %s! There were\n",bodyPart);
	  printf("%s %s on the %s!\n",noun2,verb4,noun3);
      
	  /* I'm sorry */
	  printf("\nI STOLE THIS MAD LIB OFF THE INTERNET IM SORRY :(");
	  
	  /* Prompting the user to end the script manually */
	  printf("\n\nPress enter key to exit... ");
	  getchar();
	  
      return 0;
  }