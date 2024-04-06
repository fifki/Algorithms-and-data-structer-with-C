//the problem:
    /*Given the value and the weight of each 
    one of n items, we want to maximize the value 
    of items we take in our knapsack without exceeding 
    its capacity k. You are asked to find the maximum 
    total value that we can get without exceeding a total weight of k.
    Note that each item can be took at most once*/


// the solution:

#include<stdio.h>

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

int knapsac(int cap, int items, int valeur[items], int weight[items]){
    int resultat_val[cap+1];
    int resultat_weight[cap+1];
    //base case:
    resultat_val[0]=0;
    resultat_weight[0]=1;
    for (int i = 1; i < cap+1 ; i++)
    {
        resultat_val[i]=0;
        resultat_weight[i]=-1;
        for (int j=0; j<items; j++){
            if(i-weight[j]>=0){
                resultat_weight[i]=1;
                resultat_val[i]=max(3 , (int[]){resultat_val[i], valeur[j] ,resultat_val[i-1]}) ;
            }
        }
    }
for (int i = 0; i < cap+1; i++)
{
    printf("|%d",resultat_val[i] );
}
printf("\r\n");
return resultat_val[cap];

}

int main(){
    int items=5;
    int cap=20;
    int valeur[5]={20,30,5,10,3};
    int weight[5]={6,13,5,10,3};
    int result=knapsac(cap , items , valeur , weight);
    printf("%d\r\n", result);
    return 0;
}