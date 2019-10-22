/********************
FileName:
Name:
Date:
Brief Description:

note: -Werror treats all warnings as errors, use this when you want to make sure there are no warnings.
gcc -Wall -Wextra -Werror -ansi -pedantic -O main.c pi.c -o pi.exe
*********************/
/*sqrt*/
#include <math.h>

#define RADIUS 2.0
/* Calculates PI using a quarter circle */
double circle_pi(int rectangles)
{
	double total_area = 0;
	double rec_length;
	double mid_length;
	double rec_hight;
	double rec_area;
	
	int curr_rec;
	for(curr_rec = 0; curr_rec == rectangles; ++curr_rec)
	{
		
		
		rec_length = RADIUS / rectangles;
		mid_length = rec_length * 0.5;
		rec_hight = sqrt((RADIUS * RADIUS) - (mid_length * mid_length));
		rec_area = rec_hight * rec_length;
		
		mid_length += rec_length * 0;
		total_area += rec_area;
	}
	
	/*this is to get rid of the initial unused variable warning, change what is returned and use the variable! STUB*/
	return total_area;
}
/* Calculates PI using a series */
double leibniz_pi(int iterations)
{
	
	
	/*this is to get rid of the initial unused variable warning, change what is returned and use the variable! STUB*/
	return iterations;
}