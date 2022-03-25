class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1, 0);
        
        for (int i=0; i<ranges.size(); i++) {
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            jumps[l] = max(jumps[l], r-l);
        }
        
        
        
        // See Jump Game II
        int count = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i<jumps.size()-1; i++) {
            if (i>curFarthest)
                return -1;
            
            curFarthest = max(curFarthest, i + jumps[i]);
            
            if (i == curEnd) {
                count++;
                curEnd = curFarthest;
            }
        }
        
        return curFarthest >= n ? count : -1;
    }
};
// tc- O(n)


/*
 int minTaps(int n, vector<int>& A) {
        vector<int> dp(n + 1, n + 2);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = max(i - A[i] + 1, 0); j <= min(i + A[i], n); ++j)
                dp[j] = min(dp[j], dp[max(0, i - A[i])] + 1);
        return dp[n]  < n + 2 ? dp[n] : -1;
    }
tc - O(n*r)

*/