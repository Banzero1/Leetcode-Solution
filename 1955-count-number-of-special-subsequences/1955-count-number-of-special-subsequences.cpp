class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> memo;
  
    int dfs(vector<int> &A, int i, int prev) {
      if(i == A.size()) return prev == 2; 
      
      if(memo[prev+1][i] != -1) return memo[prev+1][i];
      
      long long ans = 0; 
      ans += dfs(A, i+1, prev);
      
      if(A[i] == prev) ans += dfs(A, i+1, prev);
      if(prev == -1 && A[i] == 0) ans += dfs(A, i+1, 0);
      if(prev == 0 && A[i] == 1) ans += dfs(A, i+1, 1);
      if(prev == 1 && A[i] == 2) ans += dfs(A, i+1, 2);
      
      ans = ans % M;
      return memo[prev+1][i] = ans;
    }
  
    int countSpecialSubsequences(vector<int>& nums) {
      memo = vector<vector<int>> (4, vector<int>(nums.size() + 1, -1));
      return dfs(nums, 0, -1);
    }
};