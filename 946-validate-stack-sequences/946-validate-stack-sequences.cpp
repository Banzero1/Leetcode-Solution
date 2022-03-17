class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int i=0,n=pushed.size(),j=0;
        stack<int>s;
        for(i=0;i<n;i++)
        {
            s.push(pushed[i]);
            while(s.size()>0&&s.top()==popped[j])
            {
                s.pop();
                j++;
            }
            
        }
        
        return s.size()==0;
        
        
    }
};