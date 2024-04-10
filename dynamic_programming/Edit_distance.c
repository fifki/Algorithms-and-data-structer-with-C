/* Edit distance (problem)
Given two strings word1 and word2, calculate their edit distance.
The edit distance in this problem is defined as the 
minimum number of insertions, deletions, and substitutions 
of characters to go from word1 to word2.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < c)
        return b;
    else
        return c;
}

int dist(char *word1, char *word2) {
    int n = strlen(word1);
    int m = strlen(word2);
    int dp[n + 1][m + 1];
    
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        }
    }
    
    return dp[n][m];
}

int main() {
    char word1[] = "kitten";
    char word2[] = "sitting";
    printf("Distance between '%s' and '%s' is %d\n", word1, word2, dist(word1, word2));
    return 0;
}
