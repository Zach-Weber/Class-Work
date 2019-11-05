/* 
ZombieDice.c
By: Zach Weber
Last Edited: 11/4/2019
Brief: A dice game meant for up to 8 people, player with the most after one gets 13 or more brains wins
gcc -Wall -Wextra -ansi -pedantic -O -o ZombieDice ZombieDice.c
 */

/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>


int main(void)
{
	int bagCurrAmount = 13;
	char bag[13] = {'R','R','R','Y','Y','Y','Y','G','G','G','G','G','G'};
	char hand[3] = {0};
	
	/* Go through the hand */
	{
		int handIndex;
		for(handIndex = 0; handIndex < 3; ++handIndex)
		{
			/* Draw from bag */
			/* Only fill hand slots that are empty */
			if (hand[handIndex] == 0)
			{
				/* Pick a rand num */
				int bagIndex = rand() % badCurrAmount;
				/* Take a die from the bag */
				hand[handIndex] = bag[bagIndex];
				/* We took a die, so subtrant how many we have left */
				bagCurrAmount -= 1;
				/* Swap the now in use die to the back of the bag array */
				{
					char temp = bag[bagIndex];
					bag[bagIndex] = bag[bagCurrAmount];
					bag[bagCurrAmount] = temp;
				}
			}
		}
	} /* End fill the hand */
	
	/* Roll dice based on colors in hand */
	{
		int roll = (rand() % 6) + 1;
		/*  */
		switch (hand[0])
		{
			case 'G':
				{
				
				}
				break;
			case 'Y':
				{
					
				}
				break;
			case 'R':
				{
					
				}
				break;
		}
	}
}

