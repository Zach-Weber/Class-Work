/***********************************
TicTacToe.c
10/1/17
Programmed By: The Masked Programmer and (insert name here) 
Brief: Tic Tac Toe game with some missing components to be fixed.
gcc -Wall -Wextra -ansi -pedantic -O -o TicTacToe TicTacToe.c
***********************************/
/*printf scanf*/
#include <stdio.h>

/*function prototypes*/
/*function will need to look at the grid and determine if there is a winner or if it is a tie*/
int CheckGrid(int Grid[][3]);
/*print out the board for the players*/
void printBoard(int Grid[][3]);

/*contains main game loop and player input runs other functions*/
int main(void)
{
	/*2D array for our grid, 3x3*/
	int Grid[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
	/* 0 is for O 1 is for X*/
	int playerTurn = 1;
	int input;
	int gameState = CheckGrid(Grid);
	printf("Welcome to Tic Tac Toe!\nTake turns with another player chosing places.\n");
	
	while(gameState == -1)
	{
		/*display board with numbers*/
		printBoard(Grid);
		if(playerTurn == 1)
		{
			printf("Player X's Turn, select your position:\n");
		}
		else
		{
			printf("Player O's Turn, select your position:\n");
		}
		/*Get input from the current player*/
		while(1)
		{
			scanf(" %i", &input);
			while(getchar() != '\n');
			if(input >= 0 && input < 9 && Grid[input/3][input%3] == -1)
			{
				/*legal input found*/
				Grid[input/3][input%3] = playerTurn;
				break;
			}
			printf("Invalid Input\n");
			
		}
		/*change playerturn*/
		if(playerTurn)
		{
			playerTurn = 0;
		}
		else
		{
			playerTurn = 1;
		}
		gameState = CheckGrid(Grid);
	}
	printBoard(Grid);
	/*determines winner*/
	switch(gameState)
	{
		case 0:
		printf("Player O Wins!\n");
		break;
		case 1:
		printf("Player X Wins!\n");
		break;
		case 2:
		printf("Tie!\n");
		break;
	}
	getchar();
	return 0;
}

/*function will need to look at the grid and determine if there is a winner or if it is a tie*/
int CheckGrid(int Grid[][3])
{
	int row, collum;
	int TieCount = 0;
	
	/*horizontal loop through all on one row*/
	for (row = 0; row <= 2; row++)
	{
		if (Grid[row][0] == Grid[row][1] && Grid[row][0] == Grid[row][2])
		{
			return Grid[row][0];
		}
	}
	
	/*verticle loop through all on one column*/
	for (collum = 0; collum <= 2; collum++)
	{
		if (Grid[0][collum] == Grid[1][collum] && Grid[0][collum] == Grid[2][collum])
		{
			return Grid[0][collum];
		}
	}
	
	/*diagonals check all at once*/
	if (Grid[0][0] == Grid[1][1] && Grid[0][0] == Grid[2][2])
	{
		return Grid[0][0];
	}
	if (Grid[0][2] == Grid[1][1] && Grid[0][2] == Grid[2][0])
	{
		return Grid[0][2];
	}
	
	/*make sure not tie*/
	for (row = 0; row <= 2; row++)
	{
		for (collum = 0; collum <= 2; collum++)
		{
			if(Grid[row][collum] != -1)
			{
				++TieCount;
			}
		}
	}
	/*it is a tie if it gets here*/
	if (TieCount == 9)
	{
		return 2;
	}
	
	/* if no one scores */
	return -1;
}
/*print out the board for the players*/
void printBoard(int Grid[][3])
{
	int i,j;
	for(i = 0; i <3; i++)
	{
		printf("|");
		for(j = 0 ; j < 3 ; j++)
		{
			switch(Grid[i][j])
			{
				case -1:
				printf(" %i |", i * 3 + j );
				break;
				case 0:
				printf(" O |");
				break;
				case 1:
				printf(" X |");
				break;
			}
		}
		printf("\n\n");
	}
	return;
}