class Solution {
public:
    
   //  vector<int>dp;
 
    
    long long mostPoints(vector<vector<int>>& q) {
        
         //vector<int>dp(1000000,-1);
      //  memset(dp,-1,sizeof(dp));
        map<long long int,long long int>dp;
        int i,n=q.size();
        for(i=n-1;i>=0;i--)
        {
            
            if(i+q[i][1]+1<n)
            {
                dp[i]=dp[i+q[i][1]+1]+q[i][0];
            }
            else
            {
                dp[i]=q[i][0];
            }
            
            if(i<n-1)
            {
                dp[i]=max(dp[i],dp[i+1]);
            }
        }
        
        
        
        return dp[0];
        
    }
};


/*
Our dp array contains maximum points we get if we start from question i.

We calculate it going right to left, and the answer for position i is the maximum of:

Take: points[i] + dp[i + 1 + brainpower[i]],
Skip: dp[i + 1].
*/