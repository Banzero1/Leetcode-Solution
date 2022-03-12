class Solution {
public:
    
    int dp[300][30000];
    int solve(vector<int>& nums,int i,int x,int sum)
    {
        int n=nums.size();
        if(i==n||x>=sum)
        {
            return x==sum;
        }
        if(dp[i][x]!=-1)
        {
            return dp[i][x];
        }
        return dp[i][x]=solve(nums,i+1,x+nums[i],sum)||solve(nums,i+1,x,sum);
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        
        int i,n=nums.size(),j,s=0;
        memset(dp,-1,sizeof(dp));
      for(i=0;i<n;i++)
      {
          s+=nums[i];
         
      }
        if(s&1)
        {
            return false;
        }
        s/=2;
        return solve(nums,0,0,s);
        
    }
};