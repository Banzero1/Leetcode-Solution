class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        priority_queue<long double>p;
         long double c=0.0,c1,y,y1;
        int ans=0,n=nums.size(),i;
        
        for(i=0;i<n;i++)
        {
            c+=(long double)nums[i];
            p.push(nums[i]);
        }
      
        c1=c;
        c=c/2.0;
     
      
        while(c1>c)
        {
          
          
            y=p.top();
              p.pop();
            y=y/2.0;
            c1-=y;
          
            if(y>0)
            {
                p.push(y);
            }
            ans++;
          
        }
        
        return ans;
        
    }
};