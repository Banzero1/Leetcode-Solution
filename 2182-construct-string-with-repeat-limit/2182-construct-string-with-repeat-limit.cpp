class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        priority_queue<pair<char,int>>p;
        int i,j,n=s.size(),x=repeatLimit,c=0;
        map<char,int>m;
        string ans;
        
        for(i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        
        for(auto i:m)
        {
            p.push({i.first,i.second});
        }
        
        
        while(p.size()>0)
        {
            auto z=p.top();
            p.pop();
            
            if(c>0&&ans[c-1]==z.first)
            {
                break;
            }
            
            
            if(z.second<=x)
            {
                for(i=0;i<z.second;i++)
                {
                    ans+=z.first;
                }
                c+=z.second;
            }
            else
            {
               
                
                for(i=0;i<x;i++)
                {
                    ans+=z.first;
                }
               
                c+=x;
                 if(p.size()!=0)
                {
                  
                    auto z1=p.top();
                    p.pop();
                    ans+=z1.first;
                    c++;
                    
                    if((z.second-x)>0){
                    p.push({z.first,z.second-x});
                    }
                    
                     if((z1.second-1)>0){
                 p.push({z1.first,z1.second-1});
                     }
                    
                }
                
           
            }
        }
        
        return ans;
        
    }
};