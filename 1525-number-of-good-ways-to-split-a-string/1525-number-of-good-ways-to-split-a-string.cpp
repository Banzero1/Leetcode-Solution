class Solution {
public:
    int numSplits(string s) {
        
        int i,c=0,n=s.size();
        unordered_map<char,int>m,m1;
        
        for(i=0;i<n;i++)
        {
            m[s[i]]++;
            
        }
        for(i=0;i<n-1;i++)
        {
            m1[s[i]]++;
            
            m[s[i]]--;
            if( m[s[i]]==0)
            {
                m.erase(s[i]);
            }
           
          if(m1.size()==m.size())
          {
              c++;
          }
        }
        
        return c;
        
    }
};