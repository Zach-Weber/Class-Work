/*
Pointers.c
By Zach Weber
Date 11.21.19
Desc. Practice with Pointer syntax and a couple uses
gcc -Wall -Wextra -ansi -pedantic -O Pointers.c -o Pointers.exe
*/

#include <stdio.h>

void ChangeIntegers(int j, int* pi)
{
	j =  9001;
	*pi = 9001;
	printf("j inside function is %i, *pi is %i\n", j, *pi);
}

/* Set up main function as normal */
int main(void)
{
	/* Make an integer and set it as well as a pointer to an integer and set it to point at the first integer. */
	int i = 10;
	int j;
	int* pi;
	int** ppi;
	int a[10] = {1,2,3,4,5};
	
	/* Make sure to make a comment about the &(address) operator!  It gets the address of the variable after it. */
	pi = &i;

	/* Show that you can make a pointer to a pointer to an int, but that you cannot use the & operator twice in a row. Also that you cannot get the address of a literal value. */
	ppi = &pi;
	
	/* Make another int variable and show how we can access through the pointer. */
	j = i;
	j = *pi;
	j = **ppi;

	/* Also show dereferencing the first integer is bad. */
	j = *(&i);

	/* Print out many values to show what is happening. */
	printf("i is now %i\n", i);
	printf("pi is now %p\n", (void*)pi);
	printf("&i is now %p\n", (void*)&i);
	printf("ppi is now %p\n", (void*)ppi);
	printf("&pi = %p\n", (void*)&pi);
	
	printf("j is now %i\n",j);
	
	/* Demonstrate using a pointer as a function parameter (passed by reference) and how it is different than simply passing the normal int (passing by value). */
	ChangeIntegers(j,&i);
	printf("j is %i after function, and i is now %i\n", j, i);
	
	/* Make an integer array and show how pointers can be used with the array to print it out in a loop (iterate through the array with an iterator). */
	pi = a;
	printf("Array a is:");
	while(*pi != 0)
	{
		printf(" %i @ %p", *pi, (void*)pi);
		pi++;
	}
	printf("\n");


	/* Print out values with the array, and the pointer, too to show how they are relative to each other. */

	
	
	
	return 0;
}
