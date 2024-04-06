#include<stdio.h>

/*
Subset sum (problem)
Given an array arr of strictly positive integers,
 and an integer k, create a function that returns 
 the number of subsets of arr that sum up to k.
Example 1:
input:
arr = [1, 2, 3, 1]
k = 4
output: 3
explanation: subsets that sum up to k are [1, 2, 1], [1, 3], 
and [3, 1]*/
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
    
    //debug:
    /*
        for (int i = 0; i < nb; i++)
    {
        printf( " \r\n----------------------------\r\n");
        for (int j = 0; j < k+1; j++)
        {
            printf(" | %d ", resultat[i][j]);
        } 
    }*/ 

    return resultat[nb-1][k];
}
//test

int main(){
    int nb=5, k=6;
    int array[5]={1,2,3,1,4};
    int result=subset_sum(k, nb, array);
    printf("\r\n %d\r\n", result);
    return 0;
}
/*/
int main(){
    int nb, k;
    printf("what is the lenght of th array?\r\n");
    scanf("%d", &nb);
    printf("enter k ?\r\n");
    scanf("%d", &k);
    int array[nb];
    printf("write the integers?\r\n");
    for (int i = 0; i < nb ; i++)
    {
        scanf("%d", &array[i]);
    }
    int result=subset_sum(k, nb, array);
    printf("the nb of ways is %d\r\n", result);
    return 0;
}*/