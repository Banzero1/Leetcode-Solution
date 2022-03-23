class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        
        int i,n=weights.size(),k=D,l=0,r=0;
      
        for(auto i:weights)
        {
            r+=i;
            l=max(i,l);
        }
        
    
        while(l<r)
        {
            int mid=(l+r)/2;
            int c=0,s=1;
            for(i=0;i<n;i++)
            {
               
                if(c+weights[i]>mid)
                {
                    s++;
                    c=0;
                }
                c+=weights[i];
            }
           
      
            
            if(s>k)
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