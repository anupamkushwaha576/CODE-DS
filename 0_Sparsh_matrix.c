#include <stdio.h>

#define MAX 100

void createSparse(int mat[][5], int rows, int cols, int sparse[][3], int *n) {
    *n = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[*n][0] = i;
                sparse[*n][1] = j;
                sparse[*n][2] = mat[i][j];
                (*n)++;
            }
        }
    }
}

void display(int sparse[][3], int n) {
    printf("Row Col Value\n");
    for (int i = 0; i < n; i++)
        printf("%3d %3d %5d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
}

int main() {
    int mat[4][5] = {
        {0, 0, 3, 0, 0},
        {0, 5, 0, 0, 9},
        {0, 0, 0, 7, 0},
        {2, 0, 0, 0, 0}
    };

    int sparse[MAX][3];
    int n;

    createSparse(mat, 4, 5, sparse, &n);

    printf("Sparse Matrix (Triplet form) for 4x5:\n");
    display(sparse, n);

    return 0;
}