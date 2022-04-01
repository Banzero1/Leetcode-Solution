#define ll long long
class Solution {
public:
     vector<vector<ll> > dp;
    ll mod = 1e9 + 7;
    ll dfs(ll n,ll k)
    {
        if(k>n||k<=0)
        {
            return 0;
        }
        if(n<=2)
        {
            return 1;
        }
        if(dp[n][k]!=-1)
        {
            return dp[n][k];
        }
        ll ans=0;
        ans=dfs(n-1,k-1)%mod;
        ans=(ans+((n-1)*dfs(n-1,k)))%mod;
        return dp[n][k]=ans;
    }
    
    
    
    int rearrangeSticks(int n, int k) {
        
        
       dp = vector<vector<ll> >(n + 1, vector<ll>(k + 1, -1));
        return dfs(n,k);
        
    }
};