class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
          int startCol = 0,  endCol = mat[0].size()-1;
        
        while(startCol <= endCol){
            int maxRow = 0,   midCol = startCol + (endCol-startCol)/2;
            
            for(int row=0; row<mat.size(); row++){
				maxRow = mat[row][midCol] >= mat[maxRow][midCol]? row : maxRow;
			}
            
			bool leftIsBig    =  midCol-1>=startCol&&  mat[maxRow][midCol-1] > mat[maxRow][midCol];
            bool rightIsBig   = midCol+1<=endCol  && mat[maxRow][midCol+1] > mat[maxRow][midCol];
            
            
            if(!leftIsBig && !rightIsBig)    // we have found the peak element
                return {maxRow, midCol};
            else if(rightIsBig)
                startCol = midCol+1;
            else                             // leftIsBig
                endCol = midCol-1;
        }
		
		return {};
    }
};

/*
The algorithm is as follows:

Pick the middle column.
Find the global maximum in the column.
If the row-neighbours of this element are smaller, then we found a 2D peak. Else, we recurse at the right-half of the matrix if the right-neighbour was bigger, and left-half of the matrix if the left-neighbour was bigger.
Here is a little intuition as to why this works.

When we find a row-neighbour that is bigger than the global maximum of a column, it means that the row-neighbour is bigger than all the elements of that column. Thus, the global maximum of the neighbour's column must be bigger than its corresponding row-neighbour in our column.

To put it more formally, consider column j whose global maximum lies in row i

// if matrix[i][j + 1] > matrix[i][j] 
// then matrix[i][j + 1] is bigger than all elements in column j
// thus maximum of column j + 1 is bigger than its row-neighbour in column j
// thus, there exists some peak in the right half of the matrix
Complexity Analysis
To find the the maximum of a list of numbers, the best we can do is a linear scan.
We do as many linear scans as log2(m), where m is the number of columns. This is because at every iteration, we discard half of the columns by moving either right or left.

// Thus, the overall time complexity is O(n * log(m)) 
// n = number of rows, m = number of columns 
The space complexity remains constant since we do not create any additional data structures.


*/