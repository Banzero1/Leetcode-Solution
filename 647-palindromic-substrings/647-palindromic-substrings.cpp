class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            palindromic(s, i, i, cnt);  //judge odd substring
            palindromic(s, i, i+1, cnt);//judge even substring
        }
        return cnt;
    }
    
private:
    void palindromic(string s, int left, int right, int& cnt) { //judge if a substring is palindromic
        while(left >=0 && right < s.size() && s[left] == s[right]) {
            cnt++;
            left--;
            right++;
        }
    }
};