class Solution {
public:
    int m, n, N;
    int t[101][101];
    
    bool check(string s1, string s2, string s3, int i, int j) {
        if(i >= m && j >= n && i+j >= N) //solution
            return true;
        
        if(i+j >= N) //other string didn't get consumed whole
            return false;
            
        if(t[i][j] != -1)
            return t[i][j];
        
        //Note that, k is same for both calls because it increases in both cases
        //Also, at any time k = i + j;
        return t[i][j] = ((s1[i]==s3[i+j] && check(s1, s2, s3, i+1, j)) || (s2[j]==s3[i+j] && check(s1, s2, s3, i, j+1)));
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(t, -1, sizeof(t));
        m = s1.length();
        n = s2.length();
        N = s3.length();
        
        if(m + n != N)
            return false;
        
        return check(s1, s2, s3, 0, 0);
    }
};