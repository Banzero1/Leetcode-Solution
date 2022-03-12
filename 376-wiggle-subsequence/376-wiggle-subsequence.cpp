class Solution {
public:
    int wiggleMaxLength(vector<int>& A) {
        
        
        int i=0,n=A.size(),ans=1,up=1,down=1;
        
        for(i=1;i<n;i++)
        {
            if(A[i]>A[i-1])
            {
                up=1+down;
            }
            else if(A[i]<A[i-1])
            {
                down=1+up;
            }
            ans=max({up,down,ans});
        }
        
        return ans;
    }
};