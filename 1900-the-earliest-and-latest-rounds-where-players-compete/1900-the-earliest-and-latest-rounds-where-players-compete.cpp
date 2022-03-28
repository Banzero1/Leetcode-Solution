class Solution {
public:
  int min_r = INT_MAX, max_r = INT_MIN;
void dfs(int mask, int round, int i, int j, int first, int second) {
    if (i >= j)
        dfs(mask, round + 1, 0, 27, first, second);
    else if ((mask & (1 << i)) == 0)
        dfs(mask, round, i + 1, j, first, second);
    else if ((mask & (1 << j)) == 0)
        dfs(mask, round, i, j - 1, first, second);
    else if (i == first && j == second) {
        min_r = min(min_r, round);
        max_r = max(max_r, round);
    }
    else {
        if (i != first && i != second)
            dfs(mask ^ (1 << i), round, i + 1, j - 1, first, second);
        if (j != first && j != second)
            dfs(mask ^ (1 << j), round, i + 1, j - 1, first, second);
   
   }
}
vector<int> earliestAndLatest(int n, int first, int second) {
    dfs((1 << n) - 1, 1, 0, 27, first - 1, second - 1);
    return { min_r, max_r };
}
};