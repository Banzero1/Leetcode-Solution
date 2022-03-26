class Solution {
public:
    int dp[5000 + 1][300 + 1];
    
    int memoization(int w, vector<int>& wt, int n)
    {
        if (n == 0 || w == 0)
            return w == 0 ? 1 : 0;
        
        if (dp[w][n] != -1)
            return dp[w][n];
        
        if (wt[n - 1] > w)
            return dp[w][n] = memoization(w, wt, n - 1);
        else
            return dp[w][n] = memoization(w, wt, n - 1) + memoization(w - wt[n - 1], wt, n);
    }
    
    int change(int amount, vector<int>& coins) 
    {
        memset(dp, -1, sizeof(dp));
        return memoization(amount, coins, coins.size());    
    }
};