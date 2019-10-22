/* srand, rand */
#include <stdlib.h>
/* Printf */
#include <stdio.h>
/* time */
#include <time.h>


int rollDie(int sides)
{
	return rand() % sides + 1;
}


/* Entry point of our program */
int main (void)
{
	unsigned numSeconds = time(0);
	
	printf("%i\n", rollDie(6));
	srand(numSeconds);
	
	return 0;
}