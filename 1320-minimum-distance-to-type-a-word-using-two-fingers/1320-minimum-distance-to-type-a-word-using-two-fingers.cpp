class Solution {
public:
    
    int dp[305][30][30];
    int getd(int x,int y)
    {
        if(x==-1||y==-1)
        {
            return 0;
        }
        
        int p=abs(y/6-x/6)+abs(y%6-x%6);
        return p;
    }
    
    
    int dfs(string word,int pos,int x,int y)
    {
        if(pos==word.size())
        {
            return 0;
        }
        if(dp[pos][x+1][y+1]!=-1)
        {
            return dp[pos][x+1][y+1];
        }
        int ans1,ans2;
        ans1=getd(x,word[pos]-'A')+dfs(word,pos+1,word[pos]-'A',y);
        ans2=getd(y,word[pos]-'A')+dfs(word,pos+1,x,word[pos]-'A');
        
        return dp[pos][x+1][y+1]=min(ans1,ans2);
    }
    
    int minimumDistance(string word) {
        
        int i,j,k;
        for(i=0;i<=301;i++)
        {
            for(j=0;j<=26;j++)
            {
                for(k=0;k<=26;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        
        
        
        return dfs(word,0,-1,-1);
    }
};