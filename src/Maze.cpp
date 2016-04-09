/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int find_path(int *maze, int rows, int columns, int index1, int index2){
	if (index1 == index2){
		return 1;
	}
	else{
		if (index1 >= rows*columns-1){
			if (*(maze + index1 -columns) == 1){
				return find_path(maze, rows, columns, index1 - 2*columns, index2);
			}
			else{
				if (*(maze - columns + index1-1) == 1){
					return find_path(maze, rows, columns, index1 - columns, index2);
				}
				else{
					if (*(maze - columns + index1 + 1) == 1){
						return find_path(maze, rows, columns, index1 - columns - 1, index2);
					}
				}
			}
		}
		else{
			if (*(maze+ index1) == 1){
				if (*(maze +index1+1) == 1){
					return find_path(maze, rows, columns, index1+1,index2);
				}
				else{
					if (*(maze +columns+ index1) == 1){
						return find_path(maze, rows, columns, index1+columns,index2);
					}
					else{
						if (*(maze + (columns *( index1 + 1))) == 1){
							return find_path(maze, rows, columns, index1 + columns + 1, index2);
						}
						else{
							if ((columns == 1)||(rows==1)){
								return 0;
							}
							else{
								return find_path(maze, rows, columns, index1 + columns, index2);
							}
						}
					}
				}
			}
			else{
				return 0;
			}
		}
	}
}
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if ((rows > 0) && (columns > 0)){
		if (((x1 >= 0) && (x1 < rows)) && ((x2 >= 0) && (x2 < rows)) && ((y1 >= 0) && (y1 < columns)) && ((y2 >= 0) && (y2 < columns))){
			int index1 = x1*columns + y1, index2 = x2*columns + y2;
			if ((*(maze + index1) == 1) && (*(maze + index2) == 1)){
				return find_path(maze, rows, columns, index1, index2);
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
	return 0;
}
