class Solution {
public:
    
    void dfs(int i,int j,int &x1,int &x2,int &y1,int &y2,vector<vector<int>>& land,vector<vector<int>>& vis,int &c)
    {
        int n,m;
        n=land.size();
        m=land[0].size();
        if(i>=n||i<0||j>=m||j<0||land[i][j]==0||vis[i][j]==1)
        {
            return;
        }
        vis[i][j]=1;
        x1=min(x1,i);
        x2=max(i,x2);
        y1=min(y1,j);
        y2=max(j,y2);
        c++;
        dfs(i+1,j,x1,x2,y1,y2,land,vis,c);
        dfs(i-1,j,x1,x2,y1,y2,land,vis,c);
        dfs(i,j+1,x1,x2,y1,y2,land,vis,c);
        dfs(i,j-1,x1,x2,y1,y2,land,vis,c);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>>v;
        int i,j,n=land.size(),m=land[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(vis[i][j]==0&&land[i][j])
                {
                    int x1=n,y1=m,x2=0,y2=0,c=0;
                    dfs(i,j,x1,x2,y1,y2,land,vis,c);
                    if(c>0)
                    {
                        v.push_back({x1,y1,x2,y2});
                    }
                }
            }
        }
        
        return v;
    }
};