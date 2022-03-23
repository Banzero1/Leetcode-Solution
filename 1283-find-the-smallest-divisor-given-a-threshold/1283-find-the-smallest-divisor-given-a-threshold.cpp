class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int i,j,l,r,n=nums.size(),k=threshold,c=0,mid,x=0;
        
        l=1;
        r=1e6;
        while(l<r)
        {
            mid=l+(r-l)/2;
            x=0;
            c=0;
            for(i=0;i<n;i++)
            {
                c+=nums[i]/mid;
                if(nums[i]%mid!=0)
                {
                    c++;
                }
            }
            if(c>k)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
            
            
        }
       // cout<<l<<r<<endl;
        return l;
        
    }
};