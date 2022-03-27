class Solution {
public:
     bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
       
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

/*
dp[i] means the result for n = i.

if there is any k that dp[i - k * k] == false,
it means we can make the other lose the game,
so we can win the game an dp[i] = true.

*/