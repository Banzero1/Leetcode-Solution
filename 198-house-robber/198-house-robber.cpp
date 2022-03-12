class Solution {
public:
    int rob(vector<int>& nums) {
        
            int i,n=nums.size(),p=2;
        
        vector<int>dp(n+1,0);
      
        if(!n)
        {
            return 0;
        }
        if(n==1)
        {
            return nums[0];
        }
       
       dp[1]=nums[0];
       
        
        for(i=1;i<n;i++)
        {
            
            dp[i+1]=max(dp[i-1]+nums[i],dp[i]);
        }
        
        return dp[n];
        
        
    }
};