class Solution {
public:
   int findMaxForm(vector<string>& strs, int m, int n) {
	// dp[i][j] will store Max subset size possible with zeros_limit = i, ones_limit = j
       int an=0;
	vector<vector<int> > dp(m + 1, vector<int>(n + 1,0));
	for(auto& str : strs) {
		// count zeros & ones frequency in current string            
		int zeros = count(begin(str), end(str), '0'), ones = size(str) - zeros; 
		// which positions of dp will be updated ?
		// Only those having atleast `zeros` 0s(i >= zeros) and `ones` 1s(j >= ones)
		for(int i = m; i >= zeros; i--)
        {		for(int j = n; j >= ones; j--)                    
            {dp[i][j] = max(dp[i][j], // either leave the current string
							   dp[i - zeros][j - ones] + 1);
        an=max(an,dp[i][j]);}
    }
        // or take it by adding 1 to optimal solution of remaining balance
		// at this point each dp[i][j] will store optimal value for items considered till now & having constraints i and j respectively
	}
	return an;
}
//Time Complexity : O(L*m*n), where L is the length of strs
//Space Complexity : O(m*n)
};