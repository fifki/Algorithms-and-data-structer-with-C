#include <stdio.h>

#define NB_VOWELS 5

int count(int n) {
    int dp[n][NB_VOWELS];

    // Initialize the first row of the dp matrix
    for (int i = 0; i < NB_VOWELS; i++) {
        dp[0][i] = 1;
    }

    // Fill the dp matrix
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
        dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
        dp[i][2] = dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
        dp[i][3] = dp[i - 1][3] + dp[i - 1][4];
        dp[i][4] = dp[i - 1][4];
    }

    // Calculate the sum of the last row of the dp matrix
    int sum = 0;
    for (int i = 0; i < NB_VOWELS; i++) {
        sum += dp[n - 1][i];
    }

    return sum;
}

int main() {
    int n = 5;
    printf("Result for n = %d: %d\n", n, count(n));
    return 0;
}
/*
We define the count function to calculate the 
number of strings of length n consisting only 
of vowels ('a', 'e', 'i', 'o', 'u').
We use a 2D array dp to store the dynamic
 programming values.
We initialize the first row of dp with all 
elements as 1, as there is only one possible 
string of length 1 for each vowel.
We fill the dp matrix iteratively according 
to the given recurrence relation.
Finally, we calculate the sum of all elements
 in the last row of the dp matrix, which represents the total 
number of strings of length n consisting only of vowels.
*/