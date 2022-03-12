class Solution {
public:
    int mod=1e9+7;
    int dp[31][1005];
    int solve(int n, int k, int target,int sum)
    {
        if(n==0)
        {
            return sum==target;
        }
        if(sum>target)
        {
            return 0;
        }
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        int ans=0,j;
        for(j=0;j<k;j++)
        {
            ans=(ans+solve(n-1,k,target,sum+j+1))%mod;
        }
        ans%=mod;
        return dp[n][sum]=ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
     
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target,0);
    }
};