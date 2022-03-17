class Solution {
public:
    
    void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<int>>& vis,int x,int y,int &f)
    {
        int n,m,i,j;
        n=grid1.size();m=grid1[0].size();
        if(x<0||x>=n||y<0||y>=m||vis[x][y]==1||grid2[x][y]==0)
        {
            return;
        }
        vis[x][y]=1;
      
        if(grid1[x][y]==0)
        {
            f=0;
            
        }
        dfs(grid1,grid2,vis,x+1,y,f);
        dfs(grid1,grid2,vis,x-1,y,f);
        dfs(grid1,grid2,vis,x,y+1,f);
        dfs(grid1,grid2,vis,x,y-1,f);
        
        
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int i,j,n=grid1.size(),m=grid1[0].size(),c=0;
        
        
       
        vector<vector<int>>v(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
       
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid2[i][j]==1&&vis[i][j]==0)
                {
                   int p=1;
                    dfs(grid1,grid2,vis,i,j,p);
                  
                    if(p==1)
                    {
                        c++;
                    }
                    
                 
                }
            }
        }
        
        
        return c;
        
        
    }
};