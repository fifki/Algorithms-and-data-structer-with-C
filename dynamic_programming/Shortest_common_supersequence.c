/***
 
 Given two strings s1 and s2, find the length of their shortest 
 common supersequence, the shortest string that has both
  s1 and s2 subsequences.

A string A is a supersequence of a string B if B is a 
subsequence of A.



Example:

input:
s1 = "abdacebfcab"
s2 = "acebfca"

output: 11

explanation: The shortest common supersequence 
of s1 and s2 is "abdacebfcab", its length is 11**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int scs(const char *s1, const char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((m + 1) * sizeof(int));
    }

    for (int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int result = dp[n][m];

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    const char *s1 = "ABCBDAB";
    const char *s2 = "BDCAB";
    printf("Shortest Common Supersequence length: %d\n", scs(s1, s2));
    return 0;
}
