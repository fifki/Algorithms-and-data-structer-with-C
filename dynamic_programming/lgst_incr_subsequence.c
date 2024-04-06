#include<stdio.h>
int longest (int nb , int array[nb]){
int resultat[nb];
int somme=0;
int old=0, new=0;
for (int i = 0; i < nb; i++)
{
    somme=array[i];
    for (int j = i ; i < nb ; j++)

    {
        if(array[j+1]>array[j]){
        somme+=array[j+1];}
        else 
    }
    
}

}
int main(){
int nb ; 
int array[13]={7, 5, 2, 4, 7, 2, 3, 6, 4, 5, 12, 1, 7};
int resultat= longest(nb , array);
printf("%d\r\n", resultat);
    return 0;
}