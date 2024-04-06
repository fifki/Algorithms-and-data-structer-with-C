//the problem:
    /*Given the value and the weight of each 
    one of n items, we want to maximize the value 
    of items we take in our knapsack without exceeding 
    its capacity k. You are asked to find the maximum 
    total value that we can get without exceeding a total weight of k.
    Note that each item can be took at most once*/


// the solution:

#include<stdio.h>

int max(int a ,  int b){
    if(a>b){return a; }
    else {return b; }
}

int knapsac(int cap, int items, int valeur[items], int weight[items]){
    int resultat[items][cap+1];
    int somme_weight=0;
    int somme_val=0; 
    for(int i=0; i<items; i++){
        somme_weight+=weight[i];
        somme_val+=valeur[i];
    }
    if(cap==0){return 0;}
    else if(cap>somme_weight){return somme_val;}
    else{
        for (int i = 0; i < items ; i++)
        {
            for (int j=0; j<cap+1; j++){
                //the base case
                if(i==0){
                    if(weight[0]>j){
                        resultat[i][j]=0;
                    }
                    else {
                        resultat[i][j]=valeur[0];
                    }
                }
                //otherwise
                else if(weight[i]>j){
                    resultat[i][j]=resultat[i-1][j];
                    }
                else{
                    resultat[i][j]=max(valeur[i] + resultat[i-1][j-weight[i]], resultat[i-1][j]);
                    }         
            }
        }
    }
return resultat[items-1][cap];
} 
//test 

/*
int main(){
    int items=5;
    int cap=20;
    int valeur[5]={20,30,15,25,10};
    int weight[5]={6,13,5,10,3};
    int result=knapsac(cap , items , valeur , weight);
    printf("%d\r\n", result);
    return 0;
}*/

//to be able to ajuste the code use this main:

int main(){
int items, cap;
    printf("how many items do u have?\r\n");
    scanf("%d", &items);
    printf("what is the kapacity of the knapsac?\r\n");
    scanf("%d", &cap);
    int weight[items];
    printf("write the items?\r\n");
    for (int i = 0; i < items ; i++)
    {
        scanf("%d", &weight[i]);
    }
    int valeur[items];
    printf("the value of the items ?\r\n");
    for (int i = 0; i < items; i++)
    {
        scanf("%d", &valeur[i]);
    }
    int result=knapsac(cap , items , valeur , weight);
    printf(" the maximum value is  %d\r\n", result);
    return 0;
}