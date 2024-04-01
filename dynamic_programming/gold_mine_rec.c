#include<stdio.h>
int gold_mine(int n ,int  m ,  int matrix[n][m]);
int max(int size , int tab[size]);
int gold (int n ,int  m ,  int matrix[n][m]);

int main(){
int n=4, m=5;
int matrix[4][5] = {
   {3, 2, 12, 15, 10},
   {6, 19, 7, 11, 17},
   {8, 5, 12, 32, 21},
   {3, 20, 2, 9, 7}
   };
int resultat= gold(n , m , matrix);

printf("\r\n %d", resultat);
    return 0;
}
int max(int size , int tab[size]){
    int max= tab[0];
    for (int i = 1; i < size; i++)
    {
        if(max<tab[i]){
            max=tab[i];
        }
    }
    return max;
}

 int gold_mine_rec(int i , int j, int n ,int  m ,  int matrix[n][m]){
        if(i==n || j<0 || j==m ){
            return 0;
            }
         else{
              return matrix[i][j] + max( 3 , (int[]){gold_mine_rec(i + 1, j-1,n, m,  matrix), gold_mine_rec(i + 1, j ,n,m, matrix), gold_mine_rec(i + 1, j+1,n,m, matrix)});
            }
}
int gold (int n ,int  m ,  int matrix[n][m]){   
    int maxValue = 0;
    for (int j = 0; j < m; j++)
    {
     maxValue = max(2,(int[]){maxValue,gold_mine_rec(0,j,n,m,matrix)});
    }
    return maxValue;
}