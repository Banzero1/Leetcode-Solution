class Solution {
public:
    
    int dp[1005][1005];
    int dfs(string &s,string &t,int i,int j,int n,int m)
    {
        if(j==m)
        {
            return 1;
        }
        
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans=dfs(s,t,i+1,j,n,m);
        if(s[i]==t[j])
        {
            ans+=dfs(s,t,i+1,j+1,n,m);
        }        
        
        return dp[i][j]=ans;
    }
    
    
    int numDistinct(string s, string t) {
        
        int n=s.size(),m=t.size();
        memset(dp,-1,sizeof(dp));
        return dfs(s,t,0,0,n,m);
        
        
    }
};