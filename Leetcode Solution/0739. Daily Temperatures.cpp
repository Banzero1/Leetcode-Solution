class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        int i,n=T.size();
        
        vector<int>v(n,0);
        stack<int>s;
        
        
        for(i=0;i<n;i++)
        {
            if(s.size()==0)
            {
                s.push(i);
            }
            else
            {
                while(!s.empty()&&T[i]>T[s.top()])
                {
                    v[s.top()]=i-s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
        
        return v;
        
    }
};

TC - O(N)
SC - O(N) 
