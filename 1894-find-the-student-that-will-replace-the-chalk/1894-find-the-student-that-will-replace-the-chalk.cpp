class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        long long int i,n=chalk.size(),s=0,p=n;
        
        for(i=0;i<n;i++)
        {
            s+=chalk[i];
        }
        
        while(k>s)
        {
            k-=s;
        }
        
        for(i=0;i<n;i++)
        {
            k-=chalk[i];
            if(k<0)
            {
                p=i;
                break;
            }
        }
        if(p==n)
        {
            p=0;
        }
        
        return p;
    }
};