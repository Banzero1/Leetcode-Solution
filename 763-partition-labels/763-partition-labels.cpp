class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        int i,a[27]={0},j=-1,mx=0,n=S.size();
        vector<int>v;
        
        for(i=0;i<S.size();i++)
        {
            a[S[i]-'a']=i;
        }
        i=0;
        while(i<n)
        {
            mx=max(mx,a[S[i]-'a']);
            if(i==mx)
            {
                v.push_back(i-j);
                j=i;
            }
            i++;
        }
        
        
         return v;
        
    }
};