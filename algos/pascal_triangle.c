#include<stdio.h>

int main(){
    int row=5;
    int matrix[row][row]; 
    for(int i=0; i<row; i++){
        for(int j=0; j<i+1; j++){
            if (j==0 || j==i){
                matrix[i][j]=1;
            }
            else{
                matrix[i][j]= matrix[i-1][j] + matrix[i-1][j-1];
            }
        }
    }
    for(int j=0; j<row; j++){
          printf(" %d ", matrix[row- 1][j]);  
        }
    return 0;
}