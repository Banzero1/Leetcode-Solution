/*dp[i][j] denote the number of distinct subsequences starting with 'i' and end with 'j'
Here's the dp transition:
Case '0':
If the current character is '0', since we are counting distinct subsequences and there shouldn't be any leading zeros in the subsequences, we set dp[0][0] = 1, ex: string "000000" only have a subsequence '0'
dp[1][0] = dp[1][0] + dp[1][1] because it will be the number of ways that we add a '0' to a subsequence starting with '1' and ends with either '0' or '1'

Case '1':
If the current character is '1', since we can't have leading zeros, dp[0][1] is always 0 ("0001" is not a valid subsequence)
The transition will be dp[1][1] = dp[1][0] + dp[1][1] + 1. As we can see, dp[1][0] + dp[1][1] part is same as the case ending with zero. Since we append a '1' to every subsequence dp[1][0] and dp[1][1], we are missing the subsequence "1" with length 1; therefore, we add a one to it.

Note that all calculation above should be done with modulo.

Time Complexity: O(n)
Space Complexity: O(1)
*/
typedef int64_t ll;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) {
        const int mod = 1e9 + 7;
        ll dp[2][2] = {};
        for(char c : s) {
            int a = c - '0';
            if(a == 0) {
                dp[0][0] = 1;
                dp[1][0] = (dp[1][0] + dp[1][1]) % mod;
            } else {
                dp[1][1] = (dp[1][0] + dp[1][1] + 1) % mod;
            }
        }
        return (dp[0][0] + dp[0][1] + dp[1][0] + dp[1][1]) % mod;
    }
};