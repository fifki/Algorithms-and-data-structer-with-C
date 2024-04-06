#include<stdio.h>
//Partition (problem)
/*
Given an array of strictly positive integers arr, 
check if we can split it into two subsets that have 
the same sum of elements.
Example 1:
input:
arr = [4, 5, 3, 2, 5, 1]
output: true
*/
int subset_sum(int k, int nb , int array[nb]){
    int resultat[nb][k+1];
    int somme=0;
    for(int i=0; i<nb; i++){
    somme+=array[i];
    }

    if(k>somme || nb==0 ){return 0;}
    else{
        resultat[0][0]=1;
        for (int i = 0; i < nb; i++)
        {
            for (int j = 0; j < k+1; j++)
            {    
                if(j==0) {
                    resultat[i][0]=1;
                } 
                else if(i==0) {
                    if(array[0]==j){
                        resultat[0][j]=1;
                    }
                    else{
                        resultat[0][j]=0;
                    }
                }
                else{
                    if(j-array[i]>=0){
                        resultat[i][j]=resultat[i-1][j]+resultat[i-1][j-array[i]];
                    }
                    else{
                        resultat[i][j]=resultat[i-1][j];
                    }
                }
            }
        } 
        }
    for (int i = 0; i < nb; i++)
    {
        printf( " \r\n----------------------------\r\n");
        for (int j = 0; j < k+1; j++)
        {
            printf(" | %d ", resultat[i][j]);
        }
    }
    return resultat[nb-1][k];
}
int partition(int nb, int array[nb]){
    int sum=0;
    for(int i=0; i<nb; i++){
        sum+=array[i];
    }
    if(sum%2!= 0){
        return 0;
        }
    else{
        return subset_sum(sum/2 , nb , array);
    }
}
int main(){
int nb=6;
int array[6]={4,5,3,2,5,1};
int result= partition(nb, array);
printf("%d\r\n", result);
    return 0;
}
/*

int main(){
    int nb;
    printf("how many nb  do u have?\r\n");
    scanf("%d", &nb);
    int array[nb];
    printf("write the nombers ?\r\n");
    for (int i = 0; i < nb ; i++)
    {
        scanf("%d", &array[i]);
    }
    int result= partition(nb, array);
    printf("%d\r\n", result);
    return 0;
}*/