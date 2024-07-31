#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100

void transpose(int original[MAX_ROWS][MAX_COLS], int transposed[MAX_COLS][MAX_ROWS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = original[i][j];
        }
    }
}

int main() {
    int original[MAX_ROWS][MAX_COLS], transposed[MAX_COLS][MAX_ROWS];
    int rows, cols;

    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &original[i][j]);
        }
    }

    transpose(original, transposed, rows, cols);

    printf("The transpose of the matrix is:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    return 0;
}