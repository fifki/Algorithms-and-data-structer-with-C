#include<stdio.h>
#include<string.h>
int max(int a, int b ){
    return a>b ? a:b ; 
}
int longest(int n , int m , char text1[n], char text2[m]){
    int matrix[n+1][m+1];
    //intialisation 
    for (int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
             matrix[i][j]=0;
        }
    }
    for (int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
             if(text1[i-1]== text2[j-1]){
                matrix[i][j]=matrix[i-1][j-1]+1;
             }
             else{
                matrix[i][j]=max(matrix[i][j-1],matrix[i-1][j]);

             }
        }
    }
    return matrix[n][m];
}

int main(){
    char text1[]="abdacbab";
    char text2[]="acebfca";
    printf(" %d " , longest(8, 7, text1, text2));
return 0;
}