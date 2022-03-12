class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        
        int i,n=nums.size(),c=0,j,right[2]={0},left[2]={0};
        
        for(i=0;i<n;i++)
        {
            right[i%2]+=nums[i];
        }
        
        for(i=0;i<n;i++)
        {
            right[i%2]-=nums[i];
             
            c+=((left[0]+right[1])==(left[1]+right[0]));
            left[i%2]+=nums[i];
            
        }
        
        return c;
    }
};