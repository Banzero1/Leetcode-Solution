class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
/*
Time O(Nlog(max(A[i])))
Space O(1)
*/
        
        long long int i,j,l,r,mid,n=bloomDay.size(),adjacentday,totalbouqets;
     
        l=1;r=1e9;
        if(m*k>n)
        {
            return -1;
        }
        int z=0;
        while(l<r)
        {
            mid=(r+l)/2;
            
            totalbouqets=0;
            adjacentday=0;
            
            //mid=days
            
            for(j=0;j<n;j++)
            {
                if(bloomDay[j]<=mid)
                {
                    adjacentday++;
                }
                else
                {
                    totalbouqets+=adjacentday/k;
                    adjacentday=0;
                }
            }
         
            totalbouqets+=adjacentday/k;
        
            
            if(totalbouqets<m)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
            
        }
        
      return l;
    }
};
