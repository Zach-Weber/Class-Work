/* 
Filename: YesNoGame.c
Name: Zach Weber
Date Last Edited: 16 Sep 2019
Brief Description: A game based in a diner where you must say yes or no to the requests from customers and staff
gcc -Wall -Wextra -Werror -ansi -pedantic -O YesNoGame.c -o game.exe
 */
 
 
 
 /*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

#define INTRO -1



int main(void)
{
	/* creating variables */
	char input;
	int eventID = -1;
	int maxEventID = 5;
	
	
	
	/* Gameplay Variables */
	int money = 10;
	int happy = 10;
	int people = 10; /* how many customers and staff */
	
	int eventMoneyLoss; /* Keeps track of how much money you need to loose to get to 1 money */
	
	
	/* set a seed using time */ 
	srand(time(0));
	
	
	
	do
	{
		/* Resets input */
		input = 'a';
		
		
		
		/* Dialogue before user import */
		switch(eventID)
		{
			case INTRO:
				printf("Assistant: Hello! You must be our new manager. Welcome our SPACE diner, 'The Rusty Spoon'!\n");
				printf("Your job is to manage the requests and complaints of the customers and staff\n");
				printf("all while maintaining your staff numbers, customer happiness, and money.\n");
				printf("Assistant: Do you think your up to the task?\n");
				break;
			case 1:
				printf("Head Chef: So I've been trying a few new things on my off time and I think we should add a dish called\n");
				printf("Coconut-Custard Meringue Pie to the menu, what do you say?\n");
				break;
			case 2:
				printf("Customer: Hey! I've been a long time customer here and I think its great, but what it really needs is\n");
				printf("some atmosphere. How about you get a jukebox to put in that corner over there?\n");
				break;
			case 3:
				printf("Janitor: Listen, I have found an infestation of rats in the pantry. This means we are going to have to\n");
				printf("scrap the whole contents, should I go ahead and call the pest control?\n");
				break;
			case 4:
				printf("Assistant: I got a call from the city, they are zoning more resturants right next us... but they want us to\n");
				printf("agree with it before going through with it. They are willing to pay us in compensation for it.\n");
				break;
			case 5:
				printf("Customer: Hi. I've just had the worst experience at your diner here. The food was cold and the waiter didn't\n");
				printf("do anything about it. Can you promise me that someone will pay for this?\n");
				break;
		}
		
		
		
		/* Get user input */
		while(input != 'n' && input != 'y'&& input != 'q')
		{
			printf("Enter 'y' for yes or 'n' for no ('q' to quit):\n");
			scanf(" %c", &input);
		}
		
		
		
		/* Text responces to user input */
		switch(eventID)
		{
			case INTRO:
				if(input == 'y')
				{
					printf("Assistant: Awesome! I will prep the kitchen and open up for the day.\n");
					
					printf("+10 Money, +10 Happiness, +10 People\n"); /*This is just for the user, don't add to resources here*/
				}
				else if(input == 'n')
				{
					printf("Assistant: Well thats unfortunate...\n");
					input = 'q';
				}
				break;
			case 1:
				if(input == 'y')
				{
					printf("Head Chef:  Thank you! You won't be disappointed.\n");
					money -= 4;
					happy += 2;
					printf("-4 Money, +2 Happiness\n");
				}
				else if(input == 'n')
				{
					printf("Head Chef:  Ah, ok. Well you're the boss.\n");
					happy -= 3;
					printf("-3 Happiness\n");
				}
				break;
			case 2:
				if(input == 'y')
				{
					printf("Customer: Sweat, the boys are gonna love that. I'll even invite some people in!\n");
					money -= 5;
					happy += 4;
					people += 3;
					printf("-5 Money, +4 Happiness, +3 People\n");
				}
				else if(input == 'n')
				{
					printf("Customer: Aw that sucks man... You're no fun.\n");
					people -= 1;
					printf("-1 People\n");
				}
				break;
			case 3:
				if(input == 'y')
				{
					printf("Janitor: Alright. I call them down, they should be down in the hour. I'm not sure if you'll like the bill on this one.\n");
					eventMoneyLoss = money - 1;
					happy -=2;
					money -= eventMoneyLoss;
					printf("-2 Happiness, -%i Money\n", eventMoneyLoss);
				}
				else if(input == 'n')
				{
					printf("Janitor: Are you serious?! I strongly advise against that...\n");
					printf("-%i Happiness, -%i People\n", happy, people);
					happy = 0;
					people = 0;
				}
				break;
			case 4:
				if(input == 'y')
				{
					printf("Assistant: Okay... I will call them back. Though I'm not sure the folks are going to like this.\n");
					money += 10;
					happy -= 5;
					people -= 5;
					printf("+10 Money, -5 Happiness, -5 People\n");
				}
				else if(input == 'n')
				{
					printf("Assistant: Alright, I resect that. Turn down the money for the people.\n");
				}
				break;
			case 5:
				if(input == 'y')
				{
					printf("Customer: Thank you. At least someone around here is reasonable...\n");
					people -= 1;
					happy +=1;
					printf("+1 Happiness, -1 People");
				}
				else if(input == 'n')
				{
					printf("Customer: Whatever. This place is a disaster.\n");
					people -= 2;
					happy -= 1;
					printf("-1 Happiness, -2 People");
				}
				break;
		}
		
		
		
		/* Tells the player how many resources they have */
		printf("YOU HAVE: Money: %i, Happiness: %i, People: %i\n", money, happy, people);
		
		
		
		/*reset event id with rand*/
		eventID = rand() % (maxEventID + 1);
		getchar();
		getchar();
		
	}while(input != 'q');
	
	printf("GAME OVER...\n\n\n\n\n\n\n\n");
	
	return 0;
}