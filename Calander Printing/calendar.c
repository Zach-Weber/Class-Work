/**************************
calendar.c
By: 
Date: 
Brief: 
**************************/

#include <stdio.h>

#define TRUE  1
#define FALSE 0

int is_leapyear(int year)
{
	if ((year % 4) == 0)
	{
		if ((year % 100) == 0)
		{
			if ((year % 400) == 0)
			{
				return 1;
			}
			else
				return 0;
		}
		else 
			return 1;
	}
	else
		return 0;
}

int day_of_the_week(int day, int month, int year)
{
  int month_keys[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
  int year_keys[] = {4, 2, 0, 6};
	int leapyear = is_leapyear(year);
	int temp = 0;
	int year_lastdigits = 0;
	
	/* finds the last digits of the year */
	year_lastdigits = year % 100;
	
	/* Divide that number by 4 using integer division */
	temp = year_lastdigits / 4;
	
	/* Add the day of the month. */
	temp = temp + day;
	
	/* Add the month's key value from this table */
	temp = temp + (month_keys[month - 1]);
	
	/* If the date is in January or February AND the year is a leap year, subtract 1 from the total so far. */
	if ((month == 1 || month == 2) && (leapyear == 1))
	{
		temp = temp - 1;
	}
	
	/* If the year is not in the table, you just keep subtracting/adding 400 from the year until you get 
	one of the centuries that is in the table */
	while (year > 2099)
	{
		year -= 400;
	}
	while (year < 1700)
	{
		year += 400;
	}
	
	/* Add the century code from the following table */
	if (year >= 1700 && year <= 1799)
		temp = temp + (year_keys[0]);
	else if (year >= 1800 && year <= 1899)
		temp = temp + (year_keys[1]);
	else if (year >= 1900 && year <= 1999)
		temp = temp + (year_keys[2]);
	else if (year >= 2000 && year <= 2099)
		temp = temp + (year_keys[3]);
	
	/* Add the last 2 digits in the year to the total */
	temp = temp + year_lastdigits;
	
	/* Finally, divide by 7 and take the remainder */
	temp = temp % 7;
	
	/* If the result is 0, set it to 7 to represent saturday */
	if (temp == 0)
		temp = 7;
	
	/* Return the day of the week */
  return temp;
}

void print_calendar(int month, int year)
{
	int dayofweek = (day_of_the_week(1, month, year) - 1);
	/* int isleapyear = is_leapyear(year); */
	int i, j;
	
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char *months[] = {"January",   "February", "March",    "April", 
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};

    /* Print calendar header */
  printf("%s, %i\n", months[month - 1], year);
  printf("Su Mo Tu We Th Fr Sa\n");
  printf("---------------------\n");
  
	
	/* For loop to space days until the first day based on day_of_the_week */
	for (i = 0; i < dayofweek; ++i)
	{
		printf("   ");
	}
	
	/* For loop to place the rest of the days (1 to # of days in that month) */
	for (j = 1; j <= days_in_month[month - 1]; j++)
	{
		printf("%2i", j);
		printf(" ");
		
		/* Determine what day of the week is so the new line is in the right place */
		if (dayofweek == 6)
		{
			dayofweek = 0;
			printf("\n");
		}
		else 
			++dayofweek;
	}
	
	printf("\n");
}
