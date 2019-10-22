/******************************************************************************
Filename: array.c
Author: Zach Weber
Date: 10/21/2019
Brief Description:

gcc -O -Wall -Wextra -ansi -pedantic main1.c array.c -o array1

******************************************************************************/

/*
	Name: reverse_array
	Given an array, reverse the order of the elements in the array. Do not create another array in the function.
*/
void reverse_array(int a[], int size)
{
	/* create a temp variable to store extra number */
	int temp;
	int i;
	/* k is the opposite value in the array to i */
	int k = size - 1;
	/* create a for loop to move numbers from first to last */
	for (i = 0; i < (size / 2); i++)
	{
		temp = a[i];
		a[i] = a[k];
		a[k] = temp;
		--k;
	}
	
} 

/*
	Name: add_arrays
	Given three arrays, add the elements of the first two arrays and put the sum in the third array.
*/
void add_arrays(const int a[], const int b[], int c[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		c[i] = a[i] + b[i];
	}
}

/*
	Name: scalar_multiply
	Given an array and a multiplier, multiply each element by the multiplier.
*/
void scalar_multiply(int a[], int size, int multiplier)
{
	if(a && size && multiplier)
		return;
	return;
}

/*
	Name: dot_product
	Given two arrays, determine the dot product (multiply each corresponding element and sum the products). Return the value.
*/
int dot_product(const int a[], const int b[], int size)
{
	if(a || b)
		return size;
	return size;
}

/*
	Name: cross_product
	Given three arrays, determine the cross product of the first two. The cross product is another array and will be placed into the third array. The size of all three arrays will always be 3.
*/
void cross_product(const int a[], const int b[], int c[])
{
	if(a || b || c)
		return;
	return;
}
