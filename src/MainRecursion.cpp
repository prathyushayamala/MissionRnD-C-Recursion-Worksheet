#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"
#include<conio.h>
void generate_array(int **input_array, int rows, int columns, int seq)
{
	int k = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			input_array[i][j] = k++;
}
int main(){
	int n = 4;
	int board[4][4];
	int i = 0, j = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			board[i][j] = 0;
		}
	}

	int result = solve_nsnipers(&board[0][0], n);
	//Check NSnipers

	//Check CountPairs Sample Code 

	//Check Steps Sample Code

	//Check Spiral Sample Code

	//Check Maze Sample Code
	/*int maze[3][5] = {
		{ 1, 0, 0, 0, 1 },
		{ 1, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0 }
	};

	int m = 3, n = 5;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 4;
	int c=path_exists((int*)maze, m, n, x1, y1, x2, y2);*/

	/*int maze[4][3] = {
		{ 0, 0, 1 },
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 0, 1 }
	};

	int m = 4, n = 3;
	int x1 = 3, y1 = 0, x2 = 0, y2 = 2;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);*/

	
	return 0;
}