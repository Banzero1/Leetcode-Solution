class Solution {
public:
	vector<vector<int>> dp;
	vector<vector<int>> dp1;
	bool isPalindrome(string& s, int i, int j) {
		if (i >= j) return true;
		if (dp1[i][j] != -1) return dp1[i][j];
		if (s[i] == s[j]) return dp1[i][j] = isPalindrome(s, i + 1, j - 1);
		return dp1[i][j] = false;
	}

	int solve(string s, int l, int r){
		if(l>=r) return dp[l][r] = 0;
		if(dp[l][r]!=-1) return dp[l][r];
		if(isPalindrome(s,l,r)) return dp[l][r] = 0;
		int ans = INT_MAX;
		for(int i=l;i<=r-1;i++){
			if(isPalindrome(s,l,i)) ans = min(ans, 1+solve(s,i+1,r));
		}
		return dp[l][r] = ans;
	}

	int minCut(string s) {
		dp.resize(s.size(),vector<int> (s.size(),-1));
		dp1.resize(s.size(),vector<int> (s.size(),-1));
		return solve(s,0,s.size()-1);
	}
};