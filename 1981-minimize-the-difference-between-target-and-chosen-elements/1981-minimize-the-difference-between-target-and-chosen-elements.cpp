class Solution {
public:
    int dp[10000][79];
    int find(vector<vector<int>>&mat,int r,int sum,int target)
    {
        if(r>=mat.size())
        {
            return abs(sum-target);
        }
        if(dp[sum][r]!=-1)
        {
            return dp[sum][r];
        }
        int ans=INT_MAX;
        for(int i=0;i<mat[r].size();i++)
        {
            ans=min(ans,find(mat,r+1,sum+mat[r][i],target));
        }
       return dp[sum][r]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) 
    {
        memset(dp,-1,sizeof(dp));
        int n=mat.size();
        int m=mat[0].size();
        return find(mat,0,0,target);
    }
};