class Solution {
public:
    int dp[58 + 1][57 + 1];
    
    int recursion(int n, int cur)
    {    
        if (n == 0 || cur == 0)
            return 1;
        if (dp[n][cur] != -1)
            return dp[n][cur];
        if (cur > n)
            return dp[n][cur] = recursion(n - 0, cur - 1);
        else
            return dp[n][cur] = max(recursion(n - 0, cur - 1), cur * recursion(n - cur, cur));
    }
    
    int integerBreak(int n) 
    {
        memset(dp, -1, sizeof(dp));
        return recursion(n, n - 1);    
    }
};