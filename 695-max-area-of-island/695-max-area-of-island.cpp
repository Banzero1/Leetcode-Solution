class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
         
     int i,j,x,y,n=grid.size(),m=grid[0].size(),k,mx=0,ans=0,c=0;
        vector<vector<int>>v(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>dx={0,1,0,-1,0};
        queue<pair<int,int>>q;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1&&vis[i][j]==0)
                {
                
                    q.push({i,j});
                    vis[i][j]=1;
                   c=1;
                    
                       while(q.size()>0)
        {
            int s=q.size();
            while(s--)
            {
                auto p=q.front();
                q.pop();
                for(k=0;k<4;k++)
                {
                    x=p.first+dx[k];
                    y=p.second+dx[k+1];
                    
                    if(x>=0&&x<n&&y>=0&&y<m&&vis[x][y]==0&&grid[x][y]==1)
                    {
                        q.push({x,y});
                    c++;
                        vis[x][y]=1;
                    }
                }
            }
        }
                    ans=max(ans,c);
                }
            }
        }
           
        
        
        return ans;
        
    }
};