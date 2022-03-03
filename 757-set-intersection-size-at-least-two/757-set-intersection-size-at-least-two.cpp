class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& v) {
        
        sort(v.begin(),v.end(),[](vector<int>&a,vector<int>&b)
        {
            return a[1]<b[1]||(a[1]==b[1]&&b[0]<a[0]);
        });
        
        int i,p1=-1,p2=-1,ans=0,n=v.size();
        
        for(i=0;i<n;i++)
        {
            
            if(v[i][0]<=p1)
            {
                continue;
                /*
                b[i] is sorted in ascending order so we know our current b[i] is always greater or equal than all other b[i] we visited yet.
                
                
                
                */
            }
            
            if(v[i][0]>p2)
            {
                ans+=2;
                p2=v[i][1];
                p1=p2-1;
                
                /*
                 case like p1=3 p2=4
                 (3,4)
                 (5,6)
            
            
                */
            }
            else
            {
                 /*
                 case like p1=3 p2=4
                 (3,4)
                 (4,6)
            
            
                */
                ans++;
                p1=p2;
                p2=v[i][1];
                
            }
            
            cout<<v[i][0]<<" "<<v[i][1]<<" "<<ans<<endl;
        }
        
        
        return ans;
    }
};