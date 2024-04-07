#include<stdio.h>
/*
Square matrix of ones (problem)
Given a matrix of ones and zeros, 
find the area of the greatest square submatrix full of ones.
A square matrix is a matrix whose the number of rows
 is equal to the number of columns.

Example:

intput:
matrix = [
   [0, 0, 1, 1, 1, 0],
   [1, 0, 1, 1, 1, 1],
   [0, 1, 1, 1, 1, 0],
   [1, 1, 1, 1, 0, 1],
   [0, 1, 0, 1, 1, 1]
]

output: 9
*/
int square(int n, int m , int matrix[n][m]){





}

int main(){
int n=5, m=6;
int matrix[5][6] = {
   {0, 0, 1, 1, 1, 0},
   {1, 0, 1, 1, 1, 1},
   {0, 1, 1, 1, 1, 0},
   {1, 1, 1, 1, 0, 1},
   {0, 1, 0, 1, 1, 1}
};
    int resultat= square(n , m , matrix);
    printf("\r\n %d", resultat);
    return 0;
}

/**
int main(){
    int n, m;
    printf("what is n ?\r\n");
    scanf("%d", &n);
    printf("what is m?\r\n");
    scanf("%d", &m);
    int matrix[n][m];
    printf("write the matrix?\r\n");
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<m; j++){
        scanf("%d", &matrix[i][j]);
        }
    }
    int resultat= gold_mine(n , m , matrix);
    printf("\r\n %d", resultat);
    return 0;
}*/