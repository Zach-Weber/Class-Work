/* printf */
#include <stdio.h>
/* AddIntegers, SubtractIntegers */
#include "my_math.h"

int main (void)
{
	int first = 6;
	int second = -1;
	
	printf("%i + %i = %i\n", first, second, AddIntegers(first, second));
	
	printf("%i - %i = %i", second, first, SubtractIntegers(first, second));
	
	return 0;
}
