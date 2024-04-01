#include<stdio.h>
int gold_mine(int n ,int  m ,  int matrix[n][m]);
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

 int gold_mine(int n ,int  m ,  int matrix[n][m]){
    int resultat[n][m];
    int gold=0;
    for (int i= 0; i<n; i++){
        for(int j=0; j<m; j++){
            //the first ligne
            if(i==0){
                resultat[i][j]=matrix[i][j];
            }
            else if(j==0 && i!=0 ){
                resultat[i][j] = matrix[i][j] + max( 2 , (int[]){resultat[i - 1][j], resultat[i - 1][j + 1]});
            }
            else if(j==m-1 && i!=0){
                resultat[i][j]=matrix[i][j] + max(2 , (int[]){resultat[i-1][j], resultat[i-1][j-1]});
            }
            else {
                resultat[i][j]=matrix[i][j] + max(3, (int[]){resultat[i-1][j], resultat[i-1][j-1], resultat[i-1][j+1]});

            }
        }
    }
    
    gold = max(m, resultat[n-1]);
    return gold;
}
int main(){
int n=4, m=5;
int matrix[4][5] = {
   {3, 2, 12, 15, 10},
   {6, 19, 7, 11, 17},
   {8, 5, 12, 32, 21},
   {3, 20, 2, 9, 7}
   };
int resultat= gold_mine(n , m , matrix);

printf("\r\n %d", resultat);
    return 0;
}