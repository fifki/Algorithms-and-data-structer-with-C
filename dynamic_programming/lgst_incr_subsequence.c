#include<stdio.h>
int maxi(int size , int tab[size]){
    int max= tab[0];
    for (int i = 1; i < size; i++)
    {
        if(max<tab[i]){
            max=tab[i];
        }
    }
    return max;
}

int longest (int nb , int array[nb]){
int resultat[nb];
resultat[0]=1;
int max=0;
for (int i = 1; i < nb; i++)
{
    max=0;
    for (int j = 0 ; j < i ; j++)
    {
        if(array[j]< array[i]&& resultat[j]>max){
        max=resultat[j];
        }
       
    } 
    resultat[i]=1+max;
   
}
/*/
    printf( " \r\n----------------------------\r\n");
    for (int i = 0; i < nb; i++)
    {
        printf(" | %d ", resultat[i]);
    }*/ 

    return maxi(nb , resultat);

}
int main(){
int nb=13 ; 
int array[13]={7, 5, 2, 4, 7, 2, 3, 6, 4, 5, 12, 1, 7};
int resultat= longest(nb , array);
printf("%d\r\n", resultat);
    return 0;
}