class Solution {
public:
    int ans=0;
    int dp[5005][8][20],m=1e9+7;
    int dfs(int dieLeft,vector<int>&rollMax,int last, int curlen)
    {
        
         if(dieLeft == 0){
            ans++;
            return 1;
        }
        if(last>=0&&dp[dieLeft][last][curlen]!=0)
        {
            return dp[dieLeft][last][curlen];
        }
        int z=0;
        for(int i=0; i<6; i++){
            if(i == last && curlen == rollMax[i]) continue;
            z=(z+dfs(dieLeft - 1, rollMax, i, i == last ? curlen + 1 : 1)%m);
            z%=m;
        }
        
        if(last>=0)
        {
            dp[dieLeft][last][curlen]=z;
        }
        
        return z;
    }
    
    
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,0,sizeof(dp));
        ans=dfs(n,rollMax,-1,0);
        return ans;
    }
};


/*

For DFS, it is 6 ^n.

For memoization, the total states to fill is the dp array. Worst case n * n * 6 ~ O(n^2)
*/