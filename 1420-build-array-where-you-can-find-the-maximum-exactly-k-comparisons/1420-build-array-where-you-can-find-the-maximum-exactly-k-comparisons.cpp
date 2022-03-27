class Solution {
public:
    
    int dp[101][101][101];
    int mod=1e9+7;
    int dfs(int i,int n, int m, int k,int mx,int cost)
    {
        if(i==n)
        {
            if(cost==k)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][mx][cost]!=-1)
        {
            return dp[i][mx][cost];
        }
        int ans=0;
        for(int j=1;j<=m;j++)
        {
            int a=0;
            if(j>mx)
            {
                 a=dfs(i+1,n,m,k,j,cost+1)%mod;
            }
            else
            {
               // a=dfs(n,m,k,max(mx,j),cost+j>mx?1:0,i+1)%mod;
                 a=dfs(i+1,n,m,k,mx,cost)%mod;
            }
       
            
            a=a%mod;
            ans=ans%mod;
            ans=(ans+a)%mod;
        }
        return dp[i][mx][cost]=ans;
    }
    
    
    int numOfArrays(int n, int m, int k) {
     
        memset(dp,-1,sizeof(dp));
        return dfs(0,n,m,k,0,0);
    }
};