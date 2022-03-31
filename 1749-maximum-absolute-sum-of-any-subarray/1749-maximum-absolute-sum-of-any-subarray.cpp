class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int i,c=0,mx=0,n=nums.size(),s=0;
        
        for(i=0;i<n;i++)
        {
            c+=nums[i];
            s+=nums[i];
            if(s>0)
            {
                s=0;
            }
            if(c<0)
            {
                c=0;
            }
            mx=max(mx,c);
            mx=max(mx,abs(s));
        }
        
        return mx;
        
    }
};

//We can break this problem into finding a max sum subarray and min sum subarray.