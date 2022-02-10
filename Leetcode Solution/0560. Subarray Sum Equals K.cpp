class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        
        int i,c=0,n=nums.size(),sum=0;
        unordered_map<int,int>m;
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==target)
            {
                c++;
            }
            
            //we are looking for subarray with sum=current sum-target
                c+=m[sum-target];
                 
            m[sum]++;
           
            
        }
        
        return c;
        
    }
};

//TC - O(N)
//SC - O(N)    
