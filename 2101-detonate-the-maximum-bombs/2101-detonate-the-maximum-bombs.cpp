class Solution {
public:
    vector<int>v[1000];
    
    long long int c=0;
    void dfs(int i,vector<int>&vis)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            c++;
            for(auto j:v[i])
            {
                dfs(j,vis);
            }
        }
    }
    
    int maximumDetonation(vector<vector<int>>& b) {
        
        long long int i,j,n=b.size(),x=0,mx=0,x1,y1;
        
 
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                x1=(long long int)(b[i][0]-b[j][0])*(b[i][0]-b[j][0]);
                y1=(long long int)(b[i][1]-b[j][1])*(b[i][1]-b[j][1]);
            
                 long long int z=(long long int)((long long int)b[i][2]*b[i][2]);
                
                if(x1+y1<=z)
                {
                  
                    v[i].push_back(j);
                   
                }
            }
        }
        
        for(i=0;i<n;i++)
        {
            c=0;
           vector<int>vis(n,0);
            if(vis[i]==0)
            {
                dfs(i,vis);
            }
            mx=max(mx,c);
        }
        
        return mx;
        
        
    }
};