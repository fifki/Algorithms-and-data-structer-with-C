#include <stdio.h>
#include <string.h>

int ways(char *s) {
    int n = strlen(s);
    int dp[n];
    memset(dp, 0, sizeof(dp));

    if (s[0] == '0')
        return 0;
    else if (n == 1)
        return 1;

    dp[0] = 1;
    dp[1] = (s[1] != '0') + (('1' <= s[0] && s[0] <= '2') && ('0' <= s[1] && s[1] <= '6'));

    for (int i = 2; i < n; i++) {
        if (s[i] != '0')
            dp[i] += dp[i-1];
        if (('1' <= s[i-1] && s[i-1] <= '2') && ('0' <= s[i] && s[i] <= '6'))
            dp[i] += dp[i-2];
    }

    return dp[n-1];
}

int main() {
    char s[] = "12345";
    printf("Number of ways: %d\n", ways(s));
    return 0;
}
/***
 
Ways to decode (problem)
A string made of letters can be encoded by 
replacing each letter by its position in the 
alphabet (e.g.: ELD -> 5124), but when decoding, 
a same encoded string can have multiple ways to 
be decoded (e.g.: 5124 can be decoded as 5 1 2 4 (EABD),
 or 5 12 4 (ELD), or 5 1 24 (EAX)).

Given an encoded string s made of numbers, 
find the number of possible ways to decode it by 
following this decoding map:

1 -> A,   2 -> B,   3 -> C,   4 -> D,   5 -> E,  
 6 -> F,   7 -> G,   8 -> H,   9 -> I,   10 -> J,
    11 -> K,   12 -> L,   13 -> M,   14 -> N,   15 -> O, 
      16 -> P,   17 -> Q,   18 -> R,   19 -> S,   20 -> T, 
        21 -> U,   22 -> V,   23 -> W,   24 -> X,   25 -> Y,  
         26 -> Z
*/