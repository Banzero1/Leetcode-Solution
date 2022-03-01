class Solution {
public:
    vector<int> countBits(int num) {
        if(num==0)
        {
            return {0};
        }
        int i;
        vector<int>dp(num+1,0);
        for(i=0;i<=num;i++)
        {
            if(i&1)
            {
                dp[i]=dp[i-1]+1;
            }
            else
            {
                dp[i]=dp[i/2];
            }
        }
        
        return dp;
    }
};