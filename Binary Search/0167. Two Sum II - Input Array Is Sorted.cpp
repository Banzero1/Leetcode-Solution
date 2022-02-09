class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
        int i,j,n=nums.size();
        
        i=0;
        j=n-1;
        
        while(i<j)
        {
            if(nums[i]+nums[j]==target)
            {
                return {i+1,j+1};
            }
            if(nums[i]+nums[j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        
        return {};
    }
};

// TC - O(N)
// SC - O(1)
