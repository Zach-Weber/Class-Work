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

/* Prototypes */
void RefillHand(char hand[], char bag[], int* bagCurrAmount);
void RollDice(char hand[], int* potentialBrains, int* shots); 



int main(void)
{
	int bagCurrAmount = 13;
	char bag[13] = {'R','R','R','Y','Y','Y','Y','G','G','G','G','G','G'};
	char hand[3] = {0};
	
	/* Just defining these here for now, should be put into a turn */
	int potentialBrains = 0;
	int shots = 0;
	
	RefillHand(hand, bag, &bagCurrAmount);
	RollDice(hand, &potentialBrains, &shots);
	
	return 0;
}



/* Go through the hand and fill empty slots with dice from the bag */
void RefillHand(char hand[], char bag[], int* bagCurrAmount)
{
	int handIndex;
	for (handIndex = 0; handIndex < 3; ++handIndex)
	{
		/* Draw from bag */
		/* Only fill hand slots that are empty */
		if (hand[handIndex] == 0)
		{
			/* Pick a rand num */
			int bagIndex = rand() % *bagCurrAmount;
			/* Take a die from the bag */
			hand[handIndex] = bag[bagIndex];
			/* We took a die, so subtrant how many we have left */
			*bagCurrAmount -= 1;
			/* Swap the now in use die to the back of the bag array */
			{
				char temp = bag[bagIndex];
				bag[bagIndex] = bag[*bagCurrAmount];
				bag[*bagCurrAmount] = temp;
			}
		}
	}
	return;
} /* End fill the hand */



/* Roll dice based on colors in hand */
void RollDice(char hand[], int* potentialBrains, int* shots)
{
	int handIndex;
	for (handIndex = 0; handIndex < 3; ++handIndex)
	{
		int roll = (rand() % 6);
		
		switch (hand[handIndex])
		{
		case 'G':
			{
				switch (roll)
				{
					case 1:
					case 2:
					case 3:
						printf("[%%]"); 		/* Print a brain 						*/
						*potentialBrains += 1;	/* Account for the score				*/
						hand[handIndex] = 0; 	/* this slot in the hand is now open 	*/
						break;
					case 4:
					case 5:
						printf("[',]"); 		/* Print a runner 						*/
						break;
					case 6:
						printf("[**]");			/* Print a shot 						*/
						*shots += 1;				/* Account for rolling a shot			*/
						hand[handIndex] = 0;	/* This slot in the hand is open		*/
						break;
				}
			}
			break;
		case 'Y':
			{
				switch (roll)
				{
					case 1:
					case 2:
						printf("[%%]"); 		/* Print a brain 						*/
						*potentialBrains += 1;	/* Account for the score				*/
						hand[handIndex] = 0; 	/* this slot in the hand is now open 	*/
						break;
					case 3:
					case 4:
						printf("[',]"); 		/* Print a runner 						*/
						break;
					case 5:	
					case 6:
						printf("[**]");			/* Print a shot 						*/
						*shots += 1;				/* Account for rolling a shot			*/
						hand[handIndex] = 0;	/* This slot in the hand is open		*/
						break;
				}
			}
			break;
		case 'R':
			{
				switch (roll)
				{
					case 1:
						printf("[%%]"); 		/* Print a brain 						*/
						*potentialBrains += 1;	/* Account for the score				*/
						hand[handIndex] = 0; 	/* this slot in the hand is now open 	*/
						break;
					case 2:
					case 3:
					case 4:
						printf("[',]"); 		/* Print a runner 						*/
						break;
					case 5:
					case 6:
						printf("[**]");			/* Print a shot 						*/
						*shots += 1;				/* Account for rolling a shot			*/
						hand[handIndex] = 0;	/* This slot in the hand is open		*/
						break;
				}
			}
			break;
		}
	} 
	return;
}

