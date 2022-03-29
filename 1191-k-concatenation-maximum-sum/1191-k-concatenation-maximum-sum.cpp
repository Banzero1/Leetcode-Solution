class Solution {
public:
    int kConcatenationMaxSum(vector<int>& nums, int k) {
        
        long long int i,n=nums.size(),pre=0,s=0,sum=0,mod=1e9+7,ans=0,c=0;
        
        
        for(i=0;i<n;i++)
        {
            c+=nums[i];
            pre=max(pre,c);
        }
        c=0;
        for(i=n-1;i>=0;i--)
        {
            c+=nums[i];
            s=max(s,c);
        }
        
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        if(sum>=0)
        {
            ans=((k-2)*sum)%mod;
        }
        
        
       
        ans=(((pre>0?pre:0)+(s>0?s:0))%mod+ans%mod)%mod;
        s=0;
        c=0;
      
        for(int j=0;j<2&&j<k;j++){
        for(i=0;i<n;i++)
        {
            c=c>=0?(c+nums[i]):nums[i];
            
            s=max(s,c);
            c%=mod;
            s%=mod;
        }
      
    }
      
        
        if(k==1)
        {
            return s;
        }
        s=(s>0)?s%mod:0;
        
        ans=max(ans,s);
        ans=ans%mod;
       
            return ans>0?ans:0;
        
    }
};