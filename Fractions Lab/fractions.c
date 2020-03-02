/*****



gcc -Wall -Wextra -ansi -pedantic -O -o fractions main.c fractions.c
*****/

#include "fractions.h" /* FRACTION stuff */

int GCD(int a, int b)
{
	int i;
	int gcd = 0;
	
	if (a <= 0)
		return b;
	if (b <= 0)
		return a;
	
	else
	{
		for(i = 1; i <= a && i <= b; ++i)
		{
			if(a % i == 0 && b % i == 0)
				gcd = i;
		}
		return gcd;
	}
}

struct FRACTION add_fractions(const struct FRACTION *a, const struct FRACTION *b)
{
	struct FRACTION newA = *a;
	struct FRACTION newB = *b;
	struct FRACTION c;
	int gcd;
	
	/* get common denominator */
	int denominator = a->denominator * b->denominator;
	/* multiply numerators with opposite denominators */
	newA.numerator *= newB.denominator;
	newB.numerator *= newA.denominator;
	
	/* add two numerators and put everything in the c fraction */
	c.numerator = newA.numerator + newB.numerator;
	c.denominator = denominator;
	/*  */
	gcd = GCD(c.numerator, c.denominator);
	/*  */
	c.numerator /= gcd;
	c.denominator /= gcd;
	
	return c;
}

struct FRACTION subtract_fractions(const struct FRACTION *a, const struct FRACTION *b)
{
	struct FRACTION temp;
	temp.numerator = a->numerator;
	temp.denominator = b->denominator;
	return temp;
}

struct FRACTION multiply_fractions(const struct FRACTION *a, const struct FRACTION *b)
{
	struct FRACTION temp;
	temp.numerator = a->numerator;
	temp.denominator = b->denominator;
	return temp;
}

struct MIXED_FRACTION reduced_to_mixed(const struct FRACTION *fraction)
{
	struct MIXED_FRACTION temp;
	temp.whole_number = fraction->numerator;
	return temp;
}