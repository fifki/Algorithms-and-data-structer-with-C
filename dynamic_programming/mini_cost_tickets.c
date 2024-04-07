#include<stdio.h>
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


int cost_ticket(int period , int day,int ncost, int train[day], int cost[ncost]){



}

int main(){


int period = 32, nb_day=8, nb_cost=3;
int train_days[8] = {1, 3, 8, 9, 22, 23, 28, 31};
int costs[3] = {4, 10, 25};
int resultat=cost_ticket(period , nb_day, nb_cost, train_days, costs);
printf("%d\r\n", resultat);



    return 0;
}