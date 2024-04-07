#include<stdio.h>
#include <stdbool.h>
//the problrm 
/*
Minimum cost for tickets (problem)
We are about to travel for a period of n days, 
during which we will use the train in some days that you
 can find in a given set train_days.

And to use the train, we have to possess either 
a 1-day pass, a 7-days pass, or a 30-days pass, 
each one of them has a price that you can find in a given array prices,
 where prices[0] represents the price of a 1-day pass, 
 prices[1] represents the price of a 7-days pass, 
 and prices[2] represents the price of a 30-days pass.

You are asked to find the minimum amount 
of money that we need to use the train during all the train days.

Example:
inpt:
train_days = [1, 3, 8, 9, 22, 23, 28, 31]
costs = [4, 10, 25]
n = 32
output: 28
*/
int min(int size , int tab[size]);
bool in_array(int n ,int b , int array[n]);
int cost_ticket(int period , int day,int ncost, int train[day], int cost[ncost]);


int min(int size , int tab[size]){
    int mini= tab[0];
    for (int i = 1; i < size; i++)
    {
        if(mini>tab[i]){
            mini=tab[i];
        }
    }
return mini;
}


bool in_array(int n ,int b , int array[n]){
bool exist=false;
for(int i=0; i<n; i++){
    if(array[i]==b){
        exist = true;
        break;
    }
}
return exist;
}

int cost_ticket(int period , int day,int ncost, int train[day], int cost[ncost]){
int resultat[period];
int day_cost=0,week_cost=0, month_cost=0;
for(int i =0; i<period; i++){
    resultat[i]=0;
    if (in_array( day, i, train) == 0 ){
        if(i-1>=0){resultat[i]=resultat[i-1]; }
        else{resultat[i]=0;}
    }
    else {
        if(i-1>=0){day_cost=cost[0]+resultat[i-1]; }
            else{day_cost=0;}
        if(i-7>=0){week_cost=cost[1]+resultat[i-7]; }
            else{week_cost=0;}
        if(i-30>=0){month_cost=cost[2]+resultat[i-30]; }
            else{month_cost=0;}

        resultat[i]=min(3, (int[]){day_cost, week_cost , month_cost});
    }
}
printf( " \r\n-------------------------------------------------------------\r\n");
for (int i = 0; i < period; i++)
    {
      printf("|%d ", resultat[i]);  
    }
    printf( " \r\n------------------------------------------------------------\r\n");
return resultat[period-1];
}

int main(){


int period = 32, nb_day=8, nb_cost=3;
int train_days[8] = {1, 3, 8, 9, 22, 23, 28, 31};
int costs[3] = {4, 10, 25};
//output 28
int resultat=cost_ticket(period , nb_day, nb_cost, train_days, costs);
printf("%d\r\n", resultat);

    return 0;
}