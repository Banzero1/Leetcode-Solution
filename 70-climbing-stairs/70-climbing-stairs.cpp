class Solution {
public:
    int climbStairs(int n) {
       int dp[n+2],i,j;
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        int m=dp[n];
        return m;
    }
};