class Solution {
public:
    int ans=0,dp[1005][1005];
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j)
    {
        if(i>=nums1.size()||j>=nums2.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int an=0;
           solve(nums1,nums2,i+1,j);
            solve(nums1,nums2,i,j+1);
        if(nums1[i]==nums2[j])
        {
            an=1+ solve(nums1,nums2,i+1,j+1);
        }
        
        ans=max(ans,an);
        return dp[i][j]=an;
    }
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        memset(dp,-1,sizeof(dp));
         solve(nums1,nums2,0,0);
        return ans;
    }
};