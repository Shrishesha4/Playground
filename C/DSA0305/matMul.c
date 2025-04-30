#include<stdio.h>
#define MAX 10

void multiplyMatrix(int m1[MAX][MAX], int m2[MAX][MAX], int m, int n) {
    int res[MAX][MAX];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            res[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    printf("\nResultant Matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}

void getUserInput( int mat[MAX][MAX], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[MAX][MAX], int m, int n) {
    printf("Matrix:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matA[MAX][MAX], matB[MAX][MAX], res[MAX][MAX];
    int m, n;
    printf("Enter the size of matrix: \n");
    scanf("%d", &m);
    printf("\n");
    scanf("%d", &n);
    
    printf("\nEnter elements of matrix A:\n");
    getUserInput(matA, m, n);
    displayMatrix(matA, m, n);

    printf("\nEnter elements of matrix B:\n");
    getUserInput(matB, n, m);
    displayMatrix(matB, n, m);
    
    multiplyMatrix(matA, matB, m, n);
    
    return 0;
}