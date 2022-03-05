class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int i,n=nums.size();
        
        vector<int>dp(10005,0);
        vector<int>v(10005,0);
        
        for(i=0;i<n;i++)
        {
            v[nums[i]]+=nums[i];
        }
        dp[0]=v[0];
        dp[1]=v[1];
        for(i=2;i<=10000;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+v[i]);
        }
        
        return dp[10000];
    }
};

// TC -O(N)
// SC- O(N)