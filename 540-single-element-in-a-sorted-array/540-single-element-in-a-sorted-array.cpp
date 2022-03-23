class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
           int l=0,r=nums.size()-1,mid;
        
        
        while(l<r)
        {
            mid=(l+r)/2;
            if((mid%2==1&&nums[mid]==nums[mid-1])||(mid%2==0&&nums[mid]==nums[mid+1]))
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
            
            
        }
       
        return nums[l];
    }
};