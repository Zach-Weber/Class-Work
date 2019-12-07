/********************
Ohms.c
Name: Zach Weber
Date: 11.22.19
brief: This program is meant to use funcitons to figure out different missing pieces of circuit data.
gcc -Wall -Wextra -ansi -pedantic -O -o ohm Ohms.c
*******************/

/* printf */
#include <stdio.h>
/* Number of resistors */
#define RESNUM 10

/*Function takes 3 pointers one of which is NULL, solves for the missing values and returns what it should be. Returns -1 if something was wrong.*/
double findMissingOhmValue(double* V, double* I, double* R);

/*takes an array of resistances for parallel resistors and a given size of the array and stores the total reistance into the double pointed at by Rtotal, 
can be used with as many resistances as needed in a row.*/
void findTotalResistanceParallel(double* Rtotal, double Resistor[], int size);

int main(void)
{
	/*5 volts, 2 amps*/
	double V = 5, I = 2, R;
	
	double Resistor[RESNUM];
	
	double* pV = &V;
	double* pI = &I;
	double* pR = 0;
	
	int i;
	
	R = findMissingOhmValue(pV, pI, pR);
	
	printf("Given a voltage of %.5f Volts, and a current of %.5f Amps, the total resistance would be %.5f Ohms\n", V, I, R);
	
	V = 12;
	R = 100;
	
	pV = &V;
	pI = 0;
	pR = &R;
	
	I = findMissingOhmValue(pV, pI, pR);
	
	printf("Given a voltage of %.5f Volts, and a total resistance of %.5f Ohms, the current would be %.5f Amps\n", V, R, I);
	
	I = 0.5;
	R = 14;
	
	pV = 0;
	pI = &I;
	pR = &R;
	
	V = findMissingOhmValue(pV, pI, pR);
	
	printf("Given a current of %.5f Amps, and a total resistance of %.5f Ohms, the voltage would be %.5f Volts\n", I, R, V);
	
	Resistor[0] = 300;
	Resistor[1] = 300;
	
	findTotalResistanceParallel(pR, Resistor, 2);
	
	printf("Total resistance is %f when R1, %f, and R2, %f, are hooked in parallel.\n", *pR, Resistor[0], Resistor[1]);
	
	for(i = 0; i < RESNUM; i++)
	{
		Resistor[i] = (i+1)*10;
	}
	/* run setup with first 2 then run through other parallel resistors */
	Resistor[0] = 10;
	Resistor[1] = 20;
	findTotalResistanceParallel(pR, Resistor, 2);
	/* findTotalResistanceParallel(); */
	printf("Total resistance is %f with resistor values 10, 20.\n", *pR);
	findTotalResistanceParallel(pR ,Resistor, RESNUM);
	
	printf("Total resistance is %f with resistor values 10, 20, 30, 40, 50, 60, 70, 80, 90, and 100.\n", *pR);
	
	
	/* Here try to program a test for the following circuit.
	We do not have a function for a series becausee it is just addition but you can build one if it feels worth it. 
	                    |----R2---|
	5V ------R1----------         --------Ground
	                    |---R3----|
	R1 = 25 Ohms, R2 = 50 Ohms, R3 = 100 Ohms
	
	Make sure to print out the results!
	*/
	Resistor[0] = 50;
	Resistor[1] = 100;
	findTotalResistanceParallel(pR, Resistor, 2);
	(*pR) += 25;
	printf("Resistance of last one is %f\n", *pR);
	
	V = 5;
	R = *pR;
	
	pV = &V;
	pI = 0;
	pR = &R;
	printf("Current (I) is: %f\n", findMissingOhmValue(pV, pI, pR));
	
	return 0;
}
/* Fill in this function! */
/*takes an array of resistances for parallel resistors and a given size of the array and stores the total reistance into the double pointed at by Rtotal, 
can be used with as many resistances as needed in a row.*/
void findTotalResistanceParallel(double* Rtotal, double Resistors[], int size)
{	
	int i;
	double tempTotal = 0;
	
	 /* Check for Bad Pointer */
	if (Rtotal == 0 || Resistors == 0)
	{
		printf("findTotalResistanceParallel Bad Pointer\n");
		return;
	}
	
	/* Find the total resistance for a parallel circuit */
	for (i = 0; i < size; ++i)
	{
		tempTotal += (1 / Resistors[i]);
	}
	
	/* *Rtotal = ?? */
	*Rtotal = (1 / tempTotal);
}
/* Fill in this function! */
/*Function takes 3 pointers one of which is NULL, solves for the missing values and returns what it should be. Returns -1 if something was wrong.*/
double findMissingOhmValue(double* V, double* I, double* R)
{
	/* Do a null check first */
	/* if (V == 0 || I == 0 || R == 0)
	{
		printf("findMissingOhmValue Bad Pointer\n");
		return -1.0;
	} */
	
	if (V == 0)
	{
		return (*I) * (*R);
	}
	
	else if (I == 0)
	{
		return (*V) / (*R);
	}
	
	else if (R == 0)
	{
		return (*V) / (*I);
	}
	
	return -1.0;
}
