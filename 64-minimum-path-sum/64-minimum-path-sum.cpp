class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& memo)
    {
        if(i<0||j<0)
        {
            return INT_MAX;
        }
        if(i==0&&j==0)
        {
            
            return grid[i][j];
        }
        
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        
        int ans=grid[i][j]+min(dfs(grid,i-1,j,memo),dfs(grid,i,j-1,memo));
        
        
        return memo[i][j]=ans;
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        //vector<unordered_map<int,int>>dp(grid.size()+5);
         int m=grid.size(),n=grid[0].size();
        vector<vector<int>> memo(m+5,vector<int>(n+5, -1));
        return dfs(grid,m-1,n-1,memo);
        
        
        
    }
};