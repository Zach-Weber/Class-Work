/****************
main.c
By:
Date: 
Brief: The test file to use with vigenereCipher.c.  You will need to set it up to take input from the console for 
both the string to encrypt and the key to encrypt with, please use the provided arrays!  After encrypting also test the decrypting! 
gcc -O -Wall -Wextra -ansi -pedantic -o vcipher vigenereCipher.c main.c
****************/
#include <stdio.h>
#include <string.h>
#include "vigenereCipher.h"

int main(void)
{
	char string[256];
	char key[32];
	int passes;
	
	/*ask for the string to encrypt and store it in string*/
	printf("Input a string to encrypt!\n");
	scanf("%s", string);
	
	/*ask for the key to encrypt with and store it in key*/
	printf("Input a key to encrypt with!\n");
	scanf("%s", key);
	
	/*ask for how many passes to encrypt with*/
	printf("How many passes to encrypt with?\n");
	scanf("%i", &passes);
	
	/*encrypt string with the key, make sure set to encode!*/
	vigenere(string, key, ENCODE, passes);
	
	/*print out the encoded string*/
	/* printf("%s\n", string); */
	
	/*now reverse it back to normal by setting it to decode and print it out again*/
	vigenere(string, key, DECODE, passes);
	/* printf("%s\n", string); */

	return 0;
}