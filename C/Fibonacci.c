/* 
Fibonacci.c
Name: Zach Weber
Last Edited: 9/23/19
Description: A program that will print the numbers in the fibonacci sequence
gcc -Wall -Wextra -Werror -ansi -pedantic -O Fibonacci.c -o fib.exe
 */
 
 /* printf */
 #include <stdio.h>
 
 int main(void)
 {
	 /* create variables */
	 int prev = 0;
	 int curr = 1;
	 int new;
	 
	 
	 printf("%i\n",prev); /*Print Previous*/
	 printf("%i\n",curr);/*Print Current*/
	 
	 new = prev + curr;
	 prev = curr;
	 	
	 while(1)
	 {
		 printf("%i\n",new); /*Prints new number from adding previous 2*/
		 
		 prev = curr;
		 
		 curr = new;
		 
		 new = prev + curr;
		 
		 
	 }
	 
	 return 0;
 }