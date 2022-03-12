class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        vector<vector<int>> dp(A.size(), vector<int>(2, 1));
        if(A.size()==1)
        {
            return 1;
        }
        
        int res = 1,c=(A[0] != A[1]) ? 2 : 1,inc=A[0]<A[1];
        res=c;
        for (int i = 1; i < A.size()-1; i++) {
            
          
            if((inc&&A[i]>A[i+1])||(!inc&&A[i]<A[i+1]))
            {
                c++;
                res=max(res,c);
            }
            else
            {
                c=(A[i]!=A[i+1])?2:1;
            }
            inc=A[i]<A[i+1];
        }
        return res;
    }
};