#include <stdio.h>
//the problrm

/*
Matrix chain problem (problem)
We have n matrices and we want to compute their product.

Matrix multiplication is associative, 
so ABC for example can be calculated as A(BC) or (AB)C.

But A(BC) and (AB)C can require a different number of operations 
to be computed.

For example if A is a 10x30 matrix,
 B is a 30x5 matrix, and C is a 5x60, 
 then computing ABC as A(BC) costs 27000 operations, 
 because:

cost(BC) = rows(B) x cols(B) x cols(C) = 30x5x60 = 9000
cost(A(BC)) = rows(A) x cols(A) x cols(C) = 10x30x60 = 18000
total = 9000 + 18000 = 27000

But computing it as (AB)C costs 4500 operations, because:

cost(AB) = rows(A) x cols(A) x cols(B) = 10x30x5 = 1500
cost((AB)C) = rows(A) x cols(B) x cols(C) = 10x5x60 = 3000
total = 1500 + 3000 = 4500

So it's better to compute it as (AB)C, it takes less operations.

(NB: To be able to multiply a matrix A of
 size n x m by a matrix B of size m x p, 
 the number of columns of A must be equal 
 to the number of rows of B, and the cost 
 of the multiplication is n x m x p, and 
 the result of the product is a matrix of size n x p)

In the Matrix chain multiplication problem, 
we are given dimensions of n matrices, 
and we are asked to calculate the minimum 
number of operations to calculate the product M0*M1*M2*...

Example:
input:
matrices = [(40, 20), (20, 30), (30, 10), (10, 30), (30, 50)]
output: 49000
*/
int matrix_chain(int n, int matrix[n][2]){



}


int main(){
int n=5;
int nb =27000;
int matrices[5][2] = {{40, 20},
                    {20, 30}, 
                    {30, 10}, 
                    {10, 30}, 
                    {30, 50}};
 //the correct output is 49000
int resultat=matrix_chain(n,matrices);
printf("%d\r\n", resultat);
    return 0;
}

/*
int main(){
int n;
printf("how many matrix do u have?")
scanf("%d"&n);
int matrix[n][2];
printf("write the matrix");
for (int i=0; i<n; i++){
    for(int j=0; j<2; j++){
        scanf("%d", &matrix[n][j]);
    }
}
int resultat=matrix_chain(n,m,matrix);
printf("%d\r\n", resultat);

    return 0;
}*/