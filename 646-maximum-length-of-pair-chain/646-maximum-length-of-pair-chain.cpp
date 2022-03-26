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



/*
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(!pairs.size()) return 0;
        sort(pairs.begin(), pairs.end());
		// LIS array initialized as 1. As, every element is itself an answer
        vector<int> lis(pairs.size(), 1);
        int longestChainNum = 1;
		// Finding LIS in [0-----j]i for each 'i'
        for(int i=1;i<pairs.size();i++){
            for(int j=0;j<i;j++){
				// Condition similar to LIS
                if((pairs[j][1] < pairs[i][0]) && (lis[i] < lis[j] + 1)){
                    lis[i] = lis[j] + 1;
					// Updating maximum
                    longestChainNum = max(longestChainNum, lis[i]);
                }
            }
        }
        return longestChainNum;
    }
};

*/