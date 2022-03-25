/*
In the brute-force approach, we were not sure if an element should be included or not to form the longest increasing subsequence and thus we explored both options. The problem lies in knowing if an element must be included in the sequence formed till now. Let's instead try an approach where we include element whenever possible to maximize the length
The optimization which improves this approach over DP is applying Binary search when we can't extend the sequence and need to replace some element from maintained list - sub. The list always remains sorted and thus binary search gives us the correct index of element in list which will be replaced by current element under iteration.

Basically, we will compare end element of sub with element under iteration cur. If cur is bigger than it, we just extend our list. Otherwise, we will simply apply binary search to find the smallest element >= cur and replace it
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>ans;
        int i,n=nums.size();
        for(i=0;i<n;i++)
        {
            int z=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            
            if(z==ans.size())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                ans[z]=nums[i];
            }
        }
        
        return (int)ans.size();
        
    }
};

/*
Instead, we could store the state of (i, prev_i), where prev_i denotes the index of previous chosen element. Thus we would use a dp matrix where dp[i][j] will denote the longest increasing subsequence from index i when previous chosen element's index is j.

class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums), vector<int>(1+size(nums), -1));   // dp[i][j] denotes max LIS starting from i when nums[j] is previous picked element
        return solve(nums, 0, -1);
    }
    int solve(vector<int>& nums, int i, int prev_i) {
        if(i >= size(nums)) return 0;
        if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
        int take = 0, dontTake = solve(nums, i + 1, prev_i);
        if(prev_i == -1 || nums[i] > nums[prev_i]) take = 1 + solve(nums, i + 1, i); // try picking current element if no previous element is chosen or current > nums[prev_i]
        return dp[i][prev_i+1] = max(take, dontTake);
    }
};
Time Complexity : O(N2)
Space Complexity : O(N2)


*/