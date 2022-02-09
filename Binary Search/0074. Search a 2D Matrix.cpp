class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int start = 0, end = r * c - 1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            int midVal = matrix[mid / c][mid % c];
            
            if (target == midVal) {
                return true;
            } else if (target < midVal) {
                end = mid - 1;
            } else if (target > midVal) {
                start = mid + 1;
            }
        }
        
        return false;
    }
};

//TC - O(log(n*m))
//SC-  O(1)
