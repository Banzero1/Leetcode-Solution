class Solution {
public:

int dp[100005][3][3];
int solve(vector<int>& prices,int idx,int k,bool is_stock)
{
    int n=prices.size();
    if(idx>=n)
        return 0;
    if(k<=0)
        return 0;
    if(dp[idx][k][is_stock]!=-1)
        return dp[idx][k][is_stock];
    int ans=0;
    if(is_stock)
    {
        ans=max(prices[idx]+solve(prices,idx+1,k-1,0),solve(prices,idx+1,k,1));
    }
    else
    {
        ans=max(solve(prices,idx+1,k,1)-prices[idx],solve(prices,idx+1,k,0));
    }
    return dp[idx][k][is_stock]=ans;
}
int maxProfit(vector<int>& prices)
{
    int k=2;
    memset(dp,-1,sizeof(dp));
    return solve(prices,0,k,0);
}
};