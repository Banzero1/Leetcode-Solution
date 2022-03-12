class Solution {
public:
    int numSquares(int n) {
        
        int i,j;
        vector<int>dp(n+2,1e9);
        dp[1]=1;
        dp[0]=0;
        for(i=2;i<=n;i++)
        {
            for(j=1;j*j<=i;j++)
            {
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        
        return dp[n];
    }
};