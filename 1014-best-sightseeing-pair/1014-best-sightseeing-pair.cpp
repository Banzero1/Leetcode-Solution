class Solution {
public:
   int maxScoreSightseeingPair(vector<int>& a)
    {
        int n = a.size(), maxScore = 0;
        int maxLeft = a[0] + 0;
        for(int j = 1; j < n; j++) {
            maxScore = max(maxScore, maxLeft + a[j] - j);
            maxLeft = max(maxLeft, a[j] + j);
        }
        return maxScore;
    }
};