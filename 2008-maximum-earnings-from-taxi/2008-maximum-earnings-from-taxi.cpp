class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        sort(rides.begin(),rides.end());
        
        int i,n1=rides.size(),j=n1-1;
        vector<long long int>dp(n+5,0);
        
        for(i=n;i>=1;i--)
        {
            dp[i]=max(dp[i],dp[i+1]);
            while(j>=0&&rides[j][0]==i)
            {
                dp[i]=max(dp[i],dp[rides[j][1]]+(rides[j][1]-rides[j][0])+rides[j][2]);
                j--;
            }
            
        }
        
        
        return dp[1];
        
        
    }
};