#include <stdio.h>
#include <stdlib.h>
#define N 16

int solveMazeUtil(int maze[N][N], int x, int y);

int isSafe(int maze[N][N], int x, int y) {
	if(x >= 0 && 
		 x < N &&
		 y >= 0 &&
		 y < N &&
		 maze[x][y] == 1)
		return 1;
	else
		return 0;
}

void printSolution(int maze[N][N]) {
	for(int x = 0; x < N; x++) {
		for(int y = 0; y < N; y++)
			if(maze[x][y] != 2)
				printf(" %2d ", 0);
			else
				printf(" %2d ", maze[x][y]);
		printf("\n");
	}
}

int solveMaze(int maze[N][N]) {

	if(solveMazeUtil(maze, 0, 0) == false) {
		printf("Solution doesn't e1ist");
		return 0;
	}

	printSolution(maze);
	return 1;
}

int solveMazeUtil(int maze[N][N], int x, int y) {
	if(x == N - 1 && y == N - 1) {
		maze[x][y] = 2;
		return 1;
	}

	if(isSafe(maze, x, y) == true && maze[x][y] != 2) {
		maze[x][y] = 2;

		if(solveMazeUtil(maze, x + 1, y) == true)
			return 1;

		if(solveMazeUtil(maze, x, y + 1) == true)
			return 1;

		if(solveMazeUtil(maze, x - 1, y) == true)
			return 1;

		if(solveMazeUtil(maze, x, y - 1) == true)
			return 1;

		maze[x][y] = 1;
		return 0;
	}

	return 0;
}

int main() {
	int maze[N][N] = {{1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					  {1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
					  {0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
					  {1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1},
					  {0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
					  {1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1},
					  {1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
					  {1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0},
					  {0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0},
					  {1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
					  {0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
					  {0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1},
					  {0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
					  {0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
					  {0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
					  {0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1}};

	solveMaze(maze);
	return 0;
}