class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        unordered_map<int,int>m;
        int i,n=nums.size(),c=0;
        for(i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        set<int>s;
        for(i=0;i<n;i++)
        {
            if(m[nums[i]]==1&&m[nums[i]-1]==0&&m[nums[i]+1]==0)
            {
                s.insert(nums[i]);
            }
        }
        vector<int>ans(s.begin(),s.end());
 
      
        return ans;
        
    }
};


//TC - O(N)
//SC - O(N)
