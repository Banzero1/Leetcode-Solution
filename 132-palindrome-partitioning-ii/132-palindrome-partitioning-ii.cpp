class Solution {
public:
	vector<vector<int>> dp;
	vector<vector<int>> dp1;
	
	int solve(string s, int l, int r){
		if(l>=r) return dp[l][r] = 0;
		if(dp[l][r]!=-1) return dp[l][r];
		if(dp1[l][r]) return dp[l][r] = 0;
		int ans = INT_MAX;
		for(int i=l;i<=r-1;i++){
			if(dp1[l][i]) ans = min(ans, 1+solve(s,i+1,r));
		}
		return dp[l][r] = ans;
	}

	int minCut(string s) {
		dp.resize(s.size(),vector<int> (s.size(),-1));
		dp1.resize(s.size(),vector<int> (s.size(),0));
        int N=s.size();
      
for (int i = N - 1; i >= 0; --i) {
	for (int j = i; j < N; ++j) {
		if (s[i] == s[j]) dp1[i][j] = ((i + 1 <= j - 1) ? dp1[i + 1][j - 1] : 1);
		else dp1[i][j] = 0;
	}
}
        
		return solve(s,0,s.size()-1);
	}
};