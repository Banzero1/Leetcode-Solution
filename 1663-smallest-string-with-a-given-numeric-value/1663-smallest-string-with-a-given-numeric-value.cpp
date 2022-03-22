class Solution {
public:
    string getSmallestString(int n, int k) {
     
        
        int i;
        string s(n,'a');
        k-=n;
        for(i=n-1;i>=0;i--)
        {
            int z=min(k,25);
            k-=z;
            s[i]+=z;
        }
        
        
        return s;
        
    }
};