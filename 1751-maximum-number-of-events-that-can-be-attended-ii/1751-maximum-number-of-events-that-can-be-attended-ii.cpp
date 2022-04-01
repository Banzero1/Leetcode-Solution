class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>& events, int k,int c,int i,int n)
    {
        if(i==n||k==0)
        {
           
            return 0;
        }
         
      
        int ans=0;
      
        if(events[i][0]<=c){
        return ans=dfs(events,k,c,i+1,n);}
         if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        
      
            ans=max(dfs(events,k,c,i+1,n),events[i][2]+dfs(events,k-1,events[i][1],i+1,n));
        
      
        return dp[i][k]=ans;
    }
    
    
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n=events.size();
          sort(events.begin() , events.end());
        dp.resize( n, vector<int>( k + 1, -1));
    //vector<unordered_map<int,int>>dp(n+5);
        return dfs(events,k,0,0,n);
    }
};