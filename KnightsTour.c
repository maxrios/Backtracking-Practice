#include <stdio.h>
#define N 8 // N x N cells in the matrix

//Prototype
int solveKnightUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]);

//Checks if i and j are valid indexes for an NxN chessboard
int isSafe(int x, int y, int sol[N][N]) {
	if(x >= 0 && 
		 x < N &&
		 y >= 0 &&
		 y < N &&
		 sol[x][y] == -1)
		return true;
	else
		return false;
}

//Prints solution matrix
void printSolution(int sol[N][N]) {
	for(int x = 0; x < N; x++) {
		for(int y = 0; y < N; y++)
			printf(" %2d ", sol[x][y]);
		printf("\n");
	}
}

int solveKnight() {
	int sol[N][N];

	for(int x = 0; x < N; x++) {
		for(int y = 0; y < N; y++) {
			sol[x][y] = -1;
		}
	}

	//Determines the x and y next move position for the night
	int xMove[N] = {2, 1, -1, -2, -2, -1, 1, 2};
	int yMove[N] = {1, 2, 2, 1, -1, -2, -2, -1};

	//Starting position
	sol[0][0] = 0;

	if(solveKnightUtil(0, 0, 1, sol, xMove, yMove) == 0) {
		printf("Solution does not exist");
		return 0;
	}
	else 
		printSolution(sol);

	return 1;
}

int solveKnightUtil(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N]) {
	int k, nextX, nextY;
	
	if(movei == N*N)
		return 1;

	for(k = 0; k < N; k++) {
		nextX = x + xMove[k];
		nextY = y + yMove[k];
		if(isSafe(nextX, nextY, sol)) {
			sol[nextX][nextY] = movei;
			if(solveKnightUtil(nextX, nextY, movei+1, sol, xMove, yMove) == 1)
				return 1;
			else
				sol[nextX][nextY] = -1; //Backtracking
		}
	}

	return 0;
}

int main() {
	solveKnight();
	return 0;
}