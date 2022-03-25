class Solution {
public:
    
    bool static cmp (pair<int, int> i, pair<int, int> j) {
    if (i.first == j.first)
        return i.second > j.second;
    return i.first < j.first;
}
    int maxEnvelopes(vector<vector<int>>& e) {
        
        int i,n=e.size();
        
        vector<int>ans;
        
        sort(e.begin(),e.end(),[](vector<int>&a,vector<int>&b){if(a[0]==b[0])
        {return a[1]>b[1];}else{return a[0]<b[0];}                                              });
        
        for(i=0;i<n;i++)
        {
            int z=lower_bound(ans.begin(),ans.end(),e[i][1])-ans.begin();
            if(z==ans.size())
            {
                ans.push_back(e[i][1]);
            }
            else
            {
                ans[z]=e[i][1];
            }
        }
        
        return (int)ans.size();
    }
};