#include <stdio.h>
#define ROW_SIZE 3
#define COL_SIZE 3
void multiply_matrices(int mat1[ROW_SIZE][COL_SIZE], int mat2[ROW_SIZE][COL_SIZE], int result[ROW_SIZE][COL_SIZE]) {
int i, j, k;
for (i = 0; i < ROW_SIZE; i++) {
for (j = 0; j < COL_SIZE; j++) {
result[i][j] = 0;
for (k = 0; k < COL_SIZE; k++) {
result[i][j] += mat1[i][k] * mat2[k][j];
}
}
}
}
void print_matrix(int mat[ROW_SIZE][COL_SIZE]) {
int i, j;
for (i = 0; i < ROW_SIZE; i++) {
for (j = 0; j < COL_SIZE; j++) {
printf("%d ", mat[i][j]);
}
printf("\n");
}
}
int main() {
int matrix1[ROW_SIZE][COL_SIZE] = {
{1, 2, 3},
{4, 5, 6},
{7, 8, 9}
};
int matrix2[ROW_SIZE][COL_SIZE] = {
{9, 8, 7},
{6, 5, 4},
{3, 2, 1}
};
int result_matrix[ROW_SIZE][COL_SIZE];
multiply_matrices(matrix1, matrix2, result_matrix);
printf("Matrix 1:\n");
print_matrix(matrix1);
printf("Matrix 2:\n");
print_matrix(matrix2);
printf("Result Matrix:\n");
print_matrix(result_matrix);
return 0;
}

