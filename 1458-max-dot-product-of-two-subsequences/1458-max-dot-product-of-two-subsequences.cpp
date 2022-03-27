class Solution {
public:
    
    
    int dfs(vector<int>& A, vector<int>& B,int n,int m,int i,int j, vector<vector<int>> &dp)
    {
        if(i>=n||j>=m)
        {
            return -1e9;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=-1e9;
        
        ans=dfs(A,B,n,m,i+1,j,dp);
        ans=max(ans,dfs(A,B,n,m,i,j+1,dp));
        ans=max(ans,dfs(A,B,n,m,i+1,j+1,dp));
        ans=max(ans,A[i]*B[j]+(dfs(A,B,n,m,i+1,j+1,dp)<0?0:dfs(A,B,n,m,i+1,j+1,dp)));
        
        return dp[i][j]=ans;
    }
    
    
     int maxDotProduct(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
      
         return dfs(A,B,n,m,0,0,dp);
    }
};