class Solution {
public:
    bool checkPartitioning(string s) {
        vector<vector<int>> dp1;
        	dp1.resize(s.size(),vector<int> (s.size(),0));
        int N=s.size();
      
for (int i = N - 1; i >= 0; --i) {
	for (int j = i; j < N; ++j) {
		if (s[i] == s[j]) dp1[i][j] = ((i + 1 <= j - 1) ? dp1[i + 1][j - 1] : 1);
		else dp1[i][j] = 0;
	}
}
        
        for (int i = 1; i < N - 1; ++i) {
	for (int j = i; j < N - 1; ++j) {
		if (dp1[0][i - 1] && dp1[i][j] && dp1[j + 1][N - 1]) return true;
	}
}
        
        return false;
    }
};