#include<stdio.h>
//the approach used is : tabulation (bottom_up approach)

//declaration 
int cost(int n, int m , int matrix[n][m]);
int min(int a ,  int b);

//definition 
int min(int a ,  int b){
    if(a>b){return b; }
    else {return a; }
}
int cost(int n, int m , int matrix[n][m]){
int resultat[n][m];
for (int i=0; i<n ; i++){
    for (int j=0; j<m ; j++){
        //base case:
        if(i==0 && j==0){
            resultat[i][j]=matrix[i][j];
        }
        //first ligne :
        else if(i==0 && j!=0){
            resultat[i][j]=matrix[i][j]+resultat[i][j-1];
        }
        //first column :
        else if(i!=0 && j==0){
             resultat[i][j]=matrix[i][j]+resultat[i-1][j];
        }
        //otherwise
        else{
            resultat[i][j]=matrix[i][j]+min(resultat[i-1][j], resultat[i][j-1] );
        }
    }
}
    return resultat[n-1][m-1];
}
int main(){
int n , m  ;
scanf("%d%d", &n , &m);
int matrice [n][m];
for (int i=0; i<n ; i++){
    for (int j=0; j<m ; j++){
        scanf("%d", &matrice[i][j]);
    }
}
printf("\n");
 int resultat = cost(n , m , matrice);
 printf("\r\n minimum cost path (matrix) is : %d\r\n ", resultat);
    return 0;
}