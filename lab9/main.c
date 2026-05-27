#include <stdio.h>
#include <stdlib.h>

int **board;
int N;

// Function to print the board
void printSolution() {

    printf("One Possible Solution:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check whether queen can be placed
int isSafe(int row, int col) {

    // Check left side of row
    for (int i = 0; i < col; i++) {
        if (board[row][i])
            return 0;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return 0;
    }

    // Check lower-left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return 0;
    }

    return 1;
}

// Recursive backtracking function
int solveNQueens(int col) {

    // If all queens are placed
    if (col == N)
        return 1;

    // Try placing queen in all rows
    for (int i = 0; i < N; i++) {

        if (isSafe(i, col)) {

            // Place queen
            board[i][col] = 1;

            // Recur for next column
            if (solveNQueens(col + 1))
                return 1;

            // Backtrack
            board[i][col] = 0;
        }
    }

    return 0;
}

int main() {

    printf("Enter value of N: ");
    scanf("%d", &N);

    // Dynamic memory allocation
    board = (int **)malloc(N * sizeof(int *));

    for (int i = 0; i < N; i++) {
        board[i] = (int *)malloc(N * sizeof(int));
    }

    // Initialize board with 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Solve the problem
    if (solveNQueens(0))
        printSolution();
    else
        printf("No solution exists\n");

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(board[i]);
    }

    free(board);

    return 0;
}
