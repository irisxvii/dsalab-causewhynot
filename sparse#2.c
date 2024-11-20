#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[10][10]) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int toTupleForm(int rows, int cols, int matrix[10][10], int tuple[10][3]) {
    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    tuple[0][0] = rows;
    tuple[0][1] = cols;
    tuple[0][2] = k - 1; 
    return k; 
}

void printTuple(int tuple[10][3], int size) {
    printf("Row Col Value\n");
    for (int i = 0; i < size; i++) {
        printf("%d   %d   %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

void transposeTuple(int tuple[10][3], int transposed[10][3], int size) {
    transposed[0][0] = tuple[0][1];
    transposed[0][1] = tuple[0][0];
    transposed[0][2] = tuple[0][2];

    int k = 1;
    for (int col = 0; col < tuple[0][1]; col++) { 
        for (int i = 1; i < size; i++) {
            if (tuple[i][1] == col) {
                transposed[k][0] = tuple[i][1];
                transposed[k][1] = tuple[i][0];
                transposed[k][2] = tuple[i][2];
                k++;
            }
        }
    }
}

int main() {
    int rows, cols;
    int matrix[10][10];
    int tuple[10][3], transposed[10][3];

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    inputMatrix(rows, cols, matrix);

    int tupleSize = toTupleForm(rows, cols, matrix, tuple);
    printf("Tuple form of the matrix:\n");
    printTuple(tuple, tupleSize);

    transposeTuple(tuple, transposed, tupleSize);
    printf("\nTranspose of the sparse matrix in tuple form:\n");
    printTuple(transposed, tupleSize);

    return 0;
}
