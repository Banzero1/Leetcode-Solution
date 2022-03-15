class Solution {
public:
    
        
    int numOfMinutes(int n, int h, vector<int>& ma, vector<int>& in) {
        
        int i,j,mx=0;
        vector<int>d(n,0);
        vector<vector<int>>v(n+5);
        for(i=0;i<n;i++)
        {
            if(i==h)
            {
                continue;
            }
            v[ma[i]].push_back(i);
           
        }
        
        queue<pair<int,int>>q;
        q.push({0,h});
      
        while(q.size()>0)
        {
            int s=q.size();
            while(s--)
            {
                auto z=q.front();
                int p=z.first+in[z.second];
                d[z.second]=1;
                q.pop();
                for(auto i:v[z.second]){
                    if(d[i]==0){
                q.push({p,i});
                    mx=max(mx,p);}
                    }
                
                
            }
        }
        
        return mx;
    }
};