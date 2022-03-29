class Solution {
public:
    int countVowelPermutation(int n) {
        
        
        long long int i,j,MOD=1e9+7;
        vector<vector<long long int>>dp(n+1,vector<long long int>(5,0));
        
        for(i=0;i<5;i++)
        {
            dp[1][i]=1;
        }
        
        
        for(i=1;i<n;i++)
        {
             dp[i+1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) %MOD;
        
        dp[i+1][1] = (dp[i][0] + dp[i][2]) % MOD;
        
        dp[i+1][2] = (dp[i][1] + dp[i][3]) % MOD;
        
        dp[i+1][3] = dp[i][2];
        
        dp[i+1][4] = (dp[i][2] + dp[i][3]) % MOD;
        }
        
        long long int c=0;
        
        for(i=0;i<5;i++)
        {
            c=(c+dp[n][i])%MOD;
        }
        
        return c;
    }
};