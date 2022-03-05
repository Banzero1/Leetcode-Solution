class Solution {
public:
    bool isUgly(int n) {
        
        
        vector<int>v={2,3,5};
        
        int i=0;
        while(n&&i<3)
        {
            while(n%v[i]==0)
            {
                n=n/v[i];
                
            }
            i++;
        }
        
        return n==1;
        
    }
};