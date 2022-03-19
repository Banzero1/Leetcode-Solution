class Solution {
public:
 
    int dp[1005][1005];
    int dfs(string &s,int x,int sz,int i,vector<int>&v)
    {
        int n=s.size();
        if(i>=n)
        {
           return 0;
        }
        if(x==0)
        {
           
            return v[n]-v[i];
        }
        if(dp[i][x]!=-1)
        {
            return dp[i][x];
        }
        
        int ans=1e9;
        if(s[i]=='1'){
          ans=1+dfs(s,x,sz,i+1,v);  
        }
        else
        {
             ans=dfs(s,x,sz,i+1,v);  
        }
        if(x>0)
        {
            
           
            ans=min(ans,dfs(s,x-1,sz,i+sz,v));
        }
  
        
        return dp[i][x]=ans;
        
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        
        int i,n=floor.size();
        vector<int>v(n+1,0);
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
        {
            v[i+1]=v[i]+(floor[i]-'0');
        }
       
        
     return dfs(floor,numCarpets,carpetLen,0,v);
       
        
    }
};