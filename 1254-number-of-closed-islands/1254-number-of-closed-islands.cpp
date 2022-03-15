class Solution {
public:
    int n,m;
      vector<int>dx={0,1,0,-1,0};
    void dfs(vector<vector<int>>&g,int i,int j)
    {
        if(i < 0 || j < 0 || j >= m || i >= n || g[i][j] != 0) return;
        g[i][j] = -1;
        dfs(g , i - 1 , j);
        dfs(g , i + 1 , j);
        dfs(g, i , j - 1);
        dfs(g , i , j + 1);
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int i,j,c=0;
        
         n=grid.size();
        m=grid[0].size();
        
        //first mark all 0 which aren't totally surrounded by 1
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if((i==0||i==n-1||j==0||j==m-1)&&grid[i][j]==0)
                {
                    dfs(grid,i,j);
                }
            }
        }
        
         //count total islands
         for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                  
                      c++;
                    dfs(grid,i,j);
                    
                }
            }
        }
        
        return c;
        
    }
};

/*
Time: O(n), where n is the total number of cells. We flood-fill all land cells once.

Memory: O(n) for the stack. Flood fill is DFS, and the maximum depth is n.

*/
