class Solution {
public:
    
    int dp[1<<16][30],n,time;
    
    int dfs(vector<int>&tasks,int ct,int mask)
    {
        if(ct>time)
        {
            return 1e9;
        }
        if(mask==(1<<n)-1)
        {
            return 1;
        }
        
        if(dp[mask][ct]!=-1)
        {
            return dp[mask][ct];
        }
        int ans=1e9;
        for(int i=0;i<tasks.size();i++)
        {
          //  int ans=30;
            if((mask&(1<<i))==0)
            {
                ans=min(ans,dfs(tasks,ct+tasks[i],mask|(1<<i)));
                ans=min(ans,dfs(tasks,tasks[i],mask|(1<<i))+1);
            }
        }
        dp[mask][ct]=ans;
        return ans;
    }
    
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        
        memset(dp,-1,sizeof(dp));
         n=tasks.size();
        time=sessionTime;
        int mask=(1<<n)-1;
        int z=dfs(tasks,0,0);
        return z;
        
        
        
    }
};