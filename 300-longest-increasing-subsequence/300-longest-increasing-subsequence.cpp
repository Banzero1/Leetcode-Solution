class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>ans;
        int i,n=nums.size();
        for(i=0;i<n;i++)
        {
            int z=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            
            if(z==ans.size())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                ans[z]=nums[i];
            }
        }
        
        return (int)ans.size();
        
    }
};