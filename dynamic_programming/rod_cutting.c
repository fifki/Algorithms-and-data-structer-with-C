#include<stdio.h>
/*Rod cutting (problem)
We want to sell a rod of size n, 
and to maximize the profit, 
we can cut it into multiple pieces. 
The price of a piece depends on its length, 
to know it, we are given an array prices where prices[i] 
represents the price of a piece of length i.

You are asked to find the maximum price 
that we can get by cutting it into pieces.

Note that you are allowed to sell it as a single 
piece of length n if it's the most profitable choice.

Example:

input:
n = 8
prices = [0, 1, 3, 5, 6, 7, 9, 10, 11]

output: 13*/
int max(int a ,  int b){
    if(a>b){return a; }
    else {return b; }
}

int rod_cut(int n, int nb , int prices[nb]){
    int resultat[n+1];
    resultat[0]=0;
    for (int i = 1; i < n+1; i++)
    {
        resultat[i] = prices[i];
        for (int j = 1; j < i+1; j++)
        {
            resultat[i]=max(resultat[i], prices[j]+resultat[i-j]);
        }
    } 
    printf( " \r\n----------------------------\r\n");
    for (int i = 0; i < n+1; i++)
    {
        printf(" | %d ", resultat[i]);
    } 
 printf( " \r\n----------------------------\r\n");
    return resultat[n];
}
int main(){
    int n=8;
    int nb=9;
    int prices [9]= {0, 1, 3, 5, 6, 7, 9, 10, 11};
    int result=rod_cut(n, nb, prices);
    printf("%d\r\n", result);
    return 0;
}
/*
int main(){
    int n, nb;
    printf("what is n ?\r\n");
    scanf("%d", &n);
    printf("enter number of element in the array ?\r\n");
    scanf("%d", &nb);
    int prices[nb];
    printf("write the integers?\r\n");
    for (int i = 0; i < nb ; i++)
    {
        scanf("%d", &prices[i]);
    }
    int result=rod_cut(n, nb, prices);
    printf("%d\r\n", result);
    return 0;*/