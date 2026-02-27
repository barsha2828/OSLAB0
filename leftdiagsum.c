#include <stdio.h>

int main() {
    int n, i, j;
    int sum = 0;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate sum of left diagonal
    for (i = 0; i < n; i++) {
        sum += matrix[i][i];  // left diagonal elements are where row == column
    }

    printf("Sum of the left diagonal elements = %d\n", sum);

    return 0;
}