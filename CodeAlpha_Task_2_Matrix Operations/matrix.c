#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void readMatrix(int a[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void printMatrix(int a[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], res[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;
    int i, j, k;

    while (1) {
        printf("\n--- Matrix Operations ---\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        switch (choice) {

        case 1:  // Addition
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            if (r1 > MAX || c1 > MAX) {
                printf("Matrix size must be <= %d\n", MAX);
                break;
            }

            printf("Enter first matrix:\n");
            readMatrix(a, r1, c1);

            printf("Enter second matrix:\n");
            readMatrix(b, r1, c1);

            for (i = 0; i < r1; i++)
                for (j = 0; j < c1; j++)
                    res[i][j] = a[i][j] + b[i][j];

            printf("\nResultant Matrix (Addition):\n");
            printMatrix(res, r1, c1);
            break;

        case 2:  // Multiplication
            printf("Enter rows and columns of first matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter rows and columns of second matrix: ");
            scanf("%d %d", &r2, &c2);

            if (r1 > MAX || c1 > MAX || r2 > MAX || c2 > MAX) {
                printf("Matrix size must be <= %d\n", MAX);
                break;
            }

            if (c1 != r2) {
                printf("Multiplication not possible!\n");
                break;
            }

            printf("Enter first matrix:\n");
            readMatrix(a, r1, c1);

            printf("Enter second matrix:\n");
            readMatrix(b, r2, c2);

            for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                    res[i][j] = 0;
                    for (k = 0; k < c1; k++)
                        res[i][j] += a[i][k] * b[k][j];
                }
            }

            printf("\nResultant Matrix (Multiplication):\n");
            printMatrix(res, r1, c2);
            break;

        case 3:  // Transpose
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            if (r1 > MAX || c1 > MAX) {
                printf("Matrix size must be <= %d\n", MAX);
                break;
            }

            printf("Enter matrix:\n");
            readMatrix(a, r1, c1);

            printf("\nTranspose Matrix:\n");
            for (i = 0; i < c1; i++) {
                for (j = 0; j < r1; j++)
                    printf("%d ", a[j][i]);
                printf("\n");
            }
            break;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}