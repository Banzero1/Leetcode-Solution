class Solution {
public:
    
        int dfs(string&s,int i,int j,vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return 1;
        }
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[i][j]=2+dfs(s,i+1,j-1,dp);
        }
        else
        {
            return dp[i][j]=max(dfs(s,i+1,j,dp),dfs(s,i,j-1,dp));
        }
    }
    
    int longestPalindromeSubseq(string s) {
          int n=s.size();
       vector<vector<int>>dp(n+5,vector<int>(n+5,-1));
        int p= dfs(s,0,n-1,dp);
        return p;
    }
};