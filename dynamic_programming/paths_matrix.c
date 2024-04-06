#include<stdio.h>
//the approach used is : tabulation (bottom_up approach)

int Path(int n, int m , int matrix[n][m]){
int resultat[n][m];
for (int i=0; i<n ; i++){
    for (int j=0; j<m ; j++){
        //base case:
        if(i==0 && j==0){
            //there is one only way to ba in matrix[0][0]
            if(matrix[i][j]==0){
            resultat[i][j]=1;
            }
            else{
                return 0;
            }
        }
        //first ligne :
        else if(i==0 && j!=0){
            //if the cell i am in contains no wall and neither do the cell before 
         //there is only one whay to acces the cell matrix[0][j] is coming from matrix[0][j-1]
            if( matrix[i][j]==0 && matrix[i][j-1]==0 ){
                resultat[i][j]=1;
            }
             else {
                resultat[i][j]=0;

            }

        }
        //first column :
        else if(i!=0 && j==0){
            if( matrix[i][j]==0 && matrix[i-1][j]==0 ){
                resultat[i][j]=1;
            }
             else {
                resultat[i][j]=0;

            }
        }
        //otherwise
        else{
            if(matrix[i][j]==0){
            resultat[i][j]=resultat[i-1][j]+ resultat[i][j-1];
            }
            else {
                resultat[i][j]=0;

            }
        }
    }
}
    for (int i=0; i<n ; i++){
        printf("\r\n-------------------------------\r\n");
        for (int j=0; j<m ; j++){
            printf(" | %d | ", resultat[i][j]);
        }
    }
    return resultat[n-1][m-1];
}
//test
/*/
int main(){
int n=4 , m =5 ;
int matrice [4][5]={
    { 0, 0, 1, 0, 1 },
    {0, 0, 0, 0, 1 },
    { 0, 0, 1, 0, 0 },
    {1, 0, 0, 0, 0 } };
    printf("\n");
    int resultat = Path(n, m, matrice);
    printf("\r\n number of paths in matrix  is : %d\r\n ", resultat);
    return 0;
}*/

int main(){
    int n, m; 
    scanf("%d%d", &n , &m);
    int matrice [n][m];
    for (int i=0; i<n ; i++){
        for (int j=0; j<m ; j++){
            scanf("%d", &matrice[i][j]);
        }
    }
    printf("\n");
    int resultat = Path(n, m, matrice);
    printf("\r\n number of paths in matrix  is : %d\r\n ", resultat);
    return 0;
}