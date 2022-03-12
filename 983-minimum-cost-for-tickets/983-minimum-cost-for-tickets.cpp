class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       
        set<int>s(days.begin(),days.end());
        int i,n=days.size();
        vector<int>dp(366,0);
        
        for(i=1;i<=365;i++)
        {
            dp[i]=dp[i-1];
          
              if(s.find(i)!=s.end()){
                dp[i]=dp[i-1]+costs[0];
                dp[i]=min(dp[max(0,i-7)]+costs[1],dp[i]);
                dp[i]=min(dp[max(0,i-30)]+costs[2],dp[i]);
        }
           
        }
        
        return dp[365];
        
        
        
        
    }
};