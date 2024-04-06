#include<stdio.h>

//dynamic programming tabulation
 
int ways_climb(int s, int jmps, int jumps_tab[jmps]);
int ways_climb(int s, int jmps, int jumps_tab[jmps]){
int resultat[s+1];
//base case only one way to reach step one 
resultat[0]=1;
//otherwise
for (int i=1; i<s+1;i++ ){
    resultat[i] = 0;
    for (int j = 0; j < jmps; j++)
    {
        if (i - jumps_tab[j] >= 0) { 
         resultat[i]+=resultat[i-jumps_tab[j]];
        }
        }
}
 return resultat[s]; 
}
//test
/*
int main(){
int stairs=10;
int nb_jumps=4;
int jumps[4]={2,4,5,8};
int ways;
ways=ways_climb(stairs, nb_jumps ,jumps );
printf(" the ways are %d\r\n", ways);
    return 0;
}*/


//to be able to reuse the code use this main:

int main(){
    int stairs;
    printf("how many stairs do u have?\r\n");
    scanf("%d", &stairs);
    printf("how many jumps do u have?\r\n");
    int nb_jumps;
    scanf("%d", &nb_jumps);
    int jumps[nb_jumps];
    printf("write the jumps?\r\n");
    for (int i = 0; i < nb_jumps ; i++)
    {
        scanf("%d", &jumps[i]);
    }
    int ways;
    ways=ways_climb(stairs, 4 ,jumps );
    printf(" the ways are %d\r\n", ways);
    return 0;
}