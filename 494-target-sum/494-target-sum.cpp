class Solution {
public:
   
    int solve(vector<int>& nums, int target,int s,int i,vector<unordered_map<int,int>> &dp)
    {
        int n=nums.size();
        if(i==n)
        {
            return s==target;
        }
        if(dp[i].count(s))
        {
            return dp[i][s];
        }
        int ans=0;
        ans=solve(nums,target,s-nums[i],i+1,dp)+solve(nums,target,s+nums[i],i+1,dp);
        return dp[i][s]=ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        vector<unordered_map<int,int>> dp(nums.size()+1);
        return solve(nums,target,0,0,dp);
    }
};