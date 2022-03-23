class Solution { // 20 ms, faster than 98.92%
public:
    int m, n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
        int left = matrix[0][0], right = matrix[m-1][n-1], ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid) >= k) {
                ans = mid;
                right = mid - 1; // try to looking for a smaller value in the left side
            } else left = mid + 1; // try to looking for a bigger value in the right side
        }
        return ans;
    }
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int cnt = 0, c = n - 1; // start with the rightmost column
        for (int r = 0; r < m; ++r) {
            while (c >= 0 && matrix[r][c] > x) --c;  // decrease column until matrix[r][c] <= x
            cnt += (c + 1);
        }
        return cnt;
    }
};


/*
Time: O((M+N) * logD), where M <= 300 is the number of rows, N <= 300 is the number of columns, D <= 2*10^9 is the difference between the maximum element and the minimum element in the matrix.
Space: O(1).
Algorithm

Start with left = minOfMatrix = matrix[0][0] and right = maxOfMatrix = matrix[n-1][n-1].
Find the mid of the left and the right. This middle number is NOT necessarily an element in the matrix.
If countLessOrEqual(mid) >= k, we keep current ans = mid and try to find smaller value by searching in the left side. Otherwise, we search in the right side.
Since ans is the smallest value which countLessOrEqual(ans) >= k, so it's the k th smallest element in the matrix.
How to count number of elements less or equal to x efficiently?

Since our matrix is sorted in ascending order by rows and columns.
We use two pointers, one points to the rightmost column c = n-1, and one points to the lowest row r = 0.
If matrix[r][c] <= x then the number of elements in row r less or equal to x is (c+1) (Because row[r] is sorted in ascending order, so if matrix[r][c] <= x then matrix[r][c-1] is also <= x). Then we go to next row to continue counting.
Else if matrix[r][c] > x, we decrease column c until matrix[r][c] <= x (Because column is sorted in ascending order, so if matrix[r][c] > x then matrix[r+1][c] is also > x).
Time complexity for counting: O(M+N).
It's exactly the same idea with this problem


*/