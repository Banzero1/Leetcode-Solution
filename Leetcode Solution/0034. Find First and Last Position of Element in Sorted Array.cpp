class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l=0,r=nums.size()-1,mid,k=target;
        
       vector<int>ans(2,-1);
        if(r==-1)
        {
            return ans;
        }
        
        
      
        while(l<r)
        {
            mid=l+(r-l)/2;
            
            if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
            
        }
       
        
        if(nums[l]!=k)
        {
            return ans;
        }
        else
        {
            ans[0]=l;
        }
        
       
       
        r=nums.size()-1;
          while(l<r)
        {
            mid=(l+(r-l)/2)+1;
            
            if(nums[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l=mid;
            }
            
        }
        ans[1]=r;
        return ans;
    }
};

//TC - O(log(max(A[i])))
//SC - O(1)
