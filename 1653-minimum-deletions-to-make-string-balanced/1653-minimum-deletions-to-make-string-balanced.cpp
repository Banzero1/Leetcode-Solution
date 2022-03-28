class Solution {
public:
    int minimumDeletions(string s) {
        
        int i,n=s.size(),b=0;
        vector<int>dp(n+1,0);
        
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                 //case 1: keep current a. ==> prev chars must be a...a
                //so need to remove all 'b' chars before i, which is bcount
                
                //case 2: remove current a ==> prev chars must be a...ab...b
                //so need to remove current a and whatever makes substring before current i valid which is dp[i];
                dp[i+1]=min(dp[i]+1,b);
            }
            else
            {
                  //since it is always valid to append 'b' if substring before current i is valid, so just copy whatever makes substring before i valid which is dp[i];
                dp[i+1]=dp[i];
                b++;
            }
        }
        
        return dp[n];
        
    }
};


