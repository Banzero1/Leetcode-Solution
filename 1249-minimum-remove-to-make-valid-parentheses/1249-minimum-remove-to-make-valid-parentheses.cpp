class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        string x;
        int i,n=s.size(),c=0;
        vector<int>v(n+2,-1);
        for(i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                if(c==0){
                v[i]=0;}
                else
                {
                    c--;
                }
            }
            if(s[i]=='(')
            {
                c++;
            }
           c=(c>0)?c:0;        
        }
        
        c=0;
        for(i=n-1;i>=0;i--)
        {
              if(s[i]=='(')
            {
                if(c==0){
                v[i]=0;}
                else
                {
                    c--;
                }
            }
            if(s[i]==')')
            {
                c++;
            }
           c=(c>0)?c:0;  
        }
        
        for(i=0;i<n;i++)
        {
            if(v[i]==-1){
            x+=s[i];}
        }
        
        return x;
    }
};