class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        
        int i,j,n=mat.size(),m=mat[0].size(),l,r,mid;
        
        priority_queue<pair<int,int>>p;
        
        for(i=0;i<n;i++)
        {
           l=0;
            r=m-1;
            while(l<=r)
            {
                mid=l+(r-l)/2;
                if(mat[i][mid]==1)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            
          //  cout<<l<<endl;
            p.push({l,i});
            
            
        }
       
        while(p.size()>k)
        {
            p.pop();
        }
        
        vector<int>ans;
        while(p.size()>0)
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};