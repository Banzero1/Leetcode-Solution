class Solution {
public:
    
    
    int dfs(int n,int c,int x,vector<unordered_map<int,int>> &dp)
    {
        if(c==n)
        {
            return 0;
        }
        
        if(c>n)
        {
            //cout<<c;
            return 1e5;
        }
        
        if(dp[c].count(x))
        {
            return dp[c][x];
        }
        
        int ans=1e9;
        ans=2+dfs(n,2*c,c,dp);
        ans=min(ans,1+dfs(n,c+x,x,dp));
        
        cout<<ans<<endl;
        return dp[c][x]=ans;
    }
    
    int minSteps(int n) {
        
      vector<unordered_map<int,int>> dp(2*n+5);
        if(n==1)
        {
            return 0;
        }
        return dfs(n,1,1,dp)+1;
    }
};