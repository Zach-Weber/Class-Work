/****************
vigenereCipher.c
By:
Date:
Brief:
gcc -O -Wall -Wextra -ansi -pedantic -o vcipher vigenereCipher.c main.c
****************/
#include "vigenereCipher.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void vigenere(char *string, char *key, enum CODE_METHOD method, int passes)
{
	
	int sLength = (int) strlen(string);
	int keyLength = (int) strlen(key);
	
	if(method == ENCODE)
	{
		int j;
		for(j = 0; j < passes; j++)
		{
			int i;
			
			for(i = 0; i < sLength; i++)
			{
				/* printf("Char: %c | Val: %i || KeyChar: %c | Val: %i\n",string[i], string[i], key[i % keyLength], key[i % keyLength]); */
				
				string[i] = (((string[i] - 97) + (key[i % keyLength] - 97)) % 26) + 97;
			}
		}	
		printf("%s\n", string);
	}
	else if (method == DECODE)
	{
		int j;
		for(j = 0; j < passes; j++)
		{
			int i;
			
			for(i = 0; i < sLength; i++)
			{
				/* printf("Char: %c | Val: %i || KeyChar: %c | Val: %i\n",string[i], string[i], key[i % keyLength], key[i % keyLength]); */
				
				string[i] = (string[i] - 97) - (key[i % keyLength] - 97);
				if (string[i] < 0)
					string[i] += 26;
				string[i] = (string[i] % 26) + 97;
			}
		}	
		printf("%s\n", string);
	}
	
	return;
}

