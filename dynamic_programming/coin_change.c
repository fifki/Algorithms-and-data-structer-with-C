#include<stdio.h>

//dynamic programming tabulation

int min(int a ,  int b){
    if(a<b){return a; }
    else {return b; }
}
int coin_change(int m, int nb, int coin_tab[nb]);
int coin_change(int m, int nb, int coin_tab[nb]){
int resultat[m+1];
//base case only one way to reach step one 
resultat[0]=0;
//otherwise
for (int i=1; i<m+1;i++ ){
    resultat[i] = -1;
    for (int j = 0; j < nb; j++)
    {
        if(i - coin_tab[j] >= 0 && resultat[i]!= -1 && resultat[i-coin_tab[j]]!= -1){
            resultat[i]=min(resultat[i] , 1 + resultat[i-coin_tab[j]]);
        }
        else if(i - coin_tab[j] >= 0 && resultat[i]== -1 && resultat[i-coin_tab[j]]!= -1){
            resultat[i]= 1 + resultat[i-coin_tab[j]];
        }
        

    }
}
 return resultat[m]; 
}
int main(){
    int money=80;
    int nb=3;
    int possible_coin[3]={1,20,25};
    int nb_coin;
    nb_coin=coin_change(money, nb ,possible_coin );
    printf(" the nb_coin are %d\r\n", nb_coin);
        return 0;
}