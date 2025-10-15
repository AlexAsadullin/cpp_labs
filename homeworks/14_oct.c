#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getRandomMatrix(int **arr, int rows, int cols, int min_val, int max_val) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = (rand() % (max_val - min_val + 1)) + min_val;
        }
    }
}

void printMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multMatrix(int **A, int **B, int **C, int N, int M, int K) {
    if (M != M) { // Placeholder; assumes B has M rows
        fprintf(stderr, "Matrix multiplication impossible: cols(A) != rows(B)\n");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            C[i][j] = 0;
            for (int k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void freeMatrix(int **mat, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(mat[i]);
    }
    free(mat);
}

int main() {
    srand(time(NULL));
    int N, M, K;

    // Test 1
    printf("Test 1: Enter dimensions for A (N x M) and B (M x K):\n");
    scanf("%d %d %d", &N, &M, &K);

    int **A = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; ++i) {
        A[i] = (int *)malloc(M * sizeof(int));
    }
    int **B = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; ++i) {
        B[i] = (int *)malloc(K * sizeof(int));
    }
    int **C = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; ++i) {
        C[i] = (int *)malloc(K * sizeof(int));
    }

    getRandomMatrix(A, N, M, 1, 10);
    getRandomMatrix(B, M, K, 1, 10);

    printf("Matrix A (%d x %d):\n", N, M);
    printMatrix(A, N, M);
    printf("Matrix B (%d x %d):\n", M, K);
    printMatrix(B, M, K);

    multMatrix(A, B, C, N, M, K);

    printf("Result C (%d x %d):\n", N, K);
    printMatrix(C, N, K);

    freeMatrix(A, N);
    freeMatrix(B, M);
    freeMatrix(C, N);

    // Test 2
    printf("Test 2: Enter dimensions for A (N x M) and B (M x K):\n");
    scanf("%d %d %d", &N, &M, &K);

    A = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; ++i) {
        A[i] = (int *)malloc(M * sizeof(int));
    }
    B = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; ++i) {
        B[i] = (int *)malloc(K * sizeof(int));
    }
    C = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; ++i) {
        C[i] = (int *)malloc(K * sizeof(int));
    }

    getRandomMatrix(A, N, M, 1, 10);
    getRandomMatrix(B, M, K, 1, 10);

    printf("Matrix A (%d x %d):\n", N, M);
    printMatrix(A, N, M);
    printf("Matrix B (%d x %d):\n", M, K);
    printMatrix(B, M, K);

    multMatrix(A, B, C, N, M, K);

    printf("Result C (%d x %d):\n", N, K);
    printMatrix(C, N, K);

    freeMatrix(A, N);
    freeMatrix(B, M);
    freeMatrix(C, N);

    return 0;
}