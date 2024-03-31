#include<stdio.h>
//declaration
int robber(int a, int array[a]);
int max(int a ,  int b);
//definition 
int max(int a ,  int b){
    if(a>b){return a; }
    else {return b; }
}
int robber(int a, int array[a]){
    int resultat[a];
    for(int i=0; i<a; i++){
        if(i==0){
            resultat[0]=array[i];
        }
        else if(i==1){
            resultat[i]=max( array[0], array[1]);
        }
        else{
            resultat[i]= max(array[i]+resultat[i-2], resultat[i-1]);
        }
    }
    for(int i=0; i<a; i++ ){
        
        printf("| %d |", resultat[i]);
    }
    
    return resultat[a-1];
}
int main(){
    int n=7;
    int array1[7]={2,10,3,6,8,1,7};
    int array2[9]={4,8,12,1,2,10,3,6,8};
    /*for(int i=0; i<7; i++ ){
        scanf("%d", &array[i]);
        printf("| %d |", array[i]);
    }*/
    int resultat= robber(7, array1);
    printf("\r\n the first array :  %d\r\n", resultat);
    int resultat2= robber(9 , array2);
    printf("\r\n the seconde array : %d\r\n", resultat2);
    return 0; 
}