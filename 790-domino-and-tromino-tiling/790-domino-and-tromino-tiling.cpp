class Solution {
public:
    int numTilings(int N) {
        
        long long int i,n=N,mod=1e9+7;
        vector<long long int>dp(n+5,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(i=4;i<=n;i++)
        {
            dp[i]=dp[i-3]+dp[i-1]*2;
            dp[i]%=mod;
        }
        
        return dp[n];
    }
};

/*
dp[n]=dp[n-1]+dp[n-2]+ 2*(dp[n-3]+...+d[0])
=dp[n-1]+dp[n-2]+dp[n-3]+dp[n-3]+2*(dp[n-4]+...+d[0])
=dp[n-1]+dp[n-3]+(dp[n-2]+dp[n-3]+2*(dp[n-4]+...+d[0]))
=dp[n-1]+dp[n-3]+dp[n-1]
=2*dp[n-1]+dp[n-3]

*/