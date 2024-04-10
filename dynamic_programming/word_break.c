#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string can be segmented into space-separated words
// from the given list of words using dynamic programming
int word_break(char *s, char **words, int word_count) {
    int k = strlen(s);
    int i, j;

    // Convert the list of words into a set for faster lookup
    int *dp = (int *)malloc((k + 1) * sizeof(int));
    if (dp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    memset(dp, 0, (k + 1) * sizeof(int));
    dp[0] = 1;

    for (i = 1; i <= k; i++) {
        for (j = 0; j < i; j++) {
            char *substring = (char *)malloc((i - j + 1) * sizeof(char));
            if (substring == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            strncpy(substring, s + j, i - j);
            substring[i - j] = '\0';

            // Check if the substring from index j to i exists in the word list
            // and if dp[j] is true (meaning substring up to index j can be segmented)
            int found = 0;
            for (int l = 0; l < word_count; l++) {
                if (strcmp(substring, words[l]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found && dp[j]) {
                dp[i] = 1;
                break;
            }
            free(substring);
        }
    }

    int result = dp[k];
    free(dp);
    return result;
}

int main() {
    char *s = "leetcode";
    char *words[] = {"leet", "code"};
    int word_count = sizeof(words) / sizeof(words[0]);

    int result = word_break(s, words, word_count);
    printf("Can '%s' be segmented into words from the given list? %s\n", s, result ? "Yes" : "No");

    return 0;
}
/**
 Given a string s and a list of words, check if we can break 
 s into words 
 from the list (A same word can be used multiple times).
*/