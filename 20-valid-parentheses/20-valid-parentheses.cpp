class Solution {
public:
    bool isValid(string s) {
        
        stack<char>z;
        int i,n=s.size(),f=1;
        for(i=0;i<n;i++)
        {
            if(z.size()>0)
            {
                char x=z.top();
                if((x=='('&&s[i]==')')||(x=='['&&s[i]==']')||(x=='{'&&s[i]=='}'))
                {
                    z.pop();
                }
                else
                {
                    z.push(s[i]);
                }
                   
            }
            else
            {
                z.push(s[i]);
            }
        }
        
        if(z.size()==0)
        {
            return true;
        }
        return false;
    }
};