class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dp[101][101][101],mod=1e9+7;
    int dfs(int m,int n,int i,int j,int N)
    {
        if(i>=m||j>=n||i<0||j<0)
        {
            return 1;
        }
        if(N<=0)
        {
            return 0;
        }
        if(dp[i][j][N]!=-1)
        {
            return dp[i][j][N];
        }
        
        int totalPaths = 0;
        
        for (int k=0; k<4; k++) {
            totalPaths += dfs(m, n, i + dx[k], j + dy[k],N-1) % mod;
            totalPaths %= mod;
        }
        
        return dp[i][j][N] = totalPaths % mod;
    }
    
    
    int findPaths(int m, int n, int N, int i, int j) {
     
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,i,j,N);
    }
};