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
int min(int size , int tab[size]){
    int mini= tab[0];
    for (int i = 1; i < size; i++)
    {
        if(mini>tab[i]){
            mini=tab[i];
        }
    }
return mini;
}
int max(int n ,int m, int matrix[n][m]){
    int maxi = matrix[0][0];
    for (int i = 1; i <n; i++)
    {
        for(int j =1; j<m;j++){
            if(matrix[i][j]>maxi ){maxi= matrix[i][j];}
        }
}
return maxi;
}

int square(int n, int m , int matrix[n][m]){
int resultat[n][m];
//base case
resultat[0][0]=matrix[0][0];
for (int j = 1; j < m; j++)
{
    resultat[0][j]=matrix[0][j];
}
for (int j = 1; j < n; j++)
{
    resultat[j][0]=matrix[j][0];
}
//otherwise
for (int i = 1; i <n; i++)
{
    for(int j =1; j<m;j++){
        if(matrix[i][j]==0 ){resultat[i][j]=0;}
        else{
            resultat[i][j]=1+min(3, (int[]){resultat[i-1][j], resultat[i][j-1], resultat[i-1][j-1]});
        }
    }
}
//to debug:
/*/
      for (int i = 0; i < n; i++)
    {
        printf( " \r\n----------------------------\r\n");
        for (int j = 0; j < m; j++)
        {
            printf(" | %d ", resultat[i][j]);
        } 
    } */
int max_value = max(n, m, resultat);
return max_value * max_value;
}

//test  
/**
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
*/

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
    int resultat= square(n , m , matrix);
    printf("\r\n %d", resultat);
    return 0;
}