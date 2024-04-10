#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool inter(char *s1, char *s2, char *s3) {
    int n = strlen(s1);
    int m = strlen(s2);
    if (n + m != strlen(s3)) {
        return false;
    }
    
    bool **dp = (bool**)malloc((n + 1) * sizeof(bool*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (bool*)malloc((m + 1) * sizeof(bool));
    }
    
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) {
        dp[0][j] = s2[j - 1] == s3[j - 1] && dp[0][j - 1];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = s1[i - 1] == s3[i - 1] && dp[i - 1][0];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool check_s1 = s1[i - 1] == s3[i + j - 1] && dp[i - 1][j];
            bool check_s2 = s2[j - 1] == s3[i + j - 1] && dp[i][j - 1];
            dp[i][j] = check_s1 || check_s2;
        }
    }
    
    bool result = dp[n][m];
    
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}

int main(void) {
    char s1[] = "abc";
    char s2[] = "def";
    char s3[] = "adbcef";
    
    if (inter(s1, s2, s3)) {
        printf("Interleaving\n");
    } else {
        printf("Not interleaving\n");
    }
    
    return 0;
}
