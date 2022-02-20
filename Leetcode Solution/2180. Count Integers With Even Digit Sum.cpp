class Solution {
public:
    
    bool dfs(int n)
    {
        string s=to_string(n);
        int i,c=0,n1=s.size();
        for(i=0;i<n1;i++)
        {
            c+=(s[i]-'0');
        }
        
        return c%2==0;
    }
    
    int countEven(int num) {
        
        
        int i,c=0,p=0;
        for(i=1;i<=num;i++)
        {
            if(dfs(i))
            {
                c++;
            }
            
        }
        
        return c;
        
    }
};
