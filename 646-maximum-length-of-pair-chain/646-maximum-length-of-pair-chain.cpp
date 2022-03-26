class Solution {
public:
    
   
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        vector<pair<int,int>> vop;
        
       
        sort(pairs.begin(),pairs.end());
        
        int i=0 , right=pairs[0][1] , c=1,len = pairs.size();
       
        for(i=1;i<len;i++)
        {
            
            if(pairs[i][1]<right)
            {
                right=pairs[i][1];
            }
            else if(pairs[i][0]>right)
            {
                c++;
                right=pairs[i][1];
            }
         
        }
        
        
        
        return c;
    }
};