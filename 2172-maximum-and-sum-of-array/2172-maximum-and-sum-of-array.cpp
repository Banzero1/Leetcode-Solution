class Solution {
public:
    
    int dfs(vector<int>& nums,int sl,vector<int>&m,int i,map<pair<int,vector<int>>,int>&dp)
    {
        if(i==nums.size())
        {
           // cout<<sum<<endl;
           
            return 0;
        }
        
        int ans=0;
        if(dp.find({i,m})!=dp.end())
        {
            return dp[{i,m}];
        }
        for(int j=1;j<=sl;j++)
        {
            if(m[j]==2)
            {
                continue;
            }
            
                    m[j]++;
                   ans=max(ans,dfs(nums,sl,m,i+1,dp)+(nums[i]&j));
                   m[j]--;
            
        }
        
        return dp[{i,m}]=ans;
        
    }
    
    
    int maximumANDSum(vector<int>& nums, int sl) {
        
        int mx=0;
        unordered_map<int,int>m1;
        vector<int>m(sl+1,0);
        map<pair<int,vector<int>>,int>dp;
        return dfs(nums,sl,m,0,dp);
        
        
    }
};