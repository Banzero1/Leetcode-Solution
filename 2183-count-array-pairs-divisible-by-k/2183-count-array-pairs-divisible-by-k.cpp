class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        
     
       long long i,n=nums.size(),x=k,j,p,xx,ans=0;
        vector<long long>m(1e5+5,0),m1(1e5+5,0),m2(1e5+5,0),m3(1e5+5,0);
        
        vector<long long>v;
        i=2;
        while(x>1)
        {
            while(x%i==0)
            {
                x=x/i;
                v.push_back(i);
                m1[i]++;
            }
            i++;
        }
        
        for(i=0;i<n;i++)
        {
            m2[nums[i]]++;
        }
        
        for(i=2;i<=1e5;i++)
        {
            for(j=i;j<=1e5;j+=i)
            {
                m3[i]+=m2[j];
            }
        }
        
        m3[1]=n;
  
        for(i=0;i<n;i++)
        {
            x=k;
            p=nums[i];
            xx=1;
            j=0;
            while(p>0&&j<v.size())
            {
                if(p%v[j]==0)
                {
                    p/=v[j];
                    x/=v[j];
                    xx=xx*v[j];
                }
              
                j++;
            }
            
            
            ans+=m3[x];
            if(xx%x==0)
            {
                ans--;
            }
          
        }
        
        return ans/2;
        
    }
};